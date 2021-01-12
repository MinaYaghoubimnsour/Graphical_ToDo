#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
#include <vector>
typedef unsigned int ui;
class task
{
public:
task(std::string);
void set_task_name(std::string);
// void set_favorite(std::string);
// void set_isCompleted(bool);
std::string get_task_name();
// std::string get_favorite();
// bool get_isCompleted();
// void print();
private:
std::string task_name;
bool favorite = false;
bool isCompleted = false;
};
#endif