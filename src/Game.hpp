#ifndef GAME_HPP
#define GAME_HPP

#include <thread>
#include <memory>

#include "Console.hpp"

#define REFRESH_RATE_MS 1000/65

class Game{
    public:
        Game(uint8_t new_width = 91, uint8_t new_height = 33);
        ~Game();
        void StartGame();
        void StopGame();
    private:
        void Update();
        void Wait(uint8_t secs);
        void WaitMillis(uint16_t millis);

        std::unique_ptr<std::thread> t_run = nullptr;
        std::shared_ptr<Console> term;
        bool is_running_ = false;
        uint8_t width, height;
};

#endif