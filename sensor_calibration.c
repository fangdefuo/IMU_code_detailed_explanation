#include"sensor_calibration.h"
#include "argument_config.h"


u16 Calib_Command_Chose_Pre=0;
u16 first_flag=0;

void HMC5983L_Start_CalibXY(void)
{
  HMC5983_calibxy = 1;
  HMC5983_maxx = -2048;
  HMC5983_maxy = -2048; 
  HMC5983_minx = 2047;
  HMC5983_miny = 2047;
}
void HMC5983L_Start_CalibZ(void)
{
  HMC5983_calibz = 1;
  HMC5983_maxz = -2048; 
  HMC5983_minz = 2047;
}

void HMC5983L_Save_CalibXY(void){
  //将磁力计标定值写入 Flash 保存
  Config.dMx_offset = (HMC5983_maxx+HMC5983_minx)/2;
  Config.dMy_offset = (HMC5983_maxy+HMC5983_miny)/2;
  //Config.dMz_offset = 0;
  Config.dMx_min = HMC5983_minx;
  Config.dMy_min = HMC5983_miny;
  //Config.dMz_min = 0;
  Config.dMx_max = HMC5983_maxx;
  Config.dMy_max = HMC5983_maxy;
  //Config.dMz_max = 0;
  Config.Mag_is_good = 0xF7;
  EEPROM_Write_Config();	 //将当前配置写入
  HMC5983_calibxy=0; //结束标定
}	//HMC5983L_Save_Calib()

void HMC5983L_Save_CalibZ(void)
{
  //将磁力计标定值写入 Flash 保存
  Config.dMz_offset = (HMC5983_maxz+HMC5983_minz)/2;
  Config.dMz_min = HMC5983_minz;
  Config.dMz_max = HMC5983_maxz;
  Config.Mag_is_good = 0xA66A;
  Config.Mag_is_good = 0xF8;
  EEPROM_Write_Config();	 //将当前配置写入
  HMC5983_calibz=0; //结束标定
}


void HMC5983L_Stop_CalibXY(void)
{
  HMC5983_calibxy=0; 
  HMC5983_maxx = -2048;	
  HMC5983_maxy = -2048; 
  HMC5983_minx = 2047;
  HMC5983_miny = 2047;
}

void HMC5983L_Calib(void)
{    
  if(HMC5983L_Start_CalibXY_Flag) 
  { 
    HMC5983L_Start_CalibXY();
    Calib_Command_Chose_Pre = Calib_Command_Chose;
  }
  if(HMC5983L_Save_CalibXY_Flag) 
  { 
    Config.MAGXY_factor=HMC5983_XYFactor_Check_APutout();
    if(fabs(Config.MAGXY_factor-1.0)<0.1)
    {  
      HMC5983L_Save_CalibXY();
      mag_factor_Healthstate=MAG_FACTOR_NORMAL;
    }  
    else
    {
      Config.MAGXY_factor=1.0;
      HMC5983L_Stop_CalibXY();
      mag_factor_Healthstate=MAG_FACTOR_ABNORMAL;
    }
    LED_STEST_State(1);
    Calib_Command_Chose_Pre=Calib_Command_Chose;
  }
  if((mag_factor_Healthstate==MAG_FACTOR_NORMAL)&&(Commandbit14==1)&&HMC5983L_Start_CalibZ_Flag) 
  {
    LED_STEST_State(0);
    HMC5983L_Start_CalibZ();
    Calib_Command_Chose_Pre=Calib_Command_Chose;
  }
  if((mag_factor_Healthstate==MAG_FACTOR_NORMAL)&&HMC5983L_Save_CalibZ_Flag)
  { 
    //  Config.MAGXZ_factor=HMC5983_XZFactor_Check_APutout();
    HMC5983L_Save_CalibZ();
    Calib_Command_Chose_Pre=Calib_Command_Chose;
  } 
}

u32 offset_sumx=0,offset_sumy=0,offset_sumz=0;

void ACC_Calib(void)
{  
  u16 i;
  if(ACC_Start_Calib_Flag)
  {
    for(i=0;i<50;i++) AD_To_RawAhrs();
    for(i=0;i<1000;i++)
    {
      AD_To_RawAhrs();
      //delay_us(2000);
      offset_sumx+=pAHRS_Data_raw->Xacc;
      offset_sumy+=pAHRS_Data_raw->Yacc;
      offset_sumz+=pAHRS_Data_raw->Zacc;
    } 
    Calib_Command_Chose_Pre=Calib_Command_Chose;
  } 
  if(ACC_Save_Calib_Flag)
  {
    Config.dAx_offset=(u16)(offset_sumx/1000);
    Config.dAy_offset=(u16)(offset_sumy/1000);
    Config.dAz_offset=(u16)(offset_sumz/1000)+979;  
    Config.Acc_is_good=0xA66A;
    Config.Mag_is_good = 0xF9;
    EEPROM_Write_Config();
    Calib_Command_Chose_Pre=Calib_Command_Chose;
  }
  
}

void Is_In_Sensor_Calib_State(void)
{
  //HMC5983L_Calib();
  ACC_Calib();
}

float HMC5983_XYFactor_Check_APutout(void)
{      
  float factor,magxd,magyd;
  magxd=HMC5983_maxx-HMC5983_minx;
  magyd=HMC5983_maxy-HMC5983_miny; 
  if(magxd==0) return 0.0;
  if(magyd==0) return 0.0;
  factor=magxd/magyd;  
  return factor;
}

float HMC5983_XZFactor_Check_APutout(void)
{      
  float factor,magxd,magzd;
  magxd=HMC5983_maxx-HMC5983_minx;
  magzd=HMC5983_maxz-HMC5983_minz; 
  if(magxd==0) return 0.0;
  if(magzd==0) return 0.0;
  factor=magxd/magzd;  
  return factor;
}
