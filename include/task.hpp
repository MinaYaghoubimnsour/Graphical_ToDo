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
    void set_favorite(bool);
    void set_isCompleted(bool);
    std::string get_task_name();
    bool &get_isCompleted();
    bool get_favorite();
    // bool get_isCompleted();
    // void print();

    sf::Sprite &get_circleSprite();
    sf::Texture &get_circleTexture();
    sf::Sprite &get_trashSprite();
    sf::Texture &get_trashTexture();
    sf::Texture get_starTexture();
    sf::Sprite get_starSprite();
    void loadStarTexture();
    void setTextureStarSpr();
    void setPositionStarSpr(float, float);


private:
    sf::Texture circle;
    sf::Sprite circleSpr;
    sf::Texture trash;
    sf::Sprite trashSpr;
    sf::Texture star;
    sf::Sprite starSpr;
    std::string task_name;
    bool favorite = false;
    bool isCompleted = false;
};
#endif
