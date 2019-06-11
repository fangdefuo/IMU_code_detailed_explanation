#ifndef __SENSOR_CALIBRATION_H
#define __SENSOR_CALIBRATION_H

#include"hmc5983.h"
#include"filter.h" 
#include"argument_config.h"
#include"Mag_Correct.h" 
#include"Imu_health.h"
#include"eeprom.h"
#include"Fc_Command_Decode.h"
void HMC5983L_Start_CalibXY(void);
void HMC5983L_Start_CalibZ(void);
void HMC5983L_Calib(void);
void HMC5983L_Save_CalibZ(void);
void HMC5983L_Save_CalibXY(void);
void ACC_Calib(void);
void Is_In_Sensor_Calib_State(void);
float HMC5983_XYFactor_Check_APutout(void);
float HMC5983_XZFactor_Check_APutout(void);
void HMC5983L_Stop_CalibXY(void);
#endif