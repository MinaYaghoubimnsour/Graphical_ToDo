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

// void task::set_favorite(string f)
// {
//   if(f == "y" || f == "n")
//   {
//     favorite = f;
//   }
//   else
//   {
//     throw invalid_argument("favorite must be \"y\" or \"n\" !");
//   }
// }
void task::set_isCompleted(bool c)
{
  isCompleted = c;
}
string task::get_task_name()
{
  return task_name;
}
//
// string task::get_favorite()
// {
//   return favorite;
// }
//

// void task::print()
// {
//   cout << setw(maxSizeOfTaskName + 3) << left << task_name << setw(4) << left
//     << priority << setw(4) << left << favorite << setw(4) << left
//     << ID << endl;
// }

sf::Sprite &task::get_sprite()
{
  return sp;
}

sf::Texture &task::get_texture()
{
  return tex;
}

bool &task::get_isCompleted()
{
  return isCompleted;
}

sf::Sprite &task::get_trashSprite()
{
  return trashSp;
}
sf::Texture &task::get_trashTexture()
{
  return trash;
}