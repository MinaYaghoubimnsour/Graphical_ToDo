#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "task.hpp"
using namespace std;
task::task(string n) : task_name(n)
{
}
void task::set_task_name(string n)
{
  task_name = n;
}

string task::get_task_name()
{
  return task_name;
}

void task::set_favorite(bool b)
{
  favorite = b;
}

bool task::get_favorite()
{
  return favorite;
}

void task::set_isCompleted(bool c)
{
  isCompleted = c;
}

bool task::get_isCompleted()
{
  return isCompleted;
}

//member functions which relate to circle icon
void task::loadCircleTexture()
{
  if (isCompleted)
  {
    circle.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/checkmark.png");
  }
  else
  {
    circle.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/circle.png");
  }

}

void task::setTextureCircleSpr()
{
  circleSpr.setTexture(circle);
}
void task::setPositionCircleSpr(float x, float y)
{
  circleSpr.setPosition(sf::Vector2f(x, y));

}


sf::Texture task::get_circleTexture()
{
  return circle;
}

sf::Sprite task::get_circleSprite()
{
  return circleSpr;
}
//member functions which relate to trash icon
void task::loadTrashTexture()
{
  trash.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/trash.png");
}
void task::setTextureTrashSpr()
{
  trashSpr.setTexture(trash);
}
void task::setPositionTrashSpr(float x, float y)
{
  trashSpr.setPosition(x,y);
}

sf::Texture task::get_trashTexture()
{
  return trash;
}

sf::Sprite task::get_trashSprite()
{
  return trashSpr;
}

//member functions which relate to star icon

void task::loadStarTexture()
{
  if(!favorite)
  star.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/star.png");
  else
  star.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/yellow_star.png");

}

void task::setTextureStarSpr()
{
  starSpr.setTexture(star);
}

void task::setPositionStarSpr(float x, float y)
{
  starSpr.setPosition(sf::Vector2f(x, y));
}

sf::Texture task::get_starTexture()
{
  return star;
}
sf::Sprite task::get_starSprite()
{
  return starSpr;
}
