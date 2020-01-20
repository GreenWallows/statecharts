/** Generated by YAKINDU Statechart Tools code generator. */
package org.yakindu.scr.eventdriveninternalevent;

import java.util.LinkedList;
import java.util.Queue;

public class EventDrivenInternalEventStatemachine implements IEventDrivenInternalEventStatemachine {
	protected class SCInterfaceImpl implements SCInterface {
	
		private boolean start;
		
		
		public void raiseStart() {
			start = true;
			runCycle();
		}
		
		private boolean reset;
		
		
		public void raiseReset() {
			reset = true;
			runCycle();
		}
		
		private boolean e;
		
		private long eValue;
		
		
		public boolean isRaisedE() {
			return e;
		}
		
		protected void raiseE(long value) {
			eValue = value;
			e = true;
		}
		
		public long getEValue() {
			if (! e ) 
				throw new IllegalStateException("Illegal event value access. Event E is not raised!");
			return eValue;
		}
		
		private long x;
		
		public long getX() {
			return x;
		}
		
		public void setX(long value) {
			this.x = value;
		}
		
		private long i1_sequence;
		
		public long getI1_sequence() {
			return i1_sequence;
		}
		
		public void setI1_sequence(long value) {
			this.i1_sequence = value;
		}
		
		private long i2_sequence;
		
		public long getI2_sequence() {
			return i2_sequence;
		}
		
		public void setI2_sequence(long value) {
			this.i2_sequence = value;
		}
		
		protected void clearEvents() {
			start = false;
			reset = false;
		}
		protected void clearOutEvents() {
		
		e = false;
		}
		
	}
	
	
	protected SCInterfaceImpl sCInterface;
	
	private boolean initialized = false;
	
	public enum State {
		eventDrivenInternalEvent_r1_A,
		eventDrivenInternalEvent_r1_B,
		eventDrivenInternalEvent_r2_C,
		eventDrivenInternalEvent_r2_D,
		eventDrivenInternalEvent_check_VALID,
		eventDrivenInternalEvent_check_MULTIPLEEVENTS,
		$NullState$
	};
	
	private final State[] stateVector = new State[3];
	
	private int nextStateIndex;
	
	private Queue<Runnable> internalEventQueue = new LinkedList<Runnable>();
	private boolean i1;
	private boolean i2;
	public EventDrivenInternalEventStatemachine() {
		sCInterface = new SCInterfaceImpl();
	}
	
	public void init() {
		this.initialized = true;
		for (int i = 0; i < 3; i++) {
			stateVector[i] = State.$NullState$;
		}
		clearEvents();
		clearOutEvents();
		sCInterface.setX(0);
		
		sCInterface.setI1_sequence(0);
		
		sCInterface.setI2_sequence(0);
	}
	
	public void enter() {
		if (!initialized) {
			throw new IllegalStateException(
				"The state machine needs to be initialized first by calling the init() function."
			);
		}
		enterSequence_EventDrivenInternalEvent_r1_default();
		enterSequence_EventDrivenInternalEvent_r2_default();
		enterSequence_EventDrivenInternalEvent_check_default();
	}
	
	public void runCycle() {
		if (!initialized)
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");
		
		clearOutEvents();
	
		Runnable task = getNextEvent();
		if (task == null) {
			task = getDefaultEvent();
		}
		
		while (task != null) {
			task.run();
			clearEvents();
			task = getNextEvent();
		}
		
	}
	
	protected void singleCycle() {
		for (nextStateIndex = 0; nextStateIndex < stateVector.length; nextStateIndex++) {
			switch (stateVector[nextStateIndex]) {
			case eventDrivenInternalEvent_r1_A:
				eventDrivenInternalEvent_r1_A_react(true);
				break;
			case eventDrivenInternalEvent_r1_B:
				eventDrivenInternalEvent_r1_B_react(true);
				break;
			case eventDrivenInternalEvent_r2_C:
				eventDrivenInternalEvent_r2_C_react(true);
				break;
			case eventDrivenInternalEvent_r2_D:
				eventDrivenInternalEvent_r2_D_react(true);
				break;
			case eventDrivenInternalEvent_check_VALID:
				eventDrivenInternalEvent_check_VALID_react(true);
				break;
			case eventDrivenInternalEvent_check_MULTIPLEEVENTS:
				eventDrivenInternalEvent_check_MULTIPLEEVENTS_react(true);
				break;
			default:
				// $NullState$
			}
		}
	}
	
	protected Runnable getNextEvent() {
		if(!internalEventQueue.isEmpty()) {
			return internalEventQueue.poll();
		}
		return null;
	}
	
	protected Runnable getDefaultEvent() {
		return new Runnable() {
			@Override
			public void run() {
				singleCycle();
			}
		};
	}
	
	public void exit() {
		exitSequence_EventDrivenInternalEvent_r1();
		exitSequence_EventDrivenInternalEvent_r2();
		exitSequence_EventDrivenInternalEvent_check();
	}
	
	/**
	 * @see IStatemachine#isActive()
	 */
	public boolean isActive() {
		return stateVector[0] != State.$NullState$||stateVector[1] != State.$NullState$||stateVector[2] != State.$NullState$;
	}
	
	/** 
	* Always returns 'false' since this state machine can never become final.
	*
	* @see IStatemachine#isFinal()
	*/
	public boolean isFinal() {
		return false;
	}
	/**
	* This method resets the incoming events (time events included).
	*/
	protected void clearEvents() {
		sCInterface.clearEvents();
		i1 = false;
		i2 = false;
	}
	
	/**
	* This method resets the outgoing events.
	*/
	protected void clearOutEvents() {
		sCInterface.clearOutEvents();
	}
	
	/**
	* Returns true if the given state is currently active otherwise false.
	*/
	public boolean isStateActive(State state) {
	
		switch (state) {
		case eventDrivenInternalEvent_r1_A:
			return stateVector[0] == State.eventDrivenInternalEvent_r1_A;
		case eventDrivenInternalEvent_r1_B:
			return stateVector[0] == State.eventDrivenInternalEvent_r1_B;
		case eventDrivenInternalEvent_r2_C:
			return stateVector[1] == State.eventDrivenInternalEvent_r2_C;
		case eventDrivenInternalEvent_r2_D:
			return stateVector[1] == State.eventDrivenInternalEvent_r2_D;
		case eventDrivenInternalEvent_check_VALID:
			return stateVector[2] == State.eventDrivenInternalEvent_check_VALID;
		case eventDrivenInternalEvent_check_MULTIPLEEVENTS:
			return stateVector[2] == State.eventDrivenInternalEvent_check_MULTIPLEEVENTS;
		default:
			return false;
		}
	}
	
	public SCInterface getSCInterface() {
		return sCInterface;
	}
	
	private void raiseI1() {
	
		internalEventQueue.add( new Runnable() {
			@Override public void run() {
				i1 = true;					
				singleCycle();
			}
		});
	}
	
	private void raiseI2() {
	
		internalEventQueue.add( new Runnable() {
			@Override public void run() {
				i2 = true;					
				singleCycle();
			}
		});
	}
	
	public void raiseStart() {
		sCInterface.raiseStart();
	}
	
	public void raiseReset() {
		sCInterface.raiseReset();
	}
	
	public boolean isRaisedE() {
		return sCInterface.isRaisedE();
	}
	
	public long getEValue() {
		return sCInterface.getEValue();
	}
	
	public long getX() {
		return sCInterface.getX();
	}
	
	public void setX(long value) {
		sCInterface.setX(value);
	}
	
	public long getI1_sequence() {
		return sCInterface.getI1_sequence();
	}
	
	public void setI1_sequence(long value) {
		sCInterface.setI1_sequence(value);
	}
	
	public long getI2_sequence() {
		return sCInterface.getI2_sequence();
	}
	
	public void setI2_sequence(long value) {
		sCInterface.setI2_sequence(value);
	}
	
	/* 'default' enter sequence for state A */
	private void enterSequence_EventDrivenInternalEvent_r1_A_default() {
		nextStateIndex = 0;
		stateVector[0] = State.eventDrivenInternalEvent_r1_A;
	}
	
	/* 'default' enter sequence for state B */
	private void enterSequence_EventDrivenInternalEvent_r1_B_default() {
		nextStateIndex = 0;
		stateVector[0] = State.eventDrivenInternalEvent_r1_B;
	}
	
	/* 'default' enter sequence for state C */
	private void enterSequence_EventDrivenInternalEvent_r2_C_default() {
		nextStateIndex = 1;
		stateVector[1] = State.eventDrivenInternalEvent_r2_C;
	}
	
	/* 'default' enter sequence for state D */
	private void enterSequence_EventDrivenInternalEvent_r2_D_default() {
		nextStateIndex = 1;
		stateVector[1] = State.eventDrivenInternalEvent_r2_D;
	}
	
	/* 'default' enter sequence for state VALID */
	private void enterSequence_EventDrivenInternalEvent_check_VALID_default() {
		nextStateIndex = 2;
		stateVector[2] = State.eventDrivenInternalEvent_check_VALID;
	}
	
	/* 'default' enter sequence for state MULTIPLEEVENTS */
	private void enterSequence_EventDrivenInternalEvent_check_MULTIPLEEVENTS_default() {
		nextStateIndex = 2;
		stateVector[2] = State.eventDrivenInternalEvent_check_MULTIPLEEVENTS;
	}
	
	/* 'default' enter sequence for region r1 */
	private void enterSequence_EventDrivenInternalEvent_r1_default() {
		react_EventDrivenInternalEvent_r1__entry_Default();
	}
	
	/* 'default' enter sequence for region r2 */
	private void enterSequence_EventDrivenInternalEvent_r2_default() {
		react_EventDrivenInternalEvent_r2__entry_Default();
	}
	
	/* 'default' enter sequence for region check */
	private void enterSequence_EventDrivenInternalEvent_check_default() {
		react_EventDrivenInternalEvent_check__entry_Default();
	}
	
	/* Default exit sequence for state A */
	private void exitSequence_EventDrivenInternalEvent_r1_A() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state B */
	private void exitSequence_EventDrivenInternalEvent_r1_B() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state C */
	private void exitSequence_EventDrivenInternalEvent_r2_C() {
		nextStateIndex = 1;
		stateVector[1] = State.$NullState$;
	}
	
	/* Default exit sequence for state D */
	private void exitSequence_EventDrivenInternalEvent_r2_D() {
		nextStateIndex = 1;
		stateVector[1] = State.$NullState$;
	}
	
	/* Default exit sequence for state VALID */
	private void exitSequence_EventDrivenInternalEvent_check_VALID() {
		nextStateIndex = 2;
		stateVector[2] = State.$NullState$;
	}
	
	/* Default exit sequence for state MULTIPLEEVENTS */
	private void exitSequence_EventDrivenInternalEvent_check_MULTIPLEEVENTS() {
		nextStateIndex = 2;
		stateVector[2] = State.$NullState$;
	}
	
	/* Default exit sequence for region r1 */
	private void exitSequence_EventDrivenInternalEvent_r1() {
		switch (stateVector[0]) {
		case eventDrivenInternalEvent_r1_A:
			exitSequence_EventDrivenInternalEvent_r1_A();
			break;
		case eventDrivenInternalEvent_r1_B:
			exitSequence_EventDrivenInternalEvent_r1_B();
			break;
		default:
			break;
		}
	}
	
	/* Default exit sequence for region r2 */
	private void exitSequence_EventDrivenInternalEvent_r2() {
		switch (stateVector[1]) {
		case eventDrivenInternalEvent_r2_C:
			exitSequence_EventDrivenInternalEvent_r2_C();
			break;
		case eventDrivenInternalEvent_r2_D:
			exitSequence_EventDrivenInternalEvent_r2_D();
			break;
		default:
			break;
		}
	}
	
	/* Default exit sequence for region check */
	private void exitSequence_EventDrivenInternalEvent_check() {
		switch (stateVector[2]) {
		case eventDrivenInternalEvent_check_VALID:
			exitSequence_EventDrivenInternalEvent_check_VALID();
			break;
		case eventDrivenInternalEvent_check_MULTIPLEEVENTS:
			exitSequence_EventDrivenInternalEvent_check_MULTIPLEEVENTS();
			break;
		default:
			break;
		}
	}
	
	/* Default react sequence for initial entry  */
	private void react_EventDrivenInternalEvent_r1__entry_Default() {
		enterSequence_EventDrivenInternalEvent_r1_A_default();
	}
	
	/* Default react sequence for initial entry  */
	private void react_EventDrivenInternalEvent_r2__entry_Default() {
		enterSequence_EventDrivenInternalEvent_r2_C_default();
	}
	
	/* Default react sequence for initial entry  */
	private void react_EventDrivenInternalEvent_check__entry_Default() {
		enterSequence_EventDrivenInternalEvent_check_VALID_default();
	}
	
	private boolean react() {
		sCInterface.setX(sCInterface.getX() + 1);
		
		return false;
	}
	
	private boolean eventDrivenInternalEvent_r1_A_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (react()==false) {
				if (i2) {
					exitSequence_EventDrivenInternalEvent_r1_A();
					sCInterface.setI2_sequence(sCInterface.x);
					
					enterSequence_EventDrivenInternalEvent_r1_B_default();
				} else {
					did_transition = false;
				}
			}
		}
		if (did_transition==false) {
			if (sCInterface.start) {
				raiseI1();
			}
		}
		return did_transition;
	}
	
	private boolean eventDrivenInternalEvent_r1_B_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (react()==false) {
				if (sCInterface.reset) {
					exitSequence_EventDrivenInternalEvent_r1_B();
					enterSequence_EventDrivenInternalEvent_r1_A_default();
				} else {
					did_transition = false;
				}
			}
		}
		if (did_transition==false) {
			if (((i2) && (sCInterface.getI2_sequence()<10))) {
				sCInterface.setI2_sequence(sCInterface.getI2_sequence() + 1);
			}
		}
		return did_transition;
	}
	
	private boolean eventDrivenInternalEvent_r2_C_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (i1) {
				exitSequence_EventDrivenInternalEvent_r2_C();
				sCInterface.setI1_sequence(sCInterface.x);
				
				raiseI2();
				
				enterSequence_EventDrivenInternalEvent_r2_D_default();
			} else {
				did_transition = false;
			}
		}
		return did_transition;
	}
	
	private boolean eventDrivenInternalEvent_r2_D_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (sCInterface.reset) {
				exitSequence_EventDrivenInternalEvent_r2_D();
				enterSequence_EventDrivenInternalEvent_r2_C_default();
			} else {
				did_transition = false;
			}
		}
		if (did_transition==false) {
			if (((i1) && (sCInterface.getI1_sequence()<10))) {
				sCInterface.setI1_sequence(sCInterface.getI1_sequence() + 1);
			}
		}
		return did_transition;
	}
	
	private boolean eventDrivenInternalEvent_check_VALID_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (((((sCInterface.start && i1)) || ((sCInterface.start && i2))) || ((i1 && i2)))) {
				exitSequence_EventDrivenInternalEvent_check_VALID();
				enterSequence_EventDrivenInternalEvent_check_MULTIPLEEVENTS_default();
			} else {
				did_transition = false;
			}
		}
		return did_transition;
	}
	
	private boolean eventDrivenInternalEvent_check_MULTIPLEEVENTS_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if (sCInterface.reset) {
				exitSequence_EventDrivenInternalEvent_check_MULTIPLEEVENTS();
				enterSequence_EventDrivenInternalEvent_check_VALID_default();
			} else {
				did_transition = false;
			}
		}
		return did_transition;
	}
	
}
