#include "ball.h"
#include <iostream>
using namespace std;
void Ball::init(float startX, float startY, float vel)
{
    xVelocity = vel;
    yVelocity = vel;

    position.x = startX;
    position.y = startY;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}


RectangleShape Ball::getShape()
{
    return ballShape;
}

void Ball::bounceWall()
{
    xVelocity = -xVelocity;
}

void Ball::bounceRacketOrTop()
{
    position.y -= (yVelocity *3);
    yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
    position.y = 200;
    position.x = 500;
}


void Ball::bounceBrickBottom()
{
    position.y -= (yVelocity*3);
    position.x -= (xVelocity*2);
    yVelocity = -yVelocity;
}

void Ball::update()
{
    position.y += yVelocity;
    position.x += xVelocity;
    //cout<<position.y<<" : "<<yVelocity<<endl;

    ballShape.setPosition(position);
}
