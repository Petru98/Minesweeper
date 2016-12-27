#ifndef MINESWEEPER_FUNCTION_HPP_INCLUDED
#define MINESWEEPER_FUNCTION_HPP_INCLUDED

void callHandler(void (*func)())
{
    if(func != nullptr)
        func();
}
template<typename ARG_TYPE> void callHandler(void (*func)(const ARG_TYPE&), const ARG_TYPE& arg)
{
    if(func != nullptr)
        func(arg);
}

#endif
