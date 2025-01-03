/**
  ******************************************************************************
  * @file    TIM/TIM_TimeBase/Src/main.c 
  * @author  MCD Application Team
  * @brief   This sample code shows how to use STM32F3xx TIM HAL API to generate
  *          a time base of one second with the corresponding Interrupt request.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdio.h"

/** @addtogroup STM32F3xx_HAL_Examples
  * @{
  */

/** @addtogroup TIM_TimeBase
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
#define  PERIOD_VALUE       (uint32_t)(65535 - 1)  /* Period Value  */
#define  PULSE1_VALUE       (uint32_t)(PERIOD_VALUE*5/100)        
/* Private define ------------------------------------------------------------*/
#define TRANSMITTER_BOARD
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef    TimHandleUS;
TIM_HandleTypeDef    TimHandle;

TIM_OC_InitTypeDef sConfig;


static GPIO_InitTypeDef  GPIO_InitStruct;
uint32_t uhPrescalerValue = 0;
uint32_t uwPrescalerValue = 0;
uint32_t val1 = 0;
uint32_t val2 = 0;
uint16_t distance  = 0;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
/* UART handler declaration */
UART_HandleTypeDef UartHandle;
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* STM32F3xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();
	BSP_LED_Init(LED4);
  /* Configure the system clock to 72 MHz */
  SystemClock_Config();

  /* Configure LED3 */
  BSP_LED_Init(LED3);
	BSP_LED_Init(LED7);
	BSP_LED_Init(LED5);
  /* Compute the prescaler value to have TIM3 counter clock equal to 24000000 Hz */
  uhPrescalerValue = (uint32_t)(SystemCoreClock / 3270000) - 1;

  /*##-1- Configure the TIM peripheral #######################################*/
  /* -----------------------------------------------------------------------
  TIM3 Configuration: generate 4 PWM signals with 4 different duty cycles.

In this example TIM3 input clock (TIM3CLK) is set to 2 * APB1 clock (PCLK1), 
    since APB1 prescaler is different from 1.   
      TIM3CLK = 2 * PCLK1  
      PCLK1 = HCLK / 2 
      => TIM3CLK = HCLK = SystemCoreClock
          
    To get TIM3 counter clock at 24 MHz, the prescaler is computed as follows:
       Prescaler = (TIM3CLK / TIM3 counter clock) - 1
       Prescaler = (SystemCoreClock /24 MHz) - 1
                                              
    To get TIM3 output clock at 36 KHz, the period (ARR)) is computed as follows:
       ARR = (TIM3 counter clock / TIM3 output clock) - 1
           = 665
                  
    TIM3 Channel1 duty cycle = (TIM3_CCR1/ TIM3_ARR)* 100 = 50%
    TIM3 Channel2 duty cycle = (TIM3_CCR2/ TIM3_ARR)* 100 = 37.5%
    TIM3 Channel3 duty cycle = (TIM3_CCR3/ TIM3_ARR)* 100 = 25%
    TIM3 Channel4 duty cycle = (TIM3_CCR4/ TIM3_ARR)* 100 = 12.5%

    Note:
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f3xx.c file.
     Each time the core clock (HCLK) changes, user had to update SystemCoreClock
     variable value. Otherwise, any configuration based on this variable will be incorrect.
     This variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetSysClockFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
  ----------------------------------------------------------------------- */

  /* Initialize TIMx peripheral as follows:
       + Prescaler = (SystemCoreClock / 24000000) - 1
       + Period = (665 - 1)
       + ClockDivision = 0
       + Counter direction = Up
  */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	 
	GPIO_InitStruct.Pin = (GPIO_PIN_0);
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	
	GPIO_InitStruct.Pin = (GPIO_PIN_1);
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	UartHandle.Instance        = USARTx;

  UartHandle.Init.BaudRate     = 9600;
  UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
  UartHandle.Init.StopBits     = UART_STOPBITS_1;
  UartHandle.Init.Parity       = UART_PARITY_NONE;
  UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  UartHandle.Init.Mode         = UART_MODE_TX_RX;
  UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
  UartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

  if(HAL_UART_DeInit(&UartHandle) != HAL_OK)
  {
    Error_Handler();
  }  
  if(HAL_UART_Init(&UartHandle) != HAL_OK)
  {
    Error_Handler();
  }
	  uwPrescalerValue = (uint32_t) (SystemCoreClock / 1000000) - 1;
  TimHandleUS.Instance = TIMy;
TimHandleUS.Init.Period = 1000000 - 1;
  TimHandleUS.Init.Prescaler = uwPrescalerValue;
  TimHandleUS.Init.ClockDivision = 0;
  TimHandleUS.Init.CounterMode = TIM_COUNTERMODE_UP;
  TimHandleUS.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

  if(HAL_TIM_Base_Init(&TimHandleUS) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-2- Start the TIM Base generation in interrupt mode ####################*/
  /* Start Channel1 */
  if(HAL_TIM_Base_Start_IT(&TimHandleUS) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
  }
 char my_buf[100];
	
	
  TimHandle.Instance = TIMx;

  TimHandle.Init.Prescaler         = uhPrescalerValue;
  TimHandle.Init.Period            = PERIOD_VALUE;
  TimHandle.Init.ClockDivision     = 0;
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimHandle.Init.RepetitionCounter = 0;
  TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

  if (HAL_TIM_PWM_Init(&TimHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-2- Configure the PWM channels #########################################*/
  /* Common configuration for all channels */
  sConfig.OCMode       = TIM_OCMODE_PWM1;
  sConfig.OCPolarity   = TIM_OCPOLARITY_HIGH;
  sConfig.OCFastMode   = TIM_OCFAST_DISABLE;
  sConfig.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
  sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;

  sConfig.OCIdleState  = TIM_OCIDLESTATE_RESET;
	//setting up a push button
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct); 
	
	GPIO_InitStruct.Pin = (GPIO_PIN_6);
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* Set the pulse value for channel 1 */
  sConfig.Pulse = PULSE1_VALUE;
  if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1) != HAL_OK)
  {
    /* Configuration Error */
    Error_Handler();
  }

  

  /*##-3- Start PWM signals generation #######################################*/
  /* Start channel 1 */
  if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1) != HAL_OK)
  {
    /* PWM Generation Error */
    Error_Handler();
  }
  
	int sign = 1;
	uint32_t duty_cycle = 3000;// (5/100)*PERIOD_VALUE;
  while (1)
  {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
			  __HAL_TIM_SET_COUNTER(&TimHandleUS, 0);
		 while (__HAL_TIM_GET_COUNTER (&TimHandleUS) < 10){}  // wait for 10 us
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
		
			 while ((!(HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_1)))  >  HAL_GetTick());
	   val1 = __HAL_TIM_GET_COUNTER (&TimHandleUS);
			 
			 while ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_1))  >  HAL_GetTick());
	   val2 = __HAL_TIM_GET_COUNTER (&TimHandleUS);
			 
			distance = (val2-val1)* 0.034/2;
			int dist_msg = sprintf(my_buf, "task 2 distance = %d \r\n", distance);
			HAL_UART_Transmit(&UartHandle, (uint8_t*)my_buf, dist_msg , 5000);
			char status1 [9] = ("LED1 on\r\n");
			char status2 [9] = ("LED2 on\r\n");
			char status3 [9] = ("LED3 on\r\n");
			char status4 [9] = ("LED Tog\r\n");
			char status5 [9] = ("LED off\r\n");
			 
			if (distance > 45){
				BSP_LED_Toggle(LED3);
				BSP_LED_Toggle(LED7);
				BSP_LED_Toggle(LED5);
				duty_cycle = 1300;
				HAL_UART_Transmit(&UartHandle, (uint8_t*)status4, 9 , 5000);
  }
			
			if (distance < 15){
						BSP_LED_On(LED3);
						BSP_LED_On(LED7);
						BSP_LED_On(LED5);
						duty_cycle = 3100;
						HAL_UART_Transmit(&UartHandle, (uint8_t*)status1, 9 , 5000);
		}
			else if (distance < 30){
						BSP_LED_Off(LED5);
						BSP_LED_On(LED3);
						BSP_LED_On(LED7);
						duty_cycle = 4900;
						HAL_UART_Transmit(&UartHandle, (uint8_t*)status2, 9 , 5000);
		}
			
			else if (distance < 45){
						BSP_LED_Off(LED5);
						BSP_LED_Off(LED7);
						BSP_LED_On(LED3);
						duty_cycle = 8500;
						HAL_UART_Transmit(&UartHandle, (uint8_t*)status3, 9 , 5000);
		}
		
		
		BSP_LED_Toggle(LED4);
		sConfig.Pulse = duty_cycle;
		
		if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1) != HAL_OK)
		{
			/* Configuration Error */
			Error_Handler();
		}
		if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1) != HAL_OK)
		{
			/* PWM Generation Error */
			Error_Handler();
		}
		}
  }

	
/**
  * @brief  Period elapsed callback in non blocking mode
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* Turn LED3 on */
  BSP_LED_On(LED3);
  while(1)
  {
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            HSE PREDIV                     = 1
  *            PLLMUL                         = RCC_PLL_MUL9 (9)
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    Error_Handler();
  }
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
