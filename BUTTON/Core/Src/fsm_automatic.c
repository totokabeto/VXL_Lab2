/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */
#include "fsm_automatic.h"
#include "button.h"

void fsm_automatic_run(){
	switch(status){
	case INIT :
	HAL_GPIO_WritePin (GPIOA , GPIO_PIN_5 , GPIO_PIN_RESET );
	HAL_GPIO_WritePin (GPIOA , GPIO_PIN_6 , GPIO_PIN_SET );
		status = AUTO_RED;
		SetTimer1(500);
		break;
	case AUTO_RED:
		//setTimer(500)
	HAL_GPIO_WritePin (GPIOA , GPIO_PIN_5 , GPIO_PIN_RESET );
	HAL_GPIO_WritePin (GPIOA , GPIO_PIN_6 , GPIO_PIN_SET );
		if (timer_flag1 == 1){
				status = AUTO_GREEN;
				SetTimer1 (200);
		}
		if (button1_flag ==1){
			button1_flag =0;
			status = MAN_RED;
			SetTimer1(10000);
		}
		break;
	case AUTO_GREEN:
//TODE
		HAL_GPIO_WritePin (GPIOA , GPIO_PIN_5 , GPIO_PIN_SET );
		HAL_GPIO_WritePin (GPIOA , GPIO_PIN_6, GPIO_PIN_RESET );
		if (timer_flag1 == 1){
			status = AUTO_YELLOW;
			SetTimer1 (200);}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin (GPIOA , GPIO_PIN_5 , GPIO_PIN_SET );
		HAL_GPIO_WritePin (GPIOA , GPIO_PIN_6, GPIO_PIN_SET );

			if (timer_flag1 == 1){
				status = AUTO_RED;
				SetTimer1 (200);}
		break;
	default:
		break;
}
}
