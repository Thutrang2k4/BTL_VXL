/*
 * scheduler.c
 */

#include "scheduler.h"


#define SCH_MAX_TASKS	10
#define NO_TASK			10

sTask 	SCH_tasks_G[SCH_MAX_TASKS];
uint8_t task_count = 0;


void SCH_Init(void){
    for (int i = 0; i < SCH_MAX_TASKS; i++){
    	SCH_tasks_G[i].pTask = 0x0000;
    	SCH_tasks_G[i].Delay = 0;
    	SCH_tasks_G[i].Period = 0;
    	SCH_tasks_G[i].RunMe = 0;
    	SCH_tasks_G[i].TaskID = NO_TASK;
    }
}

void SCH_Add_Task(void (*pTask)(), uint32_t DELAY, uint32_t PERIOD){
	if(task_count == SCH_MAX_TASKS) return;
	DELAY = DELAY / TICK;
	int index = 0;
	for(index; index < task_count; index++){
		if(DELAY < SCH_tasks_G[index].Delay) break;
		DELAY = DELAY - SCH_tasks_G[index].Delay;
	}
	for (int i = task_count; i >index; i--){
		SCH_tasks_G[i] = SCH_tasks_G[i - 1];
		SCH_tasks_G[i].TaskID = i;
	}
	SCH_tasks_G[index].pTask 	= pTask;
	SCH_tasks_G[index].Delay 	= DELAY;
	SCH_tasks_G[index].Period 	= PERIOD;
	SCH_tasks_G[index].RunMe 	= 0;
    SCH_tasks_G[index].TaskID 	= index;

    if(index < task_count) SCH_tasks_G[index + 1].Delay = SCH_tasks_G[index + 1].Delay - DELAY;
    task_count++;
    return;
}

void SCH_Update(void){
	if (SCH_tasks_G[0].pTask){
		if(SCH_tasks_G[0].Delay > 0) SCH_tasks_G[0].Delay--;
		else {
			SCH_tasks_G[0].RunMe++;
			if (SCH_tasks_G[0].Period != 0) SCH_tasks_G[0].Delay = SCH_tasks_G[0].Period;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	if(SCH_tasks_G[0].RunMe > 0){
		SCH_tasks_G[0].RunMe--;
		(*SCH_tasks_G[0].pTask)();
        if (SCH_tasks_G[0].Period != 0){
        	sTask temp = SCH_tasks_G[0];
        	SCH_Delete_Task(0);
        	SCH_Add_Task(temp.pTask, temp.Delay, temp.Period);
        }
        else SCH_Delete_Task(0);
	}
}

void SCH_Delete_Task(uint32_t taskID){
	for(int i = taskID; i != (task_count - 1); i++){
		SCH_tasks_G[i] = SCH_tasks_G[i + 1];
		SCH_tasks_G[i].TaskID = i;
	}
	SCH_tasks_G[task_count].pTask = 0x0000;
	SCH_tasks_G[task_count].Delay = 0;
	SCH_tasks_G[task_count].Period = 0;
	SCH_tasks_G[task_count].RunMe = 0;
	SCH_tasks_G[task_count].TaskID = NO_TASK;
	task_count--;
}
