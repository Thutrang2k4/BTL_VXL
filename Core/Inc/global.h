/*
 * global.h
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "scheduler.h"
#include "button.h"
#include "i2c-lcd.h"

#include "traffic_light.h"
#include "updateBufferLcd.h"
#include "fsm_setting.h"
#include "fsm_manual.h"
#include "fsm_auto.h"


#define AUTO 			0
#define MODIFY_RED 		1
#define MODIFY_YELLOW 	2
#define MODIFY_GREEN 	3
#define MANUAL			4

#define INIT 		5
#define GREEN_RED 	6
#define YELLOW_RED 	7
#define RED_GREEN 	8
#define RED_YELLOW	9
#define WAIT		10


extern int mode;
extern int status;
extern int laststatus;

extern int time_counter_1;
extern int time_counter_2;

extern int duration_red;
extern int duration_yellow;
extern int duration_green;
extern int setting_time;

void counter_1s();

#endif /* INC_GLOBAL_H_ */
