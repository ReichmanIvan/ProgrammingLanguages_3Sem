#pragma once
#include "BaseGenerator.h"
#include <iostream>

/**
* @brief Класс IStreamGenerator
*/
class IStreamGenerator : public Generator
{
private:
	std::istream& in;

public:
	/**
	* @brief Конструктор класса
	* @param in поток ввода
	*/
	IStreamGenerator(std::istream& in = std::cin);

	/**
	* @brief метод заполения generate()
	*/
	int generate() override;
};
