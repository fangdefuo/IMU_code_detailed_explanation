#ifndef __FC_COMMAND_DECODE_H
#define __FC_COMMAND_DECODE_H

#ifdef __cplusplus
 extern "C" {
#endif 
/**************************变量自定义********************************************
**************************变量定义********************************************
变量名1:	  Calib_Command_Chose
   MSB|  16  |  15  |  14  |  13  |  12  |  11  |  10  |  9  |  8 |  7  |  6  |  5 |  4 |  3 |  2 |  1 |LSB
BIT16: 判断是否有遥控器信号    
BIT15：判断是否校准地磁XY轴
BIT14：是否保存地磁XY轴矫正数据
BIT13：是否校准加速度计
BIT12：判断Z轴是否在+-1m/s/s 范围 并开始校准MGAZ数据
BIT11：undefined
BIT9： undefined
.....
BIT1： undefined
*输入参数：       输出数组指针	
*输出参数：       无  
*******************************************************************************
*******************************************************************************/   
#define  HMC5983L_Start_CalibXY_Flag  ((((Calib_Command_Chose_Pre&0x4000)>>14)==0)&&(((Calib_Command_Chose&0x4000)>>14)==1))
#define  HMC5983L_Save_CalibXY_Flag   ((((Calib_Command_Chose_Pre&0x2000)>>13)==0)&&(((Calib_Command_Chose&0x2000)>>13)==1)) 
#define  ACC_Start_Calib_Flag         ((((Calib_Command_Chose_Pre&0x1000)>>12)==0)&&(((Calib_Command_Chose&0x1000)>>12)==1))
#define  ACC_Save_Calib_Flag          ((((Calib_Command_Chose_Pre&0x1000)>>12)==1)&&(((Calib_Command_Chose&0x1000)>>12)==0))
#define  HMC5983L_Start_CalibZ_Flag   ((((Calib_Command_Chose_Pre&0x0800)>>11)==0)&&(((Calib_Command_Chose&0x0800)>>11)==1)) 
#define  HMC5983L_Save_CalibZ_Flag    (((Calib_Command_Chose_Pre>>15)==1)&&((Calib_Command_Chose>>15)==0)) 
   
#define  Commandbit1         ((Calib_Command_Chose&0x0001)>>0) 
#define  Commandbit2         ((Calib_Command_Chose&0x0002)>>1)
#define  Commandbit3         ((Calib_Command_Chose&0x0004)>>2)
#define  Commandbit4         ((Calib_Command_Chose&0x0008)>>3)
#define  Commandbit5         ((Calib_Command_Chose&0x0010)>>4)
#define  Commandbit6         ((Calib_Command_Chose&0x0020)>>5)
#define  Commandbit7         ((Calib_Command_Chose&0x0040)>>6)
#define  Commandbit8         ((Calib_Command_Chose&0x0080)>>7)
#define  Commandbit9         ((Calib_Command_Chose&0x0100)>>8)
#define  Commandbit10        ((Calib_Command_Chose&0x0200)>>9)   
#define  Commandbit11        ((Calib_Command_Chose&0x0400)>>10) 
#define  Commandbit12        ((Calib_Command_Chose&0x0800)>>11)
#define  Commandbit13        ((Calib_Command_Chose&0x1000)>>12)
#define  Commandbit14        ((Calib_Command_Chose&0x2000)>>13)
#define  Commandbit15        ((Calib_Command_Chose&0x4000)>>14)
#define  Commandbit16        ((Calib_Command_Chose&0x8000)>>15)   
   
#define  PRECommandbit1         ((Calib_Command_Chose_Pre&0x0001)>>0) 
#define  PRECommandbit2         ((Calib_Command_Chose_Pre&0x0002)>>1)
#define  PRECommandbit3         ((Calib_Command_Chose_Pre&0x0004)>>2)
#define  PRECommandbit4         ((Calib_Command_Chose_Pre&0x0008)>>3)
#define  PRECommandbit5         ((Calib_Command_Chose_Pre&0x0010)>>4)
#define  PRECommandbit6         ((Calib_Command_Chose_Pre&0x0020)>>5)
#define  PRECommandbit7         ((Calib_Command_Chose_Pre&0x0040)>>6)
#define  PRECommandbit8         ((Calib_Command_Chose_Pre&0x0080)>>7)
#define  PRECommandbit9         ((Calib_Command_Chose_Pre&0x0100)>>8)
#define  PRECommandbit10        ((Calib_Command_Chose_Pre&0x0200)>>9)   
#define  PRECommandbit11        ((Calib_Command_Chose_Pre&0x0400)>>10) 
#define  PRECommandbit12        ((Calib_Command_Chose_Pre&0x0800)>>11)
#define  PRECommandbit13        ((Calib_Command_Chose_Pre&0x1000)>>12)
#define  PRECommandbit14        ((Calib_Command_Chose_Pre&0x2000)>>13)
#define  PRECommandbit15        ((Calib_Command_Chose_Pre&0x4000)>>14)
#define  PRECommandbit16        ((Calib_Command_Chose_Pre&0x8000)>>15)    
         
#ifdef __cplusplus
}
#endif

#endif  