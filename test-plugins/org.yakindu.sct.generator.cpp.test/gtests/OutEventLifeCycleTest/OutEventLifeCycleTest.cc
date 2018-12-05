#include <string>
#include "gtest/gtest.h"
#include "OutEventLifeCycle.h"
#include "sc_runner.h"
#include "sc_types.h"

namespace  {

void init(sc_boolean sndCycle);
OutEventLifeCycle* statechart;



//! The timers are managed by a timer service. */
static SctUnitRunner * runner;

class OutEventLifeCycleTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new OutEventLifeCycle();
		statechart->init();
		runner = new SctUnitRunner(
			statechart,
			false,
			200
		);
	}
	virtual void TearDown() {
		delete statechart;
		delete runner;
	}
};

void init(sc_boolean sndCycle){
	statechart->enter();
	
	statechart->getDefaultSCI()->raise_e();
	
	runner->proceed_cycles(1);
	
	if (sndCycle) {
		runner->proceed_cycles(1);
	}
	
	
}

TEST_F(OutEventLifeCycleTest, availableAfterCycle) {
	
	statechart->enter();
	
	statechart->getDefaultSCI()->raise_e();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->isRaised_f());
	
	
}
TEST_F(OutEventLifeCycleTest, availableWithinCycle) {
	
	init(false);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_f_available_in_cycle());
	
	
}
TEST_F(OutEventLifeCycleTest, unvailableWithin2ndCycle) {
	
	init(true);
	
	EXPECT_TRUE(!statechart->getDefaultSCI()->get_f_available_in_next_cycle());
	
	
}
TEST_F(OutEventLifeCycleTest, unvailableAfter2ndCycle) {
	
	init(true);
	
	EXPECT_TRUE(!statechart->getDefaultSCI()->isRaised_f());
	
	
}

}

