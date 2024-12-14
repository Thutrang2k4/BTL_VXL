/*
 * button.c
 */

#include "button.h"

#define MAX_BUTTONS				2
#define NORMAL_STATE 			GPIO_PIN_SET
#define PRESSED_STATE 			GPIO_PIN_RESET
#define LONG_PRESS_THRESHOLD  	100

int KeyReg0[MAX_BUTTONS] = {NORMAL_STATE};
int KeyReg1[MAX_BUTTONS] = {NORMAL_STATE};
int KeyReg2[MAX_BUTTONS] = {NORMAL_STATE};
int KeyReg3[MAX_BUTTONS] = {NORMAL_STATE};

int TimeOutForKeyPress[MAX_BUTTONS] = {LONG_PRESS_THRESHOLD};
int button_pressed[MAX_BUTTONS] = {0};
int button_long_pressed[MAX_BUTTONS] = {0};
int button_counter[MAX_BUTTONS] = {0};

GPIO_TypeDef* butt_ports[MAX_BUTTONS] = {BUTTON0_GPIO_Port, BUTTON1_GPIO_Port};
uint16_t butt_pins[MAX_BUTTONS] = {BUTTON0_Pin, BUTTON1_Pin};

int isButtonPressed(int index){
	if(button_pressed[index] == 1){
		button_pressed[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(button_long_pressed[index] == 1){
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for (int i = 0; i < MAX_BUTTONS; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		KeyReg0[i] = HAL_GPIO_ReadPin(butt_ports[i], butt_pins[i]);

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE) TimeOutForKeyPress[i] = LONG_PRESS_THRESHOLD;
				else{
					if(TimeOutForKeyPress[i] > 0) button_pressed[i] = 1;
					TimeOutForKeyPress[i] =LONG_PRESS_THRESHOLD;
				}
			}
			else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					if (KeyReg2[i] == PRESSED_STATE){
						button_long_pressed[i] = 1;
					} else TimeOutForKeyPress[i] = LONG_PRESS_THRESHOLD;
				}
			}
		}
	}
}


