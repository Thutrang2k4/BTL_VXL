/*
 * Software_timer.c
 */

#include <software_timer.h>

#define MAX_TIMER	10
#define TICK		10
int timer_counter[MAX_TIMER] = {0};
int timer_flag[MAX_TIMER] = {0};


void setTimer(int index, int counter){
	timer_counter[index] = counter / TICK;
	timer_flag[index] = 0;
}

void timer_run(){
	for(int i = 0; i < MAX_TIMER; i++){
		if(timer_counter[i] >= 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0) timer_flag[i] = 1;
		}
	}
}

int isTimerExpired(int index){
	if(timer_flag[index] == 1){
		timer_flag[index] = 0;
		return 1;
	}
	else return 0;
}
