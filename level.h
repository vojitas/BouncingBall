#pragma once
#include <SFML/Graphics.hpp>
#include "brick.h"
#include "ball.h"
#include <vector>
#include "random.h"
#include <memory>

using namespace sf;

class Level
{
private:
  int level;
  std::vector<std::unique_ptr<Brick>> bricks;
public:

      void generateLevel(int max_width, int max_height, int stages);
      int update(Ball *ball);
      void drawBricks(RenderWindow &window);
      int getBricksSize();
};
