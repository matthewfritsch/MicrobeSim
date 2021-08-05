#include "Utils.hpp"

std::string betterSubstr(std::string str, uint8_t front, uint8_t back)
{
    return str.substr(front, back-front);
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

void Logger::Log(std::string toWrite)
{
    std::ofstream out(LOGFILE);
    if(!_logged)
    {
        _logged = true;
        out.open(LOGFILE, std::ios::app);
    }
    out << toWrite << '\n';
    out.close();
}