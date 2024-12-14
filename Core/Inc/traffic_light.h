/*
 * traffic_light.h
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "global.h"

void init_trafficlight();
void led_green_red();
void led_yellow_red();
void led_red_yellow();
void led_red_green();

void TogglePinRED();
void TogglePinYELLOW();
void TogglePinGREEN();

#endif /* INC_TRAFFIC_LIGHT_H_ */
