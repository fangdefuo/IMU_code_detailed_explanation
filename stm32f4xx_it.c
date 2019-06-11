/**
  ******************************************************************************
  * @file    TIM/TIM_TimeBase/main.c 
  * @author  UAV Application Team
  * @version V2.1.0
  * @date    23-September-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "device_init.h" 
IMU_Data  AHRS_Data_received;
IMU_Data  *pAHRS_Data_received=&AHRS_Data_received;

/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup TIM_TimeBase
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

void SysTick_Handler(void)
{
 /*  if (TimingDelay != 0)
  { 
    TimingDelay--;
  }
*/
}

/******************************************************************************/
/*            STM32F4xx Peripherals Interrupt Handlers                        */
/******************************************************************************/

/**
  * @brief  This function handles TIM3 global interrupt request.
  * @param  None
  * @retval None
  */
u8 time3_flag_800hz=0,time3_flag_400hz=0,time3_flag_200hz=0,time3_flag_100hz=0,time3_flag_50hz=0,time3_flag_25hz=0;

u8 time3_count_800hz=0;

void TIM3_IRQHandler(void)
 {
   
   if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
   {
     TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
     time3_flag_800hz=1;
     time3_count_800hz++;
     if(time3_count_800hz%2==1)
     {
       time3_flag_400hz=1;
     } 
     if(time3_count_800hz%4==2)
     {
       time3_flag_200hz=1;
     }   
     if(time3_count_800hz%8==4)
     {
       time3_flag_100hz=1;
     }
     if(time3_count_800hz>=16)
     {
       time3_flag_50hz=1;
       time3_count_800hz=0;
     }    

    }
   
 }

void TIM2_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
   {  
     
  //GPIO_SetBits(GPIOC, GPIO_Pin_7);
   
      TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
      AD_To_RawAhrs();
      GyroAcc_RawData_Process();
      ADC_data_filter();
   //GPIO_ResetBits(GPIOC, GPIO_Pin_7);
   }
}


u8 data_gps,data_gps_count=1,data_gps_flag=0;
extern RingBuffer  m_GPS_RX_RingBuff;
void UART4_IRQHandler(void)
 {   
    if (USART_GetFlagStatus(UART4, USART_FLAG_ORE) != RESET)
      {
         //USART_ClearFlag(USART1,USART_FLAG_ORE);
         USART_ReceiveData(UART4);
         //The RXNE flag can also be cleared by a read operation to the USART_DR register(USART_ReceiveData()).
      }
   /* USART in Receiver mode */
   if (USART_GetITStatus(UART4, USART_IT_RXNE) == SET)
    {      
      data_gps = USART_ReceiveData(UART4);
      rbPush(&m_GPS_RX_RingBuff, data_gps);
      if((data_gps_count>0)&&(data_gps_count<50))
      {  
        data_gps_count=data_gps_count+1;
      }
      if(data_gps_count==50)
      data_gps_flag=1;
     }
    }
   /* USART in Tramitter mode */
   
   
u8 data_hmc;
extern RingBuffer  m_HMC_RX_RingBuff;
void UART5_IRQHandler(void)
 {
    if (USART_GetFlagStatus(UART5, USART_FLAG_ORE) != RESET)
      {
         //USART_ClearFlag(USART6,USART_FLAG_ORE);
         USART_ReceiveData(UART5);
         //The RXNE flag can also be cleared by a read operation to the USART_DR register(USART_ReceiveData()).
      }
   /* USART in Receiver mode */
   if (USART_GetITStatus(UART5, USART_IT_RXNE) == SET)
    {      
      data_hmc = USART_ReceiveData(UART5);
      rbPush(&m_HMC_RX_RingBuff, data_hmc);     
    }
   /* USART in Tramitter mode */
 }

u16 RXBUFF[10];
u8 data_motor,o;
extern RingBuffer  m_MOTOR_RX_RingBuff;
//void USART6_IRQHandler(void)
// {
//    if (USART_GetFlagStatus(USART6, USART_FLAG_ORE) != RESET)
//      {
//         //USART_ClearFlag(USART6,USART_FLAG_ORE);
//         USART_ReceiveData(USART6);
//         //The RXNE flag can also be cleared by a read operation to the USART_DR register(USART_ReceiveData()).
//      }
//   /* USART in Receiver mode */
//   if (USART_GetITStatus(USART6, USART_IT_RXNE) == SET)
//    {      
//      data_motor = USART_ReceiveData(USART6);
//      rbPush(&m_MOTOR_RX_RingBuff, data_motor);
//      
//    }
//   /* USART in Tramitter mode */
// }
         //    USART1  S
          //   USART6  M

void USART1_IRQHandler(void)
 {
    if (USART_GetFlagStatus(USART1, USART_FLAG_ORE) != RESET)
      {
         //USART_ClearFlag(USART6,USART_FLAG_ORE);
         USART_ReceiveData(USART1);
         //The RXNE flag can also be cleared by a read operation to the USART_DR register(USART_ReceiveData()).
      }
   /* USART in Receiver mode */
   if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
    { 
      
      data_motor = USART_ReceiveData(USART1);
      rbPush(&m_MOTOR_RX_RingBuff, data_motor);
      
    }
   /* USART in Tramitter mode */
 }


u8 time4_phaseflag =0;
u8 ms5611_flag=0;
extern unsigned long D1_1,D1_2,d1;
extern unsigned long D2_1,d2;
TIM_TypeDef* TIM4_Pri = TIM4;

void TIM4_IRQHandler(void)
{ 
  if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) 
  {
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    //     定时器3设置： （注意数值减1）1ms中断：100 ； 2ms中断为200；依次类推 
    switch( time4_phaseflag ) {
     case FLAG_INITIAL:
      TIM4_Pri->ARR = 74 ; // 0.7496ms
      time4_phaseflag = FLAG_IDLING;
      break;
      
     case FLAG_IDLING:
      TIM4_Pri->ARR = 150;//117 ; // 1.1704ms
      //TIM4_Pri->ARR = 300 ; // 3ms
      MS5611_SendData(0x52); //Command ConvertD2 (OSR=512)
      time4_phaseflag = FLAG_D2_CONVERTING;
   //  printf("1\n\r");
      break;
      
     case FLAG_D2_CONVERTING:
      TIM4_Pri->ARR = 1000; // 0.74ms
      MS5611_SendData(0x00);
      D2_1 = Read_AdcData();
      MS5611_SendData(0x48); //Command ConvertD1 (OSR=4096)
      time4_phaseflag = FLAG_D1_CONVERTING_1ST;
      break;
      
     case FLAG_D1_CONVERTING_1ST:   
      TIM4_Pri->ARR = 1000; // 9.04ms   
      MS5611_SendData(0x00);
      D1_1 = Read_AdcData();     
      MS5611_SendData(0x48); ; //Command ConvertD1 (OSR=4096)
      time4_phaseflag = FLAG_D1_CONVERTING_2ND;
      break;
      
     case FLAG_D1_CONVERTING_2ND:
      TIM4_Pri->ARR = 74 ; // 0.7496ms
      MS5611_SendData(0x00);
      D1_2 = Read_AdcData();
      ms5611_flag=1;
      time4_phaseflag = FLAG_IDLING; 
   //   printf("D1_2:%d\r",D1_2); 
   //    printf("4\n\r");
      break;
    }  
  }    
}



/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f40xx.s/startup_stm32f427x.s).                         */
/******************************************************************************/

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT AOYIWEIYENG *****END OF FILE****/
