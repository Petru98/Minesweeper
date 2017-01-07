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

    bool isOpen()const;
    bool eof()const;

    bool write(const void* data, const std::size_t size);
    bool read(void* data, const std::size_t size);

    void writeUint8(const sf::Uint8 data);
    void writeUint16(const sf::Uint16 data);
    void writeUint32(const sf::Uint32 data);

    void writeInt8(const sf::Int8 data);
    void writeInt16(const sf::Int16 data);

    void writeSize_t(const std::size_t data);
    void writeInt(const int data);

    sf::Uint8  readUint8();
    sf::Uint16 readUint16();
    sf::Uint32 readUint32();

    sf::Int8  readInt8();
    sf::Int16 readInt16();

    std::size_t readSize_t();
    int         readInt();

protected:
    template<typename T> bool write(const T data);
    template<typename T> T read();
};

template<typename T> bool File::write(const T data)
{
    constexpr std::size_t size = sizeof(T);
    sf::Uint8 buff[size];

    for(std::size_t i = 0; i < size; ++i)
        buff[i] = static_cast<sf::Uint8>(data >> (8 * (size-1-i)));

    return fwrite(buff, size, 1, m_file) == size;
}

template<typename T> T File::read()
{
    constexpr std::size_t size = sizeof(T);
    sf::Uint8 buff[size];
    T data = 0;

    fread(buff, size, 1, m_file);

    for(std::size_t i = 0; i < size; ++i)
        data |= static_cast<T>(buff[i]) << (8 * (size-1-i));

    return data;
}

#endif
