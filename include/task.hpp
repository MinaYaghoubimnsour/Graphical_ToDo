#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
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

    sf::Sprite &get_sprite();
    sf::Texture &get_texture();

private:
    sf::Texture tex;
    sf::Sprite sp;
    std::string task_name;
    bool favorite = false;
    bool isCompleted = false;
};
#endif