#pragma once

#include "BaseGenerator.h"

#include <random>

/**
* @brief класс RandomGenerator
*/
class RandomGenerator : public Generator

{

private:

	std::uniform_int_distribution<int> distribution;
	std::mt19937 generator;

public:

	/**
	* @brief Метод рандомного заполнения
	* @param min минимальный элемент
	* @param max максимальный элемент
	*/
	RandomGenerator(const int min, const int max);

	/**
	* @brief Метод заполения generate()
	*/
	int generate() override;
};
