#include "Console.hpp"

#include <sys/ioctl.h>
#include <unistd.h>

Console::Console()
{
    Coord max_term = GetTerminalSize();
    term_width_ = max_term.x;
    term_height_= max_term.y;
    std::cout << "Found console with dimensions " << (int)term_width_ << "x" << (int)term_height_ << std::endl;
    
    board = new std::string[term_height_];
}

Console::~Console()
{
    delete[] board;
}

Coord Console::GetTerminalSize()
{
    struct winsize wsz;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsz);
    Coord c(wsz.ws_col, wsz.ws_row);
    return c;
}

bool Console::PlaceAt(char c, uint8_t x, uint8_t y)
{
    std::cout << "PlaceAt" << std::endl;
    
    return false;
}

void Console::Update()
{
        frame_ctr++;
        for(uint8_t line_num = 0; line_num < term_height_; line_num++)
        {
            std::cout << std::endl;
            for(uint8_t x = 0; x < term_width_; x++)
            {
                if(x == term_width_-1 && line_num == term_height_-1)
                {
                    std::cout.flush();
                    std::cout << "X";
                }
                else if(x == 0 || line_num == 0 || x == term_width_-1 || line_num == term_height_-1)
                    std::cout << "X";
                else
                    std::cout << " ";
            }
        }
}

char Console::GetItemAt(Coord c)
{
    if(!InBounds(c)) return 0;
    return board[c.y][c.x];
}

bool Console::InBounds(Coord c)
{
    return c.x > 0 && c.x < term_width_ && c.y > 0 && c.y < term_height_;
}