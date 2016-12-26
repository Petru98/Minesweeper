#ifndef MINESWEEPER_FUNCTION_HPP_INCLUDED
#define MINESWEEPER_FUNCTION_HPP_INCLUDED

void callHandle(void (*func)())
{
    if(func != nullptr)
        func();
}
template<typename ARG_TYPE> void callHandle(void (*func)(const ARG_TYPE&), const ARG_TYPE& arg)
{
    if(func != nullptr)
        func(arg);
}

#endif
