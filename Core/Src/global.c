/*
 * global.c
 */


#include "global.h"

int mode = INIT;
int status = INIT;
int laststatus = WAIT;

int time_counter_1 = 0;
int time_counter_2 = 0;
int setting_time = 0;

int duration_red = 5;
int duration_yellow = 2;
int duration_green = 3;

void counter_1s(){
	if (time_counter_1 != 0) time_counter_1--;
	if (time_counter_2 != 0) time_counter_2--;
	if (time_counter_1 == 9 || time_counter_2 == 9) lcd_clear_display();
}
