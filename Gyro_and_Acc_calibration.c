#include "Gyro_and_Acc_calibration.h"
#include "argument_config.h"
#include "eeprom.h"


uint16_t Gyro_and_Acc_Calibration_Operation_Step = 0;
void Gyro_and_Acc_Calibration_Operation()
{
  switch(Gyro_and_Acc_Calibration_Operation_Step)
  {
  case GYRO_AND_ACC_CALIBRATION_STATE:
    break;
    
  case ACC_CALIBRATION_SAVE_STATE:
    if(((pAcc_Calidata->Offset_X > -1.0)&&(pAcc_Calidata->Offset_X < 1.0))
       &&((pAcc_Calidata->Offset_Y > -1.0)&&(pAcc_Calidata->Offset_Y < 1.0))
         &&((pAcc_Calidata->Offset_Z > -1.0)&&(pAcc_Calidata->Offset_Z < 1.0)))    
    {
      Config.dAx_offset = pAcc_Calidata->Offset_X;
      Config.dAy_offset = pAcc_Calidata->Offset_Y;
      Config.dAz_offset = pAcc_Calidata->Offset_Z;
      Config.dAx_K = pAcc_Calidata->Kx;
      Config.dAy_K = pAcc_Calidata->Ky;
      Config.dAz_K = pAcc_Calidata->Kz;
      Config.Acc_is_good = 0xA66A;
      Config.Mag_is_good = 0xF4;
      EEPROM_Write_Config();
    }    
    break;
    
  case GYRO_CALIBRATION_SAVE_STATE:
    if((pGyro_Calidata->Kx > 0.9)&&(pGyro_Calidata->Kx < 1.1)
       &&(pGyro_Calidata->Ky > 0.9)&&(pGyro_Calidata->Ky < 1.1)
         &&(pGyro_Calidata->Kz > 0.9)&&(pGyro_Calidata->Kz < 1.1))
    { 
      Config.dGx_K = pGyro_Calidata->Kx;
      Config.dGy_K = pGyro_Calidata->Ky;
      Config.dGz_K = pGyro_Calidata->Kz;
      Config.Gyro_is_good = 0xA66A;
      Config.Mag_is_good = 0xF5;
      EEPROM_Write_Config();
    }
    break;
    
  case ERASE_FLASH_STATE:
    Config.Acc_is_good = 0x00;
    Config.dAx_offset = 0.0;	
    Config.dAy_offset = 0.0;
    Config.dAz_offset = 0.0;
    Config.dAx_K = 1.0;	
    Config.dAy_K = 1.0;
    Config.dAz_K = 1.0;
    
    Config.Gyro_is_good = 0x00;    
    Config.dGx_offset = 0.0;	
    Config.dGy_offset = 0.0;
    Config.dGz_offset = 0.0;    
    Config.dGx_K = 1.0;	
    Config.dGy_K = 1.0;
    Config.dGz_K = 1.0;
    Config.Mag_is_good = 0xF6;
    EEPROM_Write_Config();
    break;
  case CALIBRATEDDATA_FEEDBACK:
    //IMU_HEALTH_1STATE = (IMU_HEALTH_1STATE&0x0FFF)|((Gyro_and_Acc_Calibration_Operation_Step&0x000F)<<12);
    CAN2_Send_IMUFlash50Hz_Msg();
    break;    
  };  
}