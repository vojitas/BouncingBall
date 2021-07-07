#pragma once
#include <SFML/Graphics.hpp>
#include "random.h"

using namespace sf;

class Ball
{
private:
    Vector2f position;

    RectangleShape ballShape;

    float xVelocity;
    float yVelocity;

public:
    void init(float startX, float startY, float vel);

    FloatRect getPosition();

    RectangleShape getShape();

    void bounceWall();

    void bounceRacketOrTop();

    void hitBottom();

    void bounceBrickBottom();

    void update();

};
