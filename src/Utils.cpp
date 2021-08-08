#include "Utils.hpp"

std::string betterSubstr(std::string word, uint16_t front, uint16_t back)
{
    return word.substr(front, back-front);
}

std::string restOfSubstr(std::string word, uint16_t front)
{
    return betterSubstr(word, front, word.size());
}

bool ClearTerm()
{
    PrintLn("\n\n\n");
    return 0;
}

void Print(std::string toPrint)
{
    std::cout << toPrint;
}

void PrintFlush(std::string toPrint)
{
    std::cout.flush();
    Print(toPrint);
}

void PrintLn(std::string toPrint)
{
    Print(toPrint);
    std::cout << std::endl;
}

void WaitSecs(uint8_t secs)
{
    WaitMillis(secs*1000);
}

void WaitMillis(uint16_t millis)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}

Logger::Logger()
{
    out.open(LOGFILE);
    _logged = false;
}

Logger::~Logger()
{
    out.close();
    _logged = true;
}

void Logger::Log(std::string toWrite)
{
    out << toWrite << '\n';
    if(!_logged)
    {
        _logged = true;
        out.close();
        out.open(LOGFILE, std::ios::app);
    }
}