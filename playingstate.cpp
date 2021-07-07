#include "playingstate.h"

#include <sstream>

void PlayingState::Init(sf::RenderWindow *appWindow, std::vector<std::unique_ptr<GameState> > *gameStates, Config *configInfo)
{
  config = configInfo;
  states = gameStates;
  window = appWindow;

  racket.init(window->getSize().x / 2, window->getSize().y - 20, config->racketVelocity);

  ball.init(window->getSize().x / 2, 200, config->ballVelocity);

  level.generateLevel(window->getSize().x, window->getSize().y, 4);

  lives = 10;
  score = 0;

  font.loadFromFile("DS-DIGIT.TTF");
  hud.setFont(font);
  hud.setCharacterSize(25);
  hud.setFillColor(sf::Color::White);
  hud.setPosition(0, 200);
}

void PlayingState::Update()
{
  sf::Event event;

  if (level.getBricksSize()==0)
  {
    level.generateLevel(window->getSize().x , window->getSize().y, 4);
  }

  while (window->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window->close();
  }

  if (ball.getPosition().top > window->getSize().x)
  {
    ball.hitBottom();
    lives--;
    if (lives==0)
    {
      exit(0);
    }
  }

  if (ball.getPosition().top < 0)
  {
    ball.bounceRacketOrTop();
  }


  if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > window->getSize().x)
  {
    ball.bounceWall();
  }

  if (ball.getPosition().intersects(racket.getPosition()))
  {
    ball.bounceRacketOrTop();
  }

  ball.update();
  racket.update();
  score+=level.update(&ball);
}

void PlayingState::Draw()
{
  window->clear(sf::Color(26, 128, 182,255));
  level.drawBricks(*window);
  std::stringstream ss;
  ss << "Score:" << score << "    Lives:" << lives;
  hud.setString(ss.str());

  window->draw(ball.getShape());
  window->draw(racket.getShape());
  window->draw(hud);

  window->display();
}

void PlayingState::HandleInput()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    racket.moveLeft();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    racket.moveRight(window->getSize().x);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    states->pop_back();
  }
}
