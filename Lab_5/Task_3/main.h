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
#define TIMx                           TIM4
#define TIMx_CLK_ENABLE()              __HAL_RCC_TIM4_CLK_ENABLE()

/* Definition for TIMx Channel Pins */
#define TIMx_CHANNEL_GPIO_PORT()       __HAL_RCC_GPIOD_CLK_ENABLE()
#define TIMx_GPIO_PORT_CHANNEL1        GPIOD
#define TIMx_GPIO_PORT_CHANNEL2        GPIOD
#define TIMx_GPIO_PORT_CHANNEL3        GPIOD
#define TIMx_GPIO_PORT_CHANNEL4        GPIOD
#define TIMx_GPIO_PIN_CHANNEL1         GPIO_PIN_12
#define TIMx_GPIO_PIN_CHANNEL2         GPIO_PIN_13
#define TIMx_GPIO_PIN_CHANNEL3         GPIO_PIN_14
#define TIMx_GPIO_PIN_CHANNEL4         GPIO_PIN_15
#define TIMx_GPIO_AF_CHANNEL1          GPIO_AF2_TIM4
#define TIMx_GPIO_AF_CHANNEL2          GPIO_AF2_TIM4
#define TIMx_GPIO_AF_CHANNEL3          GPIO_AF2_TIM4
#define TIMx_GPIO_AF_CHANNEL4          GPIO_AF2_TIM4

#define TIMy                           TIM3
#define TIMy_CLK_ENABLE                __HAL_RCC_TIM3_CLK_ENABLE

/* Definition for TIMx's NVIC */
#define TIMy_IRQn                      TIM3_IRQn
#define TIMy_IRQHandler                TIM3_IRQHandler

#define USARTx                           USART2
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART2_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART2_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART2_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_5
#define USARTx_TX_GPIO_PORT              GPIOD
#define USARTx_TX_AF                     GPIO_AF7_USART2
#define USARTx_RX_PIN                    GPIO_PIN_6
#define USARTx_RX_GPIO_PORT              GPIOD
#define USARTx_RX_AF                     GPIO_AF7_USART2

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
