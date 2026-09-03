#pragma once 

#include "../include/countDown.hpp"



void countDown::start(){clock.start();}
void countDown::stop(){clock.stop();};
void countDown::reset(){clock.reset();}
void countDown::restart(){clock.restart();};

void countDown::setCountdown(float t){duration = t;}

std::string countDown::printCountDown()
{
    sf::Time timeElapsed = clock.getElapsedTime();
    float time = timeElapsed.asSeconds();

    float timeLeft = duration - time;
    int timeleftINT = static_cast<int>(std::round(timeLeft));

    return std::to_string(timeleftINT);

};

bool countDown::isTimerOver()
{
    sf::Time time = clock.getElapsedTime();
    float ftime = time.asSeconds();

    if(duration - ftime <= 0){return true;}

    return false;

}