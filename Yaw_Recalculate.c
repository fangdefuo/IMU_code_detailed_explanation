#include "Yaw_Recalculate.h"

float Yaw_Angle;

//����ǳ�����н�ϵش��������
void Yaw_Recalculate(void)
{
  float Mag_Bxc,Mag_Byc;
  float calibrated_hx = pAHRS_Data_filtered->magX;//����������������Ҫ�뵽�������������㺽��ǵ�
  float calibrated_hy = pAHRS_Data_filtered->magY;
  float cPHI= cos(pAHRS_Data_filtered->Roll);
  float sPHI= sin(pAHRS_Data_filtered->Roll);
  Mag_Bxc = calibrated_hx * cos(pAHRS_Data_filtered->Pitch) + (calibrated_hy * sPHI + pAHRS_Data_filtered->magZ* cPHI) * sin(pAHRS_Data_filtered->Pitch);
  Mag_Byc = calibrated_hy * cPHI - pAHRS_Data_filtered->magZ * sPHI;
  Yaw_Angle= atan2(Mag_Byc,-Mag_Bxc);
  
  pAHRS_Data_filtered->Yaw = Yaw_Angle;
}