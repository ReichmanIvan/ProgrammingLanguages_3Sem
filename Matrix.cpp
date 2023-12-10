#include "Matrix.h"

Matrix::Matrix(const size_t row, const size_t column, Generator* generator) 
	: row(row), column(column)
{
    std::vector<std::vector<int>> matrix(row, std::vector<int>(column));

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            matrix[i][j] = generator->generate();
        }
    }

    this->matrix = matrix;
    if (is_empty())
    {
        throw std::out_of_range("Error! Matrix is empty!");
    }
}

Matrix::~Matrix()
{
    if (!is_empty())
    {
        this->matrix.clear();
    }
}

Matrix::Matrix(const Matrix& other) : row(other.row), column(other.column), matrix(other.matrix)
{
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

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        Matrix temp(other);

        std::swap(matrix, temp.matrix);
        std::swap(row, temp.row);
        std::swap(column, temp.column);
    }

    return *this;
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
    if (pos > matrix.size())
    {
        throw std::out_of_range("Error!");
    }
        matrix.erase(matrix.begin() + pos);
}

std::vector<std::vector<int>> Matrix::get_matrix()
{
    return this->matrix;
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix)
{
    os << matrix.matrix_to_string();
    return os;
}
