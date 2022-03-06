/*
 * server_sett.c
 *
 *  Created on: Feb 12, 2022
 *      Author: ENGIN
 */

#include "server_sett.h"

extern wiz_NetInfo gWIZNETINFO;
extern SPI_HandleTypeDef hspi2;

uint32_t sentsize[_WIZCHIP_SOCK_NUM_];
uint8_t http_state[_WIZCHIP_SOCK_NUM_];
uint8_t gDATABUF[DATA_BUF_SIZE];

wiz_NetInfo gWIZNETINFO = { .mac = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED},
							.ip = {200, 200, 201, 225},
							.sn = {255,255,255,0},
							.gw = {192, 168, 1, 1},
							.dns = {0,0,0,0},
							.dhcp = NETINFO_STATIC };


 uint8_t W5500_Init(void)
 {
	 uint8_t i;
	 uint8_t memsize[2][8] = {{2,2,2,2,2,2,2,2},{2,2,2,2,2,2,2,2}};

	 gWIZNETINFO.ip[0] = 192;
	 gWIZNETINFO.ip[1] = 168;
	 gWIZNETINFO.ip[2] = 1;
	 gWIZNETINFO.ip[3] = 125;

	 gWIZNETINFO.gw[0] = 192;
	 gWIZNETINFO.gw[1] = 168;
	 gWIZNETINFO.gw[2] = 1;
	 gWIZNETINFO.gw[3] = 1;

	 gWIZNETINFO.dhcp = NETINFO_DHCP;

//	 printf("MAC: %02d:%02d:%02d:%02d:%02d:%02d\r\n", gWIZNETINFO.mac[0],gWIZNETINFO.mac[1],gWIZNETINFO.mac[2],gWIZNETINFO.mac[3],gWIZNETINFO.mac[4],gWIZNETINFO.mac[5]);
//	 printf("IP: %d.%d.%d.%d : %d\r\n", gWIZNETINFO.ip[0],gWIZNETINFO.ip[1],gWIZNETINFO.ip[2],gWIZNETINFO.ip[3],Server.Port);
//	 printf("GW: %02d.%02d.%02d.%02d\r\n", gWIZNETINFO.gw[0],gWIZNETINFO.gw[1],gWIZNETINFO.gw[2],gWIZNETINFO.gw[3]);

	 W5500_Reset();
	 HAL_Delay(20);
	 W5500_NoReset();
	 HAL_Delay(20);

	 reg_wizchip_cs_cbfunc(wizchip_select, wizchip_deselect);
	 reg_wizchip_spi_cbfunc(wizchip_read, wizchip_write);
	 if(ctlwizchip(CW_INIT_WIZCHIP,(void*)memsize) == -1)
	 {
		  return false;
	 }
	 network_init();

	 for(i=0;i<_WIZCHIP_SOCK_NUM_;i++)
		 HTTP_reset(i);

	 return true;
 }

 void  wizchip_select(void)
 {
	 W5500_select();
 }
 void  wizchip_deselect(void)
 {
	 W5500_release();
 }
 uint8_t W5500_rxtx(uint8_t data)
 {
	 uint8_t rxdata;
	 HAL_SPI_TransmitReceive(&hspi2, &data, &rxdata, 1, 50);
	 return (rxdata);
 }
 void  wizchip_write(uint8_t wb)
 {
	 W5500_tx(wb);
 }
 uint8_t wizchip_read(void)
 {
	 return W5500_rx();
 }
 void network_init(void)
 {
	 uint8_t tmpstr[6];
	 ctlnetwork(CN_SET_NETINFO, (void*)&gWIZNETINFO);
	 ctlwizchip(CW_GET_ID,(void*)tmpstr);

 }
 void HTTP_reset(uint8_t sockn)
 {
	 sentsize[sockn]=0;
	 http_state[sockn]=HTTP_IDLE;
 }


