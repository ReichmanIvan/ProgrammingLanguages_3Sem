#include "CppUnitTest.h"
#include "../Matrix/Matrix.h"
#include "../Matrix/BaseGenerator.h"
#include "../Matrix/RandomGenerator.h"
#include "../Matrix/IStreamGenerator.h"
#include "../Matrix/Tasks.h"
#include <iostream>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTests
{
	TEST_CLASS(MatrixTests)
	{
	public:

		TEST_METHOD(ConstructorTest_ValidData_Success)
		{
			RandomGenerator rnd(-10, 10);
			Matrix matrix(3, 3, &rnd);

			Assert::IsNotNull(&matrix);
		}

		TEST_METHOD(CopyConstructorTest_ValidData_Success)
		{
			RandomGenerator rnd(-10, 10);
			Matrix matrix(3, 3, &rnd);
			Matrix second_matrix(matrix);

			Assert::IsFalse(matrix.is_empty());
			Assert::AreEqual(matrix.matrix_to_string(), second_matrix.matrix_to_string());
			Assert::AreNotSame(matrix.matrix_to_string(), second_matrix.matrix_to_string());
		}

		TEST_METHOD(GetRowTest_ValidData_Success)
		{
			RandomGenerator rnd(-10, 10);
			size_t expected_output = 3;
			Matrix matrix(3, 3, &rnd);

			Assert::AreEqual(expected_output, matrix.get_row());
		}

		TEST_METHOD(GetColumnTest_ValidData_Success)
		{
			RandomGenerator rnd(-10, 10);
			size_t expected_output = 3;
			Matrix matrix(3, 3, &rnd);

			Assert::AreEqual(expected_output, matrix.get_column());
		}

		TEST_METHOD(IndexOperatorTest_ValidData_Success)
		{
			std::istringstream in("1 2 3 4 5 6 7 8 9");
			IStreamGenerator input(in);
			Matrix matrix(3, 3, &input);
			int expected_output = 1;

			Assert::IsFalse(matrix.is_empty());
			Assert::AreEqual(expected_output, matrix[0][0]);
		}

		TEST_METHOD(ConstIndexOperatorTest_ValidData_Success)
		{
			std::istringstream in("1 2 3 4 5 6 7 8 9");
			IStreamGenerator input(in);
			const Matrix matrix(3, 3, &input);
			int expected_output = 1;

			Assert::IsFalse(matrix.is_empty());
			Assert::AreEqual(expected_output, matrix[0][0]);
		}

		TEST_METHOD(CopyOperatorTest_ValidData_Success)
		{
			RandomGenerator rnd(-10, 10);
			Matrix matrix(3, 3, &rnd);
			Matrix second_matrix(3, 3, &rnd);

			second_matrix = matrix;

			Assert::IsFalse(matrix.is_empty());
			Assert::AreEqual(matrix.matrix_to_string(), second_matrix.matrix_to_string());
			Assert::AreNotSame(matrix.matrix_to_string(), second_matrix.matrix_to_string());
		}

		TEST_METHOD(OutputOperatorTest_ValidData_Success)
		{
			std::istringstream in("1 2 3 4 5 6 7 8 9");
			IStreamGenerator input(in);
			Matrix matrix(3, 3, &input);
			std::stringstream buffer;
			std::string expected_output = "1 2 3 \n4 5 6 \n7 8 9 \n";

			buffer << matrix;

			Assert::IsFalse(matrix.is_empty());
			Assert::AreEqual(expected_output, buffer.str());

		}

		TEST_METHOD(IsEmptyTest_ValidData_Success)
		{
			RandomGenerator rnd(-10, 10);
			Matrix matrix(3, 3, &rnd);

			Assert::IsFalse(matrix.is_empty());
		}

		TEST_METHOD(MatrixToStringTest_ValidData_Success)
		{
			std::istringstream in("1 2 3 4 5 6 7 8 9");
			IStreamGenerator input(in);
			Matrix matrix(3, 3, &input);
			std::string expected_output = "1 2 3 \n4 5 6 \n7 8 9 \n";

			Assert::IsFalse(matrix.is_empty());
			Assert::AreEqual(expected_output, matrix.matrix_to_string());
		}
	};

	TEST_CLASS(TasksTests)
	{
	public:
		TEST_METHOD(ConstructorTest_ValidData_Success)
		{
			RandomGenerator rnd(-10, 10);
			Matrix matrix(3, 3, &rnd);
			Tasks task(matrix);

			Assert::IsNotNull(&task);
		}

		TEST_METHOD(MinValueTest_ValidData_Success)
		{
			std::istringstream in("9 -8 -10 4 5 -6 2 5 4");
			IStreamGenerator input(in);
			Matrix matrix(3, 3, &input);
			std::stringstream buffer;
			std::string expected_output = "-10";

			Tasks task(matrix);
			buffer << task.get_min_value();

			Assert::AreEqual(expected_output, buffer.str());

		}
		TEST_METHOD(TaskOneTest_ValidData_Success)
		{
			std::istringstream in("9 -8 -10 4 5 -6 2 5 4");
			IStreamGenerator input(in);
			Matrix matrix(3, 3, &input);
			Tasks task(matrix);
			std::string expected_output = "9 -8 10 \n4 5 -6 \n2 5 4 \n";

			Assert::AreEqual(task.Task1().matrix_to_string(), expected_output);
		}

		TEST_METHOD(TaskTwoTest_ValidData_Success)
		{
			std::istringstream in("-3 8 6 -3 -10 8 0 -6 -1");
			IStreamGenerator input(in);
			Matrix matrix(3, 3, &input);
			Tasks task(matrix);
			std::string expected = "-3 8 6 \n-3 -10 8 \n0 -6 -1 \n";


			Assert::AreEqual(task.Task2().matrix_to_string(), expected);
		}
	};
}
