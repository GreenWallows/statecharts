
#include "gtest/gtest.h"
#include "LocalEvents.h"

#include "sc_timer_service.h"

static LocalEvents statechart;


class LocalEventsTest : public ::testing::Test
{
public:
	/* All operations from the SCTUnit test class. */
	void test();
	void setTimer(LocalEvents* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
	void unsetTimer(LocalEvents* handle, const sc_eventid evid);
protected:
	sc_unit_timer_service_t timer_service;
	virtual void SetUp();
};

static LocalEventsTest * tc;


void LocalEventsTest::SetUp()
{
	localEvents_init(&statechart);
	sc_timer_service_init(
		&timer_service,
		0,
		(sc_run_cycle_fp) &localEvents_runCycle,
		true,
		200,
		&statechart
	);
	
	
	tc = this;
}
void LocalEventsTest::test()
{
	localEvents_enter(&statechart);
	EXPECT_TRUE(localEvents_isStateActive(&statechart, LocalEvents_localEvents_r1_Comp1_r_A1));
	EXPECT_TRUE(localEvents_isStateActive(&statechart, LocalEvents_localEvents_r2_Comp2_r_A2));
	localEventsIface_raise_e(&statechart);
	EXPECT_TRUE(localEvents_isStateActive(&statechart, LocalEvents_localEvents_r1_Comp1_r_D1));
	EXPECT_TRUE(localEvents_isStateActive(&statechart, LocalEvents_localEvents_r2_Comp2_r_D2));
	EXPECT_TRUE(localEventsIface_get_cycleCountSm(&statechart)== 5l);
	EXPECT_TRUE(localEventsIface_get_cycleCount1(&statechart)== 5l);
	EXPECT_TRUE(localEventsIface_get_cycleCount2(&statechart)== 5l);
	EXPECT_TRUE(localEventsIface_get_checksum(&statechart)== 3l);
	localEvents_exit(&statechart);
}

void LocalEventsTest::setTimer(LocalEvents* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_t timer;
	sc_timer_init(&timer, time_ms, periodic, evid);
	insert_timer(&(tc->timer_service), timer);
}

void LocalEventsTest::unsetTimer(LocalEvents* handle, const sc_eventid evid){
	delete_task(&(tc->timer_service), find_time_event(&timer_service, evid));
}

TEST_F(LocalEventsTest, test) {
	test();
}


