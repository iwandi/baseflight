#include "scheduler.h"

//uint32_t totalTime;
//uint32_t cycles;
//uint32_t lastStartTime;
//uint32_t lastEndTime;

uint32_t taskPlanedTiming[TASK_COUNT];

void schedulerTick(void)
{
	uint32_t currentStartTime = micro();
		
	uint32_t taskDelay = 1;
	int32_t task = -1;
	int32_t i;
	// check all timings for the most delayed task
	for( i = 0; i < TASK_COUNT; i++ )
	{
		delay = currentStartTime - taskPlanedTiming[i];
		if ( delay > taskDelay )
		{
			taskDelay = delay;
			task = i;
		}
	}
	// execute that task
	if ( task != -1 )
	{
		taskPlanedTiming[task] = executeTask(task) + currentStartTime;
	}
	
	//cycles++;
	//lastStartTime = currentStartTime;
	//lastEndTime = micro();	
	//uint32_t tickTime = lastEndTime - currentStartTime;
	//totalTime +=  tickTime;
}

void triggerTask(uint32_t task)
{
	taskPlanedTiming[task] = 0;
}

uint32_t executeTask(uint32_t task)
{
	switch(task)
	{
		case TASK_RC:
			return taskRC();
		case TASK_MAG:
			return taskMag();
		case TASK_BARO:
			return taskBaro();
		case TASK_GPS:
			return taskGPS();
		case TASK_SONAR:
			return taskSonar();
		case TASK_PID:
			return taskPID();
	}
	return -1;
}

uint32_t taskRC(void)
{
	return 20000;
}

uint32_t taskMag(void)
{
	return 0;
}

uint32_t taskBaro(void)
{
	return 0;
}

uint32_t taskGPS(void)
{
	return 0;
}

uint32_t taskSonar(void)
{
	return 0;
}

// if mcfg.looptime == 0 it dose not get updatet every frame
uint32_t taskPID(void)
{
	return mcfg.looptime;
}

