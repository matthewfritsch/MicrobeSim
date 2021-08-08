#include "Console.hpp"

#include <sys/ioctl.h>
#include <unistd.h>

Console::Console(std::shared_ptr<Logger> lgr) : logger(lgr)
{
    Coord max_term = GetTerminalSize(term_width_, term_height_);
    lgr->Log("Found console with dimensions " + std::to_string(term_width_) + "x" + std::to_string(term_height_));
    
    board = std::make_unique<Board>(term_width_, term_height_);
}

Console::~Console()
{
    board.reset();
}

Coord Console::GetTerminalSize(uint8_t &wid, uint8_t &hei)
{
    struct winsize wsz;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsz);
    wid = wsz.ws_col;
    hei = wsz.ws_row;
    Coord c(wid, hei);
    Log("Found " + std::to_string(wid) + " and " + std::to_string(hei));
    return c;
}

bool Console::PlaceAt(char c, uint8_t x, uint8_t y)
{
    Log("PlaceAt");
    return false;
}

void Console::Update()
{
    GetTerminalSize(term_width_, term_height_);
    frame_ctr++;
    std::cout << BLUE;
    for(uint8_t line_num = 0; line_num < term_height_; line_num++)
    {
        std::cout << "\n";
        for(uint8_t x = 0; x < term_width_; x++)
        {
            Coord c(x,line_num);
            std::cout << GetItemAt(c);
            if(x == term_width_-1 && line_num == term_height_-1)
            {
                std::cout.flush();
            }
        }
    }
    std::cout << CLEAR_COLOR;
}

char Console::GetItemAt(Coord c)
{
    if(!InBounds(c)) return 0;
    return board->GetAt(c);
}

bool Console::InBounds(Coord c)
{
    return c.x > 0 && c.x < term_width_ && c.y > 0 && c.y < term_height_;
}

void Console::Log(std::string toPrint)
{
    if(!logger) return;
    logger->Log(toPrint);
}