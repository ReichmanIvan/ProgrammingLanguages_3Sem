#pragma once

/**
* @brief базовый класс Generator
*/
class Generator
{
public:
	/**
	* @brief Виртуальный деструктор
	*/
	virtual ~Generator() = 0 {};

	/**
	* @brief Виртуальный метод генератор
	*/
	virtual int generate() = 0;
};
