#ifndef UTILS_HPP
#define UTILS_HPP

#define LOGFILE "log.txt"

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