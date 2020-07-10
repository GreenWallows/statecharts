/** Generated by YAKINDU Statechart Tools code generator. */
package org.yakindu.scr.supersteponenter;

import java.util.LinkedList;
import java.util.Queue;

public class SuperStepOnEnterStatemachine implements ISuperStepOnEnterStatemachine {
	private boolean initialized = false;
	
	public enum State {
		superStepOnEnter_r1_StateA,
		superStepOnEnter_r1_StateB,
		superStepOnEnter_r2_StateA,
		superStepOnEnter_r2_StateB,
		$NullState$
	};
	
	private final State[] stateVector = new State[2];
	
	private int nextStateIndex;
	
	private Queue<Runnable> internalEventQueue = new LinkedList<Runnable>();
	private boolean e;
	private boolean isExecuting;
	
	protected boolean getIsExecuting() {
		return isExecuting;
	}
	
	protected void setIsExecuting(boolean value) {
		this.isExecuting = value;
	}
	private boolean stateConfVectorChanged;
	
	protected boolean getStateConfVectorChanged() {
		return stateConfVectorChanged;
	}
	
	protected void setStateConfVectorChanged(boolean value) {
		this.stateConfVectorChanged = value;
	}
	public SuperStepOnEnterStatemachine() {
	}
	
	public void init() {
		this.initialized = true;
		for (int i = 0; i < 2; i++) {
			stateVector[i] = State.$NullState$;
		}
		
		clearInternalEvents();
		
		
		isExecuting = false;
	}
	
	public void enter() {
		if (!initialized)
			throw new IllegalStateException(
			        "The state machine needs to be initialized first by calling the init() function.");
		
		if (getIsExecuting()) {
			return;
		}
		isExecuting = true;
		enterSequence_r1_default();
		enterSequence_r2_default();
		do { 
			stateConfVectorChanged = false;
			microStep();
		} while (getStateConfVectorChanged());
		
		isExecuting = false;
	}
	
	public void exit() {
		if (getIsExecuting()) {
			return;
		}
		isExecuting = true;
		exitSequence_r1();
		exitSequence_r2();
		isExecuting = false;
	}
	
	public void runCycle() {
		if (!initialized)
			throw new IllegalStateException(
			        "The state machine needs to be initialized first by calling the init() function.");
		
		if (getIsExecuting()) {
			return;
		}
		isExecuting = true;
		nextEvent();
		do { 
			do { 
				stateConfVectorChanged = false;
				microStep();
			} while (getStateConfVectorChanged());
			
			clearInternalEvents();
			nextEvent();
		} while (e);
		
		isExecuting = false;
	}
	
	/**
	 * @see IStatemachine#isActive()
	 */
	public boolean isActive() {
		return stateVector[0] != State.$NullState$||stateVector[1] != State.$NullState$;
	}
	
	/** 
	* Always returns 'false' since this state machine can never become final.
	*
	* @see IStatemachine#isFinal()
	*/
	public boolean isFinal() {
		return false;
	}
	private void clearInternalEvents() {
		e = false;
	}
	
	private void microStep() {
		for (nextStateIndex = 0; nextStateIndex < stateVector.length; nextStateIndex++) {
			switch (stateVector[nextStateIndex]) {
			case superStepOnEnter_r1_StateA:
				r1_StateA_react(true);
				break;
			case superStepOnEnter_r1_StateB:
				r1_StateB_react(true);
				break;
			case superStepOnEnter_r2_StateA:
				r2_StateA_react(true);
				break;
			case superStepOnEnter_r2_StateB:
				r2_StateB_react(true);
				break;
			default:
				// $NullState$
			}
		}
	}
	
	protected void nextEvent() {
		if(!internalEventQueue.isEmpty()) {
			internalEventQueue.poll().run();
			return;
		}
	}
	/**
	* Returns true if the given state is currently active otherwise false.
	*/
	public boolean isStateActive(State state) {
	
		switch (state) {
		case superStepOnEnter_r1_StateA:
			return stateVector[0] == State.superStepOnEnter_r1_StateA;
		case superStepOnEnter_r1_StateB:
			return stateVector[0] == State.superStepOnEnter_r1_StateB;
		case superStepOnEnter_r2_StateA:
			return stateVector[1] == State.superStepOnEnter_r2_StateA;
		case superStepOnEnter_r2_StateB:
			return stateVector[1] == State.superStepOnEnter_r2_StateB;
		default:
			return false;
		}
	}
	
	private void raiseE() {
	
		internalEventQueue.add(new Runnable() {
			@Override public void run() {
				e = true;					
			}
		});
	}
	
	/* Entry action for state 'StateA'. */
	private void entryAction_r2_StateA() {
		raiseE();
	}
	
	/* 'default' enter sequence for state StateA */
	private void enterSequence_r1_StateA_default() {
		nextStateIndex = 0;
		stateVector[0] = State.superStepOnEnter_r1_StateA;
		stateConfVectorChanged = true;
	}
	
	/* 'default' enter sequence for state StateB */
	private void enterSequence_r1_StateB_default() {
		nextStateIndex = 0;
		stateVector[0] = State.superStepOnEnter_r1_StateB;
		stateConfVectorChanged = true;
	}
	
	/* 'default' enter sequence for state StateA */
	private void enterSequence_r2_StateA_default() {
		entryAction_r2_StateA();
		nextStateIndex = 1;
		stateVector[1] = State.superStepOnEnter_r2_StateA;
		stateConfVectorChanged = true;
	}
	
	/* 'default' enter sequence for state StateB */
	private void enterSequence_r2_StateB_default() {
		nextStateIndex = 1;
		stateVector[1] = State.superStepOnEnter_r2_StateB;
		stateConfVectorChanged = true;
	}
	
	/* 'default' enter sequence for region r1 */
	private void enterSequence_r1_default() {
		react_r1__entry_Default();
	}
	
	/* 'default' enter sequence for region r2 */
	private void enterSequence_r2_default() {
		react_r2__entry_Default();
	}
	
	/* Default exit sequence for state StateA */
	private void exitSequence_r1_StateA() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state StateB */
	private void exitSequence_r1_StateB() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state StateA */
	private void exitSequence_r2_StateA() {
		nextStateIndex = 1;
		stateVector[1] = State.$NullState$;
	}
	
	/* Default exit sequence for state StateB */
	private void exitSequence_r2_StateB() {
		nextStateIndex = 1;
		stateVector[1] = State.$NullState$;
	}
	
	/* Default exit sequence for region r1 */
	private void exitSequence_r1() {
		switch (stateVector[0]) {
		case superStepOnEnter_r1_StateA:
			exitSequence_r1_StateA();
			break;
		case superStepOnEnter_r1_StateB:
			exitSequence_r1_StateB();
			break;
		default:
			break;
		}
	}
	
	/* Default exit sequence for region r2 */
	private void exitSequence_r2() {
		switch (stateVector[1]) {
		case superStepOnEnter_r2_StateA:
			exitSequence_r2_StateA();
			break;
		case superStepOnEnter_r2_StateB:
			exitSequence_r2_StateB();
			break;
		default:
			break;
		}
	}
	
	/* Default react sequence for initial entry  */
	private void react_r1__entry_Default() {
		enterSequence_r1_StateA_default();
	}
	
	/* Default react sequence for initial entry  */
	private void react_r2__entry_Default() {
		enterSequence_r2_StateA_default();
	}
	
	private boolean react() {
		return false;
	}
	
	private boolean r1_StateA_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (react()==false) {
				exitSequence_r1_StateA();
				enterSequence_r1_StateB_default();
			}
		}
		return did_transition;
	}
	
	private boolean r1_StateB_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (react()==false) {
				did_transition = false;
			}
		}
		return did_transition;
	}
	
	private boolean r2_StateA_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (e) {
				exitSequence_r2_StateA();
				enterSequence_r2_StateB_default();
			} else {
				did_transition = false;
			}
		}
		return did_transition;
	}
	
	private boolean r2_StateB_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			did_transition = false;
		}
		return did_transition;
	}
	
}
