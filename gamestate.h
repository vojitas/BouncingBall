#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "config.h"

class GameState
{
public:
    virtual void Init(sf::RenderWindow *appWindow, std::vector<std::unique_ptr<GameState> > *gameStates, Config *configInfo) = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void HandleInput() = 0;

protected:
    Config *config;
    sf::RenderWindow *window;
    std::vector<std::unique_ptr<GameState> > *states;
};

#endif
