/**
  ******************************************************************************
  * @file    SLAVER/STM32F4xx_StdPeriph_V1.3.0/main.h
  * @author  UAV Application Team: xujinqi/guzetao/panjiadi
  * @version V2.1.0
  * @date    23-September-2014
  * @brief   Main program body
  ******************************************************************************
  * @device  Master---STM32F405RGT6
  ******************************************************************************   
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "device_init.h"
#include "stm32f4xx_it.h"  
#include "transmit_date_chose.h"
#include "filter.h"
#include "AHRS_EKF.h"
#include "motor.h"
#include "Mag_Correct.h"
#include "gps_dc.h"
#include "hmc_dc.h"
#include "Imu_health.h"
#include "gps_generic.h"
#include "canIMUDecode.h"
#include "canIMU.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TimingDelay_Decrement(void);
void Out_Direction_init(void);
#endif /* __MAIN_H */

/************************ (C) COPYRIGHT AOYIWEIYENG *****END OF FILE***********/
