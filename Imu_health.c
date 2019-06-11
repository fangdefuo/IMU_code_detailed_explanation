# include "Imu_health.h"
# include "math.h"
/**************************变量自定义********************************************
**************************变量定义********************************************
变量名1:	  IMU_HEALTH_STATE
   MSB|  16  |  15  |  14  |  13  |  12  |  11  |  10  |  9  |  8 |  7  |  6  |  5 |  4 |  3 | 2 | 1 |LSB 
0102:mag_Healthstate
0304:Starnum_Healthstate
0506:altitude_Healthstate
0708:acc_Healthstate
0910:gyro_Healthstate
1112:attitude_Healthstate
16:mag_factor_Healthstate
*******************************************************************************
*******************************************************************************/  

#define STARNUM_NORMAL  0
#define STARNUM_ABNORMAL 1
#define GPS_DISCONNECT  3

#define MAG_NORMAL      0
#define MAG_ABNORMAL    1
#define MAG_DISCONNECT  3

#define ACC_NORMAL      0
#define ACC_ABNORMAL    3

#define GYRO_NORMAL      0
#define GYRO_ABNORMAL    3

#define ALTITUDE_NORMAL      0
#define ALTITUDE_ABNORMAL    3

#define ATTITUDE_NORMAL      0
#define ATTITUDE_ABNORMAL    3

#define MAG_FACTOR_NORMAL      0
#define MAG_FACTOR_ABNORMAL    1

uint8_t    Starnum_Healthstate=0;
uint8_t    mag_Healthstate=0;
uint8_t    mag_factor_Healthstate=0;
uint8_t    acc_Healthstate=0;
uint8_t    gyro_Healthstate=0;
uint8_t    altitude_Healthstate=0;
uint8_t    attitude_Healthstate=0;
uint16_t   IMU_HEALTH_1STATE=0xFFFF;
uint16_t   IMU_HEALTH_2STATE=0x000f;
uint16_t   Star_normal_Count=0;
uint16_t   Star_abnormal_Count=0;
uint16_t   gps_disconnect_count=0;
uint16_t   mag_abnormal_count=0;
uint16_t   mag_normal_count=0;
uint16_t   mag_disconnect_count=0; 
uint16_t   acc_normal_count=0;
uint16_t   acc_abnormal_count=0;
uint16_t   gyro_normal_count=0;
uint16_t   gyro_abnormal_count=0;
uint16_t   Altitude_normal_count=0;
uint16_t   Altitude_abnormal_count=0;
uint16_t   Attitude_normal_count=0;
uint16_t   Attitude_abnormal_count=0;
uint16_t   Roll_Health_Check_Count = 0;
uint16_t   Pitch_Health_Check_Count = 0;                   




uint8_t  isIMUReady()
{
  if((acc_Healthstate==0)&&(gyro_Healthstate==0) && mag_Healthstate==0)
    return 1;
  else
    return 0;
}


void Self_Checkmassage_send()
{
    uint16_t msage_transmit;
    msage_transmit=error_data_type_toFCM();
    USART6_Data_Send_ToFCM(msage_transmit);
}
void IMU_Health_Check()
{ 
  Starnum_Health_Check();
  Mag_Health_Check();
  IMU_HEALTH_1STATE = ((Starnum_Healthstate<<2) | (mag_Healthstate));
  IMU_HEALTH_1STATE = (IMU_HEALTH_1STATE&0x0FFF)|((Gyro_and_Acc_Calibration_Operation_Step&0x000F)<<12);
}

void IMU_Health_SelfCheck()
{ 
  Mag_Health_Check();
  Starnum_Health_Check();
  Altitude_health_check();
  Acc_Health_Check();
  Gyro_Health_Check();
  Attitude_health_check();
 IMU_HEALTH_1STATE =(uint16_t)((attitude_Healthstate)<<10|(gyro_Healthstate<<8)|(acc_Healthstate<<6)|(altitude_Healthstate<<4)|(Starnum_Healthstate<<2) | (mag_Healthstate));
 IMU_HEALTH_1STATE = (IMU_HEALTH_1STATE&0x0FFF)|((Gyro_and_Acc_Calibration_Operation_Step&0x000F)<<12);
}


void Starnum_Health_Check()
{
  
 if(pGPS_Data->Star_Num > 5)
  {
    Star_abnormal_Count = 0;
    gps_disconnect_count=0;
    Star_normal_Count++;
    if(Star_normal_Count >= 20000) Star_normal_Count = 20000;
  }
  
  else if(pGPS_Data->Star_Num > 0)
  {
    Star_normal_Count = 0;
    gps_disconnect_count=0;
    Star_abnormal_Count++;
    if(Star_abnormal_Count >= 20000) Star_abnormal_Count = 20000;
  }
  
  else
  { 
    Star_normal_Count = 0;
    Star_abnormal_Count = 0;
    gps_disconnect_count++;
    if(gps_disconnect_count >= 20000) gps_disconnect_count = 20000;
  }
  
  
  if (Star_normal_Count >= 1000)            Starnum_Healthstate = STARNUM_NORMAL;
  else if(Star_abnormal_Count >= 1000)      Starnum_Healthstate = STARNUM_ABNORMAL;
  else                                      Starnum_Healthstate = GPS_DISCONNECT;
}


void Mag_Health_Check()
{
  
if (fabs(pAHRS_Data_filtered->magX) + fabs(pAHRS_Data_filtered->magY) + fabs(pAHRS_Data_filtered->magZ) <0.01)
{ 
    mag_abnormal_count=0;
    mag_normal_count=0;
    mag_disconnect_count++;  
    if(mag_disconnect_count >= 20000) mag_disconnect_count = 20000;
}
else if((fabs(pAHRS_Data_filtered->magX)>0.65)||(fabs(pAHRS_Data_filtered->magY)>0.65)||(fabs(pAHRS_Data_filtered->magZ)>0.65))
{
    mag_disconnect_count=0;
    mag_normal_count=0;
    mag_abnormal_count++;
    if(mag_abnormal_count >= 20000)  mag_abnormal_count = 20000; 
}
else
{   mag_disconnect_count=0;
    mag_abnormal_count=0;
    mag_normal_count++;
    if(mag_normal_count >= 20000)   mag_normal_count = 20000; 
}
if       (mag_normal_count >= 100)         mag_Healthstate = MAG_NORMAL;
else if  (mag_abnormal_count >=100)        mag_Healthstate = MAG_ABNORMAL;
else                                       mag_Healthstate = MAG_DISCONNECT;   
}
u8 l,p,q;
void Acc_Health_Check()
{  
 if((fabs(pAHRS_Data_filtered->Xacc)>3)||(fabs(pAHRS_Data_filtered->Yacc)>3)||(fabs(pAHRS_Data_filtered->Zacc+9.7949)>2.0))
{
    acc_normal_count=0;
    acc_abnormal_count++;
    if(acc_abnormal_count >= 20000)  acc_abnormal_count = 20000; 
}
else
{   
    acc_abnormal_count=0;
    acc_normal_count++;
    if(acc_normal_count >= 20000)   acc_normal_count = 20000; 
}
if(acc_normal_count >= 400)         acc_Healthstate = ACC_NORMAL;
else                                acc_Healthstate = ACC_ABNORMAL;

}


void Gyro_Health_Check()
{ 
 if((fabs(pAHRS_Data_filtered->RollRate)>0.1)||(fabs(pAHRS_Data_filtered->PitchRate)>0.1)||(fabs(pAHRS_Data_filtered->YawRate)>0.1))
{
    gyro_normal_count=0;
    gyro_abnormal_count++;
    if(gyro_abnormal_count >= 20000)  gyro_abnormal_count = 20000; 
}
else
{   
    gyro_abnormal_count=0;
    gyro_normal_count++;
    if(gyro_normal_count >= 20000)   gyro_normal_count = 20000; 
}
if(gyro_normal_count >= 400)       gyro_Healthstate = GYRO_NORMAL;
else                                gyro_Healthstate = GYRO_ABNORMAL;

}

void Altitude_health_check() 
{ if((MS5611_Altitude>=-300.0)&&(MS5611_Altitude<=300.0))
  {
    Altitude_abnormal_count=0;
    Altitude_normal_count++;
    if(Altitude_normal_count >= 20000)  Altitude_normal_count = 20000;
  }
    else
    {
    Altitude_normal_count=0;
    Altitude_abnormal_count++;
    if(Altitude_abnormal_count >= 20000)  Altitude_abnormal_count = 20000;
    }  
  if(Altitude_normal_count>=1000)
    altitude_Healthstate = ALTITUDE_NORMAL;
  else
    altitude_Healthstate = ALTITUDE_ABNORMAL;
  
    
}

void Attitude_health_check()
{
  if(pAHRS_Data_filtered->Roll<0.2 && pAHRS_Data_filtered->Roll>(-0.2) )
    Roll_Health_Check_Count++;
  else 
    Roll_Health_Check_Count = 0;
  
  if(pAHRS_Data_filtered->Pitch<0.2 && pAHRS_Data_filtered->Pitch>(-0.2))
    Pitch_Health_Check_Count++;
  else 
    Pitch_Health_Check_Count = 0;
  
  if(Roll_Health_Check_Count >= 20000) Roll_Health_Check_Count = 20000;
  if(Pitch_Health_Check_Count >= 20000) Pitch_Health_Check_Count = 20000;
  
  
  if ( Roll_Health_Check_Count>=1000 && Pitch_Health_Check_Count>=1000)
    attitude_Healthstate = ATTITUDE_NORMAL;
  else
    attitude_Healthstate = ATTITUDE_ABNORMAL;
}