/*
 * traffic_light.c
 */


#include "traffic_light.h"

void trafficlight_init(){
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, RESET);
	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, RESET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, RESET);
}
void led_green_red(){
	// traffic1
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, RESET);
	// traffic2
	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);
}
void led_yellow_red(){
	//traffic1
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);
	//traffic2
	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);
}
void led_red_green(){
	//traffic1
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);
	//traffic2
	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, RESET);
}
void led_red_yellow(){
	//traffic1
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);
	//traffic2
	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, RESET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);
}
void TogglePinRED(){
	HAL_GPIO_TogglePin(LED1_A_GPIO_Port, LED1_A_Pin);
	HAL_GPIO_TogglePin(LED1_B_GPIO_Port, LED1_B_Pin);
	HAL_GPIO_TogglePin(LED2_A_GPIO_Port, LED2_A_Pin);
	HAL_GPIO_TogglePin(LED2_B_GPIO_Port, LED2_B_Pin);
}
void TogglePinYELLOW(){
	HAL_GPIO_TogglePin(LED1_B_GPIO_Port, LED1_B_Pin);
	HAL_GPIO_TogglePin(LED2_B_GPIO_Port, LED2_B_Pin);
}
void TogglePinGREEN(){
	HAL_GPIO_TogglePin(LED1_A_GPIO_Port, LED1_A_Pin);
	HAL_GPIO_TogglePin(LED2_A_GPIO_Port, LED2_A_Pin);
}
