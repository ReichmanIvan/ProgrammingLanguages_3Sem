#include "Tasks.h"

Tasks::Tasks(Matrix matrix) 
	: matrix(matrix)
{
}

Matrix Tasks::Task1()
{
    for (size_t i = 0; i < matrix.get_column(); i++)
    {
        int min_value = get_min_value();

        for (size_t j = 0; j < matrix.get_column(); j++)
        {
            if (matrix[j][i] == min_value)
            {
                matrix[j][i] = abs(matrix[j][i]);
            }
        }
    }

    return matrix;
}

Matrix Tasks::Task2()
{
    int max_value = this->matrix[0][0];
    size_t row_index = 0;

    for (size_t i = 0; i < matrix.get_matrix().size(); i++) 
    {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
                row_index = i;
            }
        }
    }

    matrix.get_matrix().erase(matrix.get_matrix().begin() + row_index);
    return matrix;
}

int Tasks::get_min_value()
{
    int min_value = 0;
    for (size_t i = 0; i < matrix.get_column(); i++)
    {
        min_value = matrix[0][i];
        for (size_t j = 1; j < matrix.get_row(); j++)
        {
            if (matrix[j][i] < min_value)
            {
                min_value = matrix[j][i];
            }
        }
    }
    return min_value;
}

int Tasks::get_max_value()
{
    int max_value = 0;
    for (size_t i = 0; i < matrix.get_column(); i++)
    {
        max_value = matrix[0][i];
        for (size_t j = 1; j < matrix.get_row(); j++)
        {
            if (matrix[j][i] > max_value)
            {
                max_value = matrix[j][i];
            }
        }
    }
    return max_value;
}
