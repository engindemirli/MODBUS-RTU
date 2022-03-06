/*
 * http_server.h
 *
 *  Created on: Feb 12, 2022
 *      Author: ENGIN
 */

#ifndef INC_HTTP_SERVER_H_
#define INC_HTTP_SERVER_H_

#ifdef __cplusplus
}
#endif
#include "main.h"
int32_t tcp_http_mt(uint8_t sn, uint8_t* buf, uint16_t port);

#endif /* INC_HTTP_SERVER_H_ */
