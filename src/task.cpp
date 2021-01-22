#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "task.hpp"
using namespace std;
task::task(string n) //: task_name(n)
{
  strcpy(task_name, n.c_str());
}
void task::set_task_name(string n)
{
  //task_name = n;
  strcpy(task_name, n.c_str());
}

string task::get_task_name()
{
  return static_cast<string>(task_name);
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
    circle.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git4/Graphical_ToDo/checkmark.png");
  }
  else
  {
    circle.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git4/Graphical_ToDo/circle.png");
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
  trash.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git4/Graphical_ToDo/trash.png");
}
void task::setTextureTrashSpr()
{
  trashSpr.setTexture(trash);
}
void task::setPositionTrashSpr(float x, float y)
{
  trashSpr.setPosition(x, y);
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
  if (!favorite)
    star.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git4/Graphical_ToDo/Star.png");
  else
    star.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git4/Graphical_ToDo/yellowStar.png");
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

//member functions which relate to pencil icon
void task::loadPencilTexture()
{
  pencil.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git4/Graphical_ToDo/pencil .png");
}
void task::setTexturePencilSpr()
{
  pencilSpr.setTexture(pencil);
}
void task::setPositionPencilSpr(float x, float y)
{
  pencilSpr.setPosition(sf::Vector2f(x, y));
}
sf::Texture task::get_PencilTexture()
{
  return pencil;
}
sf::Sprite task::get_PencilSprite()
{
  return pencilSpr;
}
