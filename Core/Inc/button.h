/*
 * button.h
 *
 *  Created on: Sep 21, 2024
 *      Author: LENOVO
 */



#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

int MAX_BUTTONS;

extern int button_pressed[];
extern int button_long_pressed[];
extern int TimeOutForKeyPress[];


int isButtonPressed();
int isButtonLongPressed();
void getKeyInput();

#endif /* INC_BUTTON_H_ */
