/*
 * fsm_auto.c
 */


#include "fsm_auto.h"


void fsm_auto_run(){
	switch(status){
		case INIT:
			mode = AUTO;
			status = GREEN_RED;
			time_counter_1 = duration_green;
			time_counter_2 = duration_red;
			setting_time = duration_red;
			lcd_clear_display();
			isButtonPressed(0);
			isButtonLongPressed(0);
			isButtonPressed(1);
			break;
		case GREEN_RED:
			mode = AUTO;
			updateBufferLcd_run();
			led_green_red();
			if(time_counter_1 == 0){
				time_counter_1 = duration_yellow;
				time_counter_2 = duration_yellow;
				status = YELLOW_RED;
			}
			if(isButtonPressed(0)){
				mode = MANUAL;
				laststatus = status;
				status = WAIT;
				time_counter_1 = 0;
				time_counter_2 = 0;
				lcd_clear_display();
			}
			if(isButtonLongPressed(0)){
				mode = MODIFY_RED;
				status = WAIT;
				setting_time = duration_red;
				time_counter_1 = 1;
				trafficlight_init();
				lcd_clear_display();
			}
			isButtonPressed(1);
			break;
		case YELLOW_RED:
			mode = AUTO;
			updateBufferLcd_run();
			led_yellow_red();
			if(time_counter_1 == 0){
				time_counter_1 = duration_red;
				time_counter_2 = duration_green;
				status = RED_GREEN;
			}
			if(isButtonPressed(0)){
				mode = MANUAL;
				laststatus = status;
				status = WAIT;
				time_counter_1 = 2;
				time_counter_2 = 0;
				lcd_clear_display();
			}
			if(isButtonLongPressed(0)){
				mode = MODIFY_RED;
				status = WAIT;
				setting_time = duration_red;
				time_counter_1 = 1;
				trafficlight_init();
				lcd_clear_display();
			}
			isButtonPressed(1);
			break;
		case RED_GREEN:
			mode = AUTO;
			updateBufferLcd_run();
			led_red_green();
			if(time_counter_2 == 0){
				time_counter_2 = duration_yellow;
				time_counter_1 = duration_yellow;
				status = RED_YELLOW;
			}
			if(isButtonPressed(0)){
				mode = MANUAL;
				laststatus = status;
				status = WAIT;
				time_counter_1 = 0;
				time_counter_2 = 0;
				lcd_clear_display();
			}
			if(isButtonLongPressed(0)){
				mode = MODIFY_RED;
				status = WAIT;
				setting_time = duration_red;
				time_counter_1 = 1;
				trafficlight_init();
				lcd_clear_display();
			}
			isButtonPressed(1);
			break;
		case RED_YELLOW:
			mode = AUTO;
			updateBufferLcd_run();
			led_red_yellow();
			if(time_counter_2 == 0){
				status = GREEN_RED;
				time_counter_1 = duration_green;
				time_counter_2 = duration_red;
			}
			if(isButtonPressed(0)){
				mode = MANUAL;
				laststatus = status;
				status = WAIT;
				time_counter_1 = 0;
				time_counter_2 = 2;
				lcd_clear_display();
			}
			if(isButtonLongPressed(0)){
				mode = MODIFY_RED;
				status = WAIT;
				setting_time = duration_red;
				time_counter_1 = 1;
				trafficlight_init();
				lcd_clear_display();
			}
			isButtonPressed(1);
			break;
		case WAIT:
			break;
	}
}
