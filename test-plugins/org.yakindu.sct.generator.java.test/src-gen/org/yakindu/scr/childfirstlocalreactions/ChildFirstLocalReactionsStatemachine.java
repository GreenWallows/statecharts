package org.yakindu.scr.childfirstlocalreactions;


public class ChildFirstLocalReactionsStatemachine implements IChildFirstLocalReactionsStatemachine {
	protected class SCInterfaceImpl implements SCInterface {
	
		private boolean e;
		
		public void raiseE() {
			e = true;
		}
		
		private long cnt;
		
		public long getCnt() {
			return cnt;
		}
		
		public void setCnt(long value) {
			this.cnt = value;
		}
		
		protected long assignCnt(long value) {
			return this.cnt = value;
		}
		
		private boolean disable_a;
		
		public boolean getDisable_a() {
			return disable_a;
		}
		
		public void setDisable_a(boolean value) {
			this.disable_a = value;
		}
		
		private boolean disable_aa;
		
		public boolean getDisable_aa() {
			return disable_aa;
		}
		
		public void setDisable_aa(boolean value) {
			this.disable_aa = value;
		}
		
		private boolean disable_aaa;
		
		public boolean getDisable_aaa() {
			return disable_aaa;
		}
		
		public void setDisable_aaa(boolean value) {
			this.disable_aaa = value;
		}
		
		private long a_local;
		
		public long getA_local() {
			return a_local;
		}
		
		public void setA_local(long value) {
			this.a_local = value;
		}
		
		private long aa_local;
		
		public long getAa_local() {
			return aa_local;
		}
		
		public void setAa_local(long value) {
			this.aa_local = value;
		}
		
		private long aaa_local;
		
		public long getAaa_local() {
			return aaa_local;
		}
		
		public void setAaa_local(long value) {
			this.aaa_local = value;
		}
		
		private long sm_local;
		
		public long getSm_local() {
			return sm_local;
		}
		
		public void setSm_local(long value) {
			this.sm_local = value;
		}
		
		protected void clearEvents() {
			e = false;
		}
	}
	
	protected SCInterfaceImpl sCInterface;
	
	private boolean initialized = false;
	
	public enum State {
		childFirstLocalReactions_r_A,
		childFirstLocalReactions_r_A_r_AA,
		childFirstLocalReactions_r_A_r_AA_r_AAA,
		childFirstLocalReactions_r_A_r_AA_r_AAB,
		childFirstLocalReactions_r_A_r_AB,
		childFirstLocalReactions_r_B,
		$NullState$
	};
	
	private final State[] stateVector = new State[1];
	
	private int nextStateIndex;
	
	public ChildFirstLocalReactionsStatemachine() {
		sCInterface = new SCInterfaceImpl();
	}
	
	public void init() {
		this.initialized = true;
		for (int i = 0; i < 1; i++) {
			stateVector[i] = State.$NullState$;
		}
		clearEvents();
		clearOutEvents();
		sCInterface.setCnt(0);
		
		sCInterface.setDisable_a(false);
		
		sCInterface.setDisable_aa(false);
		
		sCInterface.setDisable_aaa(false);
		
		sCInterface.setA_local(0);
		
		sCInterface.setAa_local(0);
		
		sCInterface.setAaa_local(0);
		
		sCInterface.setSm_local(0);
	}
	
	public void enter() {
		if (!initialized) {
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");
		}
		enterSequence_ChildFirstLocalReactions_r_default();
	}
	
	public void exit() {
		exitSequence_ChildFirstLocalReactions_r();
	}
	
	/**
	 * @see IStatemachine#isActive()
	 */
	public boolean isActive() {
		return stateVector[0] != State.$NullState$;
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
	}
	
	/**
	* This method resets the outgoing events.
	*/
	protected void clearOutEvents() {
	}
	
	/**
	* Returns true if the given state is currently active otherwise false.
	*/
	public boolean isStateActive(State state) {
	
		switch (state) {
		case childFirstLocalReactions_r_A:
			return stateVector[0].ordinal() >= State.
					childFirstLocalReactions_r_A.ordinal()&& stateVector[0].ordinal() <= State.childFirstLocalReactions_r_A_r_AB.ordinal();
		case childFirstLocalReactions_r_A_r_AA:
			return stateVector[0].ordinal() >= State.
					childFirstLocalReactions_r_A_r_AA.ordinal()&& stateVector[0].ordinal() <= State.childFirstLocalReactions_r_A_r_AA_r_AAB.ordinal();
		case childFirstLocalReactions_r_A_r_AA_r_AAA:
			return stateVector[0] == State.childFirstLocalReactions_r_A_r_AA_r_AAA;
		case childFirstLocalReactions_r_A_r_AA_r_AAB:
			return stateVector[0] == State.childFirstLocalReactions_r_A_r_AA_r_AAB;
		case childFirstLocalReactions_r_A_r_AB:
			return stateVector[0] == State.childFirstLocalReactions_r_A_r_AB;
		case childFirstLocalReactions_r_B:
			return stateVector[0] == State.childFirstLocalReactions_r_B;
		default:
			return false;
		}
	}
	
	public SCInterface getSCInterface() {
		return sCInterface;
	}
	
	public void raiseE() {
		sCInterface.raiseE();
	}
	
	public long getCnt() {
		return sCInterface.getCnt();
	}
	
	public void setCnt(long value) {
		sCInterface.setCnt(value);
	}
	
	public boolean getDisable_a() {
		return sCInterface.getDisable_a();
	}
	
	public void setDisable_a(boolean value) {
		sCInterface.setDisable_a(value);
	}
	
	public boolean getDisable_aa() {
		return sCInterface.getDisable_aa();
	}
	
	public void setDisable_aa(boolean value) {
		sCInterface.setDisable_aa(value);
	}
	
	public boolean getDisable_aaa() {
		return sCInterface.getDisable_aaa();
	}
	
	public void setDisable_aaa(boolean value) {
		sCInterface.setDisable_aaa(value);
	}
	
	public long getA_local() {
		return sCInterface.getA_local();
	}
	
	public void setA_local(long value) {
		sCInterface.setA_local(value);
	}
	
	public long getAa_local() {
		return sCInterface.getAa_local();
	}
	
	public void setAa_local(long value) {
		sCInterface.setAa_local(value);
	}
	
	public long getAaa_local() {
		return sCInterface.getAaa_local();
	}
	
	public void setAaa_local(long value) {
		sCInterface.setAaa_local(value);
	}
	
	public long getSm_local() {
		return sCInterface.getSm_local();
	}
	
	public void setSm_local(long value) {
		sCInterface.setSm_local(value);
	}
	
	/* Entry action for state 'A'. */
	private void entryAction_ChildFirstLocalReactions_r_A() {
		sCInterface.setDisable_a(false);
		
		sCInterface.setDisable_aa(false);
		
		sCInterface.setDisable_aaa(false);
	}
	
	/* 'default' enter sequence for state A */
	private void enterSequence_ChildFirstLocalReactions_r_A_default() {
		entryAction_ChildFirstLocalReactions_r_A();
		enterSequence_ChildFirstLocalReactions_r_A_r_default();
	}
	
	/* 'default' enter sequence for state AA */
	private void enterSequence_ChildFirstLocalReactions_r_A_r_AA_default() {
		enterSequence_ChildFirstLocalReactions_r_A_r_AA_r_default();
	}
	
	/* 'default' enter sequence for state AAA */
	private void enterSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAA_default() {
		nextStateIndex = 0;
		stateVector[0] = State.childFirstLocalReactions_r_A_r_AA_r_AAA;
	}
	
	/* 'default' enter sequence for state AAB */
	private void enterSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAB_default() {
		nextStateIndex = 0;
		stateVector[0] = State.childFirstLocalReactions_r_A_r_AA_r_AAB;
	}
	
	/* 'default' enter sequence for state AB */
	private void enterSequence_ChildFirstLocalReactions_r_A_r_AB_default() {
		nextStateIndex = 0;
		stateVector[0] = State.childFirstLocalReactions_r_A_r_AB;
	}
	
	/* 'default' enter sequence for state B */
	private void enterSequence_ChildFirstLocalReactions_r_B_default() {
		nextStateIndex = 0;
		stateVector[0] = State.childFirstLocalReactions_r_B;
	}
	
	/* 'default' enter sequence for region r */
	private void enterSequence_ChildFirstLocalReactions_r_default() {
		react_ChildFirstLocalReactions_r__entry_Default();
	}
	
	/* 'default' enter sequence for region r */
	private void enterSequence_ChildFirstLocalReactions_r_A_r_default() {
		react_ChildFirstLocalReactions_r_A_r__entry_Default();
	}
	
	/* 'default' enter sequence for region r */
	private void enterSequence_ChildFirstLocalReactions_r_A_r_AA_r_default() {
		react_ChildFirstLocalReactions_r_A_r_AA_r__entry_Default();
	}
	
	/* Default exit sequence for state A */
	private void exitSequence_ChildFirstLocalReactions_r_A() {
		exitSequence_ChildFirstLocalReactions_r_A_r();
	}
	
	/* Default exit sequence for state AA */
	private void exitSequence_ChildFirstLocalReactions_r_A_r_AA() {
		exitSequence_ChildFirstLocalReactions_r_A_r_AA_r();
	}
	
	/* Default exit sequence for state AAA */
	private void exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAA() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state AAB */
	private void exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAB() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state AB */
	private void exitSequence_ChildFirstLocalReactions_r_A_r_AB() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state B */
	private void exitSequence_ChildFirstLocalReactions_r_B() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for region r */
	private void exitSequence_ChildFirstLocalReactions_r() {
		switch (stateVector[0]) {
		case childFirstLocalReactions_r_A_r_AA_r_AAA:
			exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAA();
			break;
		case childFirstLocalReactions_r_A_r_AA_r_AAB:
			exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAB();
			break;
		case childFirstLocalReactions_r_A_r_AB:
			exitSequence_ChildFirstLocalReactions_r_A_r_AB();
			break;
		case childFirstLocalReactions_r_B:
			exitSequence_ChildFirstLocalReactions_r_B();
			break;
		default:
			break;
		}
	}
	
	/* Default exit sequence for region r */
	private void exitSequence_ChildFirstLocalReactions_r_A_r() {
		switch (stateVector[0]) {
		case childFirstLocalReactions_r_A_r_AA_r_AAA:
			exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAA();
			break;
		case childFirstLocalReactions_r_A_r_AA_r_AAB:
			exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAB();
			break;
		case childFirstLocalReactions_r_A_r_AB:
			exitSequence_ChildFirstLocalReactions_r_A_r_AB();
			break;
		default:
			break;
		}
	}
	
	/* Default exit sequence for region r */
	private void exitSequence_ChildFirstLocalReactions_r_A_r_AA_r() {
		switch (stateVector[0]) {
		case childFirstLocalReactions_r_A_r_AA_r_AAA:
			exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAA();
			break;
		case childFirstLocalReactions_r_A_r_AA_r_AAB:
			exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAB();
			break;
		default:
			break;
		}
	}
	
	/* Default react sequence for initial entry  */
	private void react_ChildFirstLocalReactions_r__entry_Default() {
		enterSequence_ChildFirstLocalReactions_r_A_default();
	}
	
	/* Default react sequence for initial entry  */
	private void react_ChildFirstLocalReactions_r_A_r__entry_Default() {
		enterSequence_ChildFirstLocalReactions_r_A_r_AA_default();
	}
	
	/* Default react sequence for initial entry  */
	private void react_ChildFirstLocalReactions_r_A_r_AA_r__entry_Default() {
		enterSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAA_default();
	}
	
	private boolean react(boolean try_transition) {
		sCInterface.setSm_local((sCInterface.assignCnt(sCInterface.getCnt() + 1)));
		
		return false;
	}
	
	private boolean childFirstLocalReactions_r_A_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if ((sCInterface.e) && (!sCInterface.getDisable_a())) {
				exitSequence_ChildFirstLocalReactions_r_A();
				enterSequence_ChildFirstLocalReactions_r_B_default();
				react(false);
			} else {
				did_transition = false;
			}
		}
		if (did_transition==false) {
			sCInterface.setA_local((sCInterface.assignCnt(sCInterface.getCnt() + 1)));
			
			did_transition = react(try_transition);
		}
		return did_transition;
	}
	
	private boolean childFirstLocalReactions_r_A_r_AA_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if ((sCInterface.e) && (!sCInterface.getDisable_aa())) {
				exitSequence_ChildFirstLocalReactions_r_A_r_AA();
				enterSequence_ChildFirstLocalReactions_r_A_r_AB_default();
				childFirstLocalReactions_r_A_react(false);
			} else {
				did_transition = false;
			}
		}
		if (did_transition==false) {
			sCInterface.setAa_local((sCInterface.assignCnt(sCInterface.getCnt() + 1)));
			
			did_transition = childFirstLocalReactions_r_A_react(try_transition);
		}
		return did_transition;
	}
	
	private boolean childFirstLocalReactions_r_A_r_AA_r_AAA_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			if ((sCInterface.e) && (!sCInterface.getDisable_aaa())) {
				exitSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAA();
				enterSequence_ChildFirstLocalReactions_r_A_r_AA_r_AAB_default();
				childFirstLocalReactions_r_A_r_AA_react(false);
			} else {
				did_transition = false;
			}
		}
		if (did_transition==false) {
			sCInterface.setAaa_local((sCInterface.assignCnt(sCInterface.getCnt() + 1)));
			
			did_transition = childFirstLocalReactions_r_A_r_AA_react(try_transition);
		}
		return did_transition;
	}
	
	private boolean childFirstLocalReactions_r_A_r_AA_r_AAB_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			did_transition = false;
		}
		if (did_transition==false) {
			did_transition = childFirstLocalReactions_r_A_r_AA_react(try_transition);
		}
		return did_transition;
	}
	
	private boolean childFirstLocalReactions_r_A_r_AB_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			did_transition = false;
		}
		if (did_transition==false) {
			did_transition = childFirstLocalReactions_r_A_react(try_transition);
		}
		return did_transition;
	}
	
	private boolean childFirstLocalReactions_r_B_react(boolean try_transition) {
		boolean did_transition = try_transition;
		
		if (try_transition) {
			did_transition = false;
		}
		if (did_transition==false) {
			did_transition = react(try_transition);
		}
		return did_transition;
	}
	
	public void runCycle() {
		if (!initialized)
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");
		clearOutEvents();
		for (nextStateIndex = 0; nextStateIndex < stateVector.length; nextStateIndex++) {
			switch (stateVector[nextStateIndex]) {
			case childFirstLocalReactions_r_A_r_AA_r_AAA:
				childFirstLocalReactions_r_A_r_AA_r_AAA_react(true);
				break;
			case childFirstLocalReactions_r_A_r_AA_r_AAB:
				childFirstLocalReactions_r_A_r_AA_r_AAB_react(true);
				break;
			case childFirstLocalReactions_r_A_r_AB:
				childFirstLocalReactions_r_A_r_AB_react(true);
				break;
			case childFirstLocalReactions_r_B:
				childFirstLocalReactions_r_B_react(true);
				break;
			default:
				// $NullState$
			}
		}
		clearEvents();
	}
}
