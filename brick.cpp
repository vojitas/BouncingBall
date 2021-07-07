#include "brick.h"

Brick::Brick(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    brickShape.setSize(sf::Vector2f(50, 20));
    brickShape.setPosition(position);
    type=rand_i(0,4);
}

FloatRect Brick::getPosition()
{
    return brickShape.getGlobalBounds();
}

RectangleShape Brick::getShape()
{
    return brickShape;
}

int Brick::downType()
{
    return --type;
}

void Brick::update()
{
    switch(type)
    {
        case 1:
          brickShape.setFillColor (Color(255, 0, 0));
          brickShape.setOutlineColor(Color(0, 0, 0));
          break;
        case 2:
          brickShape.setFillColor (Color(255, 255, 0));
          brickShape.setOutlineColor(Color(0, 0, 0));
          break;
        case 3:
          brickShape.setFillColor (Color(0, 255, 0));
          brickShape.setOutlineColor(Color(0, 0, 0));
          break;
        case 4:
          brickShape.setFillColor (Color(0, 0, 255));
          brickShape.setOutlineColor(Color(0, 0, 0));
          break;


        default:
          brickShape.setFillColor (Color(255, 0, 0));
    }
    brickShape.setPosition(position);
}
