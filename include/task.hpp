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
    void set_isCompleted(bool);
    std::string get_task_name();
    bool &get_isCompleted();
    // std::string get_favorite();
    // bool get_isCompleted();
    // void print();

    sf::Sprite &get_sprite();
    sf::Texture &get_texture();
    sf::Sprite &get_trashSprite();
    sf::Texture &get_trashTexture();
private:
    sf::Texture tex;
    sf::Sprite sp;
    sf::Texture trash;
    sf::Sprite trashSp;
    std::string task_name;
    bool favorite = false;
    bool isCompleted = false;
};
#endif