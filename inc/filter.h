#ifndef __FILTER_H
#define __FILTER_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f4xx.h"
#include <stdio.h>
#include "ringbuffer.h"
#include "uart_init.h"
#include "structural.h"
#include"adconvert.h"
#include "SysTick.h"
#include "eeprom.h"
#include "argument_config.h"
#include "Library_Filter.h"

#define Acc_2_16HZ
#define Gyro_2_30HZ
////////////////////////////////////
//     1Whz     ACC 10HZ              //
////////////////////////////////////
#if defined Acc_2_10HZ
   #define Acc_b1  0.00000982593
   #define Acc_b2  0.00001965184
   #define Acc_b3  0.00000982593
   #define Acc_a2 -1.9911142922
   #define Acc_a3  0.9911535959
////////////////////////////////////
//     1whz     ACC 16HZ              //
////////////////////////////////////
#elif defined  Acc_2_16HZ
    #define Acc_b1  0.00002508763
    #define Acc_b2  0.00005017528
    #define Acc_b3  0.00002508764
    #define Acc_a2 -1.98578301154
    #define Acc_a3  0.98588336209
////////////////////////////////////
//      1whz    ACC 20HZ              //
////////////////////////////////////
#elif defined Acc_2_20HZ
  #define Acc_b1  0.00003913021
  #define Acc_b2  0.00007826041
  #define Acc_b3  0.00003913021
  #define Acc_a2 -1.98222892979
  #define Acc_a3  0.98238545062

#elif defined FH_Acc_2
  #define Acc_b1  0.0133592
  #define Acc_b2  0.0267184
  #define Acc_b3  0.0133592
  #define Acc_a2 -1.6474600
  #define Acc_a3  0.7008968
#endif

////////////////////////////////////
// 1whz  gyro 30HZ  60HZ  16HZ    //
////////////////////////////////////
#if defined Gyro_2_30HZ
#define Gyro_b1  0.0000876555
#define Gyro_b2  0.0001753110
#define Gyro_b3  0.0000876555
#define Gyro_a2 -1.973344250
#define Gyro_a3  0.973694872

#elif defined Gyro_2_60HZ
#define Gyro_b1  0.00034604134
#define Gyro_b2  0.00069208268
#define Gyro_b3  0.00034604133
#define Gyro_a2 -1.94669754075
#define Gyro_a3  0.94808170610

#elif defined Gyro_2_16HZ
#define Gyro_b1  0.00002508763
#define Gyro_b2  0.00005017528
#define Gyro_b3  0.00002508764
#define Gyro_a2 -1.98578301154
#define Gyro_a3  0.98588336209

#elif defined FH_Gyro_2

#define Gyro_b1  0.0133592
#define Gyro_b2  0.0267184
#define Gyro_b3  0.0133592
#define Gyro_a2 -1.6474600
#define Gyro_a3  0.7008968

#endif


//   /////high////
//  #define Acc_high_b1  9.999444655053702e-001
//  #define Acc_high_b2  -1.999888931010740e+000
//  #define Acc_high_b3  9.999444655053702e-001
//  #define Acc_high_a2  -1.999888927926660e+000
//  #define Acc_high_a3  9.998889340948205e-001


extern IMU_Data  *pAHRS_Data_filtered;
extern Gyro_Data  *pGyro_zerod;
extern IMU_Data  *pAHRS_Data;
extern IMU_Data  *pAHRS_Data_Decode;
extern IMU_Data  *pAHRS_Data_raw ;

extern IIR_coeff_Typedef* psAccXCoeff;
extern IIR_coeff_Typedef* psAccYCoeff;
extern IIR_coeff_Typedef* psAccZCoeff;

extern IIR_coeff_Typedef* psGyroXCoeff;
extern IIR_coeff_Typedef* psGyroYCoeff;
extern IIR_coeff_Typedef* psGyroZCoeff;


void AD_To_RawAhrs();
void ADC_data_filter();
void GyroAcc_RawData_Process();
void TEST_GyroAcc_RawData_Process();
void Gyroad_Initial_Offset(void);

#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT AOYIWEIYENG *****END OF FILE***********/