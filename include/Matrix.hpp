#ifndef MINESWEEPER_MATRIX_HPP_INCLUDED
#define MINESWEEPER_MATRIX_HPP_INCLUDED

#include <cstddef>
#include <new>

template <typename T>
class Matrix
{
private:
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);

    T**         m_matrix;
    std::size_t m_lines;
    std::size_t m_columns;

    bool M_alloc(const std::size_t p_lines, const std::size_t p_columns);
    void M_dealloc();

public:
    Matrix();
    Matrix(const std::size_t p_lines, const std::size_t p_columns);

    ~Matrix();

    bool create(const std::size_t p_lines, const std::size_t p_columns);
    void destroy();

    bool isCreated()const;
    std::size_t lines()const;
    std::size_t columns()const;

    T* operator[] (const std::size_t index);
    const T* operator[] (const std::size_t index)const;
};

#endif
