/*
 * software_timer.h
 *
 *  Created on: Oct 21, 2022
 *      Author: BOSCH - HCMUT
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag1;
extern int timer_flag2;
void TimerRun();
void SetTimer1(int duration);
void SetTimer2(int duration);


#endif /* INC_SOFTWARE_TIMER_H_ */
