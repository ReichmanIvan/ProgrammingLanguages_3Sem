#pragma once
#include "Matrix.h"
#include "BaseTasks.h"

/**
* @brief класс Tasks.
*/
class Tasks : public BaseTasks
{
public:

	/**
	* @brief конструктор
	*/
	Tasks(Matrix matrix);

	/**
	* @brief метод для Задания 1
	* @return матрицу
	*/
	Matrix Task1() override;

	/**
	* @brief метод для Задания 2
	* @return матрицу
	*/
	Matrix Task2() override;

	/**
	* @brief метод для получения минимального значения
	* @return минимальное значение
	*/
	int get_min_value();

	/**
	* @brief метод для получения максимального значения
	* @return максимальное значение
	*/
	int get_max_value();

private:

	Matrix matrix;
};
