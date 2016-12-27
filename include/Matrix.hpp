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
    std::size_t m_width;
    std::size_t m_height;

    bool M_alloc(std::size_t w, std::size_t h);
    void M_dealloc();

public:
    Matrix();
    Matrix(std::size_t w, std::size_t h);

    ~Matrix();

    bool create(std::size_t w, std::size_t h);
    void destroy();

    bool isCreated()const;
    std::size_t width()const;
    std::size_t height()const;

    T* const operator[] (std::size_t index);
    const T* const operator[] (std::size_t index)const;
};

#endif
