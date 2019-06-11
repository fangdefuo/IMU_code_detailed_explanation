/**
******************************************************************************
* @file    argument_config.h 
* @author  panjiadi
* @version V1.0
* @date    13-03-2015
* @brief   IMU加速度计与陀螺仪零点 以及地磁计零点数据
******************************************************************************
* @device  slave---STM32F405RGT6
******************************************************************************   
*/
#ifndef __ARGUMENT_CONFIG_H
#define __ARGUMENT_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif 
  /*******************************************************************************************
  //  * @brief   请选择对应的宏
  *******************************************************************************************/ 
  
  
  
  /*******************************************************************************************
  //  * @brief   toSHOW or toFC  选择去飞控 或者PC 上位机
  *******************************************************************************************/    
#define toFC
  /*******************************************************************************************
  //  * @brief   IMUx 选择对应的IMU序号
  *********************** n*******************************************************************/    
#define IMU_CALIBARATION_AUTO
//#define IMU_V20_02_55
  /*******************************************************************************************
  //  * @brief   GPSx 选择对应的GPS序号  GPST 代表AYWTGPS
  *******************************************************************************************/    
#define MAGoc04                                                           
  /*******************************************************************************************
  //  * @brief   BEITIAN_MAG||||    AYDRONRMAG   AYDRONE_MAG_GPS_STM32F4
  //  * @brief    选择地磁数据源
  *******************************************************************************************/      
#define AYDRONE_MAG_GPS_STM32F4
  /*******************************************************************************************
  //  * @brief    BEITIAN_GPS\NOVATEL_GPS 
  //  * @brief    选择GPS数据源
  *******************************************************************************************/      
  //#define BEITIAN_GPS   
  /*******************************************************************************************
  //  * @brief   MANUAL_CALIB or AUTO_CALIB  自动校准 或者手动校准
  *******************************************************************************************/   
#define AUTO_CALIB 
  /*******************************************************************************************
  //  * @brief    是否使用地磁因子USE_MAGFACTOR   or   NUSE_MAGFACTOR
  *******************************************************************************************/ 
#define NUSE_MAGFACTOR 
  /*******************************************************************************************
  //  * @brief    是否使用检测地磁期间DETECT_MAGNETIC or NDETECT_MAGNETIC
  *******************************************************************************************/ 
#define NDETECT_MAGNETIC
  
  
  
  //GPIOTEST  toFC  toSHOW  toPRINTF四选一
  //#define GPIOTEST
  
  
  
  
#if defined GPS1   
  /////////////////白GPS1////////////////////////////  
#define  HIC_X  0.0049
#define  HIC_Y  0.0610
#define  HIC_Z  -0.0317 
#define  HIC_Z_ADJ    1.0314
  
  
#elif defined   MAGoc04
#define  HIC_X  0
#define  HIC_Y  0
#define  HIC_Z  0
#define  HIC_Z_ADJ  1     
  
#endif   
  
  
  /*******************************************************************************************
  //  * @brief   IMU1（坠机的那个飞机）
  //  * @time    焊接于2015年3月8日
  *******************************************************************************************/ 
  
#if defined IMU_V18_1
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  /**********************************************************************
  * @brief   IMU2（包铜箔的飞机）
  * @time    焊接于2015年3月9日
  *******************************************************************/
  
#elif defined  IMU_V18_2
  
#define Xacc_Offset          2330 
#define Yacc_Offset          2322     
#define Zacc_Offset          2355  
#define K_Xacc               0.010300  
#define K_Yacc               0.010300    
#define K_Zacc               0.010450
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V18_3
  
#define Xacc_Offset          2443
#define Yacc_Offset          2330     
#define Zacc_Offset          2335
#define K_Xacc               (0.010400)  
#define K_Yacc               (0.010400)    
#define K_Zacc               (0.010430)  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           (0.0030583)
#define K_PitchRate          (0.0030560)
#define K_YawRate            (0.0030560)     
  
#elif defined  IMU_V18_4
  
#define Xacc_Offset          2380  
#define Yacc_Offset          2390     
#define Zacc_Offset          2355 
#define K_Xacc               0.010300  
#define K_Yacc               0.010300    
#define K_Zacc               0.010300  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0030536
#define K_PitchRate          0.0030536
#define K_YawRate            0.0030536    
  
  
#elif defined  IMU_V18_5
  
#define Xacc_Offset          2390  
#define Yacc_Offset          2343     
#define Zacc_Offset          2370  
#define K_Xacc               0.010400  
#define K_Yacc               0.010400    
#define K_Zacc               0.010400  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
#elif defined  IMU_V18_6
  
#define Xacc_Offset          2350
#define Yacc_Offset          2360     
#define Zacc_Offset          2352  
#define K_Xacc               0.010400  
#define K_Yacc               0.010400    
#define K_Zacc               0.010450  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0030560
#define K_PitchRate          0.0030563
#define K_YawRate            0.0030569  
  
  
  
  
#elif defined  IMU_V18_7
  
#define Xacc_Offset          2370
#define Yacc_Offset          2365     
#define Zacc_Offset          2356  
#define K_Xacc               0.010300  
#define K_Yacc               0.010300    
#define K_Zacc               0.010410  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869   
  
#elif defined  IMU_V18_8
  
#define Xacc_Offset          2350
#define Yacc_Offset          2346     
#define Zacc_Offset          2350  
#define K_Xacc               0.010400  
#define K_Yacc               0.010400    
#define K_Zacc               0.010410   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
#elif defined  IMU_V17_6
  
#define Xacc_Offset          2378
#define Yacc_Offset          2330     
#define Zacc_Offset          2363
#define Xaccg_Offset          2378  
#define Yaccg_Offset          2330     
#define Zaccg_Offset          2363   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_7
  
#define Xacc_Offset          2333  
#define Yacc_Offset          2308     
#define Zacc_Offset          2310
#define Xaccg_Offset          2333  
#define Yaccg_Offset          2308     
#define Zaccg_Offset          2310   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_8
  
#define Xacc_Offset          2330  
#define Yacc_Offset          2310     
#define Zacc_Offset          2350
#define Xaccg_Offset          2330  
#define Yaccg_Offset          2310     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010540  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_9
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_10
  
#define Xacc_Offset          2345  
#define Yacc_Offset          2332     
#define Zacc_Offset          2350
#define Xaccg_Offset          2345  
#define Yaccg_Offset          2332     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010520  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_11
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_12
  
#define Xacc_Offset          2345  
#define Yacc_Offset          2300     
#define Zacc_Offset          2350
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
#elif defined  IMU_V17_13
  
#define Xacc_Offset          2337 
#define Yacc_Offset          2288     
#define Zacc_Offset          2340
#define Xaccg_Offset          2337  
#define Yaccg_Offset          2288     
#define Zaccg_Offset          2340   
#define K_Xacc               0.010520  
#define K_Yacc               0.010520    
#define K_Zacc               0.010520  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
#elif defined  IMU_V17_14
  
#define Xacc_Offset          2345  
#define Yacc_Offset          2300     
#define Zacc_Offset          2350
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_15
  
#define Xacc_Offset          2345  
#define Yacc_Offset          2300     
#define Zacc_Offset          2350
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480 
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_16
  
#define Xacc_Offset          2362  
#define Yacc_Offset          2310     
#define Zacc_Offset          2346
#define Xaccg_Offset          2362  
#define Yaccg_Offset          2310     
#define Zaccg_Offset          2346   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_17
  
#define Xacc_Offset          2350  
#define Yacc_Offset          2294     
#define Zacc_Offset          2350
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2294     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_18
  
#define Xacc_Offset          2334
#define Yacc_Offset          2320    
#define Zacc_Offset          2330
#define Xaccg_Offset          2334  
#define Yaccg_Offset          2320     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_19
  
#define Xacc_Offset          2363 
#define Yacc_Offset          2331     
#define Zacc_Offset          2371
#define Xaccg_Offset          2363  
#define Yaccg_Offset          2331     
#define Zaccg_Offset          2371   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_20
  
#define Xacc_Offset          2320  
#define Yacc_Offset          2294     
#define Zacc_Offset          2330
#define Xaccg_Offset          2320  
#define Yaccg_Offset          2294     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010540  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_21
  
#define Xacc_Offset          2350 
#define Yacc_Offset          2340     
#define Zacc_Offset          2360
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2340     
#define Zaccg_Offset          2360   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_22
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_23
  
#define Xacc_Offset          2338
#define Yacc_Offset          2330     
#define Zacc_Offset          2349
#define Xaccg_Offset          2338  
#define Yaccg_Offset          2330     
#define Zaccg_Offset          2349   
#define K_Xacc               0.010530  
#define K_Yacc               0.010530    
#define K_Zacc               0.010530  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_24
  
#define Xacc_Offset          2350  
#define Yacc_Offset          2307     
#define Zacc_Offset          2334
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2307     
#define Zaccg_Offset          2334   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_25
  
#define Xacc_Offset          2350 
#define Yacc_Offset          2318    
#define Zacc_Offset          2362
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2318     
#define Zaccg_Offset          2362   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_26
  
#define Xacc_Offset          2350
#define Yacc_Offset          2339     
#define Zacc_Offset          2356
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2339     
#define Zaccg_Offset          2356   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480 
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_27
  
#define Xacc_Offset          2376 
#define Yacc_Offset          2294     
#define Zacc_Offset          2365
#define Xaccg_Offset          2376  
#define Yaccg_Offset          2294     
#define Zaccg_Offset          2365   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480 
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_28
  
#define Xacc_Offset          2338 
#define Yacc_Offset          2308     
#define Zacc_Offset          2345
#define Xaccg_Offset          2338  
#define Yaccg_Offset          2308     
#define Zaccg_Offset          2345  
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480 
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_29
  
#define Xacc_Offset          2336  
#define Yacc_Offset          2276     
#define Zacc_Offset          2320
#define Xaccg_Offset          2336  
#define Yaccg_Offset          2276     
#define Zaccg_Offset          2320   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
#elif defined  IMU_V17_30
  
#define Xacc_Offset          2320  
#define Yacc_Offset          2325     
#define Zacc_Offset          2306
#define Xaccg_Offset          2320  
#define Yaccg_Offset          2325     
#define Zaccg_Offset          2306   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
  
#elif defined  IMU_V17_31
  
#define Xacc_Offset          2346 
#define Yacc_Offset          2310    
#define Zacc_Offset          2330
#define Xaccg_Offset          2346  
#define Yaccg_Offset          2310     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_32
  
#define Xacc_Offset          2375 
#define Yacc_Offset          2328     
#define Zacc_Offset          2360
#define Xaccg_Offset          2375  
#define Yaccg_Offset          2328     
#define Zaccg_Offset          2360   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_33
  
#define Xacc_Offset          2365 
#define Yacc_Offset          2290     
#define Zacc_Offset          2380
#define Xaccg_Offset          2365  
#define Yaccg_Offset          2290     
#define Zaccg_Offset          2380   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_34
  
#define Xacc_Offset          2333  
#define Yacc_Offset          2292     
#define Zacc_Offset          2335
#define Xaccg_Offset          2333  
#define Yaccg_Offset          2292     
#define Zaccg_Offset          2335   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010520  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_35
  
#define Xacc_Offset          2350 
#define Yacc_Offset          2298     
#define Zacc_Offset          2360
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2298     
#define Zaccg_Offset          2360   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
  
#elif defined  IMU_V17_36
  
#define Xacc_Offset          2350
#define Yacc_Offset          2330     
#define Zacc_Offset          2355
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2330     
#define Zaccg_Offset          2355   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
#elif defined  IMU_V17_37
  
#define Xacc_Offset          2350 
#define Yacc_Offset          2300     
#define Zacc_Offset          2367
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2367   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_38
  
#define Xacc_Offset          2350  
#define Yacc_Offset          2330     
#define Zacc_Offset          2340
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2330     
#define Zaccg_Offset          2340   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
  
#elif defined  IMU_V17_39
  
#define Xacc_Offset          2356  
#define Yacc_Offset          2319     
#define Zacc_Offset          2340
#define Xaccg_Offset          2356  
#define Yaccg_Offset          2319     
#define Zaccg_Offset          2340   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_40
  
#define Xacc_Offset          2390  
#define Yacc_Offset          2330     
#define Zacc_Offset          2345
#define Xaccg_Offset          2390  
#define Yaccg_Offset          2330     
#define Zaccg_Offset          2345   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480 
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_41
  
#define Xacc_Offset          2350 
#define Yacc_Offset          2344     
#define Zacc_Offset          2350
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2344     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_42
  
#define Xacc_Offset          2356 
#define Yacc_Offset          2254     
#define Zacc_Offset          2338
#define Xaccg_Offset          2356  
#define Yaccg_Offset          2254     
#define Zaccg_Offset          2338   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480 
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_43
  
#define Xacc_Offset          2338  
#define Yacc_Offset          2297     
#define Zacc_Offset          2337
#define Xaccg_Offset          2338  
#define Yaccg_Offset          2297    
#define Zaccg_Offset          2337  
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_44
  
#define Xacc_Offset          2350
#define Yacc_Offset          2312     
#define Zacc_Offset          2344
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2312     
#define Zaccg_Offset          2344   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
  
  
#elif defined  IMU_V17_45
  
#define Xacc_Offset          2346 
#define Yacc_Offset          2316     
#define Zacc_Offset          2324
#define Xaccg_Offset          2346  
#define Yaccg_Offset          2316     
#define Zaccg_Offset          2324   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869    
  
#elif defined  IMU_V17_46
#define Xacc_Offset          2337
#define Yacc_Offset          2330     
#define Zacc_Offset          2335
#define Xaccg_Offset          2337  
#define Yaccg_Offset          2330     
#define Zaccg_Offset          2335   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869 
  
#elif defined  IMU_V17_47
  
#define Xacc_Offset          2338  
#define Yacc_Offset          2323     
#define Zacc_Offset          2365
#define Xaccg_Offset          2338  
#define Yaccg_Offset          2323     
#define Zaccg_Offset          2365   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869       
  
  //////////
#elif defined  IMU_V17_48
  
#define Xacc_Offset          2375
#define Yacc_Offset          2312     
#define Zacc_Offset          2346
#define Xaccg_Offset          2375  
#define Yaccg_Offset          2312     
#define Zaccg_Offset          2346   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_49
  
#define Xacc_Offset          2342
#define Yacc_Offset          2317     
#define Zacc_Offset          2330
#define Xaccg_Offset          2342  
#define Yaccg_Offset          2317     
#define Zaccg_Offset          2330  
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010530   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_50
  
#define Xacc_Offset          2319
#define Yacc_Offset          2310     
#define Zacc_Offset          2310
#define Xaccg_Offset          2319  
#define Yaccg_Offset          2310     
#define Zaccg_Offset          2310   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_51
  
#define Xacc_Offset          2358 
#define Yacc_Offset          2332     
#define Zacc_Offset          2334
#define Xaccg_Offset          2358  
#define Yaccg_Offset          2332     
#define Zaccg_Offset          2334   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_52
  
#define Xacc_Offset          2335  
#define Yacc_Offset          2297     
#define Zacc_Offset          2358
#define Xaccg_Offset          2335  
#define Yaccg_Offset          2297     
#define Zaccg_Offset          2358   
#define K_Xacc               0.010530  
#define K_Yacc               0.010530    
#define K_Zacc               0.010530  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_53
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
  
#elif defined  IMU_V17_54
  
#define Xacc_Offset          2344  
#define Yacc_Offset          2286     
#define Zacc_Offset          2340
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2340   
#define K_Xacc               0.010530  
#define K_Yacc               0.010530    
#define K_Zacc               0.010530  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_55
  
#define Xacc_Offset          2340
#define Yacc_Offset          2315     
#define Zacc_Offset          2330
#define Xaccg_Offset          2340  
#define Yaccg_Offset          2315     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_56
  
#define Xacc_Offset          2370  
#define Yacc_Offset          2350     
#define Zacc_Offset          2370
#define Xaccg_Offset          2370  
#define Yaccg_Offset          2350     
#define Zaccg_Offset          2370   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_57
  
#define Xacc_Offset          2380  
#define Yacc_Offset          2350     
#define Zacc_Offset          2350
#define Xaccg_Offset          2380  
#define Yaccg_Offset          2350     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_58
  
#define Xacc_Offset          2360  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2360  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010600  
#define K_Yacc               0.010600    
#define K_Zacc               0.010600   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_59
  
#define Xacc_Offset          2370  
#define Yacc_Offset          2335     
#define Zacc_Offset          2350
#define Xaccg_Offset          2370  
#define Yaccg_Offset          2335     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_60
  
#define Xacc_Offset          2357  
#define Yacc_Offset          2344     
#define Zacc_Offset          2337
#define Xaccg_Offset          2357  
#define Yaccg_Offset          2344     
#define Zaccg_Offset          2337   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_61
  
#define Xacc_Offset          2380  
#define Yacc_Offset          2350     
#define Zacc_Offset          2350
#define Xaccg_Offset          2380  
#define Yaccg_Offset          2350     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_62
  
#define Xacc_Offset          2350  
#define Yacc_Offset          2335     
#define Zacc_Offset          2340
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2335     
#define Zaccg_Offset          2340   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480    
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_63
  
#define Xacc_Offset          2360 
#define Yacc_Offset          2320     
#define Zacc_Offset          2337
#define Xaccg_Offset          2360  
#define Yaccg_Offset          2320     
#define Zaccg_Offset          2337   
#define K_Xacc               0.010530  
#define K_Yacc               0.010530    
#define K_Zacc               0.010530    
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_64
  
#define Xacc_Offset          2350 
#define Yacc_Offset          2300     
#define Zacc_Offset          2340
#define Xaccg_Offset          2350  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2340   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_65
  
#define Xacc_Offset          2320  
#define Yacc_Offset          2311     
#define Zacc_Offset          2337
#define Xaccg_Offset          2320  
#define Yaccg_Offset          2311     
#define Zaccg_Offset          2337   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480    
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_66
  
#define Xacc_Offset          2346  
#define Yacc_Offset          2266     
#define Zacc_Offset          2325
#define Xaccg_Offset          2346  
#define Yaccg_Offset          2266     
#define Zaccg_Offset          2325   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480    
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_67
  
#define Xacc_Offset          2360 
#define Yacc_Offset          2336     
#define Zacc_Offset          2368
#define Xaccg_Offset          2360  
#define Yaccg_Offset          2336     
#define Zaccg_Offset          2368   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_68
  
#define Xacc_Offset          2380  
#define Yacc_Offset          2350     
#define Zacc_Offset          2350
#define Xaccg_Offset          2380  
#define Yaccg_Offset          2350     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_69
  
#define Xacc_Offset          2380  
#define Yacc_Offset          2350     
#define Zacc_Offset          2350
#define Xaccg_Offset          2380  
#define Yaccg_Offset          2350     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_70
  
#define Xacc_Offset          2380  
#define Yacc_Offset          2350     
#define Zacc_Offset          2350
#define Xaccg_Offset          2380  
#define Yaccg_Offset          2350     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480   
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_71
  
#define Xacc_Offset          2380  
#define Yacc_Offset          2350     
#define Zacc_Offset          2350
#define Xaccg_Offset          2380  
#define Yaccg_Offset          2350     
#define Zaccg_Offset          2350   
#define K_Xacc               0.010480  
#define K_Yacc               0.010480    
#define K_Zacc               0.010480  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_72
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_73
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_74
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
#elif defined  IMU_V17_75
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
#elif defined  IMU_V17_76
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_77
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_78
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_79
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_80
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_81
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_82
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_83
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_84
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_85
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_86
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_87
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_88
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_89
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_90
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_91
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
#elif defined  IMU_V17_92
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
  
#elif defined  IMU_V17_93
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
  
#elif defined  IMU_V17_94
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
  
#elif defined  IMU_V17_95
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
  
#elif defined  IMU_V17_96
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
  
  
#elif defined  IMU_V17_97
  
#define Xacc_Offset          2329  
#define Yacc_Offset          2300     
#define Zacc_Offset          2330
#define Xaccg_Offset          2329  
#define Yaccg_Offset          2300     
#define Zaccg_Offset          2330   
#define K_Xacc               0.010630  
#define K_Yacc               0.010630    
#define K_Zacc               0.010630  
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////   
#define RollRate_Offset      2308
#define PitchRate_Offset     2308
#define YawRate_Offset       2346
#define K_RollRate           0.0032683
#define K_PitchRate          0.003033
#define K_YawRate            0.0030869  
  
#elif defined IMU_V19_1
#define Xacc_Offset          2407
#define Yacc_Offset          2336  
#define Zacc_Offset          2376.5
#define K_Xacc               0.010300  
#define K_Yacc               -0.010300   
#define K_Zacc               0.010290
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
  
  
#elif defined IMU_V19_2
#define Xacc_Offset          2346
#define Yacc_Offset          2311  
#define Zacc_Offset          2364
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
#elif defined IMU_V19_3
#define Xacc_Offset          2410
#define Yacc_Offset          2325  
#define Zacc_Offset          2377
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010375
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
#elif defined IMU_V19_4
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_5
#define Xacc_Offset          2333
#define Yacc_Offset          2330    
#define Zacc_Offset          2352
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
#elif defined IMU_V19_6
#define Xacc_Offset          2338
#define Yacc_Offset          2347    
#define Zacc_Offset          2378
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010370
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
#elif defined IMU_V19_7
#define Xacc_Offset          2368
#define Yacc_Offset          2345    
#define Zacc_Offset          2365
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010310
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
#elif defined IMU_V19_8
#define Xacc_Offset          2364
#define Yacc_Offset          2368    
#define Zacc_Offset          2353
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010385
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
#elif defined IMU_V19_9
#define Xacc_Offset          2397
#define Yacc_Offset          2328    
#define Zacc_Offset          2367
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_10
#define Xacc_Offset          2339
#define Yacc_Offset          2340    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_11
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
#elif defined IMU_V19_12
#define Xacc_Offset          2354
#define Yacc_Offset          2328   
#define Zacc_Offset          2360
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010355
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
#elif defined IMU_V19_13
#define Xacc_Offset          2352
#define Yacc_Offset          2347   
#define Zacc_Offset          2336
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010480
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
#elif defined IMU_V19_14
#define Xacc_Offset          2323
#define Yacc_Offset          2335    
#define Zacc_Offset          2362
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
#elif defined IMU_V19_15
#define Xacc_Offset          2366
#define Yacc_Offset          2316   
#define Zacc_Offset          2360
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_16
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               -0.010300   
#define K_Zacc               0.010370
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0031500 
  
  
  
  
#elif defined IMU_V19_17
#define Xacc_Offset          2384
#define Yacc_Offset          2300
#define Zacc_Offset          2376
#define K_Xacc               0.010411  
#define K_Yacc               0.010350  
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
#elif defined IMU_V19_18
#define Xacc_Offset          2349
#define Yacc_Offset          2357    
#define Zacc_Offset          2342
#define K_Xacc               0.010350 
#define K_Yacc               0.010400  
#define K_Zacc               0.010460
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_19
#define Xacc_Offset          2381
#define Yacc_Offset          2310   
#define Zacc_Offset          2361
#define K_Xacc               0.010340  
#define K_Yacc               0.010360   
#define K_Zacc               0.010330
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_20
#define Xacc_Offset          2370
#define Yacc_Offset          2350
#define Zacc_Offset          2341
#define K_Xacc               0.010410  
#define K_Yacc               0.010400   
#define K_Zacc               0.010480
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_21
#define Xacc_Offset          2365
#define Yacc_Offset          2348   
#define Zacc_Offset          2362
#define K_Xacc               0.010410 
#define K_Yacc               0.010400  
#define K_Zacc               0.010370
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_22
#define Xacc_Offset          2408
#define Yacc_Offset          2319   
#define Zacc_Offset          2392
#define K_Xacc               0.010110  
#define K_Yacc               0.010240   
#define K_Zacc               0.010210
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_23
#define Xacc_Offset          2378
#define Yacc_Offset          2346  
#define Zacc_Offset          2352
#define K_Xacc               0.010300  
#define K_Yacc               0.010480   
#define K_Zacc               0.010370
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_24
#define Xacc_Offset          2370
#define Yacc_Offset          2312   
#define Zacc_Offset          2365
#define K_Xacc               0.010500
#define K_Yacc               0.010700  
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_25
#define Xacc_Offset          2381
#define Yacc_Offset          2354    
#define Zacc_Offset          2362
#define K_Xacc               0.010300  
#define K_Yacc               -0.010410  
#define K_Zacc               0.010260
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
#elif defined IMU_V19_26
#define Xacc_Offset          2355
#define Yacc_Offset          2372    
#define Zacc_Offset          2356
#define K_Xacc               0.010380  
#define K_Yacc               0.010250   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_27
#define Xacc_Offset          2369
#define Yacc_Offset          2320    
#define Zacc_Offset          2360
#define K_Xacc               0.010500  
#define K_Yacc               0.010200   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_28
#define Xacc_Offset          2342
#define Yacc_Offset          2357    
#define Zacc_Offset          2371.5
#define K_Xacc               0.010430  
#define K_Yacc               0.010300   
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_29
#define Xacc_Offset          2352
#define Yacc_Offset          2294    
#define Zacc_Offset          2335
#define K_Xacc               0.010550  
#define K_Yacc               0.010300   
#define K_Zacc               0.010480
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
  
#elif defined IMU_V19_30
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_31
#define Xacc_Offset          2317
#define Yacc_Offset          2315
#define Zacc_Offset          2338
#define K_Xacc               0.010500  
#define K_Yacc               0.010300   
#define K_Zacc               0.010500
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
#elif defined IMU_V19_32
#define Xacc_Offset          2337
#define Yacc_Offset          2345
#define Zacc_Offset          2378
#define K_Xacc               0.010450  
#define K_Yacc               0.010300   
#define K_Zacc               0.010310
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_33
#define Xacc_Offset          2349
#define Yacc_Offset          2389   
#define Zacc_Offset          2368
#define K_Xacc               0.010300  
#define K_Yacc               -0.010000   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
  
  
  
  
#elif defined IMU_V19_34
#define Xacc_Offset          2316
#define Yacc_Offset          2334  
#define Zacc_Offset          2339
#define K_Xacc               0.010450
#define K_Yacc               -0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
#elif defined IMU_V19_35
#define Xacc_Offset          2317
#define Yacc_Offset          2339    
#define Zacc_Offset          2339
#define K_Xacc               0.010400  
#define K_Yacc               0.010300   
#define K_Zacc               0.010500
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
  
  
#elif defined IMU_V19_36
#define Xacc_Offset          2371
#define Yacc_Offset          2322  
#define Zacc_Offset          2391
#define K_Xacc               0.010300  
#define K_Yacc               0.010100   
#define K_Zacc               0.010410
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
  
  
#elif defined IMU_V19_37
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500    
  
  
  
#elif defined IMU_V19_38
#define Xacc_Offset          2350
#define Yacc_Offset          2400  
#define Zacc_Offset          2342
#define K_Xacc               0.010600  
#define K_Yacc               0.010200   
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_39
#define Xacc_Offset          2360
#define Yacc_Offset          2350    
#define Zacc_Offset          2348
#define K_Xacc               0.010430  
#define K_Yacc               0.010230   
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_40
#define Xacc_Offset          2345
#define Yacc_Offset          2336    
#define Zacc_Offset          2350
#define K_Xacc               0.010430  
#define K_Yacc               0.010230   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_41
#define Xacc_Offset          2330
#define Yacc_Offset          2342   
#define Zacc_Offset          2369
#define K_Xacc               0.010350  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_42
#define Xacc_Offset          2385
#define Yacc_Offset          2340    
#define Zacc_Offset          2361
#define K_Xacc               0.010300  
#define K_Yacc               0.010100   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_43
#define Xacc_Offset          2364
#define Yacc_Offset          2342  
#define Zacc_Offset          2360
#define K_Xacc               0.010300  
#define K_Yacc               0.0101500   
#define K_Zacc               0.010365
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_44
#define Xacc_Offset          2332
#define Yacc_Offset          2295    
#define Zacc_Offset          2372
#define K_Xacc               0.010300  
#define K_Yacc               0.010320   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_45
#define Xacc_Offset          2344
#define Yacc_Offset          2343    
#define Zacc_Offset          2358
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
  
#elif defined IMU_V19_46
#define Xacc_Offset          2370
#define Yacc_Offset          2370    
#define Zacc_Offset          2370
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
  
#elif defined IMU_V19_47
#define Xacc_Offset          2332
#define Yacc_Offset          2349    
#define Zacc_Offset          2355
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010265
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_48
#define Xacc_Offset          2322
#define Yacc_Offset          2337 
#define Zacc_Offset          2344
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010460
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_49
#define Xacc_Offset          2378
#define Yacc_Offset          2343   
#define Zacc_Offset          2360
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010370
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_50
#define Xacc_Offset          2358
#define Yacc_Offset          2310   
#define Zacc_Offset          2361
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010455
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_51
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
  
#elif defined IMU_V19_52
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_53
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_54
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
#elif defined IMU_V19_55
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_56
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
#elif defined IMU_V19_57
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
  
  
#elif defined IMU_V19_58
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_59
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_60
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
  
#elif defined IMU_V19_61
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_62
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_63
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_64
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
  
#elif defined IMU_V19_65
#define Xacc_Offset          2367
#define Yacc_Offset          2350    
#define Zacc_Offset          2342
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_01 
#define Xacc_Offset          2350
#define Yacc_Offset          2365 
#define Zacc_Offset          2366
#define K_Xacc               0.010335  
#define K_Yacc               0.010310   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_02 
#define Xacc_Offset          2360
#define Yacc_Offset          2363   
#define Zacc_Offset          2334
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_03
#define Xacc_Offset          2336
#define Yacc_Offset          2334  
#define Zacc_Offset          2347
#define K_Xacc               0.010300  
#define K_Yacc               0.010390   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_04  
#define Xacc_Offset          2420
#define Yacc_Offset          2370   
#define Zacc_Offset          2375
#define K_Xacc               0.010300  
#define K_Yacc               0.010300   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_05  
#define Xacc_Offset          2353
#define Yacc_Offset          2324  
#define Zacc_Offset          2353
#define K_Xacc               0.010370  
#define K_Yacc               -0.010440  
#define K_Zacc               0.010410
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_06  
#define Xacc_Offset          2363
#define Yacc_Offset          2371    
#define Zacc_Offset          2353
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010420
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_07 
#define Xacc_Offset          2358
#define Yacc_Offset          2325    
#define Zacc_Offset          2332
#define K_Xacc               0.010350 
#define K_Yacc               0.010460   
#define K_Zacc               0.010420
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_08 
#define Xacc_Offset          2368
#define Yacc_Offset          2368   
#define Zacc_Offset          2329
#define K_Xacc               0.010350 
#define K_Yacc               -0.01040 
#define K_Zacc               0.010390
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_09 
#define Xacc_Offset          2350
#define Yacc_Offset          2372   
#define Zacc_Offset          2364
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_10
#define Xacc_Offset          2362
#define Yacc_Offset          2367   
#define Zacc_Offset          2364.5
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_11
#define Xacc_Offset          2350
#define Yacc_Offset          2345 
#define Zacc_Offset          2344
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010440
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_12
#define Xacc_Offset          2385
#define Yacc_Offset          2389   
#define Zacc_Offset          2359
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_13
#define Xacc_Offset          2353
#define Yacc_Offset          2405   
#define Zacc_Offset          2355
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010370
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_14
#define Xacc_Offset          2388
#define Yacc_Offset          2374
#define Zacc_Offset          2366
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_15
#define Xacc_Offset          2366
#define Yacc_Offset          2300  
#define Zacc_Offset          2349
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010360
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_16
#define Xacc_Offset          2355
#define Yacc_Offset          2362   
#define Zacc_Offset          2338
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_17
#define Xacc_Offset          2390
#define Yacc_Offset          2340   
#define Zacc_Offset          2328
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010520
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_18
#define Xacc_Offset          2362
#define Yacc_Offset          2367   
#define Zacc_Offset          2364.5
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_19
#define Xacc_Offset          2383
#define Yacc_Offset          2340   
#define Zacc_Offset          2364.5
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_20
#define Xacc_Offset          2374
#define Yacc_Offset          2398   
#define Zacc_Offset          2351.5
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020869  
  
#elif defined IMU_V19_01_21
#define Xacc_Offset          2373
#define Yacc_Offset          2370   
#define Zacc_Offset          2384.5
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010880
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
#elif defined IMU_V19_01_22
#define Xacc_Offset          2362
#define Yacc_Offset          2367   
#define Zacc_Offset          2360
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
#elif defined IMU_V19_01_23
#define Xacc_Offset          2387
#define Yacc_Offset          2385   
#define Zacc_Offset          2352
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_24
#define Xacc_Offset          2346
#define Yacc_Offset          2358   
#define Zacc_Offset          2364.5
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_25
#define Xacc_Offset          2397
#define Yacc_Offset          2335   
#define Zacc_Offset          2365
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_26
#define Xacc_Offset          2387
#define Yacc_Offset          2379   
#define Zacc_Offset          2357
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_27
#define Xacc_Offset          2370
#define Yacc_Offset          2396   
#define Zacc_Offset          2345
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010480
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_28
#define Xacc_Offset          2378
#define Yacc_Offset          2340   
#define Zacc_Offset          2371.5
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_29
#define Xacc_Offset          2394
#define Yacc_Offset          2363   
#define Zacc_Offset          2376
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010200
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_30
#define Xacc_Offset          2346
#define Yacc_Offset          2380   
#define Zacc_Offset          2331
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010480
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_31
#define Xacc_Offset          2357
#define Yacc_Offset          2370   
#define Zacc_Offset          2362
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010240
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_32
#define Xacc_Offset          2352
#define Yacc_Offset          2384   
#define Zacc_Offset          2357
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_33
#define Xacc_Offset          2308
#define Yacc_Offset          2382   
#define Zacc_Offset          2353
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_34
#define Xacc_Offset          2373
#define Yacc_Offset          2375   
#define Zacc_Offset          2352.5
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_35
#define Xacc_Offset          2330
#define Yacc_Offset          2330   
#define Zacc_Offset          2354
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
  
#elif defined IMU_V19_01_36
#define Xacc_Offset          2346
#define Yacc_Offset          2304   
#define Zacc_Offset          2352
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_37
#define Xacc_Offset          2334
#define Yacc_Offset          2387   
#define Zacc_Offset          2378
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010440
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_38
#define Xacc_Offset          2344
#define Yacc_Offset          2366   
#define Zacc_Offset          2359
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_39
#define Xacc_Offset          2362
#define Yacc_Offset          2367   
#define Zacc_Offset          2364.5
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_40
#define Xacc_Offset          2351
#define Yacc_Offset          2343  
#define Zacc_Offset          2325
#define K_Xacc               0.010350 
#define K_Yacc               0.010280   
#define K_Zacc               0.010440
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500  
  
#elif defined IMU_V19_01_41
#define Xacc_Offset          2335
#define Yacc_Offset          2382
#define Zacc_Offset          2367
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010250
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_42
#define Xacc_Offset          2355
#define Yacc_Offset          2384
#define Zacc_Offset          2371
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_43
#define Xacc_Offset          2350
#define Yacc_Offset          2362
#define Zacc_Offset          2355
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_44
#define Xacc_Offset          2342
#define Yacc_Offset          2322
#define Zacc_Offset          2342
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010450
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
  
#elif defined IMU_V19_01_45
#define Xacc_Offset          2338
#define Yacc_Offset          2366
#define Zacc_Offset          2348
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.0103000
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_46
#define Xacc_Offset          2342
#define Yacc_Offset          2368
#define Zacc_Offset          2355
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010250
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_47
#define Xacc_Offset          2342
#define Yacc_Offset          2348
#define Zacc_Offset          2359
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_48
#define Xacc_Offset          2332
#define Yacc_Offset          2335
#define Zacc_Offset          2348
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
  
#elif defined IMU_V19_01_49
#define Xacc_Offset          2332
#define Yacc_Offset          2368
#define Zacc_Offset          2352
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_50
#define Xacc_Offset          2377
#define Yacc_Offset          2332
#define Zacc_Offset          2361
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_51
#define Xacc_Offset          2368
#define Yacc_Offset          2374
#define Zacc_Offset          2356
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010180
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869  
  
#elif defined IMU_V19_01_52
#define Xacc_Offset          2358
#define Yacc_Offset          2332
#define Zacc_Offset          2355
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_53
#define Xacc_Offset          2340
#define Yacc_Offset          2358
#define Zacc_Offset          2366
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010200
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_54
#define Xacc_Offset          2330
#define Yacc_Offset          2355
#define Zacc_Offset          2340
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010430
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_55
#define Xacc_Offset          2350
#define Yacc_Offset          2365
#define Zacc_Offset          2371
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010330
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
  
#elif defined IMU_V19_01_56
#define Xacc_Offset          2335
#define Yacc_Offset          2370
#define Zacc_Offset          2360
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_57
#define Xacc_Offset          2332
#define Yacc_Offset          2345
#define Zacc_Offset          2367
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_58
#define Xacc_Offset          2360
#define Yacc_Offset          2367
#define Zacc_Offset          2357
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010370
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030800
  
#elif defined IMU_V19_01_59
#define Xacc_Offset          2322
#define Yacc_Offset          2335
#define Zacc_Offset          2350
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_60
#define Xacc_Offset          2368
#define Yacc_Offset          2332
#define Zacc_Offset          2382
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010200
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
  
#elif defined IMU_V19_01_61
#define Xacc_Offset          2345
#define Yacc_Offset          2362
#define Zacc_Offset          2365
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0031500
  
#elif defined IMU_V19_01_62
#define Xacc_Offset          2332
#define Yacc_Offset          2363
#define Zacc_Offset          2343
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010400
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_63
#define Xacc_Offset          2342
#define Yacc_Offset          2368
#define Zacc_Offset          2335
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_64
#define Xacc_Offset          2344
#define Yacc_Offset          2362
#define Zacc_Offset          2377
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010250
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_65
#define Xacc_Offset          2338
#define Yacc_Offset          2358
#define Zacc_Offset          2350
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010360
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869
  
#elif defined IMU_V19_01_66
#define Xacc_Offset          2352
#define Yacc_Offset          2352
#define Zacc_Offset          2363
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010180
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
  
#elif defined IMU_V19_01_67
#define Xacc_Offset          2352
#define Yacc_Offset          2356
#define Zacc_Offset          2336
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030869 
  
#elif defined IMU_V19_01_68
#define Xacc_Offset          2328
#define Yacc_Offset          2330
#define Zacc_Offset          2352
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010330
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_69
#define Xacc_Offset          2342
#define Yacc_Offset          2336
#define Zacc_Offset          2368
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0031500
  
#elif defined IMU_V19_01_70
#define Xacc_Offset          2352
#define Yacc_Offset          2328
#define Zacc_Offset          2357
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_71
#define Xacc_Offset          2335
#define Yacc_Offset          2370
#define Zacc_Offset          2360
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_72
#define Xacc_Offset          2345
#define Yacc_Offset          2325
#define Zacc_Offset          2324
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010520
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_73
#define Xacc_Offset          2354
#define Yacc_Offset          2370
#define Zacc_Offset          2362
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_74
#define Xacc_Offset          2345
#define Yacc_Offset          2385
#define Zacc_Offset          2368
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010260
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_75
#define Xacc_Offset          2335
#define Yacc_Offset          2355
#define Zacc_Offset          2353
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010310
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_76
#define Xacc_Offset          2342
#define Yacc_Offset          2348
#define Zacc_Offset          2347
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_77
#define Xacc_Offset          2345
#define Yacc_Offset          2338
#define Zacc_Offset          2338
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_78
#define Xacc_Offset          2354
#define Yacc_Offset          2390
#define Zacc_Offset          2347
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_79
#define Xacc_Offset          2356
#define Yacc_Offset          2370
#define Zacc_Offset          2363
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500
  
#elif defined IMU_V19_01_80
#define Xacc_Offset          2354
#define Yacc_Offset          2350
#define Zacc_Offset          2377
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010260
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_81
#define Xacc_Offset          2325
#define Yacc_Offset          2335
#define Zacc_Offset          2348
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010330
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_82
#define Xacc_Offset          2342
#define Yacc_Offset          2340
#define Zacc_Offset          2358
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_83
#define Xacc_Offset          2305
#define Yacc_Offset          2358
#define Zacc_Offset          2352
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.011200
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_84
#define Xacc_Offset          2345
#define Yacc_Offset          2345
#define Zacc_Offset          2353
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010300
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_85
#define Xacc_Offset          2354
#define Yacc_Offset          2378
#define Zacc_Offset          2350
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010240
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_86
#define Xacc_Offset          2343
#define Yacc_Offset          2328
#define Zacc_Offset          2335
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010500
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_87
#define Xacc_Offset          2330
#define Yacc_Offset          2335
#define Zacc_Offset          2351
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010330
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_88
#define Xacc_Offset          2338
#define Yacc_Offset          2374
#define Zacc_Offset          2317
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010510
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_89
#define Xacc_Offset          2326
#define Yacc_Offset          2326
#define Zacc_Offset          2337
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_90
#define Xacc_Offset          2345
#define Yacc_Offset          2346
#define Zacc_Offset          2348
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010360
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_91
#define Xacc_Offset          2350
#define Yacc_Offset          2348
#define Zacc_Offset          2349
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010350
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_92
#define Xacc_Offset          2335
#define Yacc_Offset          2348
#define Zacc_Offset          2370
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_93
#define Xacc_Offset          2378
#define Yacc_Offset          2374
#define Zacc_Offset          2368
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010320
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_94
#define Xacc_Offset          2350
#define Yacc_Offset          2352
#define Zacc_Offset          2362
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010290
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_95
#define Xacc_Offset          2328
#define Yacc_Offset          2330
#define Zacc_Offset          2319
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010450
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_96
#define Xacc_Offset          2340
#define Yacc_Offset          2360
#define Zacc_Offset          2377
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010310
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_97
#define Xacc_Offset          2355
#define Yacc_Offset          2350
#define Zacc_Offset          2380
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010250
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V19_01_98
#define Xacc_Offset          2350
#define Yacc_Offset          2360
#define Zacc_Offset          2360
#define K_Xacc               0.010350 
#define K_Yacc               -0.010280   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0020500 
  
#elif defined IMU_V20_02_01
#define Xacc_Offset          2357
#define Yacc_Offset          2381
#define Zacc_Offset          2363
#define K_Xacc               0.010240 
#define K_Yacc               -0.010214 
#define K_Zacc               0.010280
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030000*1.036)
  
#elif defined IMU_V20_02_02
#define Xacc_Offset          2346
#define Yacc_Offset          2341
#define Zacc_Offset          2337
#define K_Xacc               0.010397 
#define K_Yacc               -0.010381  
#define K_Zacc               0.010380
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030000 
  
  
#elif defined IMU_V20_02_03
#define Xacc_Offset          2345
#define Yacc_Offset          2335
#define Zacc_Offset          2327
#define K_Xacc               0.01038
#define K_Yacc               -0.01025  
#define K_Zacc               0.01034
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030000*1.0312)
  
  
#elif defined IMU_V20_02_04
#define Xacc_Offset          2366
#define Yacc_Offset          2379
#define Zacc_Offset          2377
#define K_Xacc               0.010161
#define K_Yacc               -0.010108 
#define K_Zacc               0.010208
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           (0.0030520*1.0187)
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030000*1.0175)  
  
  
#elif defined IMU_V20_02_05
#define Xacc_Offset          2395
#define Yacc_Offset          2372
#define Zacc_Offset          2357
#define K_Xacc               0.010256
#define K_Yacc               -0.010224  
#define K_Zacc               0.010160
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           (0.0030520*1.01)
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030000*1.0423) 
  
  
#elif defined IMU_V20_02_06
#define Xacc_Offset          2340
#define Yacc_Offset          2354
#define Zacc_Offset          2363
#define K_Xacc               0.010273 
#define K_Yacc               -0.010166   
#define K_Zacc               0.010150
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030000*1.0397)
  
  
#elif defined IMU_V20_02_07
#define Xacc_Offset          2355
#define Yacc_Offset          2320
#define Zacc_Offset          2310
#define K_Xacc               0.010365 
#define K_Yacc               -0.010224   
#define K_Zacc               0.010340
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_08
#define Xacc_Offset          2368
#define Yacc_Offset          2358
#define Zacc_Offset          2340
#define K_Xacc               0.010224 
#define K_Yacc               -0.010187   
#define K_Zacc               0.010260
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_09
#define Xacc_Offset          2343
#define Yacc_Offset          2325
#define Zacc_Offset          2338
#define K_Xacc               0.010310 
#define K_Yacc               -0.010256   
#define K_Zacc               0.010330
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_10
#define Xacc_Offset          2362
#define Yacc_Offset          2346
#define Zacc_Offset          2357
#define K_Xacc               0.010289 
#define K_Yacc               -0.010182   
#define K_Zacc               0.010254
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_11
#define Xacc_Offset          2343
#define Yacc_Offset          2340
#define Zacc_Offset          2335
#define K_Xacc               0.010453 
#define K_Yacc               -0.010420   
#define K_Zacc               0.010358
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_12
#define Xacc_Offset          2357
#define Yacc_Offset          2355
#define Zacc_Offset          2352
#define K_Xacc               0.010256 
#define K_Yacc               -0.010256   
#define K_Zacc               0.010300
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_13
#define Xacc_Offset          2348
#define Yacc_Offset          2363
#define Zacc_Offset          2360
#define K_Xacc               0.010305 
#define K_Yacc               -0.010278   
#define K_Zacc               0.010365
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
  
#elif defined IMU_V20_02_14
#define Xacc_Offset          2356
#define Yacc_Offset          2357
#define Zacc_Offset          2340
#define K_Xacc               0.010376 
#define K_Yacc               -0.010299   
#define K_Zacc               0.010240
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
  
#elif defined IMU_V20_02_15
#define Xacc_Offset          2320
#define Yacc_Offset          2369
#define Zacc_Offset          2346
#define K_Xacc               0.010267 
#define K_Yacc               -0.010214   
#define K_Zacc               0.010278
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_16
#define Xacc_Offset          2369
#define Yacc_Offset          2371
#define Zacc_Offset          2356
#define K_Xacc               0.010235 
#define K_Yacc               -0.010251   
#define K_Zacc               0.010310
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_17
#define Xacc_Offset          2336
#define Yacc_Offset          2369
#define Zacc_Offset          2335
#define K_Xacc               0.010267 
#define K_Yacc               -0.010214   
#define K_Zacc               0.010278
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500
  
  
#elif defined IMU_V20_02_18
#define Xacc_Offset          2348
#define Yacc_Offset          2373
#define Zacc_Offset          2331
#define K_Xacc               0.010316 
#define K_Yacc               -0.01019771  
#define K_Zacc               0.010262
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030500*1.013) 
  
  
#elif defined IMU_V20_02_19
#define Xacc_Offset          2300
#define Yacc_Offset          2322
#define Zacc_Offset          2328
#define K_Xacc               0.010289
#define K_Yacc               -0.010192
#define K_Zacc               0.010405
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030500*1.016)  
  
  
#elif defined IMU_V20_02_20
#define Xacc_Offset          2310
#define Yacc_Offset          2352
#define Zacc_Offset          2356
#define K_Xacc               0.010256
#define K_Yacc               -0.010267  
#define K_Zacc               0.010267
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_21
#define Xacc_Offset          2340
#define Yacc_Offset          2337
#define Zacc_Offset          2337
#define K_Xacc               0.010262
#define K_Yacc               -0.010187 
#define K_Zacc               0.010321
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030500*1.0236)
  
  
#elif defined IMU_V20_02_22
#define Xacc_Offset          2358
#define Yacc_Offset          2345
#define Zacc_Offset          2348
#define K_Xacc               0.010219
#define K_Yacc               -0.010177 
#define K_Zacc               0.010283
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            (0.0030500*1.0273)  
  
#elif defined IMU_V20_02_23
#define Xacc_Offset          2352
#define Yacc_Offset          2368
#define Zacc_Offset          2363
#define K_Xacc               0.01021899
#define K_Yacc               -0.01016068
#define K_Zacc               0.0101871
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_24
#define Xacc_Offset          2368
#define Yacc_Offset          2338
#define Zacc_Offset          2372
#define K_Xacc               0.01021366
#define K_Yacc               -0.0101187
#define K_Zacc               0.01029958
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
#elif defined IMU_V20_02_25
#define Xacc_Offset          2326
#define Yacc_Offset          2370
#define Zacc_Offset          2346
#define K_Xacc               0.01025644
#define K_Yacc               -0.01020834
#define K_Zacc               0.01023501
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_26
#define Xacc_Offset          2350
#define Yacc_Offset          2415
#define Zacc_Offset          2374
#define K_Xacc               0.0101924
#define K_Yacc               -0.01016068
#define K_Zacc               0.01024571
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500    
  
#elif defined IMU_V20_02_27
#define Xacc_Offset          2332
#define Yacc_Offset          2374
#define Zacc_Offset          2344
#define K_Xacc               0.01027796
#define K_Yacc               -0.01027796
#define K_Zacc               0.01020834
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_28
#define Xacc_Offset          2375
#define Yacc_Offset          2418
#define Zacc_Offset          2375
#define K_Xacc               0.01011347
#define K_Yacc               -0.01017124
#define K_Zacc               0.01017652
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_29
#define Xacc_Offset          2320
#define Yacc_Offset          2372
#define Zacc_Offset          2345
#define K_Xacc               0.01019771
#define K_Yacc               -0.01011347
#define K_Zacc               0.01021899
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
  
#elif defined IMU_V20_02_30
#define Xacc_Offset          2372
#define Yacc_Offset          2372
#define Zacc_Offset          2353
#define K_Xacc               0.01035402
#define K_Yacc               -0.01031042
#define K_Zacc               0.01028336
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_31
#define Xacc_Offset          2360
#define Yacc_Offset          2387
#define Zacc_Offset          2333
#define K_Xacc               0.01025644
#define K_Yacc               -0.01022432
#define K_Zacc               0.01029958
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500     
  
#elif defined IMU_V20_02_32
#define Xacc_Offset          2314
#define Yacc_Offset          2352
#define Zacc_Offset          2333
#define K_Xacc               0.01023501
#define K_Yacc               -0.01010304
#define K_Zacc               0.01024036
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
#elif defined IMU_V20_02_33
#define Xacc_Offset          2339
#define Yacc_Offset          2380
#define Zacc_Offset          2330
#define K_Xacc               0.01025644
#define K_Yacc               -0.01026181
#define K_Zacc               0.01033217
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500    
  
#elif defined IMU_V20_02_34
#define Xacc_Offset          2334
#define Yacc_Offset          2365
#define Zacc_Offset          2328
#define K_Xacc               0.01021366
#define K_Yacc               -0.01015542
#define K_Zacc               0.01033763
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_35
#define Xacc_Offset          2346
#define Yacc_Offset          2378
#define Zacc_Offset          2355
#define K_Xacc               0.01025107
#define K_Yacc               -0.01012916
#define K_Zacc               0.01020302
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_36
#define Xacc_Offset          2366
#define Yacc_Offset          2402
#define Zacc_Offset          2372
#define K_Xacc               0.01016068
#define K_Yacc               -0.01001524
#define K_Zacc               0.01023501
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_37
#define Xacc_Offset          2356
#define Yacc_Offset          2389
#define Zacc_Offset          2372
#define K_Xacc               0.01020302
#define K_Yacc               -0.01016068
#define K_Zacc               0.01016596
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_38
#define Xacc_Offset          2363
#define Yacc_Offset          2375
#define Zacc_Offset          2331
#define K_Xacc               0.01020302
#define K_Yacc               -0.01016068
#define K_Zacc               0.01016596
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500    
  
#elif defined IMU_V20_02_39
#define Xacc_Offset          2344
#define Yacc_Offset          2378
#define Zacc_Offset          2379
#define K_Xacc               0.01026181
#define K_Yacc               -0.01031042
#define K_Zacc               0.01020302
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
#elif defined IMU_V20_02_40
#define Xacc_Offset          2346
#define Yacc_Offset          2397
#define Zacc_Offset          2342
#define K_Xacc               0.01032763
#define K_Yacc               -0.01026181
#define K_Zacc               0.01034855
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500    
  
#elif defined IMU_V20_02_41
#define Xacc_Offset          2355
#define Yacc_Offset          2393
#define Zacc_Offset          2376
#define K_Xacc               0.01032763
#define K_Yacc               -0.01026181
#define K_Zacc               0.01034855
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500    
  
#elif defined IMU_V20_02_42
#define Xacc_Offset          2370
#define Yacc_Offset          2402
#define Zacc_Offset          2340
#define K_Xacc               0.01026181
#define K_Yacc               -0.01015016
#define K_Zacc               0.01022432
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_43
#define Xacc_Offset          2345
#define Yacc_Offset          2376
#define Zacc_Offset          2355
#define K_Xacc               0.01017652
#define K_Yacc               -0.01022966
#define K_Zacc               0.01022966
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500   
  
#elif defined IMU_V20_02_44
#define Xacc_Offset          2331
#define Yacc_Offset          2385
#define Zacc_Offset          2346
#define K_Xacc               0.01039247
#define K_Yacc               -0.01030500
#define K_Zacc               0.01034855
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_45
#define Xacc_Offset          2358
#define Yacc_Offset          2396
#define Zacc_Offset          2372
#define K_Xacc               0.01032129
#define K_Yacc               -0.01020302
#define K_Zacc               0.01037595
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_46
#define Xacc_Offset          2352
#define Yacc_Offset          2392
#define Zacc_Offset          2336
#define K_Xacc               0.01028336
#define K_Yacc               -0.01022432
#define K_Zacc               0.01026181
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_47
#define Xacc_Offset          2336
#define Yacc_Offset          2362
#define Zacc_Offset          2349
#define K_Xacc               0.01038696
#define K_Yacc               -0.01036497
#define K_Zacc               0.01028336
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_V20_02_48
#define Xacc_Offset          2352
#define Yacc_Offset          2328
#define Zacc_Offset          2356
#define K_Xacc               0.01020834
#define K_Yacc               -0.01016068
#define K_Zacc               0.01033217
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
  
#elif defined IMU_V20_02_49
#define Xacc_Offset          2369
#define Yacc_Offset          2370
#define Zacc_Offset          2348
#define K_Xacc               0.01023501
#define K_Yacc               -0.01016068
#define K_Zacc               0.01026719
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
  
#elif defined IMU_V20_02_50
#define Xacc_Offset          2369
#define Yacc_Offset          2364
#define Zacc_Offset          2349
#define K_Xacc               0.01007706
#define K_Yacc               -0.0100667
#define K_Zacc               0.01012916
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
  
#elif defined IMU_V20_02_51
#define Xacc_Offset          2369
#define Yacc_Offset          2364
#define Zacc_Offset          2349
#define K_Xacc               0.01007706
#define K_Yacc               -0.0100667
#define K_Zacc               0.01012916
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
  
#elif defined IMU_V20_02_52
#define Xacc_Offset          2393
#define Yacc_Offset          2390
#define Zacc_Offset          2355
#define K_Xacc               0.01017652
#define K_Yacc               -0.01020302
#define K_Zacc               0.01022432
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
  
#elif defined IMU_V20_02_53
#define Xacc_Offset          2383
#define Yacc_Offset          2361
#define Zacc_Offset          2369
#define K_Xacc               0.0101187
#define K_Yacc               -0.01001524
#define K_Zacc               0.01003576
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
  
#elif defined IMU_V20_02_54
#define Xacc_Offset          2380
#define Yacc_Offset          2376
#define Zacc_Offset          2348
#define K_Xacc               0.0101344
#define K_Yacc               -0.01024036
#define K_Zacc               0.0101871
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500  
  
  
#elif defined IMU_V20_02_55
#define Xacc_Offset          2379
#define Yacc_Offset          2366
#define Zacc_Offset          2350
#define K_Xacc               0.0101449
#define K_Yacc               -0.01018181
#define K_Zacc               0.0101924
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500    
  
  
#elif defined IMU_V20_02_56
#define Xacc_Offset          2342
#define Yacc_Offset          2339
#define Zacc_Offset          2343
#define K_Xacc               0.01024571
#define K_Yacc               -0.0101187
#define K_Zacc               0.01022432
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_57
#define Xacc_Offset          2376
#define Yacc_Offset          2350
#define Zacc_Offset          2367
#define K_Xacc               0.01015016
#define K_Yacc               -0.01015542
#define K_Zacc               0.010305
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_58
#define Xacc_Offset          2369
#define Yacc_Offset          2380
#define Zacc_Offset          2359
#define K_Xacc               0.01015016
#define K_Yacc               -0.01017124
#define K_Zacc               0.01021366
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_59
#define Xacc_Offset          2357
#define Yacc_Offset          2364
#define Zacc_Offset          2348
#define K_Xacc               0.01036497
#define K_Yacc               -0.01033763
#define K_Zacc               0.01035402
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
#elif defined IMU_V20_02_60
#define Xacc_Offset          2365
#define Yacc_Offset          2343
#define Zacc_Offset          2368
#define K_Xacc               0.01019771
#define K_Yacc               -0.01013965
#define K_Zacc               0.01019771
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.0030500 
  
  
#elif defined IMU_CALIBARATION_AUTO
#define Xacc_Offset          2365
#define Yacc_Offset          2343
#define Zacc_Offset          2368
#define K_Xacc               0.01019771
#define K_Yacc               -0.01013965
#define K_Zacc               0.01019771
  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////  
#define RollRate_Offset      2376
#define PitchRate_Offset     2319
#define YawRate_Offset       2333
#define K_RollRate           0.0030520
#define K_PitchRate          0.0030520
#define K_YawRate            0.00311609 
    
#endif
#ifdef __cplusplus
}
#endif
#endif

/************************ (C) COPYRIGHT AOYIWEIYENG *****END OF FILE***********/   


