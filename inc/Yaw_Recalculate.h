#ifndef __STM32F10x_Yaw_Recalculate_H
#define __STM32F10x_Yaw_Recalculate_H
#ifdef __cplusplus
extern "C" {
#endif
  
#include "stm32f4xx.h"
#include "stdio.h"
#include "structural.h"
//#include "config_init.h"    
#include "stm32f4xx_it.h"
#include "math.h"
#include "stdlib.h"
#include "Mag_Correct.h"

  
void Yaw_Recalculate(void);
extern float Yaw_Angle;
#ifdef __cplusplus
}
#endif

#endif