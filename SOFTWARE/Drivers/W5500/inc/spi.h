#include "main.h"

#define W5500_select() HAL_GPIO_WritePin(W5500_SCSN_GPIO_Port, W5500_SCSN_Pin, GPIO_PIN_RESET);
#define W5500_release() HAL_GPIO_WritePin(W5500_SCSN_GPIO_Port, W5500_SCSN_Pin, GPIO_PIN_SET);

#define W5500_Reset() HAL_GPIO_WritePin(W5500_NRST_GPIO_Port, W5500_NRST_Pin, GPIO_PIN_RESET);
#define W5500_NoReset() HAL_GPIO_WritePin(W5500_NRST_GPIO_Port, W5500_NRST_Pin, GPIO_PIN_SET);

#define W5500_rx() W5500_rxtx(0xff)
#define W5500_tx(data) W5500_rxtx(data)

uint8_t W5500_rxtx(uint8_t data);
