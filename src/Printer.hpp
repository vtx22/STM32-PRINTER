#pragma once
#include "stm32f1xx_hal.h"
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>

//#define PRINTER_DEBUG
//#define SWO_PRINTF

#define UART_TIMEOUT 10

class PRINTER
{
	public:
		PRINTER(UART_HandleTypeDef* huart);

		void printString(std::string str);
		void println();

		void print(std::string message);
		void print(float value);
		void println(std::string message);
		void println(float value);

	private:
		UART_HandleTypeDef* _huart;
};
