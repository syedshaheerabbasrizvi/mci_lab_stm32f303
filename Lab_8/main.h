/**
  ******************************************************************************
  * @file    TIM/TIM_PWMOutput/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3_discovery.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor TIMx instance used and associated
   resources */
/* Definition for TIMx clock resources */
#define TIMz                           TIM8
#define TIMz_CLK_ENABLE()              __HAL_RCC_TIM8_CLK_ENABLE()

/* Definition for TIMx Channel Pins */
#define TIMz_CHANNEL_GPIO_PORT()       __HAL_RCC_GPIOC_CLK_ENABLE()
#define TIMz_GPIO_PORT_CHANNEL1        GPIOC

#define TIMz_GPIO_PIN_CHANNEL1         GPIO_PIN_6
#define TIMz_GPIO_AF_CHANNEL1          GPIO_AF2_TIM8
#define TIMz_GPIO_PORT_CHANNEL3        GPIOC

#define TIMz_GPIO_PIN_CHANNEL3         GPIO_PIN_8
#define TIMz_GPIO_AF_CHANNEL3          GPIO_AF2_TIM8
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
