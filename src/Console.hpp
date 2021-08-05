
#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Utils.hpp"

#define U8BI_MAX 0b11111111

struct Coord{
    uint8_t x, y;
    inline Coord() : x(U8BI_MAX), y(U8BI_MAX){}
    inline Coord(uint8_t nx, uint8_t ny) : x(nx), y(ny){}
};

class Console
{
    public:
        Console(Logger *lgr = nullptr);
        ~Console();
        char GetItemAt(Coord c);
        void Update();
        Coord GetTerminalSize(uint8_t &wid, uint8_t &hei);
        bool PlaceAt(char c, uint8_t x, uint8_t y);

    private:
        bool InBounds(Coord c);
        void Log(std::string);

        uint16_t frame_ctr = 0;
        std::string *board = nullptr;
        Logger *logger;
        uint8_t term_width_;
        uint8_t term_height_;
};


#endif