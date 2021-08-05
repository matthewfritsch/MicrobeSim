
#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>

#define U8BI_MAX 0b11111111

struct Coord{
    uint8_t x, y;
    inline Coord() : x(U8BI_MAX), y(U8BI_MAX){}
    inline Coord(uint8_t nx, uint8_t ny) : x(nx), y(ny){}
};

class Console
{
    public:
        Console();
        ~Console();
        char GetItemAt(Coord c);
        void Update();
        Coord GetTerminalSize();
        bool PlaceAt(char c, uint8_t x, uint8_t y);

    private:
        bool InBounds(Coord c);            
        uint16_t frame_ctr = 0;
        std::string *board = nullptr;

        uint8_t term_width_;
        uint8_t term_height_;
};


#endif