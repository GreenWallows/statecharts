#include <string>
#include "gtest/gtest.h"
#include "TriggerGuardExpressions.h"
#include "sc_runner.h"
#include "sc_types.h"

namespace  {

TriggerGuardExpressions* statechart;



//! The timers are managed by a timer service. */
static SctUnitRunner * runner;

class TriggerGuardExpressionsTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new TriggerGuardExpressions();
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


TEST_F(TriggerGuardExpressionsTest, trueGuard) {
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_A));
	
	statechart->getDefaultSCI()->raise_e1();
	
	statechart->getDefaultSCI()->set_b(true);
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_B));
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_A));
	
	statechart->getDefaultSCI()->raise_e2();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_B));
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_A));
	
	statechart->getDefaultSCI()->raise_e1();
	
	statechart->getDefaultSCI()->raise_e2();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_B));
	
	
}
TEST_F(TriggerGuardExpressionsTest, falseGuard) {
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_A));
	
	statechart->getDefaultSCI()->set_b(false);
	
	statechart->getDefaultSCI()->raise_e1();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_A));
	
	statechart->getDefaultSCI()->raise_e2();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_A));
	
	statechart->getDefaultSCI()->raise_e1();
	
	statechart->getDefaultSCI()->raise_e2();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TriggerGuardExpressions::main_region_A));
	
	
}

}

