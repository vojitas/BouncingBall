#include "racket.h"

void Racket::init(float startX, float startY, float vel)
{
    racketSpeed = vel;

    position.x = startX;
    position.y = startY;

    racketShape.setSize(sf::Vector2f(100, 5));
    racketShape.setPosition(position);
}

FloatRect Racket::getPosition()
{
    return racketShape.getGlobalBounds();
}

RectangleShape Racket::getShape()
{
    return racketShape;
}

void Racket::moveLeft()
{

    position.x -= racketSpeed;
    if(position.x<0)
      position.x+=racketSpeed;
}

void Racket::moveRight(int max_w)
{
    position.x += racketSpeed;
    if(position.x>max_w-100)
      position.x-=racketSpeed;
}

void Racket::update()
{
    racketShape.setPosition(position);
}
