#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "gamestate.h"

#include "racket.h"
#include "ball.h"
#include "level.h"

class PlayingState : public GameState
{
public:
    void Init(sf::RenderWindow *appWindow, std::vector<std::unique_ptr<GameState> > *gameStates, Config *configInfo) override;
    void Update() override;
    void Draw() override;
    void HandleInput() override;

private:
    Racket racket;
    Level level;
    Ball ball;

    sf::Text hud;
    sf::Font font;

    int lives;
    int score;
};

#endif
