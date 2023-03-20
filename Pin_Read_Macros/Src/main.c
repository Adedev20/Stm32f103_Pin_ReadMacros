/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Emmanuel Adedayo Oyedokun
 * @brief          : Pin_Read with macros
 * @date 		   : 20/03/2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"

int main(void)
{
	   RCC_APB2ENR_t volatile *const pClkcontReg   = (RCC_APB2ENR_t*)0x40021018; //Pointer address for the clock reg
	   GPIOx_CRH_t volatile *const pPortBModeReg   = (GPIOx_CRH_t*)0x40010C04; //Pointer address for PortB Mode reg
	   GPIOx_CRL_t volatile *const pPortAModeReg   = (GPIOx_CRL_t*)0x40010800; //Pointer address for PortA Mode reg
	   GPIOx_IDR_t volatile *const pPinRegB        = (GPIOx_IDR_t*)0x40010C08; //Pointer address for PortB IDR
	   GPIOx_ODR_t volatile *const pPinRegA        = (GPIOx_ODR_t*)0x4001080C; //Pointer address for PortA ODR


		//Enable the clock for GPIOC
		pClkcontReg->gpioa_en = CLOCK_ENABLE;
		pClkcontReg->gpiob_en = CLOCK_ENABLE;




		//*pPortCModeReg &= ~(15 << 20);  //Clear the mode register for port c
		//*pPortCModeReg |=  (1 << 21);   //Set the mode register for portc
		//pPortAModeReg->pin3 = 0;  //clear the mode register for port a
		pPortAModeReg->pin3 =  MODE_CONF_OUTPUT;   //set the mode register for port a
		pPortBModeReg->pin12 = MODE_CONF_INPUT;   //set the mode reg b


		while(1)
		{
			//Read status of PB12
			if ((pPinRegB->pin12 == PIN_READ_HIGH)){

			pPinRegA->pin3 = PIN_STATE_HIGH;   //Set the 13th bit to turn pin PA3 turn on


			}else{


			pPinRegA->pin3 = PIN_STATE_LOW;   //clear the 3rd bit to turn pin PA3 turn off


		}
	}

}

