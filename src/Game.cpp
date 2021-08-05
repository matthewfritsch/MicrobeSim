#include "Game.hpp"

Game::Game(Logger *lgr, uint8_t new_width, uint8_t new_height): width(new_width), height(new_height)
{
    // t_run = nullptr;
    logger = lgr;
    is_running_ = true;
    term = std::make_shared<Console>();
    StartGame();
}

Game::~Game()
{
    is_running_ = false;
    if(t_run != nullptr && t_run->joinable())
    {
        t_run->join();
        t_run = nullptr;
    }
}

void Game::StartGame()
{
    if(!is_running_) return;
    if(t_run != nullptr) return;
    t_run = std::make_unique<std::thread>([this] {Update();});
}

void Game::Update()
{
    while(is_running_)
    {
        //lots of logic for vclass

        term->Update();
        WaitMillis(REFRESH_RATE_MS);
    }
}

void Game::WaitMillis(uint16_t millis)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}

void Game::Log(std::string toPrint)
{
    if(!logger) return;
    logger->Log(toPrint);
}