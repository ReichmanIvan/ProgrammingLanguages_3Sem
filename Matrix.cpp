#include "Matrix.h"

Matrix::Matrix(const size_t row, const size_t column, Generator* generator)
    : row(row), column(column)
{
    if (column && row < 0)
    {
        throw std::invalid_argument("Неправильный размер матрицы :(");
    }

    if (generator == nullptr)
    {
        throw std::invalid_argument("Ошибка генератора матрицы :(");
    }

    std::vector<std::vector<int>> matrix(row, std::vector<int>(column));

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            matrix[i][j] = generator->generate();
        }
    }
}

size_t Matrix::get_row() const
{
    return matrix.size();
}

size_t Matrix::get_column() const
{
    if (is_empty())
    {
        return 0;
    }
    return matrix[0].size();
}

bool Matrix::is_empty() const
{
    return (matrix.size() == 0) || (column == 0);
}

std::vector<int>& Matrix::operator[](size_t index)
{
    return matrix[index];
}

const std::vector<int>& Matrix::operator[](size_t index) const
{
    return matrix[index];
}

std::string Matrix::matrix_to_string() const
{
    std::stringstream buffer;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            buffer << matrix[i][j] << ' ';
        }
        buffer << std::endl;
    }
    return buffer.str();
}

void Matrix::delete_row(size_t pos, const std::vector<int>& row)
{
    if (pos >= matrix.size())
    {
        throw std::out_of_range("Error! Invalid position.");
    }

    auto it = matrix.begin() + pos;
    if (std::equal(it->begin(), it->end(), row.begin()))
    {
        matrix.erase(it);
    }
    else
    {
        throw std::invalid_argument("Error! Row does not match at the specified position.");
    }
}

std::vector<std::vector<int>> Matrix::get_matrix()
{
    return this->matrix;
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix)
{
    for (size_t i = 0; i < matrix.row;i++) {
        for (int j = 0;j < matrix.column;j++) {
            os << matrix[i][j];
        }
    }
    
    return os;
}
