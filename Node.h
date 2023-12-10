#pragma once

template <typename T>
/**
* @brief Структура "Узел"
*/
struct Node
{
	/**
	* @brief Данные, лежащие в узле
	*/
	T data;

	/**
	* @brief Указатель на следующий элемент
	*/
	Node* next_element;

	/**
	* @brief Функция, инициализирующая узел
	* \param data Данные узла
	* \param next Указатель на пустой следующий элемент
	*/
	Node(T data, Node* next = nullptr);

	/**
	* @brief Функция, перегружающая оператор =
	* \param other_data Данные, которые будут скопированы в новый узел
	*/
	void operator=(const T other_data);
};

template <typename T>
Node<T>::Node(const T data, Node* next_element)
	: data(data), next_element(next_element)
{
}

template <typename T>
void Node<T>::operator=(const T other_data)
{
	this->data = other_data;
}
