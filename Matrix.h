#pragma once

#include "BaseGenerator.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <exception>


/**
* @brief класс Матрицы
*/
class Matrix
{
public:

	/**
	* @brief Конструктор
	* @param row Количество строк
	* @param col Количество столбцов
	*/
	Matrix(const size_t row, const size_t column, Generator* generator);

	/**
	* @brief Деструктор
	*/
	~Matrix();

	/**
	* @brief Конструктор копирования
	* @param other Матрица для копирования
	*/
	Matrix(const Matrix& other);

	/**
	* @brief Получение кол-ва строк
	* @return Количество строк
	*/
	size_t get_row() const;

	/**
	* @brief Получение кол-ва столбцов
	* @return Количество столбцов
	*/
	size_t get_column() const;

	/**
	* @brief Проверка на пустоту матрицы
	* @return Логическое значение
	*/
	bool is_empty() const;

	/**
	* @brief Переопределение оператора []
	* @param index Индекс матрицы
	* @return Элемент матрицы по индексу
	*/
	std::vector<int>& operator[](size_t index);

	/**
	* @brief Переопределение константного оператора []
	* @param index Индекс матрицы
	* @return Элемент матрицы по индексу
	*/
	const std::vector<int>& operator[](size_t index) const;

	/**
	* @brief Переопределение оператора присваивания
	* @param other Матрица для копирования
	* @return Элемент матрицы по индексу
	*/
	Matrix& operator=(const Matrix& other);

	/**
	* @brief Переопределение оператора вывода
	* @param os Поток вывода
	* @param matrix Матрица
	* @return Элемент матрицы по индексу
	*/
	friend std::ostream& operator<<(std::ostream& os, Matrix& matrix);

	/**
	* @brief Вывод матрицы в строку
	* @return Матрица в строку
	*/
	std::string matrix_to_string() const;

	/**
	* @brief Удаление строки
	*/
	void delete_row(size_t pos, const std::vector<int>& row);

	/**
	* @brief Получение матрицы
	* @return Матрица
	*/
	std::vector<std::vector<int>> get_matrix();

private:
	size_t column;
	size_t row;
	std::vector<std::vector<int>> matrix;
};
