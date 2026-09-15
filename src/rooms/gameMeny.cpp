
#include "../../include/rooms/gameMeny.hpp"


void gameMeny::drawBackground()
{
    background menyBAckground("Assets/PNG/pikselBackground.png",static_cast<float>(window->getSize().x),static_cast<float>(window->getSize().y));
    menyBAckground.draw(*window);
}

void gameMeny::drawClouds()
{
    character cloud1("Assets/PNG/cloud.png", {100.0,200.0}, {0.2,0.2});
	cloud1.buildCharacter();
    cloud1.draw(*window);

}