#include "Matrix.hpp"

Matrix::Matrix() : m_matrix(nullptr), m_lines(0), m_columns(0)
{}
Matrix::Matrix(std::size_t p_lines, std::size_t p_columns) : m_matrix(nullptr), m_lines(0), m_columns(0)
{
    create(p_lines, p_columns);
}

bool Matrix::create(std::size_t p_lines, std::size_t p_columns)
{
    if(m_matrix != nullptr)
        M_dealloc();
    if(M_alloc(p_lines, p_columns) == false)
    {
        m_lines = 0;
        m_columns = 0;
        return false;
    }
    m_lines = p_lines;
    m_columns = p_columns;
    return true;
}
bool Matrix::M_alloc(std::size_t p_lines, std::size_t p_columns)
{
    m_matrix = new(std::nothrow) T*[p_lines];
    if(m_matrix == nullptr)
        return false;

    (*m_matrix) = new(std::nothrow) T[p_lines * p_columns];
    if((*m_matrix) == nullptr)
    {
        delete[] m_matrix;
        return false;
    }

    T* line_address = (*m_matrix) + p_columns;
    for(std::size_t i = 1; i < p_lines; (++i, line_address += p_columns))
        m_matrix[i] = line_address;
    return true;
}

Matrix::~Matrix()
{
    if(m_matrix != nullptr)
        M_dealloc();
}

void Matrix::destroy()
{
    M_dealloc();
    m_matrix = nullptr;
    m_lines = 0;
    m_columns = 0;
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
std::size_t Matrix::lines()const
{
    return m_lines;
}
std::size_t Matrix::columns()const
{
    return m_columns;
}

T* const Matrix::operator[] (std::size_t index)
{
    return m_matrix[index];
}
const T* const Matrix::operator[] (std::size_t index)const
{
    return m_matrix[index];
}
