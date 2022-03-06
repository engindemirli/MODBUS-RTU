/*
 * global.c
 *
 *  Created on: Feb 12, 2022
 *      Author: ENGIN
 */
#include "global.h"

extern DAC_HandleTypeDef hdac;
extern ADC_HandleTypeDef hadc;
extern UART_HandleTypeDef huart1;

uint8_t Do1 = 0;
uint8_t Do2 = 0;
uint8_t Do3 = 0;
uint8_t Do4 = 0;

void set_do(uint8_t *a)
{
	uint8_t chek = 0;
	for(uint8_t i = 0; i<4; i++)
	{
		chek = a[i] + chek;
	}
	if(chek != a[4]);

	else if(a[2] == 0xff)
	{
		if(a[1] == 0x00)
			HAL_GPIO_WritePin(D_O_1_GPIO_Port, D_O_1_Pin, GPIO_PIN_SET);
		if(a[1] == 0x10)
			HAL_GPIO_WritePin(D_O_2_GPIO_Port, D_O_2_Pin, GPIO_PIN_SET);
		if(a[1] == 0x20)
			HAL_GPIO_WritePin(D_O_3_GPIO_Port, D_O_3_Pin, GPIO_PIN_SET);
		if(a[1] == 0x40)
			HAL_GPIO_WritePin(D_O_4_GPIO_Port, D_O_4_Pin, GPIO_PIN_SET);
	}
	else if(a[2] == 0xBB)
	{
		if(a[1] == 0x00)
			HAL_GPIO_WritePin(D_O_1_GPIO_Port, D_O_1_Pin, GPIO_PIN_RESET);
		if(a[1] == 0x10)
			HAL_GPIO_WritePin(D_O_2_GPIO_Port, D_O_2_Pin, GPIO_PIN_RESET);
		if(a[1] == 0x20)
			HAL_GPIO_WritePin(D_O_3_GPIO_Port, D_O_3_Pin, GPIO_PIN_RESET);
		if(a[1] == 0x40)
			HAL_GPIO_WritePin(D_O_4_GPIO_Port, D_O_4_Pin, GPIO_PIN_RESET);
	}
}

void set_dac(uint8_t *a)
{
	uint8_t chek = 0;
	for(uint8_t i = 0; i<5; i++)
	{
		chek = a[i] + chek;
	}
	if(chek != a[5]);

	else if(a[1] == 0xff)
	{
		t_short b;
		b.B.L = a[2];
		b.B.H = a[3];
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, b.S);
	}
	else if(a[1] == 0xBB)
	{
		t_short b;
		b.B.L = a[2];
		b.B.H = a[3];
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, b.S);
	}

}


void ADC_config_chanel(uint32_t channel, uint8_t val)
{
  ADC_ChannelConfTypeDef sConfig;

  sConfig.Channel = channel;
  sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;

  if(val == 1)
  {
    sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  }
  else
  {
    sConfig.Rank = ADC_RANK_NONE;
  }

  HAL_ADC_ConfigChannel(&hadc, &sConfig);
}

uint32_t ADC_read_1_chanel(uint32_t channel)
{
  uint32_t adc_val;

  ADC_config_chanel(channel, 1);

  HAL_ADCEx_Calibration_Start(&hadc);

  HAL_ADC_Start(&hadc);
  HAL_ADC_PollForConversion(&hadc, 1000);
  adc_val = HAL_ADC_GetValue(&hadc);
  HAL_ADC_Stop(&hadc);

  ADC_config_chanel(channel, 0);

  return adc_val;
}

void ADC_Send(uint8_t* buf)
{
	t_short a;
	buf[0] = 0xAA;
	buf[1] = 0xFF;
	//adc data to buf
	a.S = ADC_read_1_chanel(ADC_CHANNEL_0);
	buf[2] = a.B.H ;
	buf[3] = a.B.L ;

	a.S = ADC_read_1_chanel(ADC_CHANNEL_1);
	buf[4] = a.B.H ;
	buf[5] = a.B.L ;

	a.S = ADC_read_1_chanel(ADC_CHANNEL_2);
	buf[6] = a.B.H ;
	buf[7] = a.B.L ;

	a.S = ADC_read_1_chanel(ADC_CHANNEL_3);
	buf[8] = a.B.H;
	buf[9] = a.B.L ;
	//gpio data to buf
	buf[10] = HAL_GPIO_ReadPin(D_I_1_GPIO_Port, D_I_1_Pin);
	buf[11] = HAL_GPIO_ReadPin(D_I_2_GPIO_Port, D_I_2_Pin);
	buf[12] = HAL_GPIO_ReadPin(D_I_3_GPIO_Port, D_I_3_Pin);
	buf[13] = HAL_GPIO_ReadPin(D_I_4_GPIO_Port, D_I_4_Pin);
	buf[14] = 0xEE;
}



void Uart_send(uint8_t* buf)
{
	uint8_t chek = 0;
	for(uint8_t i = 0; i<10;i++)
	{
		chek = chek + buf[i];
	}
	if(chek ==  buf[10])
	{
		uint8_t data[8];//= "0123456789" ;
		data[0] = buf[1];
		data[1] = buf[2];
		data[2] = buf[3];
		data[3] = buf[4];
		data[4] = buf[5];
		data[5] = buf[6];
		data[6] = buf[7];
		data[7] = buf[8];
		HAL_UART_Transmit_IT(&huart1, data, 8);
		HAL_Delay(100);
	}

}
