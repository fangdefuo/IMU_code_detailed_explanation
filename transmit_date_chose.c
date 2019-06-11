#include"transmit_date_chose.h"

extern double Yaw;
uint16_t data_type=0;
extern double MS5803_Altitude;
extern  u8 GPSDATA_START;
extern d_GPS_Data *pGPS_Data;
extern float magdata[];
extern float HMC5983_FIFO[3][6];
void CalcBcc_type_toFC(unsigned char* TxData, int16_t data_head, int16_t data_tail)
{
  u16 sBcc = 0;
  for(int i=(data_head);i<(data_tail);i++) sBcc += ((u16)TxData[i] & 0x00FF);  
  TxData[data_tail] = (u8)(sBcc & 0x00FF);
  
  return;
}

uint16_t chose_data_type_toFCM(void)
{
  
  uint16_t pinpos = 0x00, pos = 0x00, currentpin = 0x00 ;
  int16_t data_head=0,deta_tail=0,data_totalnumber=0;
  s16  sTemp=0;    
  
  data_type=0;
  
  data_type = DATA_IMU; 
  for (pinpos = 0x00; pinpos < 0x08; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;
    currentpin = data_type & pos;
    if (currentpin == pos)
    {
      switch(currentpin){
        
      case DATA_IMU:
        
        
        TxData[data_totalnumber++] = (u8)0xa5;
        TxData[data_totalnumber++] = (u8)0x5a;
        TxData[data_totalnumber++] = 22;
        TxData[data_totalnumber++] = 0xa2;
        data_head = data_totalnumber;
        
        sTemp = (s16)(pAHRS_Data_filtered->RollRate*1000.0);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pAHRS_Data_filtered->PitchRate*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->YawRate*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
	
        sTemp = (s16)(pAHRS_Data_filtered->Xacc*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->Yacc*1000.0);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        sTemp = (s16)(pAHRS_Data_filtered->Zacc*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);
        
        sTemp = (s16)(pAHRS_Data_filtered->magX*10000.0);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        sTemp = (s16)(pAHRS_Data_filtered->magY*10000.0);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->magZ*10000.0);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        
	
        sTemp = (s16)(pAHRS_Data_filtered->Roll*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->Pitch*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->Yaw*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);		
        
        sTemp = (s16)(IMU_HEALTH_2STATE);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);
        deta_tail = data_totalnumber;
        CalcBcc_type_toFC(TxData,data_head,deta_tail);
        TxData[deta_tail+1] = 0xaa;
        data_totalnumber=data_totalnumber+2;  
        break;
      default:
        data_totalnumber =0;
        break;        
      }      
    } 
  }
  return data_totalnumber;
}


uint16_t error_data_type_toFCM(void)
{
  
  uint16_t pinpos = 0x00, pos = 0x00, currentpin = 0x00 ;
  int16_t data_head=0,deta_tail=0,data_totalnumber=0;
  s16  sTemp=0;    
  
  data_type=0;
  
  data_type = DATA_IMU; 
  for (pinpos = 0x00; pinpos < 0x08; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;
    currentpin = data_type & pos;
    if (currentpin == pos)
    {
      switch(currentpin){
        
      case DATA_IMU:
        
        
        TxData[data_totalnumber++] = (u8)0xa5;
        TxData[data_totalnumber++] = (u8)0x5a;
        TxData[data_totalnumber++] = 22;
        TxData[data_totalnumber++] = 0xa2;
        data_head = data_totalnumber;
        
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
	
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);
        
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        
	
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(0xffff);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);		
        
        sTemp = (s16)(IMU_HEALTH_1STATE);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);
        deta_tail = data_totalnumber;
        CalcBcc_type_toFC(TxData,data_head,deta_tail);
        TxData[deta_tail+1] = 0xaa;
        data_totalnumber=data_totalnumber+2;  
        break;
      default:
        data_totalnumber =0;
        break;        
      }      
    } 
  }
  return data_totalnumber;
}

uint16_t chose_data_type_toFCS(void)
{
  
  uint16_t pinpos = 0x00, pos = 0x00, currentpin = 0x00 ;
  int16_t data_head=0,deta_tail=0,data_totalnumber=0;
  s16  sTemp=0;    
  
  data_type=0;
  /*****************************************
  CHOSE TYPE:
  1. DATA_IMU                
  2.DATA_PROP                
  3.DATA_CONTROL_U           
  4.DATA_MOTOR_U            
  5.DATA_SIM                 
  ****************************************/
  data_type = DATA_IMU; //| DATA_PROP;//| DATA_CONTROL_U | DATA_MOTOR_U;// | DATA_SIM; //在此处添加要发送的数据类型
  for (pinpos = 0x00; pinpos < 0x08; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;
    /* Get the port pins position */
    currentpin = data_type & pos;
    if (currentpin == pos)
    {
      switch(currentpin){
        /* 1.DATA_PROP数据区************************************************************************/  
        /********************************************************************************************/
      case DATA_IMU:
        
        
        TxData_S[data_totalnumber++] = (u8)0xa5;
        TxData_S[data_totalnumber++] = (u8)0x5a;
        TxData_S[data_totalnumber++] = 22;
        TxData_S[data_totalnumber++] = 0xa1;
        data_head = data_totalnumber;
        
        
        //        if(GPSDATA_START)
        //        {
        sTemp = (s16)(pGPS_Data->Vn*100.0);
        TxData_S[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData_S[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pGPS_Data->Ve*100.0);
        TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);
        if(GPS_NAME==NOVATEL)   
        {
          sTemp = (s16)(pGPS_Data->velVer*100.0);
        TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);
        }
        else
        {
          sTemp = (s16)(pGPS_Data->Vd*100.0);
          TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
          TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        }
        sTemp = (s16)(MS5611_Altitude*100.0);
        TxData_S[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData_S[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pGPS_Data->Star_Num);
        TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);
        
        
        double2hex(&(TxData_S[data_totalnumber]), pGPS_Data->Lat);
        data_totalnumber=data_totalnumber+8;
        double2hex(&(TxData_S[data_totalnumber]), pGPS_Data->Lon);
        data_totalnumber=data_totalnumber+8;
        
        sTemp = (s16)(pGPS_Data->Alt*100.0);
        TxData_S[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData_S[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pGPS_Data->pdop*100.0);
        TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);
        //        }
        //        else
        //        {
        //          sTemp = (s16)(0);
        //          TxData_S[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //          TxData_S[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        //          sTemp = (s16)(0);
        //          TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //          TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        //          sTemp = (s16)(0);
        //          TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //          TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        //          
        //          sTemp = (s16)(MS5611_Altitude*100.0);
        //          TxData_S[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //          TxData_S[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        //          sTemp = (s16)(7);
        //          TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //          TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);
        //          
        //          
        //          double2hex(&(TxData[data_totalnumber]),0);
        //          data_totalnumber=data_totalnumber+8;
        //          double2hex(&(TxData[data_totalnumber]),0);
        //          data_totalnumber=data_totalnumber+8;
        //          sTemp = (s16)(0);
        //          TxData_S[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //          TxData_S[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        //          sTemp = (s16)(1234);
        //          TxData_S[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //          TxData_S[data_totalnumber++] = (u8)(sTemp&0x00FF);
        //        }  	
        
        deta_tail = data_totalnumber;
        CalcBcc_type_toFC(TxData_S,data_head,deta_tail);
        TxData_S[deta_tail+1] = 0xaa;
        data_totalnumber=data_totalnumber+2;  
        break;
        
      default:
        data_totalnumber =0;
        break;        
      }      
    } 
  }
  return data_totalnumber;
}


extern double MS5611_Altitude;
extern uint16_t Count_Flag;
extern u16  GPS_Flag;

void CalcBcc_type_toGPS(unsigned char* TxData, int16_t data_head, int16_t data_tail)
{
  u16 sBcc = 0;
  for(int i=(data_head);i<(data_tail);i++) sBcc += ((u16)TxData[i] & 0x00FF);  
  TxData[data_tail] = (u8)(sBcc & 0x00FF);
  
  return;
}


uint16_t chose_data_type_toGPS(void)
{
  
  uint16_t pinpos = 0x00, pos = 0x00, currentpin = 0x00 ;
  int16_t data_head=0,deta_tail=0,data_totalnumber=0;
  s16  sTemp=0;    
  
  data_type=0;
  data_type = DATA_IMU;
  for (pinpos = 0x00; pinpos < 0x08; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;
    currentpin = data_type & pos;
    if (currentpin == pos)
    {
      switch(currentpin){
      case DATA_IMU: 
        TxData_P[data_totalnumber++] = (u8)0xa5;
        TxData_P[data_totalnumber++] = (u8)0x5a;
        TxData_P[data_totalnumber++] = 22;
        TxData_P[data_totalnumber++] = 0xa2;
        data_head = data_totalnumber;
        
        sTemp = (s16)(pAHRS_Data_Decode->Xacc*1000.0);
        TxData_P[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData_P[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pAHRS_Data_Decode->Yacc*1000.0);
        TxData_P[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData_P[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_Decode->Zacc*1000.0);
        TxData_P[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData_P[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        
        sTemp = (s16)(pAHRS_Data_Decode->Roll*1000.0);
        TxData_P[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData_P[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pAHRS_Data_Decode->Pitch*1000.0);
        TxData_P[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData_P[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_Decode->Yaw*1000.0);
        TxData_P[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData_P[data_totalnumber++] = (u8)(sTemp&0x00FF);
        
        deta_tail = data_totalnumber;
        CalcBcc_type_toGPS(TxData_P,data_head,deta_tail);
        TxData_P[deta_tail+1] = 0xaa;
        data_totalnumber=data_totalnumber+2;  
        break;   
      default:
        data_totalnumber =0;
        break;        
      }      
    } 
  }
  return data_totalnumber;
}




void CalcBcc_type_toSHOW(unsigned char* TxData, int16_t data_head, int16_t data_tail)
{
  u16 sBcc = 0,nByte=0;
  nByte = data_tail-data_head;
  for(int i=(data_head+2);i<(data_head+nByte);i++) sBcc += ((u16)TxData[i] & 0x00FF);  
  TxData[data_tail] = (u8)((sBcc >> 8) & 0x00FF);
  TxData[data_tail+1] = (u8)(sBcc & 0x00FF);
  
  return;
}


uint16_t chose_data_type_toSHOW(void)
{
  
  uint16_t pinpos = 0x00, pos = 0x00, currentpin = 0x00 ;
  int16_t data_head=0,deta_tail=0,data_totalnumber=0;
  s16  sTemp=0;    
  
  data_type=0;
  /*****************************************
  CHOSE TYPE:
  1. DATA_IMU                
  2.DATA_PROP                
  3.DATA_CONTROL_U           
  4.DATA_MOTOR_U            
  5.DATA_SIM                 
  ****************************************/
  data_type = DATA_IMU;//|DATA_PROP;//| DATA_CONTROL_U | DATA_MOTOR_U;// | DATA_SIM; //在此处添加要发送的数据类型
  //data_type = DATA_IMU;
  for (pinpos = 0x00; pinpos < 0x08; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;
    /* Get the port pins position */
    currentpin = data_type & pos;
    if (currentpin == pos)
    {
      switch(currentpin){
        /* 1.DATA_PROP数据区************************************************************************/  
        /********************************************************************************************/
      case DATA_IMU:
        
        data_head = data_totalnumber;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0x02;
        //                sTemp = (s16)(pAHRS_Data_raw->Xacc);
        //                TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //                TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        //                sTemp = (s16)(pAHRS_Data_raw->Yacc);
        //                TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //                TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        //                sTemp = (s16)(pAHRS_Data_raw->Zacc);
        //                TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //                TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);
        sTemp = (s16)(pAHRS_Data_filtered->RollRate*1000.0);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pAHRS_Data_filtered->PitchRate*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->YawRate*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF); 
        //                sTemp = (s16)(magdata[0]*10000.0);//Lroll
        //                TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //                TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        //                sTemp = (s16)(magdata[1]*10000.0);//Lpitch
        //                TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //                TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        //                sTemp = (s16)(magdata[2]*10000.0);//Lyaw
        //                TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //                TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        //        sTemp = (s16)(ADCConvertedValue1[0]);//Lroll
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        //        sTemp = (s16)(ADCConvertedValue1[1]);//Lpitch
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(ADCConvertedValue1[2]);//Lyaw
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        
        
        sTemp = (s16)(pAHRS_Data->Zacc*1000.0);//Lroll
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        sTemp = (s16)(pAHRS_Data->YawRate*1000.0);//Lpitch
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data->Xacc*1000.0);//Lyaw
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF); 
        //        sTemp = (s16)(MS5611_Altitude);//Lyaw
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        
        sTemp = (s16)(pAHRS_Data_filtered->Xacc*1000.0);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pAHRS_Data_filtered->Yacc*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->Zacc*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF); 
        
        
        //        sTemp = (s16)(pAHRS_Data_filtered->Roll*100.0);//Lroll
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        //        sTemp = (s16)(pAHRS_Data_filtered->Pitch*100.0);//Lpitch
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(pAHRS_Data_filtered->Yaw*100.0);//Lyaw
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        
        
        
        //        sTemp = (s16)(pAHRS_Data_filtered->Roll*100.0);//Lroll
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        //        sTemp = (s16)(pAHRS_Data_filtered->Pitch*100.0);//Lpitch
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(pAHRS_Data_filtered->Yaw*100.0);//Lyaw
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF); 
        //        
        //        sTemp = (s16)(pAHRS_Data_raw->RollRate);
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        //        sTemp = (s16)(pAHRS_Data_raw->PitchRate);
        //        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(pAHRS_Data_raw->YawRate);
        //        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);
        
        //        sTemp = (s16)(pAHRS_Data_raw->Xacc);
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        //        sTemp = (s16)(pAHRS_Data_raw->Yacc);
        //        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(pAHRS_Data_raw->Zacc);
        //        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);
        //        sTemp = (s16)(ADCConvertedValue1[3]);//Lroll
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        //        sTemp = (s16)(ADCConvertedValue1[4]);//Lpitch
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(MS5611_Altitude);//Lyaw
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        //        
        //        
        //                sTemp = (s16)(HMC5983_FIFO[0][5]*10000.0);
        //                TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //                TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        //                sTemp = (s16)(HMC5983_FIFO[1][5]*10000.0);
        //                TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //                TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        //                sTemp = (s16)(HMC5983_FIFO[2][5]*10000.0);
        //                TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        //                TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        
        deta_tail = data_totalnumber;
        CalcBcc_type_toSHOW(TxData,data_head,deta_tail);
        data_totalnumber=data_totalnumber+2;  
        break;
        /* 2.DATA_PROP数据区************************************************************************/  
        /********************************************************************************************/        
      case DATA_PROP:
        data_head = data_totalnumber;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0x03;
        
        sTemp = (s16)(pAHRS_Data_filtered->Roll*100.0);//Lroll
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        sTemp = (s16)(pAHRS_Data_filtered->Pitch*100.0);//Lpitch
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->Yaw*100.0);//Lyaw
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF); 
        
        
        
        //        sTemp = (s16)(pAHRS_Data_Decode->magX*10000.0);
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(pAHRS_Data_Decode->magY*10000.0);
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(pAHRS_Data_Decode->magZ*10000.0);
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
	
        sTemp = (s16)(Yaw*100.0);//Throttle
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        
        sTemp = (s16)(pAHRS_Data_filtered->Xacc*1000.0);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		  
        sTemp = (s16)(pAHRS_Data_filtered->Yacc*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_filtered->Zacc*1000.0);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF); 	
        //        sTemp = (s16)(11);//A
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        //        sTemp = (s16)(11);
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        //        
        //        sTemp = (s16)(11);
        //        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        //        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        sTemp = (s16)(111);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        
        deta_tail = data_totalnumber;
        CalcBcc_type_toSHOW(TxData,data_head,deta_tail);   
        data_totalnumber=data_totalnumber+2;
        break;
        /* 3.DATA_CONTROL_U数据区************************************************************************/  
        /********************************************************************************************/         
      case DATA_CONTROL_U:
        data_head = data_totalnumber;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0x04;
        
        
        sTemp = (s16)(pAHRS_Data_Decode->magX);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        sTemp = (s16)(pAHRS_Data_Decode->magY);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_Decode->magZ);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);
        deta_tail = data_totalnumber;
        CalcBcc_type_toSHOW(TxData,data_head,deta_tail);
        data_totalnumber=data_totalnumber+2;
        break;
        /* 4.DATA_MOTOR_U数据区************************************************************************/  
        /********************************************************************************************/            
      case DATA_MOTOR_U:
        
        data_head = data_totalnumber;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0x05;
        
        sTemp = (s16)(pAHRS_Data_Decode->magX);//Motor_F
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        sTemp = (s16)(pAHRS_Data_Decode->magX);//Motor_B
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_Decode->magX);//Motor_L
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        sTemp = (s16)(pAHRS_Data_Decode->magX);//Motor_R
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);	
        
        
        deta_tail = data_totalnumber;
        CalcBcc_type_toSHOW(TxData,data_head,deta_tail);
        data_totalnumber=data_totalnumber+2;  
        break;
        /* 5.DATA_SIM数据区************************************************************************/  
        /********************************************************************************************/            
      case DATA_SIM:
        
        data_head = data_totalnumber;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0xFF;
        TxData[data_totalnumber++] = (u8)0x06;
        
        //sTemp = (s16)(pKalman_Simulation->Roll*10);//Sim_roll
        sTemp = (s16)(pAHRS_Data_Decode->magX);
        TxData[data_totalnumber++]  = (u8)((sTemp&0xFF00)>>8);    
        TxData[data_totalnumber++]  = (u8)(sTemp&0x00FF);		
        
        //sTemp = (s16)(pKalman_Simulation->Pitch*10);//sim_pitch
        sTemp = (s16)(pAHRS_Data_Decode->magX);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        
        //sTemp = (s16)(pKalman_Simulation->Yaw*10);//sim_yaw
        sTemp = (s16)(pAHRS_Data_Decode->magX);
        TxData[data_totalnumber++] = (u8)((sTemp&0xFF00)>>8);  
        TxData[data_totalnumber++] = (u8)(sTemp&0x00FF);	
        
        deta_tail = data_totalnumber;
        CalcBcc_type_toSHOW(TxData,data_head,deta_tail);
        data_totalnumber=data_totalnumber+2;  
        break;
        
      default:
        data_totalnumber =0;
        break;        
      }      
    } 
  }
  return data_totalnumber;
}
void double2hex(u8 *hexdata, double ddata)
{
  union{
    double doubledata;
    u8 byte[8];
  }ddat;
  
  ddat.doubledata = ddata;
  
  hexdata[0] = ddat.byte[0];
  hexdata[1] = ddat.byte[1];
  hexdata[2] = ddat.byte[2];
  hexdata[3] = ddat.byte[3];
  hexdata[4] = ddat.byte[4];
  hexdata[5] = ddat.byte[5];
  hexdata[6] = ddat.byte[6];
  hexdata[7] = ddat.byte[7];
}
