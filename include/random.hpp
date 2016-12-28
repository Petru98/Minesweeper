#ifndef MINEWEEPER_RANDOM_HPP_INCLUDED
#define MINEWEEPER_RANDOM_HPP_INCLUDED

#include <cstdint>

namespace Random
{
    namespace internal
    {
        extern uint32_t state_a;
        extern uint32_t state_b;
    }

    uint32_t rand();

    void seed(const uint32_t first_seed);
    void seed(const uint32_t first_seed, const uint32_t second_seed);

    double rand01();
}

#endif
