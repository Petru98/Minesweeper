#include "file.hpp"

File::File() : m_file(nullptr)
    {}
File::File(const char* const filename, const char* const mode)
    {this->open(filename, mode);}
File::~File()
    {this->close();}

bool File::open(const char* const filename, const char* const mode)
{
    m_file = fopen(filename, mode);
    return m_file;
}
void File::close()
{
    if(m_file != nullptr)
    {
        fclose(m_file);
        m_file = nullptr;
    }
}

bool File::isOpen()const {return m_file;}
bool File::eof()const    {return feof(m_file);}

bool File::write(const void* data, const std::size_t size)
{
    return fwrite(data, 1, size, m_file) == size;
}
bool File::read(void* data, const std::size_t size)
{
    return fread(data, 1, size, m_file) == size;
}

void File::writeUint8(const sf::Uint8 data)
{
    fwrite(&data, 1, 1, m_file);
}
void File::writeUint16(const sf::Uint16 data)
{
    sf::Uint8 buff[2] = {static_cast<sf::Uint8>(data >> 8), static_cast<sf::Uint8>(data)};
    fwrite(buff, 2, 1, m_file);
}
void File::writeUint32(const sf::Uint32 data)
{
    sf::Uint8 buff[4] =
    {
        static_cast<sf::Uint8>(data >> 24),
        static_cast<sf::Uint8>(data >> 16),
        static_cast<sf::Uint8>(data >> 8),
        static_cast<sf::Uint8>(data)
    };
    fwrite(buff, 4, 1, m_file);
}

void File::writeInt8(const sf::Int8 data)
{
    fwrite(&data, 1, 1, m_file);
}

void File::writeSize_t(const std::size_t data)
{
    write(data);
}
void File::writeInt(const int data)
{
    write(static_cast<unsigned int>(data));
}

sf::Uint8 File::readUint8()
{
    sf::Uint8 buff;
    fread(&buff, 1, 1, m_file);
    return buff;
}
sf::Uint16 File::readUint16()
{
    sf::Uint8 buff[2];
    fread(buff, 2, 1, m_file);
    return (static_cast<sf::Uint16>(buff[0]) << 8) | (static_cast<sf::Uint16>(buff[1]));
}
sf::Uint32 File::readUint32()
{
    sf::Uint8 buff[4];
    fread(buff, 4, 1, m_file);
    return (static_cast<sf::Uint32>(buff[0]) << 24) | (static_cast<sf::Uint32>(buff[1]) << 16) |
           (static_cast<sf::Uint32>(buff[1]) << 8)  | (static_cast<sf::Uint32>(buff[1]));
}

sf::Int8 File::readInt8()
{
    sf::Int8 buff;
    fread(&buff, 1, 1, m_file);
    return buff;
}

std::size_t File::readSize_t()
{
    return read<std::size_t>();
}
int File::readInt()
{
    return read<unsigned int>();
}
