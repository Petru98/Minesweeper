#ifndef MINEWEEPER_RANDOM_HPP_INCLUDED
#define MINEWEEPER_RANDOM_HPP_INCLUDED

#include <cstddef>

namespace Random
{
    namespace internal
    {
        uint32_t state_a = 123456789u;
        uint32_t state_b = 1012017u;
    }

    inline uint32_t rand()
    {
        using namespace internal;

        uint32_t x = state_a;
        uint32_t y = state_b;
        state_a = state_b;

        x ^= x << 23;
        state_b = x ^ state_b ^ (x >> 17) ^ (state_b >> 26);

        return state_b + y;
    }

    inline void seed(const uint32_t first_seed)
    {
        if(first_seed == 0)
        {
            internal::state_a = 123456789u;
            internal::state_b = 1012017u;
        }
        else
        {
            internal::state_a = first_seed;
            internal::state_b = first_seed;
        }
    }
    inline void seed(const uint32_t first_seed, const uint32_t second_seed)
    {
        if(first_seed == 0 && second_seed == 0)
        {
            internal::state_a = 123456789u;
            internal::state_b = 1012017u;
        }
        else
        {
            internal::state_a = first_seed;
            internal::state_b = second_seed;
        }
    }

    inline double rand01()
    {
        return (rand() + 1.0) * 2.328306435454494 - 10.0;
    }
}

#endif
