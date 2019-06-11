/*
******************************************************************************
* @file    filter.c
* @author  huzhen
* @version v1.0
* @date    2017-09-20
* @brief   ����IIR��ͨ�˲���
*          ʹ��ʱ����ֱ���IIR_coeff_Typedef�ṹ�壬�������
******************************************************************************
*/

#include "Library_Filter.h"

#define M_PI_F (3.1415926)
// LowPassFilter2p
/*
* @brief  ����IIR�˲�������
* @param  ���ص�IIR_coeff_Typedef�ṹ�壬����Ƶ�ʣ�����
* @note
* @retval void
* @author huzhen
*/
void cal_iir_coeff(IIR_coeff_Typedef *coeff,float fs, float fc)
{
  float fr =0;
  float ohm =0;
  float c =0;

  fr= fs/fc;
  ohm=tanf(M_PI_F/fr);
  c=1.0f+2.0f*cosf(M_PI_F/4.0f)*ohm + ohm*ohm;

  coeff->fc = fc;
  coeff->b0 = ohm*ohm/c;
  coeff->b1 = 2.0f*coeff->b0;
  coeff->b2 = coeff->b0;
  coeff->a1 = 2.0f*(ohm*ohm-1.0f)/c;
  coeff->a2 = (1.0f-2.0f*cosf(M_PI_F/4.0f)*ohm+ohm*ohm)/c;
}

/*
* @brief  �˲�����
* @param  IIR_coeff_Typedef�ṹ�壬���˲���ԭʼ����
* @note
* @retval �˲��������
* @author huzhen
*/
float get_iir_output(IIR_coeff_Typedef* coeff,float sample)
{
  if (coeff->fc <= 0.0f) {
    return sample;
  }
  else
  {
    float y_0 = sample - coeff->y_1 * coeff->a1 - coeff->y_2 * coeff->a2;
    float output = y_0 * coeff->b0 + coeff->y_1 * coeff->b1 + coeff->y_2 * coeff->b2;
    coeff->y_2 = coeff->y_1;
    coeff->y_1 = y_0;
    return output;
  }
}