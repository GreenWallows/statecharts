
#include "gtest/gtest.h"
#include "ExitSequence.h"

#include "sc_timer_service.h"

static ExitSequence statechart;


class ExitSequenceTest : public ::testing::Test
{
public:
	/* All operations from the SCTUnit test class. */
	void exitStatechartFromLeafSlimState();
	void exitLeafSlimStateByTransition();
	void exitLeafSlimStateByTransitionFromParent();
	void exitStatechartFromLeafSlimOrthogonalState();
	void exitLeafSlimOrthogonaleStateByTransition();
	void exitLeafSlimOrthogonalStateByTransitionFromParent();
	void exitStatechartFromLeafSlimDeepState();
	void exitLeafSlimDeepStateByTransition();
	void exitLeafSlimDeepStateByTransitionFromParent();
	void exitStatechartFromFatState();
	void exitFatStateByTransition();
	void exitFatStateByTransitionFromParent();
	void setTimer(ExitSequence* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
	void unsetTimer(ExitSequence* handle, const sc_eventid evid);
protected:
	sc_unit_timer_service_t timer_service;
	virtual void SetUp();
};

static ExitSequenceTest * tc;


void ExitSequenceTest::SetUp()
{
	exitSequence_init(&statechart);
	sc_timer_service_init(
		&timer_service,
		0,
		(sc_run_cycle_fp) &exitSequence_runCycle,
		true,
		200,
		&statechart
	);
	
	
	tc = this;
}
void ExitSequenceTest::exitStatechartFromLeafSlimState()
{
	exitSequence_enter(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AA));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
	exitSequence_exit(&statechart);
	EXPECT_TRUE(!exitSequence_isStateActive(&statechart, ExitSequence_main_region_A));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitLeafSlimStateByTransition()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AB));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitLeafSlimStateByTransitionFromParent()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_f(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AA));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitStatechartFromLeafSlimOrthogonalState()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AB));
	exitSequence_exit(&statechart);
	EXPECT_TRUE(!exitSequence_isStateActive(&statechart, ExitSequence_main_region_A));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 5l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitLeafSlimOrthogonaleStateByTransition()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AC));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitLeafSlimOrthogonalStateByTransitionFromParent()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AB));
	exitSequenceIface_raise_f(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AA));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 5l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitStatechartFromLeafSlimDeepState()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AC));
	exitSequence_exit(&statechart);
	EXPECT_TRUE(!exitSequence_isStateActive(&statechart, ExitSequence_main_region_A));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 8l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 7l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 6l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 5l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitLeafSlimDeepStateByTransition()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AD));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 7l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 6l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 5l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitLeafSlimDeepStateByTransitionFromParent()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AC));
	exitSequenceIface_raise_f(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AA));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 8l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 7l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 6l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 5l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 0l));
}
void ExitSequenceTest::exitStatechartFromFatState()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AD));
	exitSequence_exit(&statechart);
	EXPECT_TRUE(!exitSequence_isStateActive(&statechart, ExitSequence_main_region_A));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 12l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 7l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 6l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 5l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 11l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 8l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 9l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 10l));
}
void ExitSequenceTest::exitFatStateByTransition()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AD));
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AA));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 0l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 7l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 6l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 5l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 11l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 8l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 9l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 10l));
}
void ExitSequenceTest::exitFatStateByTransitionFromParent()
{
	exitSequence_enter(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	exitSequenceIface_raise_e(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AD));
	exitSequenceIface_raise_f(&statechart);
	EXPECT_TRUE(exitSequence_isStateActive(&statechart, ExitSequence_main_region_A_r_AA));
	EXPECT_TRUE((exitSequenceIface_get_a_exit(&statechart)== 12l));
	EXPECT_TRUE((exitSequenceIface_get_aa_exit(&statechart)== 1l));
	EXPECT_TRUE((exitSequenceIface_get_ab_exit(&statechart)== 4l));
	EXPECT_TRUE((exitSequenceIface_get_aba_exit(&statechart)== 2l));
	EXPECT_TRUE((exitSequenceIface_get_abb_exit(&statechart)== 3l));
	EXPECT_TRUE((exitSequenceIface_get_ac_exit(&statechart)== 7l));
	EXPECT_TRUE((exitSequenceIface_get_aca_exit(&statechart)== 6l));
	EXPECT_TRUE((exitSequenceIface_get_acaa_exit(&statechart)== 5l));
	EXPECT_TRUE((exitSequenceIface_get_ad_exit(&statechart)== 11l));
	EXPECT_TRUE((exitSequenceIface_get_ada_exit(&statechart)== 8l));
	EXPECT_TRUE((exitSequenceIface_get_adb_exit(&statechart)== 9l));
	EXPECT_TRUE((exitSequenceIface_get_adc_exit(&statechart)== 10l));
}

void ExitSequenceTest::setTimer(ExitSequence* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_t timer;
	sc_timer_init(&timer, time_ms, periodic, evid);
	insert_timer(&(tc->timer_service), timer);
}

void ExitSequenceTest::unsetTimer(ExitSequence* handle, const sc_eventid evid){
	delete_task(&(tc->timer_service), find_time_event(&timer_service, evid));
}

TEST_F(ExitSequenceTest, exitStatechartFromLeafSlimState) {
	exitStatechartFromLeafSlimState();
}
TEST_F(ExitSequenceTest, exitLeafSlimStateByTransition) {
	exitLeafSlimStateByTransition();
}
TEST_F(ExitSequenceTest, exitLeafSlimStateByTransitionFromParent) {
	exitLeafSlimStateByTransitionFromParent();
}
TEST_F(ExitSequenceTest, exitStatechartFromLeafSlimOrthogonalState) {
	exitStatechartFromLeafSlimOrthogonalState();
}
TEST_F(ExitSequenceTest, exitLeafSlimOrthogonaleStateByTransition) {
	exitLeafSlimOrthogonaleStateByTransition();
}
TEST_F(ExitSequenceTest, exitLeafSlimOrthogonalStateByTransitionFromParent) {
	exitLeafSlimOrthogonalStateByTransitionFromParent();
}
TEST_F(ExitSequenceTest, exitStatechartFromLeafSlimDeepState) {
	exitStatechartFromLeafSlimDeepState();
}
TEST_F(ExitSequenceTest, exitLeafSlimDeepStateByTransition) {
	exitLeafSlimDeepStateByTransition();
}
TEST_F(ExitSequenceTest, exitLeafSlimDeepStateByTransitionFromParent) {
	exitLeafSlimDeepStateByTransitionFromParent();
}
TEST_F(ExitSequenceTest, exitStatechartFromFatState) {
	exitStatechartFromFatState();
}
TEST_F(ExitSequenceTest, exitFatStateByTransition) {
	exitFatStateByTransition();
}
TEST_F(ExitSequenceTest, exitFatStateByTransitionFromParent) {
	exitFatStateByTransitionFromParent();
}


