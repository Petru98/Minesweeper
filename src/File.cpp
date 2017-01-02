#include "file.hpp"

File::File() : m_file(nullptr)
{}
File::File(const char* const filename, const char* const mode)
{
    this->open(filename, mode);
}
File::~File()
{
    this->close();
}

bool File::open(const char* const filename, const char* const mode)
{
    m_file = fopen(filename, mode);
    return m_file;
}
void File::close()
{
    fclose(m_file);
    m_file = nullptr;
}

void File::writeUint16(const sf::Uint16 data)
{
    sf::Uint8 buff[2] = {static_cast<sf::Uint8>(data >> 8), static_cast<sf::Uint8>(data & 0x7F)};
    fwrite(buff, 1, 2, m_file);
}
void File::writeUint8(const sf::Uint8 data)
{
    fwrite(&data, 1, 1, m_file);
}

sf::Uint16 File::readUint16()
{
    sf::Uint8 buff[2];
    fread(buff, 1, 2, m_file);
    return (static_cast<sf::Uint16>(buff[0]) << 8) | (static_cast<sf::Uint16>(buff[1]));
}
sf::Uint8 File::readUint8()
{
    sf::Uint8 buff;
    fread(&buff, 1, 1, m_file);
    return static_cast<sf::Uint8>(buff);
}
