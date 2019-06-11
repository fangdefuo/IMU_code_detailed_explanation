#include "Yaw_Recalculate.h"

float Yaw_Angle;

//航向角冲计算中结合地磁来计算的
void Yaw_Recalculate(void)
{
  float Mag_Bxc,Mag_Byc;
  float calibrated_hx = pAHRS_Data_filtered->magX;//看见这两个向量就要想到它们是用来计算航向角的
  float calibrated_hy = pAHRS_Data_filtered->magY;
  float cPHI= cos(pAHRS_Data_filtered->Roll);
  float sPHI= sin(pAHRS_Data_filtered->Roll);
  Mag_Bxc = calibrated_hx * cos(pAHRS_Data_filtered->Pitch) + (calibrated_hy * sPHI + pAHRS_Data_filtered->magZ* cPHI) * sin(pAHRS_Data_filtered->Pitch);
  Mag_Byc = calibrated_hy * cPHI - pAHRS_Data_filtered->magZ * sPHI;
  Yaw_Angle= atan2(Mag_Byc,-Mag_Bxc);
  
  pAHRS_Data_filtered->Yaw = Yaw_Angle;
}