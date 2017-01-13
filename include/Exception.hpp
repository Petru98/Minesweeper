#ifndef MINESWEEPER_EXCEPTION_HPP_INCLUDED
#define MINESWEEPER_EXCEPTION_HPP_INCLUDED

#include <stdexcept>

class Exception : std::exception
{
private:
    const char* m_what;

public:
    Exception(const char* const p_what) : m_what(p_what) {}

    virtual const char* what()const noexcept {return m_what;}
};

#endif
