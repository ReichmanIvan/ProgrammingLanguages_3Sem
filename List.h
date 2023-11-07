#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

template <typename T>

class List
{
public:

	/**
	* \brief Функция, инициализирующая список
	*/
	List();

	/**
	* \brief Функция, удаляющая список
	*/
	~List();

	/**
	* \brief Функция, копирующая список
	* \param second_list Список, который будет скопирован
	*/
	List(const List& second_list);

	/**
	* \brief Функция, перемещающая список
	* \param second_list Список, который будет перемещен
	*/
	List(List&& second_list) noexcept;

	/**
	* \brief Функция, добавляющая элемент в начало списка
	* \param data Данные, которые будут добавлены
	*/
	void push_front(T data);

	/**
	* \brief Функция, добавляющая элемент в конец списка
	* \param data Данные, которые будут добавлены
	*/
	void push_back(T data);

	/**
	* \brief Функция, удаляющая узел в начале списка
	*/
	void del_front();

	/**
	* \brief Функция, удаляющая все узлы списка
	*/
	void clear_list();

	/**
	* \brief Функция, возвращающая размер списка
	* \return Размер списка
	*/
	int get_size();

	/**
	* \brief Функция, превращающая список в строку
	* \return Строка, состоящая из узлов
	*/
	std::string to_string();

	/**
	* \brief Функция, перегружающая оператор =
	* \param second_list Список, который будет скопирован
	* \return Скопированный список
	*/
	List& operator=(const List& second_list);

	/**
	* \brief Функция, перегружающая оператор =
	* \param second_list Список, который будет перемещен
	* \return Перемещенный список
	*/
	List& operator=(List&& second_list) noexcept;

	bool operator==(List& second_list);


private:

	Node<T>* first_element;

	size_t size;
};

template <typename T>
List<T>::List()
	:first_element(nullptr), size(0)
{
}

template <typename T>
List<T>::~List()
{
	clear_list();
}

template <typename T>
List<T>::List(const List& second_list)
{
	if (this->first_element == nullptr)
	{
		for (Node<T>* node = second_list.first_element; node != nullptr; node = node->next_element)
		{
			this->push_back(node->data);
		}
	}
}

template <typename T>
List<T>::List(List&& second_list) noexcept
{
	std::exchange(this->first_element, second_list.first_element);
}

template <typename T>
void List<T>::push_front(T data)
{
	first_element = new Node<T>(data, first_element);
	size++;
}

template <typename T>
void List<T>::push_back(T data)
{
	if (first_element == nullptr)
	{
		first_element = new Node<T>(data);
	}
	else
	{
		Node<T>* this_node = first_element;
		while (this_node->next_element != nullptr)
		{
			this_node = this_node->next_element;
		}
		this_node->next_element = new Node<T>(data);
	};

	size++;
}

template <typename T>
void List<T>::del_front()
{
	if (first_element != nullptr)
	{
		Node<T>* temp = first_element;
		first_element = first_element->next_element;
		size--;
		delete temp;
	}
}

template <typename T>
void List<T>::clear_list()
{
	while (size > 0)
	{
		del_front();
	}
}

template <typename T>
int List<T>::get_size()
{
	return size;
}

template <typename T>
std::string List<T>::to_string()
{
	std::stringstream buffer;
	if (first_element != nullptr)
	{
		Node<T>* this_node = first_element;
		for (size_t i = 0; i < size; i++)
		{
			buffer << this_node->data << ' ';
			this_node = this_node->next_element;
		}
	}
	return buffer.str();
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& second_list)
{
	if (this->first_element == nullptr)
	{
		for (Node<T>* node = second_list.first_element; node != nullptr; node = node->next_element)
		{
			this->push_back(node->data);
		}
	}
	return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& second_list) noexcept
{
	std::exchange(this->first_element, second_list.first_element);
	return *this;
}

template <typename T>
bool List<T>::operator==(List<T>& second_list)
{
	return(this->to_string() == second_list.to_string());
}
