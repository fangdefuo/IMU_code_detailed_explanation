/**
  ******************************************************************************
  * @file    control.c
  * @author  UAV Application Team
  * @version V2.1.0
  * @date    23-September-2014
  * @brief   此文件主要定义控制函数
  ******************************************************************************  
  * @device  Master---STM32F405RGT6
  ******************************************************************************  
*/  
#include "control.h"

u8 sys_state = 0;
u8 Control_Mode = 0;
d_Motor Motor={0,0,0,0,0,0,0,0};
d_Motor *pMotor = &Motor;
d_ReceiverData_Raw pReceiverData;
d_ReceiverData_Raw *pReceiverData_Raw =&pReceiverData;
extern u8 AHRS_EKF_ON;
extern u8 Attitude_Control_ON;
float AHRS_Initial_Mag_heading;

Gyro_Data  Gyro_zero;
Gyro_Data  *pGyro_zero=&Gyro_zero;

float Rollrate_Zero_Sampling[20]={0};
float Pitchrate_Zero_Sampling[20]={0};
float Yawrate_Zero_Sampling[20]={0};

void GetGyroZero(void)
{
   static u8 Gyro_i=0;
   Rollrate_Zero_Sampling[Gyro_i] = pAHRS_Data->RollRate;
   Pitchrate_Zero_Sampling[Gyro_i] = pAHRS_Data->PitchRate;
   Yawrate_Zero_Sampling[Gyro_i] = pAHRS_Data->YawRate;
   Gyro_i++;
   if (Gyro_i > 19)
   {
      Gyro_i = 0;
   }
}
void OffSetGyro(void)
{
   float Rollrate_Zero_temp = 0.0,Pitchrate_Zero_temp = 0.0,Yawrate_Zero_temp = 0.0;
   u8 j;
      for (j=0;j<20;j++)
      {
         Rollrate_Zero_temp += Rollrate_Zero_Sampling[j];
         Pitchrate_Zero_temp += Pitchrate_Zero_Sampling[j];
         Yawrate_Zero_temp += Yawrate_Zero_Sampling[j];
      }
      pGyro_zero->RollRate = (Rollrate_Zero_temp/20.0);
      pGyro_zero->PitchRate = (Pitchrate_Zero_temp/20.0);
      pGyro_zero->YawRate = (Yawrate_Zero_temp/20.0);
}
void Adjust_SendMotorData (d_Motor *Data)
{
      
      Data->FL	=(s16)((pReceiverData_Raw->Throttle-860)*0.87 + 1250);
      Data->FR	=(s16)((pReceiverData_Raw->Throttle-860)*0.87 + 1250);
      Data->BR	=(s16)((pReceiverData_Raw->Throttle-860)*0.87 + 1250);
      Data->BL	=(s16)((pReceiverData_Raw->Throttle-860)*0.87 + 1250);
      
      TIM_SetCompare1(TIM8,Data->FL);
      TIM_SetCompare2(TIM8,Data->FR);
      TIM_SetCompare3(TIM8,Data->BR);
      TIM_SetCompare4(TIM8,Data->BL);     
}


void Controll(void)
{
  if( sys_state==0 )
  {
    GetGyroZero();
    OffSetGyro();  
    Control_Mode = 0;
    if(AHRS_EKF_ON == 1)
    {
      AHRS_EKF_Init();
      AHRS_EKF_ON = 0;
    }
  }
  if( sys_state==1 )
  {
    Control_Mode = 0;
    AHRS_Compensate=0.0;
    mrsmc_Roll_Pitch_Init();
    mrsmc_Yaw_Init();
    pTheta->Roll =0.0;
    pTheta->Pitch =0.0;
    pTheta->Yaw =0.0;
    
    if(AHRS_EKF_ON == 1)
    { 
      AHRS_EKF();
      AHRS_Initial_Mag_heading = pAHRS_Data->Yaw;
      AHRS_Yaw_pre = pAHRS_Data->Yaw;
      AHRS_EKF_ON = 0;
    }
  }   
  if (sys_state==2)
  {     
    Data_Processing();
    
    if(AHRS_EKF_ON == 1)
    {
     AHRS_EKF();
     AHRS_EKF_ON = 0;

    }
    if(Attitude_Control_ON == 1)
    {
      mrsmc_Roll_Pitch();
      mrsmc_Yaw();
      Attitude_Control_ON = 0;
    }
    //pStabilize_Reference->Yaw   =  pReceiverData_Raw->Yaw;
    if(pReceiverData_Raw->Switch_G==2400) 
    {
      pStabilize_Reference->Roll  =  pReceiverData_Raw->Roll;
      pStabilize_Reference->Pitch =  pReceiverData_Raw->Pitch;
      pStabilize_Reference->Yaw   =  pReceiverData_Raw->Yaw;
    }  
    stabilize_control();   
  }   
 SendMotorData(pMotor); 
  
}

void SendMotorData (d_Motor *Data)
{
   switch(sys_state){
      
   case 0:
     PrepareMotorData2(1250);
     LED_STEST1_State(OFF);
     LED_STEST2_State(OFF);
     break;
      
   case 1:
     PrepareMotorData2(1250);
     LED_STEST1_State(OFF);
     LED_STEST2_State(ON);
     break;
     
   case 2:
     LED_STEST1_State(ON);
     LED_STEST2_State(ON);
       
      /*pwm1,2,3,4*/          
      TIM_SetCompare1(TIM8,Data->FL);//1
      TIM_SetCompare2(TIM8,Data->FR);//2
      TIM_SetCompare3(TIM8,Data->FR_Ail);//3
      TIM_SetCompare4(TIM8,Data->BR);//4
      /*pwm5,6,7,8*/          
      TIM_SetCompare2(TIM1,Data->BL);//5
      TIM_SetCompare3(TIM1,Data->BL_Ail);//6
      //TIM_SetCompare3(TIM1,Data->BR);
      //TIM_SetCompare4(TIM1,Data->BL);    
      break;
  
   case 3:       
     Data->FL	=(s16)((pReceiverData_Raw->Throttle-860)*0.87 + 1250);
     Data->FR	=(s16)((pReceiverData_Raw->Throttle-860)*0.87 + 1250);
     Data->BR	=(s16)((pReceiverData_Raw->Throttle-860)*0.87 + 1250);
     Data->BL	=(s16)((pReceiverData_Raw->Throttle-860)*0.87 + 1250);
     TIM_SetCompare1(TIM8,Data->FL);
     TIM_SetCompare2(TIM8,Data->FR);
     TIM_SetCompare3(TIM8,Data->BR);
     TIM_SetCompare4(TIM8,Data->BL);     
     break;
      
   default:
     sys_state = 0;
     LED_STEST1_State(OFF);
     LED_STEST2_State(OFF);
     break;  
   }
}


void PrepareMotorData2(uint16_t data)
{
  /* PWM1,2,3,4 */ 
   TIM_SetCompare1(TIM8,1250);
   TIM_SetCompare2(TIM8,1250);
   TIM_SetCompare3(TIM8,1250);
   TIM_SetCompare4(TIM8,1250);
  /* PWM5,6,7,8 */  
   TIM_SetCompare1(TIM1,1250);
   TIM_SetCompare2(TIM1,1250);
   TIM_SetCompare3(TIM1,1250);
   TIM_SetCompare4(TIM1,1250);
}

/************************ (C) COPYRIGHT AOYIWEIYENG *****END OF FILE***********/
