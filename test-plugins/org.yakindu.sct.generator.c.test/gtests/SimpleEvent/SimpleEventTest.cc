
#include "gtest/gtest.h"
#include "SimpleEvent.h"

#include "sc_timer_service.h"

static SimpleEvent statechart;


class SimpleEventTest : public ::testing::Test
{
public:
	/* All operations from the SCTUnit test class. */
	void simpleEventTest();
	void setTimer(SimpleEvent* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
	void unsetTimer(SimpleEvent* handle, const sc_eventid evid);
protected:
	sc_unit_timer_service_t timer_service;
	virtual void SetUp();
};

static SimpleEventTest * tc;


void SimpleEventTest::SetUp()
{
	simpleEvent_init(&statechart);
	sc_timer_service_init(
		&timer_service,
		0,
		(sc_run_cycle_fp) &simpleEvent_runCycle,
		false,
		200,
		&statechart
	);
	
	
	tc = this;
}
void SimpleEventTest::simpleEventTest()
{
	simpleEvent_enter(&statechart);
	EXPECT_TRUE(simpleEvent_isStateActive(&statechart, SimpleEvent_main_region_A)) << "Expected A to be active" ;
	EXPECT_TRUE(5l== 5l);
	simpleEventIface_raise_event1(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(simpleEvent_isStateActive(&statechart, SimpleEvent_main_region_B)) << "Expected B to be active" ;
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!simpleEvent_isStateActive(&statechart, SimpleEvent_main_region_B));
}

void SimpleEventTest::setTimer(SimpleEvent* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_t timer;
	sc_timer_init(&timer, time_ms, periodic, evid);
	insert_timer(&(tc->timer_service), timer);
}

void SimpleEventTest::unsetTimer(SimpleEvent* handle, const sc_eventid evid){
	delete_task(&(tc->timer_service), find_time_event(&timer_service, evid));
}

TEST_F(SimpleEventTest, simpleEventTest) {
	simpleEventTest();
}


