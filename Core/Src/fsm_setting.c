/*
 * fsm_setting.c
 */

#include "fsm_setting.h"


void fsm_setting_run(){
	switch(mode){
		case MODIFY_RED:
			updateBufferLcd_run();
			if(time_counter_1 == 0){
				time_counter_1 = 1;
				TogglePinRED();
			}
			if(isButtonPressed(0)){
				mode = MODIFY_YELLOW;
				setting_time = duration_yellow;
				time_counter_1 = 1;
				trafficlight_init();
				lcd_clear_display();
			}
			if(isButtonPressed(1)){
				if (setting_time == 99){
					setting_time = duration_red;
					lcd_clear_display();
				}
				else setting_time++;
			}
			if(isButtonLongPressed(0)){
				if (setting_time > duration_yellow) duration_green = setting_time - duration_yellow;
				else duration_green = duration_yellow - setting_time;
				duration_red = setting_time;
				status = INIT;
				trafficlight_init();
			}
			break;
		case MODIFY_YELLOW:
			updateBufferLcd_run();
			if(time_counter_1 == 0){
				time_counter_1 = 1;
				TogglePinYELLOW();
			}
			if(isButtonPressed(0)){
				mode = MODIFY_GREEN;
				setting_time = duration_green;
				time_counter_1 = 1;
				trafficlight_init();
				lcd_clear_display();
			}
			if(isButtonPressed(1)){
				if (setting_time == 99){
					setting_time = duration_yellow;
					lcd_clear_display();
				}
				else setting_time++;
			}
			if(isButtonLongPressed(0)){
				duration_red = setting_time + duration_green;
				duration_yellow = setting_time;
				status = INIT;
				trafficlight_init();
			}
			break;
		case MODIFY_GREEN:
			updateBufferLcd_run();
			if(time_counter_1 == 0){
				time_counter_1 = 1;
				TogglePinGREEN();
			}
			if(isButtonPressed(0)){
				mode = MODIFY_RED;
				setting_time = duration_red;
				time_counter_1 = 1;
				trafficlight_init();
				lcd_clear_display();
			}
			if(isButtonPressed(1)){
				setting_time++;
				if (setting_time == 99){
					setting_time = duration_green;
					lcd_clear_display();
				}
			}
			if(isButtonLongPressed(0)){
				duration_red = setting_time + duration_yellow;
				duration_green = setting_time;
				status = INIT;
				trafficlight_init();
			}
			break;
		default:
			break;
	}
}

