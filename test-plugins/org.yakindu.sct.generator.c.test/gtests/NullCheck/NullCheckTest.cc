/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "NullCheck.h"

#include "sc_timer_service.h"

static NullCheck statechart;



//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;
			
class NullCheckTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		nullCheck_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &nullCheck_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(NullCheckTest, SimpleNullCheckTest) {
	
	nullCheck_enter(&statechart);
	EXPECT_TRUE(nullCheck_isStateActive(&statechart, NullCheck_main_region_A));
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(nullCheck_isStateActive(&statechart, NullCheck_main_region_B));
}


