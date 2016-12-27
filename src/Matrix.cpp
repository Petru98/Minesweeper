#include "Matrix.hpp"

Matrix::Matrix() : m_matrix(nullptr), m_width(0), m_height(0)
{}
Matrix::Matrix(std::size_t w, std::size_t h) : m_matrix(nullptr), m_width(0), m_height(0)
{
    create(w, h);
}

Matrix::~Matrix()
{
    if(m_matrix != nullptr)
        M_dealloc();
}

bool Matrix::create(std::size_t w, std::size_t h)
{

}
bool Matrix::M_alloc(std::size_t w, std::size_t h)
{

}

void Matrix::destroy()
{

}
void Matrix::M_dealloc()
{
    delete[] (*m_matrix);
    delete[]   m_matrix;
}

bool Matrix::isCreated()const
{
    return m_matrix;
}
std::size_t Matrix::width()const
{
    return m_width;
}
std::size_t Matrix::height()const
{
    return m_height;
}

T* const Matrix::operator[] (std::size_t index)
{
    return m_matrix[index];
}
const T* const Matrix::operator[] (std::size_t index)const
{
    return m_matrix[index];
}
