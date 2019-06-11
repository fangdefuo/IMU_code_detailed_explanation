#ifndef INCLUDED_MAG_CORRECT_H
#define INCLUDED_MAG_CORRECT_H
#include "motor.h"
#include "filter.h" 
#include "argument_config.h" 

void Mag_Correct();
#define DYNAMICIRONMATRIX_1 \
{ \
    {  0.0000315111,  0.0000240593,  0.0000433123,  0.0000080845,  0.0001076371,  0.0000514951}, \
    {  0.0000031115,  0.0000170544,  0.0000317222,  0.0000176923,  0.0000025662, -0.0000144323}, \
    { -0.0000086992, -0.0000446753, -0.0000023486,  0.0000075515,  0.0000555054,  0.0000199034}, \
}

#define DYNAMICIRONMATRIX_2 \
{ \
    { -0.0000000366,  0.0000000080, -0.0000002333, -0.0000002108, -0.0000005614, -0.0000001248}, \
    { -0.0000000923, -0.0000001210, -0.0000001706, -0.0000001022, -0.0000000210,  0.0000000608}, \
    {  0.0000002009,  0.0000002097,  0.0000000511, -0.0000000641, -0.0000002111, -0.0000000039}, \
}

#define DYNAMICIRONMATRIX_3 \
{ \
    { -0.0000000001, -0.0000000001, -0.0000000000, -0.0000000001,  0.0000000001, -0.0000000000}, \
    { -0.0000000001, -0.0000000000, -0.0000000000, -0.0000000001,  0.0000000000, -0.0000000000}, \
    {  0.0000000001, -0.0000000001, -0.0000000000,  0.0000000001,  0.0000000002,  0.0000000001}, \
}

#endif