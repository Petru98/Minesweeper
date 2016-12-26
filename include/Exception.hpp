#ifndef MINESWEEPER_EXCEPTION_HPP_INCLUDED
#define MINESWEEPER_EXCEPTION_HPP_INCLUDED

#include <stdexcept>

class Exception : std::exception
{
private:
    unsigned int m_code;
    const char* m_what;

public:
    Exception(const unsigned int p_code, const char* p_what) : m_code(p_code), m_what(p_what) {}

    virtual unsigned int code()const noexcept {return m_code;}
    virtual const char* what()const noexcept {return m_what;}
};

#endif
