/*
 * Software_timer.h
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern int timer_flag[];

void setTimer(int index, int counter);
void timer_run();
int isTimerExpired(int index);


#endif /* INC_SOFTWARE_TIMER_H_ */
