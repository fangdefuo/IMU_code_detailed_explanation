/**
  ******************************************************************************
  * @file    TIM/TIM_TimeBase/main.h 
  * @author  UAV Application Team
  * @version V2.1.0
  * @date    23-September-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F40x_IT_H
#define __STM32F40x_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void RTC_Alarm_IRQHandler(void);
void TIM2_IRQHandler(void);
void SPI3_IRQHandler(void);
extern void USB_OTG_BSP_TimerIRQ(void);
extern u8 time3_flag_400hz,time3_flag_200hz,time3_flag_100hz,time3_flag_50hz;

#ifdef __cplusplus
}
#endif

#endif /* __STM32F40x_IT_H */

/************************ (C) COPYRIGHT AOYIWEIYENG *****END OF FILE***********/
