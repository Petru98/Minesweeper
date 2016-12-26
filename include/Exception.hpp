#ifndef MINESWEEPER_EXCEPTION_HPP_INCLUDED
#define MINESWEEPER_EXCEPTION_HPP_INCLUDED

#include "error.hpp"
#include <stdexcept>

class Exception : std::exception
{
private:
    Error m_code;
    const char* m_what;

public:
    Exception(const Error p_code, const char* p_what) : m_code(p_code), m_what(p_what) {}

    virtual Error code()const noexcept {return m_code;}
    virtual const char* what()const noexcept {return m_what;}
};

#endif
