/** Generated by YAKINDU Statechart Tools code generator. */

package org.yakindu.sct.generator.java.test;

import org.junit.*;
import static org.junit.Assert.*;
import org.yakindu.scr.statechartentryandexitactions.StatechartEntryAndExitActionsStatemachine;
import org.yakindu.scr.statechartentryandexitactions.StatechartEntryAndExitActionsStatemachine.State;	
import org.yakindu.scr.VirtualTimer;
import org.yakindu.scr.VirtualTimer.VirtualTimeTask;
import org.yakindu.scr.VirtualTimer.CycleTimeEventTask;

/**
 * Unit TestCase for StatechartEntryAndExitActions
 */
@SuppressWarnings("all")
public class StatechartEntryExitActions {
	
	private StatechartEntryAndExitActionsStatemachine statemachine;	
	private VirtualTimer timer;
	
	
	@Before
	public void statechartEntryExitActions_setUp() {
		statemachine = new StatechartEntryAndExitActionsStatemachine();
		timer = new VirtualTimer(200);
		timer.schedulePeriodicalTask(new CycleTimeEventTask(statemachine), 200, 200);
		
		statemachine.init();
		
	}

	@After
	public void statechartEntryExitActions_tearDown() {
		statemachine = null;
		
		timer = null;
	}
	
	@Test
	public void entryActionsAreExecutedOnEnteringStatechart() {
		assertTrue(statemachine.getX() == 0l);
		assertTrue(statemachine.getY() == 0l);
		statemachine.setB(true);
		statemachine.enter();
		assertTrue(statemachine.getX() == 5l);
		assertTrue(statemachine.getY() == 3l);
	}
	
	@Test
	public void entryActionGuardsAreEvaluatedOnEnteringStatechart() {
		assertTrue(statemachine.getX() == 0l);
		assertTrue(statemachine.getY() == 0l);
		statemachine.setB(false);
		statemachine.enter();
		assertTrue(statemachine.getX() == 2l);
		assertTrue(statemachine.getY() == 3l);
	}
	
	@Test
	public void exitActionsAreExecutedOnExitingStatechart() {
		statemachine.enter();
		statemachine.setB(true);
		statemachine.exit();
		assertTrue(statemachine.getX() == 6l);
		assertTrue(statemachine.getY() == 2l);
	}
	
	@Test
	public void exitActionGuardsAreEvaluatedOnExitingStatechart() {
		statemachine.enter();
		statemachine.setB(false);
		statemachine.exit();
		assertTrue(statemachine.getX() == 8l);
		assertTrue(statemachine.getY() == 2l);
	}
}
