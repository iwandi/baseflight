typedef enum {
	TASK_RC,
	TASK_MAG,
	TASK_BARO,
	TASK_GPS,
	TASK_SONAR,
	TASK_PID,
	TASK_COUNT	
} LoopTasks;

void schedulerTick(void);
void triggerTask(uint32_t task);