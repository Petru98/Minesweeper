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

    bool M_alloc(std::size_t p_lines, std::size_t p_columns);
    void M_dealloc();

public:
    Matrix();
    Matrix(std::size_t p_lines, std::size_t p_columns);

    ~Matrix();

    bool create(std::size_t p_lines, std::size_t p_columns);
    void destroy();

    bool isCreated()const;
    std::size_t width()const;
    std::size_t height()const;

    T* const operator[] (std::size_t index);
    const T* const operator[] (std::size_t index)const;
};

#endif
