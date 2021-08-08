#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <memory>

#include "Board.hpp"
#include "Utils.hpp"

#define BLUE "\033[0;34m"
#define CLEAR_COLOR "\033[0m"

class Console
{
    public:
        Console(std::shared_ptr<Logger> lgr = nullptr);
        ~Console();
        char GetItemAt(Coord c);
        void Update();
        Coord GetTerminalSize(uint8_t &wid, uint8_t &hei);
        bool PlaceAt(char c, uint8_t x, uint8_t y);

    private:
        bool InBounds(Coord c);
        void Log(std::string);

        uint16_t frame_ctr = 0;
        std::unique_ptr<Board> board;
        std::shared_ptr<Logger> logger;
        uint8_t term_width_;
        uint8_t term_height_;
};

#endif