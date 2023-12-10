#include "../Matrix/Matrix.h"
#include "../Matrix/RandomGenerator.h"
#include "../Matrix/IStreamGenerator.h"
#include "../Matrix/Tasks.h"
#include <iostream>

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		//RandomGenerator rnd(-10, 10);
		std::istream& in = std::cin;
		IStreamGenerator rnd(in);

		Matrix matrix(3, 3, &rnd);

		std::cout << matrix << std::endl;
		Tasks number_one(matrix);
		std::cout << number_one.Task1().matrix_to_string();
		Tasks number_two(matrix);
		std::cout << number_two.Task2().matrix_to_string();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
	return 0;
}
