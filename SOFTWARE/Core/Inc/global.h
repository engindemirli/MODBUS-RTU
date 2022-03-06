/*
 * global.h
 *
 *  Created on: Feb 12, 2022
 *      Author: ENGIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"

#define true  1
#define false 0

 void set_do(uint8_t *a);
 void set_dac(uint8_t *a);

 uint32_t ADC_read_1_chanel(uint32_t channel);
 void ADC_config_chanel(uint32_t channel, uint8_t val);
 void ADC_Send(uint8_t* buf);
 void Uart_send(uint8_t *buf);

 extern uint8_t Do1 ;
 extern uint8_t Do2 ;
 extern uint8_t Do3 ;
 extern uint8_t Do4 ;
 extern uint16_t adc_buf[4];
 extern uint8_t adc_flag;


#ifdef __cplusplus
}
#endif

#endif /* INC_GLOBAL_H_ */
