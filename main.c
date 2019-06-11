/**
******************************************************************************
* @file    SLAVER/STM32F4xx_StdPeriph_V1.3.0/main.c
* @author  UAV Application Team: xujinqi/guzetao/panjiadi
* @version V2.1.0
* @date    23-September-2014
* @brief   Main program body
******************************************************************************
* @device  Master---STM32F405RGT6
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "main.h"


#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
uint16_t data_transmit;
extern u8 ms5611_flag;
RCC_ClocksTypeDef RCC_Clocks;
u8 count=0,twinkle=0;
s16 gyro,gyro_filter;
u32 count1=0;
u16 j;
extern d_GPS_Data *pGPS_Data;
u8 GPSDATA_START=1;
u8 GPSDATA_START_COUNT=0,STAR_NUM_PRE=0;

int main(void)
{
  RCC_GetClocksFreq(&RCC_Clocks);
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  LED_IO_Toggle_init();
  //Out_Direction_init();
  //UART4_DMA_CGPS_init();
  //USART1_DMA_CFCS_init(230400);
  ADC_DMA_init();
  delay_us(60000);
  Init_HMC5983();
  //HMC5983_Configure();
  delay_us(60000);
  MS5611_init();
  delay_us(60000);
  MS5611_TIM_init();
  //MOTOR_Configure();
  delay_us(60000);
  CAN_IMUmag_Configure();//解码获取数据
  CAN_IMUmotor_Configure();
  CAN_IMUcalidevice_Configure();
#if defined AUTO_CALIB
  EEPROM_Loading_Config();
#endif
  delay_us(60000);
  Gyroad_Initial_Offset();
  Filter_Tim2_init();
  //GPS_Configure();
  Main_Tim3_init();
  CAN2_Mode_Init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,6,CAN_Mode_Normal);//CAN1  500Kbps

  EEPROM_Loading_DeviceInformation();

  /////////////////////////////// IMU自检 + AHRS初始化 ////////////////////////////
  while(1)
  {
    if(CAN_IMUmag_IsReadyToRead())////解码
      CAN_IMUmag_Update();
    if(CAN_IMUcalidevice_IsReadyToRead())
      CAN_IMUcalidevice_Update();
    if(CAN_IMUmotor_IsReadyToRead())
      CAN_IMUmotor_Update();
    if(ms5611_flag==1){
      ms5611_update();
      ms5611_flag=0; }

    if(time3_flag_400hz)
    {
      time3_flag_400hz=0;
      IMU_Health_SelfCheck();
      if(isIMUReady())
      {
        AHRS_EKF_Init();
        LED_STEST1_State(0);
        break;
      }
      CAN2_Send_IMU400Hz_Msg();
    }
    if(time3_flag_50hz)
    {
      time3_flag_50hz=0;
      if((count++)%10==1)
        twinkle=1;
      else twinkle=0;
      LED_STEST1_State(twinkle);
      CAN2_Send_IMU50Hz_Msg();
      Gyro_and_Acc_Calibration_Operation();
    }
  }

  ///////////////////////////////////// 主程序 /////////////////////////////////
  while (1)
  {
    if(CAN_IMUmag_IsReadyToRead())//解码
      CAN_IMUmag_Update();
    if(CAN_IMUcalidevice_IsReadyToRead())
      CAN_IMUcalidevice_Update();
    if(CAN_IMUmotor_IsReadyToRead())
      CAN_IMUmotor_Update();
    if(ms5611_flag==1){
      ms5611_update();
      ms5611_flag=0;//更新完了之后要把标志位变0
    }

    if(time3_flag_400hz)
    {
      //LED_STEST_State(1);
      time3_flag_400hz=0;
      IMU_Health_Check();
      CAN2_Send_IMU400Hz_Msg();
      //LED_STEST_State(0);
    }

    if(time3_flag_200hz)
    {
      time3_flag_200hz=0;
      Mag_Caculated_AHRS_ReInit();

    }

    if(time3_flag_100hz){
      time3_flag_100hz=0;}

    if(time3_flag_50hz)
    {
        LED_STEST_State(1);
      time3_flag_50hz=0;
      if((Calib_Command_Chose>>15)==0)
      {
        if((count++)%10==1)
          twinkle=1;
        else twinkle=0;
        //LED_STEST_State(twinkle);
      }
      AHRS_EKF();
      //Is_In_Sensor_Calib_State();
      CAN2_Send_IMU50Hz_Msg();
      Gyro_and_Acc_Calibration_Operation();
      LED_STEST_State(0);
    }
  }
}

void GPSDATA_IsReadyToStart(void)
{
  if(GPSDATA_START_COUNT<50)
  {
    if(pGPS_Data->Star_Num>=7)
    {
      if((pGPS_Data->Star_Num>=7)&&(STAR_NUM_PRE>=7))
      {
        GPSDATA_START_COUNT++;
      }
    }
    else
    {
      GPSDATA_START_COUNT=0;
    }
  }
  else
  {
    GPSDATA_START=1;
  }
  STAR_NUM_PRE=(u8)pGPS_Data->Star_Num;
}

void IO_init(void)
{
  //SLAVE RX口用作测试口//
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_InitTypeDef  GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOC, GPIO_Pin_6);
  GPIO_ResetBits(GPIOC, GPIO_Pin_7);
}
void Out_Direction_init()
{
#if defined toFC
  USART6_DMA_CFCM_init(230400);
#endif
#if defined  toSHOW
  USART6_DMA_CFCM_init(57600);
#endif
#if defined  GPIOTEST
  IO_init();
#endif
}

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART6, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART6, USART_FLAG_TC) == RESET)
  {}

  return ch;
}


#ifdef  USE_FULL_ASSERT

/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  file: pointer to the source file name
* @param  line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/************************ (C) COPYRIGHT AOYIWEIYENG *****END OF FILE***********/
