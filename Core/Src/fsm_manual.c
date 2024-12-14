/*
 * fsm_manual.c
 */

#include "fsm_manual.h"


void fsm_manual_run(){
	updateBufferLcd_run();
	switch(laststatus){
		case GREEN_RED:
			led_green_red();
			if(isButtonPressed(0)){
				status = laststatus;
				laststatus = WAIT;
				mode = AUTO;
				time_counter_1 = duration_green;
				time_counter_2 = duration_red;
				isButtonLongPressed(0);
			}
			if(isButtonPressed(1)){
				laststatus = YELLOW_RED;
				time_counter_1 = duration_yellow;
				time_counter_2 = 0;
			}
			break;
		case YELLOW_RED:
			led_yellow_red();
			if(time_counter_1 == 0){
				laststatus = RED_GREEN;
				time_counter_2 = 0;
			}
			if(isButtonPressed(0)){
				status = laststatus;
				laststatus = WAIT;
				mode = AUTO;
				time_counter_1 = duration_yellow;
				time_counter_2 = duration_yellow;
				isButtonLongPressed(0);
			}
			isButtonPressed(1);
			break;
		case RED_GREEN:
			led_red_green();
			if(isButtonPressed(0)) {
				status = laststatus;
				laststatus = WAIT;
				mode = AUTO;
				time_counter_1 = duration_red;
				time_counter_2 = duration_green;
				isButtonLongPressed(0);
			}
			if(isButtonPressed(1)){
				laststatus = RED_YELLOW;
				time_counter_1 = 0;
				time_counter_2 = duration_yellow;
			}
			break;
		case RED_YELLOW:
			led_red_yellow();
			if(time_counter_2 == 0){
				laststatus = GREEN_RED;
				time_counter_1 = 0;
			}
			if(isButtonPressed(0)){
				status = laststatus;
				laststatus = WAIT;
				mode = AUTO;
				time_counter_1 = duration_yellow;
				time_counter_2 = duration_yellow;
				isButtonLongPressed(0);
			}
			isButtonPressed(1);
			break;
		case WAIT:
			break;
	}
}



