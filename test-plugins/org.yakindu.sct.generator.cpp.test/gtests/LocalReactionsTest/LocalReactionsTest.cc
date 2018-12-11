#include <string>
#include "gtest/gtest.h"
#include "LocalReactions.h"
#include "sc_runner.h"
#include "sc_types.h"

namespace  {

LocalReactions* statechart;



//! The timers are managed by a timer service. */
static SctUnitRunner * runner;

class LocalReactionsTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new LocalReactions();
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


TEST_F(LocalReactionsTest, LocalReactionsTest) {
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->isStateActive(LocalReactions::main_region_A));
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 1);
	
	
}

}

