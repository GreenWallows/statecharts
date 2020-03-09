package org.yakindu.sct.generator.c.files

import org.yakindu.sct.generator.c.IContentTemplate
import org.yakindu.sct.generator.c.extensions.GenmodelEntries
import com.google.inject.Inject
import org.yakindu.sct.model.sexec.ExecutionFlow
import org.yakindu.sct.model.sgen.GeneratorEntry
import org.yakindu.sct.generator.c.IGenArtifactConfigurations
import org.yakindu.sct.generator.c.CGeneratorConstants
import org.yakindu.sct.model.sexec.TimeEvent
import org.yakindu.sct.generator.c.extensions.Naming

class MetaSource implements IContentTemplate {
	@Inject extension GenmodelEntries
	@Inject extension Naming
	
	override content(ExecutionFlow flow, GeneratorEntry entry, extension IGenArtifactConfigurations locations) {
		'''
		«entry.licenseText»
		
		#include "«(flow.metaModule.h).relativeTo(flow.metaModule.c)»"				
				
		«CGeneratorConstants::STRING_TYPE» feature_names[] = {
			"<nothing>",
			«FOR feature : flow.scopes.map[it | it.declarations].flatten.reject(TimeEvent) SEPARATOR ","»
			"«feature.name»"
			«ENDFOR»
		};
		
		«CGeneratorConstants::STRING_TYPE» state_names[] = {
			"<nostate>",
			«FOR state : flow.states SEPARATOR ","»
			"«state.name.removePrefix»"
			«ENDFOR»
		};
		'''
	}
	
	def protected removePrefix(String s){
		return s.substring(s.indexOf(".")+1)
	}
}