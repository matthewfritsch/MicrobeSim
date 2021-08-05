#ifndef UTILS_HPP
#define UTILS_HPP

#define LOGFILE "log.txt"

#include <fstream>
#include <iostream>
#include <thread>

std::string betterSubstr(std::string, uint16_t front, uint16_t back);
bool ClearTerm();
void Print(std::string);
void PrintFlush(std::string);
void PrintLn(std::string);
void WaitSecs(uint8_t secs);
void WaitMillis(uint16_t millis);

class Logger
{
    public:
        void Log(std::string toWrite);
    private:
        bool _logged = false;
};


#endif