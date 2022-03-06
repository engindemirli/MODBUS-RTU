/*
 * server_sett.h
 *
 *  Created on: Feb 12, 2022
 *      Author: ENGIN
 */

#ifndef INC_SERVER_SETT_H_
#define INC_SERVER_SETT_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"

#define W5500_select() HAL_GPIO_WritePin(W5500_SCSN_GPIO_Port,W5500_SCSN_Pin,GPIO_PIN_RESET);
#define W5500_release() HAL_GPIO_WritePin(W5500_SCSN_GPIO_Port,W5500_SCSN_Pin, GPIO_PIN_SET);

#define W5500_Reset() HAL_GPIO_WritePin(W5500_NRST_GPIO_Port, W5500_NRST_Pin, GPIO_PIN_RESET);
#define W5500_NoReset() HAL_GPIO_WritePin(W5500_NRST_GPIO_Port, W5500_NRST_Pin, GPIO_PIN_SET);

#define W5500_rx() W5500_rxtx(0xff)
#define W5500_tx(data) W5500_rxtx(data)

#define HTTP_IDLE 0

#define DATA_BUF_SIZE	50

#define CONNECTED    1
#define DISCONNECTED 0



 extern wiz_NetInfo gWIZNETINFO;
 extern SPI_HandleTypeDef hspi2;

 extern uint32_t sentsize[_WIZCHIP_SOCK_NUM_];
 extern uint8_t http_state[_WIZCHIP_SOCK_NUM_];
 extern uint8_t gDATABUF[DATA_BUF_SIZE];

 uint8_t W5500_Init(void);
 void  wizchip_select(void);
 void  wizchip_deselect(void);
 uint8_t W5500_rxtx(uint8_t data);
 void  wizchip_write(uint8_t wb);
 uint8_t wizchip_read(void);
 void network_init(void);
 void HTTP_reset(uint8_t sockn);





 typedef union {
	 uint16_t S;
	 struct {
		 uint8_t L;
         uint8_t H;
     }B;
 }t_short;


#ifdef __cplusplus
}
#endif

#endif /* INC_SERVER_SETT_H_ */
