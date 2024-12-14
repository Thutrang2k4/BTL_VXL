/*
 * updateBufferLcd.c
 */

#include "updateBufferLcd.h"
char buffer[16];
void updateBufferLcd_run(){
	    lcd_goto_XY(0, 0);
	    sprintf(buffer, "MODE:%d", mode);
	    lcd_send_string(buffer);

	    lcd_goto_XY(1, 0);
	    if (mode == AUTO || mode == MANUAL) sprintf(buffer, "LED1:%d  LED2:%d", time_counter_1, time_counter_2);
	    else if (mode == MODIFY_RED) sprintf(buffer, "LEDR:%d", setting_time);
	    else if (mode == MODIFY_YELLOW) sprintf(buffer, "LEDY:%d", setting_time);
	    else if (mode == MODIFY_GREEN) sprintf(buffer, "LEDG:%d", setting_time);
	    lcd_send_string(buffer);
}
void clearBuffer() {
    for (int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = '\0';
    }
}


