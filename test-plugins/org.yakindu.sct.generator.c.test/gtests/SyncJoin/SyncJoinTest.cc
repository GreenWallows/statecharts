/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "SyncJoin.h"

#include "sc_timer_service.h"

static SyncJoin statechart;



//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;
			
class SyncJoinTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		syncJoin_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &syncJoin_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(SyncJoinTest, syncJoin_C2_Waits) {
	
	syncJoin_enter(&statechart);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C1));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D1));
	syncJoinIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C2));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D1));
	syncJoinIface_raise_jc(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C2));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D1));
	syncJoinIface_raise_jd(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C2));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D1));
	syncJoinIface_raise_jc(&statechart);
	syncJoinIface_raise_jd(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C2));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D1));
	syncJoinIface_raise_f(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C2));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D2));
	syncJoinIface_raise_jc(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C2));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D2));
	syncJoinIface_raise_jd(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C2));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D2));
	syncJoinIface_raise_jc(&statechart);
	syncJoinIface_raise_jd(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_A));
}
TEST_F(SyncJoinTest, syncJoin_D2_Waits) {
	
	syncJoin_enter(&statechart);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C1));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D1));
	syncJoinIface_raise_f(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C1));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D2));
	syncJoinIface_raise_jc(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C1));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D2));
	syncJoinIface_raise_jd(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C1));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D2));
	syncJoinIface_raise_jc(&statechart);
	syncJoinIface_raise_jd(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C1));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D2));
	syncJoinIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r1_C2));
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_B_r2_D2));
}
TEST_F(SyncJoinTest, doubleEntryActionBug) {
	
	syncJoin_enter(&statechart);
	syncJoinIface_raise_e(&statechart);
	syncJoinIface_raise_f(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	syncJoinIface_raise_jc(&statechart);
	syncJoinIface_raise_jd(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(syncJoin_isStateActive(&statechart, SyncJoin_main_region_A));
	EXPECT_TRUE(syncJoinIface_get_x(&statechart)== 1l);
}


