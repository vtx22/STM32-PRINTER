#include "Printer.hpp"


PRINTER::PRINTER(UART_HandleTypeDef* huart)
{
	_huart = huart;
}

void PRINTER::print(std::string message)
{
	HAL_UART_Transmit(_huart, (uint8_t*)message.c_str(), message.length(), UART_TIMEOUT);
}

void PRINTER::print(float value)
{
	std::string message = std::to_string(value);
	HAL_UART_Transmit(_huart, (uint8_t*)message.c_str(), message.length(), UART_TIMEOUT);
}

void PRINTER::println(std::string message)
{
	HAL_UART_Transmit(_huart, (uint8_t*)(message+"\n").c_str(), message.length(), UART_TIMEOUT);
}

void PRINTER::println(float value)
{
	std::string message = std::to_string(value) + "\n";
	HAL_UART_Transmit(_huart, (uint8_t*)message.c_str(), message.length(), UART_TIMEOUT);
}


void PRINTER::println()
{
	HAL_UART_Transmit(_huart, (uint8_t*)"\n", 1, UART_TIMEOUT);
}
