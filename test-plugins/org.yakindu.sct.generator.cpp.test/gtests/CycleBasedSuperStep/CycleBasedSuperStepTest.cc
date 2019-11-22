/** Generated by YAKINDU Statechart Tools code generator. */
#include <string>
#include "gtest/gtest.h"
#include "CycleBasedSuperStep.h"
#include "sc_runner.h"
#include "sc_types.h"

namespace  {

supersteps::CycleBasedSuperStep* statechart;



//! The timers are managed by a timer service. */
static SctUnitRunner * runner;

class CycleBasedSuperStepTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new supersteps::CycleBasedSuperStep();
		statechart->init();
		runner = new SctUnitRunner(
			statechart,
			false,
			100
		);
	}
	virtual void TearDown() {
		delete statechart;
		delete runner;
	}
};


TEST_F(CycleBasedSuperStepTest, superStepTakesTwoTransitionsUsingSameEvent) {
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->isStateActive(supersteps::CycleBasedSuperStep::CycleBasedSuperStep_main_region_A));
	
	statechart->getDefaultSCI()->raise_e();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(supersteps::CycleBasedSuperStep::CycleBasedSuperStep_main_region_C));
	
	statechart->exit();
	
	
}
TEST_F(CycleBasedSuperStepTest, superStepIteratesUsingAlwaysTrigger) {
	
	statechart->enter();
	
	statechart->getDefaultSCI()->raise_f();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(supersteps::CycleBasedSuperStep::CycleBasedSuperStep_main_region_I));
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 0);
	
	statechart->exit();
	
	
}
TEST_F(CycleBasedSuperStepTest, superStepIteratesUsingSameEventAndGuard) {
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->isStateActive(supersteps::CycleBasedSuperStep::CycleBasedSuperStep_main_region_A));
	
	statechart->getDefaultSCI()->raise_e();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(supersteps::CycleBasedSuperStep::CycleBasedSuperStep_main_region_C));
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 42);
	
	statechart->getDefaultSCI()->raise_f();
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(supersteps::CycleBasedSuperStep::CycleBasedSuperStep_main_region_I));
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 0);
	
	statechart->exit();
	
	
}

}

