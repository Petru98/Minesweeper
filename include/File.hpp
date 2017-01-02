#ifndef MINESWEEPER_FILE_HPP_INCLUDED
#define MINESWEEPER_FILE_HPP_INCLUDED

#include <cstdio>
#include <SFML/Config.hpp>

class File
{
private:
    FILE* m_file;

public:
    File();
    File(const char* const filename, const char* const mode);
    ~File();

    bool open(const char* const filename, const char* const mode);
    void close();

    void writeUint16(const sf::Uint16 data);
    void writeUint8(const sf::Uint8 data);

    sf::Uint16 readUint16();
    sf::Uint8 readUint8();

};

#endif
