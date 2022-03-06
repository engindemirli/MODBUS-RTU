/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "user.h"
#include "socket.h"
#include "server_sett.h"
#include "http_server.h"
#include "tcp_server.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define D_O_2_Pin GPIO_PIN_13
#define D_O_2_GPIO_Port GPIOC
#define D_O_3_Pin GPIO_PIN_14
#define D_O_3_GPIO_Port GPIOC
#define D_O_4_Pin GPIO_PIN_15
#define D_O_4_GPIO_Port GPIOC
#define W5500_NRST_Pin GPIO_PIN_11
#define W5500_NRST_GPIO_Port GPIOB
#define W5500_INT_Pin GPIO_PIN_12
#define W5500_INT_GPIO_Port GPIOB
#define W5500_SCK_Pin GPIO_PIN_13
#define W5500_SCK_GPIO_Port GPIOB
#define W5500_MISO_Pin GPIO_PIN_14
#define W5500_MISO_GPIO_Port GPIOB
#define W5500_MOSI_Pin GPIO_PIN_15
#define W5500_MOSI_GPIO_Port GPIOB
#define W5500_SCSN_Pin GPIO_PIN_8
#define W5500_SCSN_GPIO_Port GPIOA
#define D_I_1_Pin GPIO_PIN_5
#define D_I_1_GPIO_Port GPIOB
#define D_I_2_Pin GPIO_PIN_6
#define D_I_2_GPIO_Port GPIOB
#define D_I_3_Pin GPIO_PIN_7
#define D_I_3_GPIO_Port GPIOB
#define D_I_4_Pin GPIO_PIN_8
#define D_I_4_GPIO_Port GPIOB
#define D_O_1_Pin GPIO_PIN_9
#define D_O_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
