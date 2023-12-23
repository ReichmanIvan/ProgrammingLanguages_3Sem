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
    for (size_t i = 0; i < this->matrix.get_matrix().size(); i++) 
    {
        for (size_t j = 0; j < this->matrix[i].size(); j++) 
        {
            if (this->matrix[i][j] > max_value) 
            {
                max_value = this->matrix[i][j];
                row_index = i;
            }
        }
    }
    Matrix new_matrix = matrix;

    this->matrix = new_matrix;
    return new_matrix;
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
