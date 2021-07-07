#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Racket
{
private:
    Vector2f position;

    RectangleShape racketShape;

    float racketSpeed;

public:
    void init(float startX, float startY, float vel);

    FloatRect getPosition();

    RectangleShape getShape();

    void moveLeft();

    void moveRight(int max_w);

    void update();

};
