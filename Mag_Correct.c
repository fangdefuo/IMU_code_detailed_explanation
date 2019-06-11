
#include"Mag_Correct.h" 

#define MAXIMUM_NUMBER_OF_ROTORS   6
#define NUM_OF_AXES   3
//#define dynamic_calibration
float x_offset=0.0;
float y_offset=0.0;
float z_offset=0.0;

u16 RotorInput[MAXIMUM_NUMBER_OF_ROTORS] = {0, 0, 0, 0, 0, 0};

void Mag_Correct()
{
 #if defined dynamic_calibration
  if(pMotor->FL>=1250)
  {
    RotorInput[0] = pMotor->FL-1250;
    RotorInput[1] = pMotor->FR-1250;
    RotorInput[2] = pMotor->FR_Ail-1250;
    RotorInput[3] = pMotor->BR-1250;
    RotorInput[4] = pMotor->BL-1250;
    RotorInput[5] = pMotor->BL_Ail-1250;
  }
  else
  {
    RotorInput[0] = 0;
    RotorInput[1] = 0;
    RotorInput[2] = 0;
    RotorInput[3] = 0;
    RotorInput[4] = 0;
    RotorInput[5] = 0;
  } 
  // 动态磁场校正
  
  //const int   NUM_OF_AXES = 3; // 轴数(XYZ)
  
  //const float m = 1.0 / 65536; // 尺寸系数
  
  float input1[MAXIMUM_NUMBER_OF_ROTORS];
  float input2[MAXIMUM_NUMBER_OF_ROTORS];
  float input3[MAXIMUM_NUMBER_OF_ROTORS];
  
  for( int i = 0; i < MAXIMUM_NUMBER_OF_ROTORS; i++ )
  {
    input1[i] = RotorInput[i];
    input2[i] = input1[i] * input1[i];
    input3[i] = input1[i] * input2[i];
  }
  
  float mag[3] = {0, 0, 0};
  
  float MATRIX1[NUM_OF_AXES][MAXIMUM_NUMBER_OF_ROTORS] = DYNAMICIRONMATRIX_1;
  float MATRIX2[NUM_OF_AXES][MAXIMUM_NUMBER_OF_ROTORS] = DYNAMICIRONMATRIX_2;
  float MATRIX3[NUM_OF_AXES][MAXIMUM_NUMBER_OF_ROTORS] = DYNAMICIRONMATRIX_3;
  
  for( int i = 0; i < NUM_OF_AXES; i++ )
  {
    
    float n = 0.0;
    for( int j = 0; j < MAXIMUM_NUMBER_OF_ROTORS; j++ ) 
    {
      n += MATRIX1[i][j] * input1[j] + MATRIX2[i][j] * input2[j] + MATRIX3[i][j] * input3[j];
    }
    
    mag[i] = n;
  }
   
  x_offset = mag[0];
  y_offset = mag[1];
  z_offset = mag[2];
#endif
  x_offset=x_offset + HIC_X;
  y_offset=x_offset + HIC_Y;
  z_offset=x_offset + HIC_Z;
  
//  pAHRS_Data_Decode->magX = pAHRS_Data_Decode->magX ; 
//  pAHRS_Data_Decode->magY = pAHRS_Data_Decode->magY ;
//  pAHRS_Data_Decode->magZ = pAHRS_Data_Decode->magZ ;
  
  //计算出经过滤波后三轴地磁的数据
  #if defined  AYDRONE_MAG
  pAHRS_Data_filtered->magX = (pAHRS_Data_Decode->magX- HIC_X);
  pAHRS_Data_filtered->magY = (pAHRS_Data_Decode->magY- HIC_Y)*HIC_Z_ADJ;
  pAHRS_Data_filtered->magZ = pAHRS_Data_Decode->magZ- HIC_Z;
  #elif defined  BEITIAN_MAG
  pAHRS_Data_filtered->magX = (pAHRS_Data_Decode->magX- HIC_X);
  pAHRS_Data_filtered->magY = (pAHRS_Data_Decode->magY- HIC_Y)*HIC_Z_ADJ;
  pAHRS_Data_filtered->magZ = pAHRS_Data_Decode->magZ- HIC_Z;
  #endif
}

