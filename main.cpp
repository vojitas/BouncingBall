#include <iostream>

#include "app.h"

// kompilacja:   g++ main.cpp app.cpp racket.cpp ball.cpp brick.cpp level.cpp random.cpp playingstate.cpp menustate.cpp settingsstate.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
// program:  ./sfml-app



#include <SFML/Graphics.hpp>
using namespace std;


int main()
{
    App *application = new App();
    application->run(1000,768,"Breakout");

    delete application;

    return 0;
}
