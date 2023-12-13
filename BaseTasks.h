#pragma once
#include "Matrix.h"
#include "BaseGenerator.h"
	
/**
* @brief Абстрактный класс заданий
*/
class BaseTasks
{
public:
	/**
	* @brief Виртуальный деструткор
	*/
	virtual ~BaseTasks() = 0 {};

	/**
	* @brief Виртуальный метод для первого задания
	*/
	virtual Matrix Task1() = 0;

	/**
	* @brief Виртуальный метод для второго задания
	*/
	virtual Matrix Task2() = 0;

};
