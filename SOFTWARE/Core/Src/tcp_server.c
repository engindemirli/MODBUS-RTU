/*
 * tcp_server.c
 *
 *  Created on: Feb 12, 2022
 *      Author: ENGIN
 */

#include "tcp_server.h"

void TCP_server(unsigned char sn, uint8_t* buf, uint16_t local_port)
{
	uint16_t len=0;

	switch(getSn_SR(sn))
	{
		case SOCK_CLOSED:
			socket(sn ,Sn_MR_TCP,local_port,Sn_MR_ND);
		  break;
		case SOCK_INIT:
			listen(sn);
		  break;
		case SOCK_ESTABLISHED:
			if(getSn_IR(sn) & Sn_IR_CON)
			{
				setSn_IR(sn, Sn_IR_CON);
			}
			//Server.Tmr = TCP_TIMEOUT;
		    //Server.Connected = TRUE;
			len=getSn_RX_RSR(sn);
			if(len>0)
			{
				//Server.Status = CONNECTED;
				//Server.Tmr = TCP_TIMEOUT;
				recv(sn,buf,len);
				if(buf[0] == 0xFA && buf[3] == 0XC3)
				{
					set_do(buf);
				}
				else if(buf[0] == 0xC3 && buf[4] == 0XFA)
				{
					set_dac(buf);
				}
				else if(buf[0] == 0xFF && buf[9] == 0XFF)
				{
					Uart_send(buf);
				}
				//send(sn,buf, len);
			}

			ADC_Send(buf);
			send(sn,buf, 15);
			break;
		case SOCK_CLOSE_WAIT:
			close(sn);
//			Server.Connected = FALSE;
		  break;
	}
}
