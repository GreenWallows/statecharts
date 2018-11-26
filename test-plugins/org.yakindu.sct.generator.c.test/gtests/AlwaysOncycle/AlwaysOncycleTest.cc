/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "AlwaysOncycle.h"

#include "sc_timer_service.h"

static AlwaysOncycle statechart;



//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;
			
class AlwaysOncycleTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		alwaysOncycle_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &alwaysOncycle_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(AlwaysOncycleTest, alwaysOnCycleTest) {
	
	alwaysOncycle_enter(&statechart);
	EXPECT_TRUE(alwaysOncycle_isStateActive(&statechart, AlwaysOncycle_main_region_StateA));
	sc_integer count = 0l;
	while (count< 5l) {
		sc_timer_service_proceed_cycles(&timer_service, 1);
		EXPECT_TRUE(alwaysOncycle_isStateActive(&statechart, AlwaysOncycle_main_region_StateA));
		count++;
	}
	EXPECT_TRUE((alwaysOncycleIface_get_value(&statechart)== 5l));
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(alwaysOncycle_isStateActive(&statechart, AlwaysOncycle_main_region_StateB));
	EXPECT_TRUE(alwaysOncycleIface_get_value(&statechart)== 0l);
	count = 0l;
	while (count< 5l) {
		sc_timer_service_proceed_cycles(&timer_service, 1);
		EXPECT_TRUE(alwaysOncycle_isStateActive(&statechart, AlwaysOncycle_main_region_StateB));
		count++;
	}
	EXPECT_TRUE((alwaysOncycleIface_get_value(&statechart)== 5l));
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(alwaysOncycle_isStateActive(&statechart, AlwaysOncycle_main_region_StateA));
	EXPECT_TRUE(alwaysOncycleIface_get_value(&statechart)== 0l);
}


