
#include "gtest/gtest.h"
#include "TriggerExpressionPrecedence.h"

#include "sc_timer_service.h"

static TriggerExpressionPrecedence statechart;


class TriggerExpressionPrecedenceTest : public ::testing::Test
{
public:
	/* All operations from the SCTUnit test class. */
	void unsatisfiedTriggerAndFGuardFalseOrFalse();
	void unsatisfiedTriggerAndFGuardTrueOrFalse();
	void unsatisfiedTriggerAndFGuardFalseOrTrue();
	void unsatisfiedTriggerAndFGuardTrueOrTrue();
	void setTimer(TriggerExpressionPrecedence* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
	void unsetTimer(TriggerExpressionPrecedence* handle, const sc_eventid evid);
protected:
	sc_unit_timer_service_t timer_service;
	virtual void SetUp();
};

static TriggerExpressionPrecedenceTest * tc;


void TriggerExpressionPrecedenceTest::SetUp()
{
	triggerExpressionPrecedence_init(&statechart);
	sc_timer_service_init(
		&timer_service,
		0,
		(sc_run_cycle_fp) &triggerExpressionPrecedence_runCycle,
		false,
		200,
		&statechart
	);
	
	
	tc = this;
}
void TriggerExpressionPrecedenceTest::unsatisfiedTriggerAndFGuardFalseOrFalse()
{
	triggerExpressionPrecedence_enter(&statechart);
	triggerExpressionPrecedenceIface_set_c1(&statechart,false);
	triggerExpressionPrecedenceIface_set_c2(&statechart,false);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!triggerExpressionPrecedenceIface_get_e1_transition(&statechart));
}
void TriggerExpressionPrecedenceTest::unsatisfiedTriggerAndFGuardTrueOrFalse()
{
	triggerExpressionPrecedence_enter(&statechart);
	triggerExpressionPrecedenceIface_set_c1(&statechart,true);
	triggerExpressionPrecedenceIface_set_c2(&statechart,false);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!triggerExpressionPrecedenceIface_get_e1_transition(&statechart));
}
void TriggerExpressionPrecedenceTest::unsatisfiedTriggerAndFGuardFalseOrTrue()
{
	triggerExpressionPrecedence_enter(&statechart);
	triggerExpressionPrecedenceIface_set_c1(&statechart,false);
	triggerExpressionPrecedenceIface_set_c2(&statechart,true);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!triggerExpressionPrecedenceIface_get_e1_transition(&statechart));
}
void TriggerExpressionPrecedenceTest::unsatisfiedTriggerAndFGuardTrueOrTrue()
{
	triggerExpressionPrecedence_enter(&statechart);
	triggerExpressionPrecedenceIface_set_c1(&statechart,true);
	triggerExpressionPrecedenceIface_set_c2(&statechart,true);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!triggerExpressionPrecedenceIface_get_e1_transition(&statechart));
}

void TriggerExpressionPrecedenceTest::setTimer(TriggerExpressionPrecedence* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_t timer;
	sc_timer_init(&timer, time_ms, periodic, evid);
	insert_timer(&(tc->timer_service), timer);
}

void TriggerExpressionPrecedenceTest::unsetTimer(TriggerExpressionPrecedence* handle, const sc_eventid evid){
	delete_task(&(tc->timer_service), find_time_event(&timer_service, evid));
}

TEST_F(TriggerExpressionPrecedenceTest, unsatisfiedTriggerAndFGuardFalseOrFalse) {
	unsatisfiedTriggerAndFGuardFalseOrFalse();
}
TEST_F(TriggerExpressionPrecedenceTest, unsatisfiedTriggerAndFGuardTrueOrFalse) {
	unsatisfiedTriggerAndFGuardTrueOrFalse();
}
TEST_F(TriggerExpressionPrecedenceTest, unsatisfiedTriggerAndFGuardFalseOrTrue) {
	unsatisfiedTriggerAndFGuardFalseOrTrue();
}
TEST_F(TriggerExpressionPrecedenceTest, unsatisfiedTriggerAndFGuardTrueOrTrue) {
	unsatisfiedTriggerAndFGuardTrueOrTrue();
}


