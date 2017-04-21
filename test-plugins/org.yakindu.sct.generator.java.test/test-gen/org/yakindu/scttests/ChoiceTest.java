/**
* Copyright (c) 2017 committers of YAKINDU and others.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*     committers of YAKINDU - initial API and implementation
*/

package org.yakindu.scttests;

import org.junit.*;
import static org.junit.Assert.*;
import org.yakindu.scr.choice.ChoiceStatemachine;
import org.yakindu.scr.choice.ChoiceStatemachine.State;

/**
 * Unit TestCase for Choice
 */
@SuppressWarnings("all")
public class ChoiceTest {
	private ChoiceStatemachine statemachine;	
	
	@Before
	public void setUp() {
		statemachine = new ChoiceStatemachine();
		statemachine.init();
	}

	@After
	public void tearDown() {
		statemachine = null;
	}
	
	@Test
	public void testElseChoiceUsingNonDefaultTransition() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_A));
		 
		statemachine.setC(true);
		statemachine.raiseE();
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_C));
		 
	}
	@Test
	public void testElseChoiceUsingDefaultTransition() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_A));
		 
		statemachine.setC(false);
		statemachine.raiseE();
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_B));
		 
	}
	@Test
	public void testDefaultChoiceUsingNonDefaultTransition() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_A));
		 
		statemachine.setC(true);
		statemachine.raiseG();
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_C));
		 
	}
	@Test
	public void testDefaultChoiceUsingDefaultTransition() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_A));
		 
		statemachine.setC(false);
		statemachine.raiseG();
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_B));
		 
	}
	@Test
	public void testUncheckedChoiceUsingNonDefaultTransition() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_A));
		 
		statemachine.setC(true);
		statemachine.raiseF();
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_C));
		 
	}
	@Test
	public void testUncheckedChoiceUsingDefaultTransition() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_A));
		 
		statemachine.setC(false);
		statemachine.raiseF();
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_B));
		 
	}
	@Test
	public void testAlwaysTrueTransitionInChoice() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_A));
		 
		statemachine.setC(true);
		statemachine.raiseH();
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_C));
		 
	}
}