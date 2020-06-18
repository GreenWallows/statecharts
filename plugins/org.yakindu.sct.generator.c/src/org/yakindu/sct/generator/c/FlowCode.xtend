/**
 * Copyright (c) 2012-2018 committers of YAKINDU and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 * Contributors:
 * 	committers of YAKINDU - initial API and implementation
 * 
 */
package org.yakindu.sct.generator.c

import com.google.inject.Inject
import org.yakindu.sct.generator.c.extensions.Naming
import org.yakindu.sct.generator.c.types.CLiterals
import org.yakindu.sct.generator.core.types.ICodegenTypeSystemAccess
import org.yakindu.sct.model.sexec.Call
import org.yakindu.sct.model.sexec.Check
import org.yakindu.sct.model.sexec.CheckRef
import org.yakindu.sct.model.sexec.EnterState
import org.yakindu.sct.model.sexec.Execution
import org.yakindu.sct.model.sexec.ExitState
import org.yakindu.sct.model.sexec.HistoryEntry
import org.yakindu.sct.model.sexec.If
import org.yakindu.sct.model.sexec.LocalVariableDefinition
import org.yakindu.sct.model.sexec.Return
import org.yakindu.sct.model.sexec.SaveHistory
import org.yakindu.sct.model.sexec.ScheduleTimeEvent
import org.yakindu.sct.model.sexec.Sequence
import org.yakindu.sct.model.sexec.StateSwitch
import org.yakindu.sct.model.sexec.Statement
import org.yakindu.sct.model.sexec.Step
import org.yakindu.sct.model.sexec.Trace
import org.yakindu.sct.model.sexec.UnscheduleTimeEvent
import org.yakindu.sct.model.sexec.extensions.SExecExtensions
import org.yakindu.sct.model.sexec.naming.INamingService
import org.yakindu.sct.model.stext.lib.StatechartAnnotations

import static org.yakindu.sct.generator.c.CGeneratorConstants.*
import org.yakindu.sct.model.sexec.DoWhile
import org.yakindu.sct.generator.core.submodules.lifecycle.NamedConceptSequenceCode
import org.yakindu.sct.model.sexec.transformation.ng.StateMachineConcept

/**
 * @author axel terfloth
 */
class FlowCode {
	
	@Inject extension Naming
	@Inject extension SExecExtensions
	@Inject extension CExpressionsGenerator
	@Inject extension INamingService
	@Inject extension TraceCode 
	@Inject protected extension ICodegenTypeSystemAccess
	@Inject protected extension StatechartAnnotations
	@Inject protected extension NamedConceptSequenceCode
	@Inject protected extension StateMachineConcept
	
	@Inject protected extension CLiterals
	
 
 
	def stepComment(Step it) '''
		«IF !comment.nullOrEmpty»
			/* «comment» */
		«ENDIF»
	'''
	
	def dispatch CharSequence code(Step it) '''
		#error ActionCode for Step '«getClass().name»' not defined
	'''
	

	def dispatch CharSequence code(Trace it) {
		traceCode
	}
		

	def dispatch CharSequence code(SaveHistory it) '''
		«stepComment»
		«scHandle»->«HISTORYVECTOR»[«region.historyVector.offset»] = «scHandle»->«STATEVECTOR»[«region.stateVector.offset»];
	'''
	
	def dispatch CharSequence code(HistoryEntry it) '''
		«stepComment»
		if («scHandle»->«HISTORYVECTOR»[«region.historyVector.offset»] != «null_state»)
		{
			«historyStep.code»
		} «IF initialStep !== null»else
		{
			«initialStep.code»
		} «ENDIF»
	'''

	def dispatch CharSequence code(StateSwitch it) '''
		«stepComment»
		«IF historyRegion !== null»
			switch(«scHandle»->«HISTORYVECTOR»[ «historyRegion.historyVector.offset» ])
			{
		«ELSE»
			switch(«scHandle»->«STATEVECTOR»[ «stateConfigurationIdx» ])
			{
		«ENDIF»
			«FOR caseid : cases»
				case «caseid.state.stateName» :
				{
					«caseid.step.code»
					break;
				}
			«ENDFOR»
			default: break;
		}
	'''

	def dispatch CharSequence code(ScheduleTimeEvent it) '''
		«stepComment»
		«flow.setTimerFctID»(«scHandle», («EVENT_TYPE») &(«scHandle»->timeEvents.«timeEvent.shortName»_raised) , «timeValue.code», «IF timeEvent.periodic»bool_true«ELSE»bool_false«ENDIF»);
		«traceCode»
	'''

	def dispatch CharSequence code(UnscheduleTimeEvent it) '''
		«stepComment»
		«flow.unsetTimerFctID»(«scHandle», («EVENT_TYPE») &(«scHandle»->timeEvents.«timeEvent.shortName»_raised) );		
		«traceCode»
	'''

	def dispatch CharSequence code(Execution it) '''
		«statement.code»;
		«statement.traceCode»
		'''
	
	def dispatch CharSequence code(Call it)
		'''«step.shortName»(«scHandle»);'''

	def dispatch CharSequence code(Sequence it) {
		if (it.isStateMachineConcept) 
			it.flow.stateMachineConceptCode(it)	
		else '''
			«IF !steps.nullOrEmpty»«stepComment»«ENDIF»
			«FOR s : steps»
				«s.code»
			«ENDFOR»
		'''
	}

	def dispatch CharSequence code(Check it)
		'''«IF condition !== null»«condition.sc_boolean_code»«ELSE»«TRUE_LITERAL»«ENDIF»'''
	
	def dispatch CharSequence code(CheckRef it)
		'''«IF check !== null»«check.shortName»(«scHandle») == «TRUE_LITERAL»«ELSE»«TRUE_LITERAL»«ENDIF»'''

	def dispatch CharSequence code(If it) '''
		«stepComment»
		if («check.code»)
		{ 
			«thenStep.code»
		} «IF (elseStep !== null)» else
		{
			«elseStep.code»
		}
		«ENDIF»
	'''
	
	def dispatch CharSequence code(DoWhile it) '''
		«stepComment»
		do
		{ 
			«body.code»
		} while («check.code»);
	'''
	
	def dispatch CharSequence code(EnterState it) '''
		«scHandle»->«STATEVECTOR»[«state.stateVector.offset»] = «state.stateName»;
		«scHandle»->«STATEVECTOR_POS» = «state.stateVector.offset»;
		«IF flow.statechart.isSuperStep»
		«scHandle»->«STATEVECTOR_CHANGED» = true;
		«ENDIF»
	'''

	def dispatch CharSequence code(ExitState it) '''
		«scHandle»->«STATEVECTOR»[«state.stateVector.offset»] = «null_state»;
		«scHandle»->«STATEVECTOR_POS» = «state.stateVector.offset»;
	'''
	
	def dispatch CharSequence code(Return it) '''
		return«IF value !== null» «value.code»«ENDIF»;
	'''
	
	def dispatch CharSequence code(LocalVariableDefinition it) '''
		«variable.typeSpecifier.targetLanguageName» «variable.name»«IF initialValue !== null» = «initialValue.code»«ENDIF»;
	'''
	
	def dispatch CharSequence code(Statement it) '''
		«expression.code»;
		«expression.traceCode»
	'''

	def unusedParam(String s) '''
		SC_UNUSED(«s»);
	'''
	
}
