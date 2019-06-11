#ifndef __TransmitDataChose_H
#define __TransmitDataChose_H

#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"   
#include "stm32f4xx.h"   
#include "stdio.h"
#include "structural.h"
#include "stm32f4xx_it.h"   
# include "Imu_health.h"

#define DATA_IMU                 ((uint16_t)0x0001)  
#define DATA_PROP                ((uint16_t)0x0002)  
#define DATA_CONTROL_U           ((uint16_t)0x0004)   
#define DATA_MOTOR_U             ((uint16_t)0x0008) 
#define DATA_SIM                 ((uint16_t)0x0010) 
 
 

void double2hex(u8 *hexdata, double ddata);
extern uint8_t TxData[];
extern uint8_t TxData_P[];
extern uint8_t TxData_S[];
uint16_t chose_data_type_toFC(void);
uint16_t chose_data_type_toFCM(void);
uint16_t error_data_type_toFCM(void);
uint16_t chose_data_type_toFCS(void);
void CalcBcc_type_toFCM(unsigned char* TxData, int16_t data_head, int16_t data_tail);
void CalcBcc_type_toFCS(unsigned char* TxData, int16_t data_head, int16_t data_tail); 
uint16_t chose_data_type_toSHOW(void);   
void CalcBcc_type_toSHOW(unsigned char* TxData, int16_t data_head, int16_t data_tail);    
uint16_t chose_data_type_toGPS(void); 
void CalcBcc_type_toGPS(unsigned char* TxData, int16_t data_head, int16_t data_tail);   
#ifdef __cplusplus
}
#endif
#endif