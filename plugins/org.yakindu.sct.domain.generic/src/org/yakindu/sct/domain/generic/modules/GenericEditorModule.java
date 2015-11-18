/**
 * Copyright (c) 2015 committers of YAKINDU and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 * Contributors:
 * 	committers of YAKINDU - initial API and implementation
 * 
 */
package org.yakindu.sct.domain.generic.modules;

import org.eclipse.xtext.service.AbstractGenericModule;
import org.yakindu.sct.domain.generic.assist.SCTSmartEditProposalProvider;
import org.yakindu.sct.ui.editor.proposals.IEditProposalProvider;

import com.google.inject.Binder;
import com.google.inject.multibindings.Multibinder;

/**
 * 
 * @author terfloth
 *
 */
public class GenericEditorModule extends AbstractGenericModule {

	public void configure(Binder binder) {
		super.configure(binder);
		
		Multibinder<IEditProposalProvider> proposalProviderBinder = Multibinder.newSetBinder(binder, IEditProposalProvider.class);
	    proposalProviderBinder.addBinding().to(SCTSmartEditProposalProvider.class);
	}

	
}
