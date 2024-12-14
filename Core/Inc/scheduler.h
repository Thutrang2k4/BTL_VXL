/*
 * scheduler.h
 */

#include "main.h"
#include "stdint.h"


#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_


typedef struct {
	void(*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
}sTask;

#define SCH_MAX_TASKS	10
#define NO_TASK			10
#define TICK			10

void SCH_Init(void);
void SCH_Update(void);
void SCH_Add_Task(void(*pTask)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(uint32_t taskID);


#endif /* INC_SCHEDULER_H_ */
