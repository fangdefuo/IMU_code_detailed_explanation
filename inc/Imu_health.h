
#ifndef __IMU_HEALTH_H
#define __IMU_HEALTH_H

#ifdef __cplusplus
 extern "C" {
#endif 

#include"transmit_date_chose.h"
#include "uart_init.h" 
#include "stm32f4xx.h"
#include "ringbuffer.h"
#include "gps_dc.h"
     
uint8_t isIMUReady();   
void Self_Checkmassage_send();   
void IMU_Health_Check();
void IMU_Health_SelfCheck();
void Starnum_Health_Check();   
void Mag_Health_Check();   
void Acc_Health_Check();
void Gyro_Health_Check();
void Attitude_health_check();
void Altitude_health_check();
extern uint16_t  IMU_HEALTH_1STATE;  
extern uint16_t  IMU_HEALTH_2STATE; 
extern uint8_t    mag_factor_Healthstate;

#define MAG_FACTOR_NORMAL      0
#define MAG_FACTOR_ABNORMAL    1
#ifdef __cplusplus
}
#endif

#endif   