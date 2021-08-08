#ifndef UTILS_HPP
#define UTILS_HPP

#define LOGFILE "log.txt"
#define U8BI_MAX 0b11111111

#include <fstream>
#include <iostream>
#include <thread>

std::string restOfSubstr(std::string word, uint16_t front);
std::string betterSubstr(std::string word, uint16_t front, uint16_t back);
bool ClearTerm();
void Print(std::string);
void PrintFlush(std::string);
void PrintLn(std::string);
void WaitSecs(uint8_t secs);
void WaitMillis(uint16_t millis);

struct Coord{
    uint8_t x, y;
    inline Coord() : x(U8BI_MAX), y(U8BI_MAX){}
    inline Coord(uint8_t nx, uint8_t ny) : x(nx), y(ny){}
};

class Logger
{
    public:
        Logger();
        ~Logger();
        void Log(std::string toWrite);
    private:
        bool _logged = false;
        std::ofstream out;
};


#endif