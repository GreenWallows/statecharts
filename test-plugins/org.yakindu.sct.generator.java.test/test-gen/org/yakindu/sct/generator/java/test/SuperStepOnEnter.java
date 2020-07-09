/** Generated by YAKINDU Statechart Tools code generator. */

package org.yakindu.sct.generator.java.test;

import org.junit.*;
import static org.junit.Assert.*;
import org.yakindu.scr.supersteponenter.SuperStepOnEnterStatemachine;
import org.yakindu.scr.supersteponenter.SuperStepOnEnterStatemachine.State;	

/**
 * Unit TestCase for SuperStepOnEnter
 */
@SuppressWarnings("all")
public class SuperStepOnEnter {
	
	private SuperStepOnEnterStatemachine statemachine;	
	
	
	@Before
	public void superStepOnEnter_setUp() {
		statemachine = new SuperStepOnEnterStatemachine();
		
		statemachine.init();
		
	}

	@After
	public void superStepOnEnter_tearDown() {
		statemachine = null;
		
	}
	
	@Test
	public void test() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.superStepOnEnter_r1_StateB));
		assertTrue(statemachine.isStateActive(State.superStepOnEnter_r2_StateB));
		statemachine.exit();
	}
}
