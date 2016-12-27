#include "Matrix.hpp"

template<typename T> Matrix<T>::Matrix()
    : m_matrix(nullptr), m_lines(0), m_columns(0) {}

template<typename T> Matrix<T>::Matrix(const std::size_t p_lines, const std::size_t p_columns)
    : m_matrix(nullptr), m_lines(0), m_columns(0)
{
    create(p_lines, p_columns);
}

template<typename T> bool Matrix<T>::create(const std::size_t p_lines, const std::size_t p_columns)
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
template<typename T> bool Matrix<T>::M_alloc(const std::size_t p_lines, const std::size_t p_columns)
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

template<typename T> Matrix<T>::~Matrix()
{
    if(m_matrix != nullptr)
        M_dealloc();
}

template<typename T> void Matrix<T>::destroy()
{
    M_dealloc();
    m_matrix = nullptr;
    m_lines = 0;
    m_columns = 0;
}
template<typename T> void Matrix<T>::M_dealloc()
{
    delete[] (*m_matrix);
    delete[]   m_matrix;
}

template<typename T> bool Matrix<T>::isCreated()const
{
    return m_matrix;
}
template<typename T> std::size_t Matrix<T>::lines()const
{
    return m_lines;
}
template<typename T> std::size_t Matrix<T>::columns()const
{
    return m_columns;
}

template<typename T> T* Matrix<T>::operator[] (const std::size_t index)
{
    return m_matrix[index];
}
template<typename T> const T* Matrix<T>::operator[] (const std::size_t index)const
{
    return m_matrix[index];
}
