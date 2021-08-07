#ifndef GAME_HPP
#define GAME_HPP

#include <thread>
#include <memory>
#include <vector>

#include "Console.hpp"
#include "Plague.hpp"

#define REFRESH_RATE_MS 1000/65

class Game{
    public:
        Game(std::shared_ptr<Logger> lgr = nullptr, uint8_t new_width = 91, uint8_t new_height = 33);
        ~Game();
        void StartGame();
        void StopGame();
    private:
        void Update();
        void Wait(uint8_t secs);
        void WaitMillis(uint16_t millis);
        void Log(std::string);

        std::vector<Plague> plagues;
        std::unique_ptr<std::thread> t_run;
        std::shared_ptr<Console> term;
        std::shared_ptr<Logger> logger;

        bool is_running_ = false;
        uint8_t width, height;
};

#endif