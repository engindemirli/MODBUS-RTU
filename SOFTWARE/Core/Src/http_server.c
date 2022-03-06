///*
// * http_server.c
// *
// *  Created on: Feb 12, 2022
// *      Author: ENGIN
// */
//#include "http_server.h"
//
// extern uint8_t Do1 ;
// extern uint8_t Do2 ;
// extern uint8_t Do3 ;
// extern uint8_t Do4 ;
//
//int32_t tcp_http_mt(uint8_t sn, uint8_t* buf, uint16_t port)
// {
//    int32_t ret;
//    uint32_t size = 0;
//    uint16_t cntBytesTX;
//    uint32_t sampleTX;
//    uint8_t flagHtmlGen = 0;
//    char *url,*p;
//    uint16_t blocklen=0;
//
//    switch(getSn_SR(sn))
//    {
//       case SOCK_ESTABLISHED :
//
//          if(getSn_IR(sn) & Sn_IR_CON)
//          {
//             setSn_IR(sn,Sn_IR_CON);
//          }
//
//          if((size = getSn_RX_RSR(sn)) > 0)
//          {
//             if(size > DATA_BUF_SIZE) size = DATA_BUF_SIZE;
//             ret = recv(sn,buf,size);
//
//             HTTP_reset(sn);
//
//             if(ret <= 0)
//             return ret;
//
//             url =(char*) buf + 4;
//
//             if((http_state[sn]==HTTP_IDLE)&&(memcmp(buf, "GET ", 4)==0)&&((p = strchr(url, ' '))))// extract URL from request header
//             {
//               *(p++) = 0;//making zeroed url string
//
// 				if ((url != NULL)&&(strncmp("/favicon.ico",url,12) != 0))
// 				{
// 					flagHtmlGen = 1;
// 					if (strncmp("/S1/ON",url,6) == 0)
// 					{
// 						Do1 = 1;
// 						HAL_GPIO_WritePin(D_O_1_GPIO_Port, D_O_1_Pin, GPIO_PIN_SET);
// 					}
// 					else if (strncmp("/S1/OFF",url,6) == 0)
// 					{
// 						Do1 = 0;
// 						HAL_GPIO_WritePin(D_O_1_GPIO_Port, D_O_1_Pin, GPIO_PIN_RESET);
// 					}
// 					else if (strncmp("/S2/ON",url,6) == 0)
// 					{
// 						Do2 = 1;
// 						HAL_GPIO_WritePin(D_O_2_GPIO_Port, D_O_2_Pin, GPIO_PIN_SET);
// 					}
// 					else if (strncmp("/S2/OFF",url,6) == 0)
// 					{
// 						Do2 = 0;
// 						HAL_GPIO_WritePin(D_O_2_GPIO_Port, D_O_2_Pin, GPIO_PIN_RESET);
// 					}
// 					else if (strncmp("/S3/ON",url,6) == 0)
// 					{
// 						Do3 = 1;
// 						HAL_GPIO_WritePin(D_O_3_GPIO_Port, D_O_3_Pin, GPIO_PIN_SET);
// 					}
// 					else if (strncmp("/S3/OFF",url,6) == 0)
// 					{
// 						Do3 = 0;
// 						HAL_GPIO_WritePin(D_O_3_GPIO_Port, D_O_3_Pin, GPIO_PIN_RESET);
// 					}
// 					else if (strncmp("/S4/ON",url,6) == 0)
// 					{
// 						Do4 = 1;
// 						HAL_GPIO_WritePin(D_O_4_GPIO_Port, D_O_4_Pin, GPIO_PIN_SET);
// 					}
// 					else if (strncmp("/S4/OFF",url,6) == 0)
// 					{
// 						Do4 = 0;
// 						HAL_GPIO_WritePin(D_O_4_GPIO_Port, D_O_4_Pin, GPIO_PIN_RESET);
// 					}
//
// 					//Geração da HTML
// 					if(flagHtmlGen == 1)
// 					{
// 						strcpy((char*)buf,"HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n");
// 						strcat((char*)buf, "<html><head>");
// 						strcat((char*)buf, "<title>Eletrocursos W5500 Web Server</title>");
// 						strcat((char*)buf, "<link href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/css/bootstrap.min.css' rel='stylesheet'></link>");
// 						strcat((char*)buf, "</head>");
// 						strcat((char*)buf, "<body>");
// 						strcat((char*)buf, "<div class='jumbotron'>");
// 						strcat((char*)buf, "<h2>RTU</h2>");
//
// 						strcat((char*)buf, "<div class='row'>");
// 						strcat((char*)buf, "<div class='col-md-3'>");
// 						strcat((char*)buf, "<table class='table table-bordered'>");
// 						strcat((char*)buf, "<tbody>");
//
// 						strcat((char*)buf, "<tr>");
// 						strcat((char*)buf, "<td>D_o_1: ");
// 						if(Do1 == 1)
// 						{
// 							strcat((char*)buf, "ON");
// 							strcat((char*)buf, "</td><td><a href='/S1/OFF'>RESET</a>");
// 						}
// 						else
// 						{
// 							strcat((char*)buf, "OFF");
// 							strcat((char*)buf, "</td><td><a href='/S1/ON'SET</a>");
// 						}
//
// 						strcat((char*)buf, "</td>");
// 						strcat((char*)buf, "</tr>");
// 						strcat((char*)buf, "<td>D_O_2: ");
// 						if(Do2 == 1)
// 						{
// 							 strcat((char*)buf, "ON");
// 							 strcat((char*)buf, "</td><td><a href='/S2/OFF'>RESET</a>");
// 						}
// 						else
// 						{
// 							 strcat((char*)buf, "OFF");
// 							 strcat((char*)buf, "</td><td><a href='/S2/ON'>SET</a>");
// 						}
//
// 						strcat((char*)buf, "</td>");
// 						strcat((char*)buf, "</tr>");
// 						strcat((char*)buf, "<td>D_O_3: ");
// 						if(Do3 == 1)
// 						{
// 							strcat((char*)buf, "ON");
// 							strcat((char*)buf, "</td><td><a href='/S3/OFF'>RESET</a>");
// 						}
// 						else
// 						{
// 							 strcat((char*)buf, "OFF");
// 							 strcat((char*)buf, "</td><td><a href='/S3/ON'>SET</a>");
// 						}
//
// 						strcat((char*)buf, "</td>");
// 						strcat((char*)buf, "</tr>");
//
// 						strcat((char*)buf, "<td>D_O_4: ");
// 						if(Do2 == 1)
// 						{
// 							strcat((char*)buf, "ON");
// 							strcat((char*)buf, "</td><td><a href='/S4/OFF'>RESET</a>");
// 						}
// 						else
// 						{
// 							strcat((char*)buf, "OFF");
// 							strcat((char*)buf, "</td><td><a href='/S4/ON'>SET</a>");
// 						}
// 						strcat((char*)buf, "</td>");
// 						strcat((char*)buf, "</tr>");
//
// 						strcat((char*)buf, "</html>");
//
// 						blocklen = strlen((char*)buf);
//
// 						ret = send(sn,buf,blocklen);
// 						if(ret < 0)
// 						{
// 							close(sn);
// 							return ret;
// 						}
// 						else
// 						{
// 							HTTP_reset(sn);
// 							disconnect(sn);
// 						}
// 					}
// 				}
// 				else
// 				{
// //					strcpy((char*)buf,http_404_full);
// //					size=strlen((char*)buf);
// //					ret=send(sn,buf,size);
// //					if(ret < 0)
// //					{
// //						close(sn);
// //						return ret;
// //					}
// 					HTTP_reset(sn);
// 					disconnect(sn);
// 				}
//         	  }
//          }
//          break;
//       case SOCK_CLOSE_WAIT :
//
//     	  HTTP_reset(sn);
//
//          if((ret=disconnect(sn)) != SOCK_OK)
//          return ret;
//
//          break;
//       case SOCK_INIT :
//
//     	  HTTP_reset(sn);
//
//          if( (ret = listen(sn)) != SOCK_OK) return ret;
//          break;
//       case SOCK_CLOSED:
//
//     	  HTTP_reset(sn);
//
//          if((ret=socket(sn,Sn_MR_TCP,port,0x00)) != sn)
//          return ret;
//
//          break;
//
//       default:
//     	  HTTP_reset(sn);
//          break;
//    }
//    return 1;
// }
