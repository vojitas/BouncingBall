#ifndef BRICK_H
#define BRICK_H
#include <SFML/Graphics.hpp>
#include "random.h"

using namespace sf;

class Brick
{
private:
    Vector2f position;

    RectangleShape brickShape;

    int type;

public:

    Brick(float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    int downType();

    void update();
};


#endif
