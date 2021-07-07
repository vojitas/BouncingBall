
#include "app.h"
#include "playingstate.h"
#include "menustate.h"
#include "config.h"
#include <sstream>
#include <cstdlib>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
void App::run(int width, int height,string n){
  Config config;
  config.ballVelocity = 3.5f;
  config.racketVelocity = 7.0f;
  RenderWindow window(VideoMode(width, height), n);

  window.setFramerateLimit(60);

  std::vector<std::unique_ptr<GameState> > states;
  states.push_back(std::make_unique<MenuState>());
  states.back()->Init(&window, &states, &config);

  while (window.isOpen())
  {
    states.back()->HandleInput();
    states.back()->Update();
    states.back()->Draw();
  }
}
