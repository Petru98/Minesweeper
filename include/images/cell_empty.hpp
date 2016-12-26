#ifndef MINESWEEPER_CELLEMPTY_HPP_INCLUDED
#define MINESWEEPER_CELLEMPTY_HPP_INCLUDED

#include <cstddef>

namespace Resources
{
    namespace Images
    {
        static constexpr struct {std::size_t size; unsigned char data[113u + 1u];} cell_empty =
        {
            113,
            "\x89PNG\15\12\32\12\0\0\0\15IHDR\0\0\0\20\0\0\0\20\10\2\0\0\0\x90\x91h6\0\0\0\tpHYs\0\0\16\xC3\0\0\16\xC3\1\xC7o\xA8""d\0\0\0#"
            "IDAT(\xCF""clhh` \5\xB0""000888\20\xAF\x81\x89\x81""D0\xAA""aT\xC3\x80i\0\0\xF2\xA8\2""b\xE1\x9C\xB7J\0\0\0\0IEND\xAE""B`\x82"
        };
    }
}

#endif
