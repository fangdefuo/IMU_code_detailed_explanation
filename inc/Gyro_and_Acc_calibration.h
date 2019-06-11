#ifndef __GYRO_AND_ACC_CALIBRATION_H
#define __GYRO_AND_ACC_CALIBRATION_H

#include "canIMUDecode.h"
#include"filter.h" 
#include"argument_config.h"
#include"Mag_Correct.h" 
#include"Imu_health.h"
#include"eeprom.h"
#include"Fc_Command_Decode.h"

void Gyro_and_Acc_Calibration_Operation(void);

#define GYRO_AND_ACC_CALIBRATION_STATE 0xFF01
#define GYRO_CALIBRATION_SAVE_STATE    0xFF02
#define ACC_CALIBRATION_SAVE_STATE     0xFF03
#define ERASE_FLASH_STATE              0xFF04
#define CALIBRATEDDATA_FEEDBACK        0xFF05
extern uint16_t Gyro_and_Acc_Calibration_Operation_Step;
#endif