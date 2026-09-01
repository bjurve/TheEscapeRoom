#pragma once

#include <SFML/Graphics.hpp>


class countDown{
    public:
    countDown(float seconds): duration{seconds}, clock{}{};


    void start();
    void stop();
    void restart();
    void reset();
    std::string printCountDown();
    
    bool isTimerOver();



    private:
    float duration;

    sf::Clock clock;



};