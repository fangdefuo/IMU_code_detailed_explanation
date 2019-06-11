
#include "filter.h"
#include "Library_Filter.h"
extern u8 data_gps_flag;
u16 RollRate_Offset_Dynamic=0;
u16 PitchRate_Offset_Dynamic=0;
u16 YawRate_Offset_Dynamic=0;
IMU_Data  AHRS_Data_Decode;
IMU_Data  *pAHRS_Data_Decode = &AHRS_Data_Decode;

IMU_Data  AHRS_Data_raw;
IMU_Data  *pAHRS_Data_raw = &AHRS_Data_raw;

IMU_Data  AHRS_Data;
IMU_Data  *pAHRS_Data = &AHRS_Data;

IMU_Data  AHRS_Data_old;
IMU_Data  *pAHRS_Data_old=&AHRS_Data_old;

IMU_Data  AHRS_Data_pre_old;
IMU_Data  *pAHRS_Data_pre_old=&AHRS_Data_pre_old;

IMU_Data  AHRS_Data_low_filtered;
IMU_Data  *pAHRS_Data_low_filtered=&AHRS_Data_low_filtered;

IMU_Data  AHRS_Data_filtered_old;
IMU_Data  *pAHRS_Data_filtered_old=&AHRS_Data_filtered_old;

IMU_Data  AHRS_Data_filtered_pre_old;
IMU_Data  *pAHRS_Data_filtered_pre_old=&AHRS_Data_filtered_pre_old;

IMU_Data  AHRS_Data_filtered;
IMU_Data  *pAHRS_Data_filtered=&AHRS_Data_filtered;

IMU_Data  AHRS_Data_high_old;
IMU_Data  *pAHRS_Data_high_old=&AHRS_Data_high_old;

IMU_Data  AHRS_Data_high_pre_old;
IMU_Data  *pAHRS_Data_high_pre_old=&AHRS_Data_high_pre_old;

IMU_Data  AHRS_Data_high_filtered;
IMU_Data  *pAHRS_Data_high_filtered=&AHRS_Data_high_filtered;

IMU_Data  AHRS_Data_high_filtered_old;
IMU_Data  *pAHRS_Data_high_filtered_old=&AHRS_Data_high_filtered_old;

IMU_Data  AHRS_Data_high_filtered_pre_old;
IMU_Data  *pAHRS_Data_high_filtered_pre_old=&AHRS_Data_high_filtered_pre_old;

IIR_coeff_Typedef sAccCoeff[3]={{16,-1.98578301154,0.98588336209,0.00002508763,0.00005017528,0.00002508764,0,0},{16,-1.98578301154,0.98588336209,0.00002508763,0.00005017528,0.00002508764,0,0},{16,-1.98578301154,0.98588336209,0.00002508763,0.00005017528,0.00002508764,0,0}};
IIR_coeff_Typedef* psAccXCoeff = &sAccCoeff[0];
IIR_coeff_Typedef* psAccYCoeff = &sAccCoeff[1];
IIR_coeff_Typedef* psAccZCoeff = &sAccCoeff[2];

IIR_coeff_Typedef sGyroCoeff[3]={{30,-1.973344250,0.973694872,0.0000876555,0.0001753110,0.0000876555,0,0},{30,-1.973344250,0.973694872,0.0000876555,0.0001753110,0.0000876555,0,0},{30,-1.973344250,0.973694872,0.0000876555,0.0001753110,0.0000876555,0,0}};
IIR_coeff_Typedef* psGyroXCoeff = &sGyroCoeff[0];
IIR_coeff_Typedef* psGyroYCoeff = &sGyroCoeff[1];
IIR_coeff_Typedef* psGyroZCoeff = &sGyroCoeff[2];


void AD_To_RawAhrs()
{
  pAHRS_Data_raw->Xacc= ADCConvertedValue1[0];
  pAHRS_Data_raw->Yacc= ADCConvertedValue1[1];
  pAHRS_Data_raw->Zacc= ADCConvertedValue1[3];
  pAHRS_Data_raw->RollRate= ADCConvertedValue1[4];
  pAHRS_Data_raw->PitchRate= ADCConvertedValue1[5];
  pAHRS_Data_raw->YawRate= ADCConvertedValue1[6];
}
//原始数据不滤波

void ADC_data_filter()
{
  pAHRS_Data_filtered->Xacc = get_iir_output(psAccXCoeff,pAHRS_Data->Xacc);
  pAHRS_Data_filtered->Yacc = get_iir_output(psAccYCoeff,pAHRS_Data->Yacc);
  pAHRS_Data_filtered->Zacc = get_iir_output(psAccZCoeff,pAHRS_Data->Zacc);

  pAHRS_Data_filtered->RollRate     = get_iir_output(psGyroXCoeff,pAHRS_Data->RollRate);
  pAHRS_Data_filtered->PitchRate    = get_iir_output(psGyroYCoeff,pAHRS_Data->PitchRate);
  pAHRS_Data_filtered->YawRate      = get_iir_output(psGyroZCoeff,pAHRS_Data->YawRate);

//
//  pAHRS_Data_filtered->Xacc    =  (Acc_b1*pAHRS_Data->Xacc + Acc_b2*pAHRS_Data_old->Xacc + Acc_b3*pAHRS_Data_pre_old->Xacc - Acc_a2 * pAHRS_Data_filtered_old->Xacc - Acc_a3*pAHRS_Data_filtered_pre_old->Xacc);
//  pAHRS_Data_filtered->Yacc    =  (Acc_b1*pAHRS_Data->Yacc + Acc_b2*pAHRS_Data_old->Yacc + Acc_b3*pAHRS_Data_pre_old->Yacc - Acc_a2 * pAHRS_Data_filtered_old->Yacc - Acc_a3*pAHRS_Data_filtered_pre_old->Yacc);
//  pAHRS_Data_filtered->Zacc    =  (Acc_b1*pAHRS_Data->Zacc + Acc_b2*pAHRS_Data_old->Zacc + Acc_b3*pAHRS_Data_pre_old->Zacc - Acc_a2 * pAHRS_Data_filtered_old->Zacc - Acc_a3*pAHRS_Data_filtered_pre_old->Zacc);
//
//  pAHRS_Data_filtered->RollRate   =(Gyro_b1*pAHRS_Data->RollRate  + Gyro_b2*pAHRS_Data_old->RollRate  + Gyro_b3*pAHRS_Data_pre_old->RollRate  - Gyro_a2* pAHRS_Data_filtered_old->RollRate  - Gyro_a3*pAHRS_Data_filtered_pre_old->RollRate);
//  pAHRS_Data_filtered->PitchRate  =(Gyro_b1*pAHRS_Data->PitchRate + Gyro_b2*pAHRS_Data_old->PitchRate + Gyro_b3*pAHRS_Data_pre_old->PitchRate - Gyro_a2* pAHRS_Data_filtered_old->PitchRate - Gyro_a3*pAHRS_Data_filtered_pre_old->PitchRate);
//  pAHRS_Data_filtered->YawRate    =(Gyro_b1*pAHRS_Data->YawRate   + Gyro_b2*pAHRS_Data_old->YawRate   + Gyro_b3*pAHRS_Data_pre_old->YawRate   - Gyro_a2* pAHRS_Data_filtered_old->YawRate   - Gyro_a3*pAHRS_Data_filtered_pre_old->YawRate);
//
//  pAHRS_Data_pre_old->RollRate=pAHRS_Data_old->RollRate;
//  pAHRS_Data_old->RollRate=pAHRS_Data->RollRate;
//
//  pAHRS_Data_pre_old->PitchRate=pAHRS_Data_old->PitchRate;
//  pAHRS_Data_old->PitchRate=pAHRS_Data->PitchRate;
//
//  pAHRS_Data_pre_old->YawRate=pAHRS_Data_old->YawRate;
//  pAHRS_Data_old->YawRate=pAHRS_Data->YawRate;
//
//  pAHRS_Data_pre_old->Xacc=pAHRS_Data_old->Xacc;
//  pAHRS_Data_old->Xacc=pAHRS_Data->Xacc;
//
//  pAHRS_Data_pre_old->Yacc=pAHRS_Data_old->Yacc;
//  pAHRS_Data_old->Yacc=pAHRS_Data->Yacc;
//
//  pAHRS_Data_pre_old->Zacc=pAHRS_Data_old->Zacc;
//  pAHRS_Data_old->Zacc=pAHRS_Data->Zacc;
//
//  pAHRS_Data_filtered_pre_old->RollRate=pAHRS_Data_filtered_old->RollRate;
//  pAHRS_Data_filtered_old->RollRate=pAHRS_Data_filtered->RollRate;
//
//  pAHRS_Data_filtered_pre_old->PitchRate=pAHRS_Data_filtered_old->PitchRate;
//  pAHRS_Data_filtered_old->PitchRate=pAHRS_Data_filtered->PitchRate;
//
//  pAHRS_Data_filtered_pre_old->YawRate=pAHRS_Data_filtered_old->YawRate;
//  pAHRS_Data_filtered_old->YawRate=pAHRS_Data_filtered->YawRate;
//
//  pAHRS_Data_filtered_pre_old->Xacc=pAHRS_Data_filtered_old->Xacc;
//  pAHRS_Data_filtered_old->Xacc=pAHRS_Data_filtered->Xacc;
//
//  pAHRS_Data_filtered_pre_old->Yacc=pAHRS_Data_filtered_old->Yacc;
//  pAHRS_Data_filtered_old->Yacc=pAHRS_Data_filtered->Yacc;
//
//  pAHRS_Data_filtered_pre_old->Zacc=pAHRS_Data_filtered_old->Zacc;
//  pAHRS_Data_filtered_old->Zacc=pAHRS_Data_filtered->Zacc;
//
}

void GyroAcc_RawData_Process()
{

  pAHRS_Data->Xacc=-(((pAHRS_Data_raw->Xacc - Xacc_Offset)*K_Xacc+Config.dAx_offset)*Config.dAx_K);
  pAHRS_Data->Yacc= (((pAHRS_Data_raw->Yacc - Yacc_Offset)*K_Yacc-Config.dAy_offset)*Config.dAy_K);
  pAHRS_Data->Zacc=-(((pAHRS_Data_raw->Zacc - Zacc_Offset)*K_Zacc+Config.dAz_offset)*Config.dAz_K);

  pAHRS_Data->RollRate= -(pAHRS_Data_raw->RollRate     -  RollRate_Offset_Dynamic)*K_RollRate*Config.dGx_K;
  pAHRS_Data->PitchRate= (pAHRS_Data_raw->PitchRate    -  PitchRate_Offset_Dynamic)*K_PitchRate*Config.dGy_K;
  pAHRS_Data->YawRate  = -(pAHRS_Data_raw->YawRate     -   YawRate_Offset_Dynamic)*K_YawRate*Config.dGz_K;

}

void TEST_GyroAcc_RawData_Process()
{
  pAHRS_Data_filtered->Xacc=-(pAHRS_Data_raw->Xacc - Xacc_Offset)*K_Xacc;
  pAHRS_Data_filtered->Yacc=-(pAHRS_Data_raw->Yacc - Yacc_Offset)*K_Yacc;
  pAHRS_Data_filtered->Zacc=(pAHRS_Data_raw->Zacc - Zacc_Offset)*K_Zacc;
  pAHRS_Data_filtered->RollRate = -(pAHRS_Data_raw->RollRate     -  RollRate_Offset_Dynamic)*K_RollRate;
  pAHRS_Data_filtered->PitchRate=  (pAHRS_Data_raw->PitchRate   -  PitchRate_Offset_Dynamic)*K_PitchRate;
  pAHRS_Data_filtered->YawRate  = -(pAHRS_Data_raw->YawRate       -   YawRate_Offset_Dynamic)*K_YawRate;
  //  pAHRS_Data_filtered->RollRate = -(pAHRS_Data_raw->RollRate  - RollRate_Offset   -  RollRate_Offset_Dynamic)*K_RollRate;
  // pAHRS_Data_filtered->PitchRate=  (pAHRS_Data_raw->PitchRate - PitchRate_Offset  -  PitchRate_Offset_Dynamic)*K_PitchRate;
  // pAHRS_Data_filtered->YawRate  = -(pAHRS_Data_raw->YawRate   - YawRate_Offset    -   YawRate_Offset_Dynamic)*K_YawRate;
}


void Gyroad_Initial_Offset(void)
{
  u16 i;
  u32 offset_sumx=0,offset_sumy=0,offset_sumz=0;

  for(i=0;i<50;i++)
  {
    delay_us(2000);
    AD_To_RawAhrs();

  }
  for(i=0;i<400;i++)
  {
    AD_To_RawAhrs();
    delay_us(1000);
    offset_sumx+=pAHRS_Data_raw->RollRate;
    offset_sumy+=pAHRS_Data_raw->PitchRate;
    offset_sumz+=pAHRS_Data_raw->YawRate;
  }

  RollRate_Offset_Dynamic=(u16)(offset_sumx/400);
  PitchRate_Offset_Dynamic=(u16)(offset_sumy/400);
  YawRate_Offset_Dynamic=(u16)(offset_sumz/400);

}


