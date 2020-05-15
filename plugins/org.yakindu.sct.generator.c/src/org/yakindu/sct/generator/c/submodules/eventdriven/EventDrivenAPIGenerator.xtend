/**
 * Copyright (c) 2018 committers of YAKINDU and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 * Contributors:
 * 	rbeckmann - initial API and implementation
 * 
 */
package org.yakindu.sct.generator.c.submodules.eventdriven

import com.google.inject.Inject
import com.google.inject.Singleton
import org.yakindu.sct.generator.c.GeneratorPredicate
import org.yakindu.sct.generator.c.TraceCode
import org.yakindu.sct.generator.c.extensions.EventNaming
import org.yakindu.sct.generator.c.submodules.APIGenerator
import org.yakindu.sct.generator.c.types.CLiterals
import org.yakindu.sct.model.sexec.ExecutionFlow

import static org.yakindu.sct.generator.c.CGeneratorConstants.BOOL_TYPE
import static org.yakindu.sct.generator.c.CGeneratorConstants.INTPTR_TYPE
import static org.yakindu.sct.generator.c.CGeneratorConstants.INT_TYPE

/**
 * @author rbeckmann
 * @author axel terfloth
 *
 */
@Singleton // Guice
class EventDrivenAPIGenerator extends APIGenerator {
	@Inject protected extension EventNaming
	@Inject protected extension CLiterals
	@Inject protected extension GeneratorPredicate
	@Inject protected extension TraceCode
	
	override protected initSignature(ExecutionFlow it) {
		val internalArgs = ''', «internalEventStructTypeName» *internal_queue_buffer, «INT_TYPE» internal_queue_capacity'''
		val inArgs = ''', «internalEventStructTypeName» *in_queue_buffer, «INT_TYPE» in_queue_capacity'''
		'''void «initFctID»(«scHandleDecl»«IF userAllocatesInternalQueue»«internalArgs»«ENDIF»«IF userAllocatesInQueue»«inArgs»«ENDIF»)'''
	}
	
	override protected initFunctionBody(ExecutionFlow it) {
		'''
		«super.initFunctionBody(it)»
		«IF needsInternalEventQueue»
			«eventQueueInitFunction»(&«scHandle»->«internalQueue», «IF userAllocatesInternalQueue»internal_queue_buffer, internal_queue_capacity«ELSE»«scHandle»->internal_buffer, «internalBufferSize»«ENDIF»);
		«ENDIF»
		«IF needsInEventQueue»
			«eventQueueInitFunction»(&«scHandle»->«inEventQueue», «IF userAllocatesInQueue»in_queue_buffer, in_queue_capacity«ELSE»«scHandle»->in_buffer, «inBufferSize»«ENDIF»);
		«ENDIF»
		«IF needsRunCycleGuard»
			«scHandle»->«runCycleGuard» = «FALSE_LITERAL»;
		«ENDIF»
		'''
	}
	
	override runCycle(ExecutionFlow it)  {
		if(!needsQueues) {
			return super.runCycle(it)
		} else {
			'''
				«runCycleSignature»
				{
					«internalEventStructTypeName» currentEvent;
					«IF needsRunCycleGuard»
					if(«scHandle»->«runCycleGuard» == «TRUE_LITERAL») {
						return;
					}
					«scHandle»->«runCycleGuard» = «TRUE_LITERAL»;
					«ENDIF»
					«IF needsClearOutEventsFunction»«clearOutEventsFctID»(«scHandle»);«ENDIF»
					
					currentEvent = «nextEventFctID»(«scHandle»);
					
					do {
						«dispatchEventFctID»(«scHandle», &currentEvent);
						«runCycleForLoop»
						«clearInEventsFctID»(«scHandle»);
					} while((currentEvent = «nextEventFctID»(«scHandle»)).name != «invalidEventEnumName»);
					
					«IF needsRunCycleGuard»
					«scHandle»->«runCycleGuard» = «FALSE_LITERAL»;
					«ENDIF»
				}
			'''
		}
	}
	
	override raiseTimeEvent(ExecutionFlow it) '''
		«IF timed»
			«raiseTimeEventSignature»
			{
				if ( ((«INTPTR_TYPE»)evid) >= ((«INTPTR_TYPE»)&(«scHandle»->timeEvents))
					&&  ((«INTPTR_TYPE»)evid) < ((«INTPTR_TYPE»)&(«scHandle»->timeEvents)) + (unsigned)sizeof(«timeEventScope.type»))
				{
					*(«BOOL_TYPE»*)evid = «TRUE_LITERAL»;
					«traceTimeEventRaised»								
					«runCycleFctID»(«scHandle»);
				}
			}
		«ENDIF»
		'''
	
	override enter(ExecutionFlow it) {
		'''
			«enterSignature»
			{
				«traceMachineEnter»
				«IF needsRunCycleGuard»
				«scHandle»->«runCycleGuard» = «TRUE_LITERAL»;
				«ENDIF»
				«enterSequences.defaultSequence.code»
				«IF needsRunCycleGuard»
				«scHandle»->«runCycleGuard» = «FALSE_LITERAL»;
				«ENDIF»
			}
		'''
	}
	
	override exit(ExecutionFlow it) {
		'''
			«exitSignature»
			{
				«IF needsRunCycleGuard»
				«scHandle»->«runCycleGuard» = «TRUE_LITERAL»;
				«ENDIF»
				«exitSequence.code»
				«IF needsRunCycleGuard»
				«scHandle»->«runCycleGuard» = «FALSE_LITERAL»;
				«ENDIF»
				«traceMachineExit»
			}
		'''
	}
}