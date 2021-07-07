#include "level.h"


void Level::generateLevel(int max_width, int max_height, int stages)
{
    int act_height=0;
    for(int i=0;i<stages;i++)
    {
      int act_width=0;
      while(act_width<max_width)
      {
        int random_num=rand_i(0,1);
        if(random_num==1){
          Brick temp(act_width, act_height);
          bricks.push_back(std::make_unique<Brick> (act_width,act_height));
        }
        act_width+=50;
      }
      act_height+=30;
    }
}

int Level::update(Ball *ball)
{
  int score=0;
  for(int i=0;i<bricks.size();i++)
  {

    if (ball->getPosition().intersects(bricks[i]->getPosition()))
    {
        ball->bounceBrickBottom();
        score++;
        if(bricks[i]->downType()<1)
          bricks.erase(bricks.begin()+i);
    }

    bricks[i]->update();
  }
  return score;
}

int Level::getBricksSize()
{
    return bricks.size();
}

void Level::drawBricks(RenderWindow &window)
{
  for(int i=0;i<bricks.size();i++)
  {
    window.draw(bricks[i]->getShape());
  }
}
