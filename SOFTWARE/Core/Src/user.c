/*
 * user.c
 *
 *  Created on: Feb 12, 2022
 *      Author: ENGIN
 */
#include "user.h"

extern uint8_t gDATABUF[DATA_BUF_SIZE];
extern DAC_HandleTypeDef hdac;


void Task(void)
{


	HAL_Delay(10);
	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	HAL_DAC_Start(&hdac, DAC_CHANNEL_2);

	W5500_Init();

	while (1)
	{
		for(uint8_t i = 0 ; i < 8 ; i++)
			TCP_server(i, gDATABUF, 5000);
	}//while(1)
}//

