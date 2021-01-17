#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "task.hpp"
//extern int maxSizeOfTaskName;
using namespace std;
//extern bool isRepeated(vector<task>, int);
task::task(string n) : task_name(n)
{
  cout << "constructor :" << task_name << endl;
}
void task::set_task_name(string n)
{
  task_name = n;
}

void task::set_favorite(bool b)
{
  favorite = b;
}
void task::set_isCompleted(bool c)
{
  isCompleted = c;
}
string task::get_task_name()
{
  return task_name;
}

bool task::get_favorite()
{
  return favorite;
}


// void task::print()
// {
//   cout << setw(maxSizeOfTaskName + 3) << left << task_name << setw(4) << left
//     << priority << setw(4) << left << favorite << setw(4) << left
//     << ID << endl;
// }

sf::Sprite &task::get_circleSprite()
{
  return circleSpr;
}

sf::Texture &task::get_circleTexture()
{
  return circle;
}
sf::Texture task::get_starTexture()
{
  return star;
}
sf::Sprite task::get_starSprite()
{
  return starSpr;
}
void task::loadStarTexture()
{
  if(!favorite)
    star.loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/star.png");
  else
    star.loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/yellow_star.png");

}
void task::setTextureStarSpr()
{
  starSpr.setTexture(star);
}
void task::setPositionStarSpr(float x, float y)
{
  starSpr.setPosition(sf::Vector2f(x, y));
}

bool &task::get_isCompleted()
{
  return isCompleted;
}

sf::Sprite &task::get_trashSprite()
{
  return trashSpr;
}
sf::Texture &task::get_trashTexture()
{
  return trash;
}
