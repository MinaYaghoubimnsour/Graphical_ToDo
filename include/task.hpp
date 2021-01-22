#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cstring>
typedef unsigned int ui;
class task
{
public:
    task(std::string);
    void set_task_name(std::string);
    std::string get_task_name();
    void set_favorite(bool);
    bool get_favorite();
    void set_isCompleted(bool);
    bool get_isCompleted();

    //member functions which relate to circle icon
    void loadCircleTexture();
    void setTextureCircleSpr();
    void setPositionCircleSpr(float, float);
    sf::Texture get_circleTexture();
    sf::Sprite get_circleSprite();
    //member functions which relate to trash icon
    void loadTrashTexture();
    void setTextureTrashSpr();
    void setPositionTrashSpr(float, float);
    sf::Texture get_trashTexture();
    sf::Sprite get_trashSprite();
    //member functions which relate to star icon
    void loadStarTexture();
    void setTextureStarSpr();
    void setPositionStarSpr(float, float);
    sf::Texture get_starTexture();
    sf::Sprite get_starSprite();

    //member functions which relate to pencil icon
    void loadPencilTexture();
    void setTexturePencilSpr();
    void setPositionPencilSpr(float, float);
    sf::Texture get_PencilTexture();
    sf::Sprite get_PencilSprite();

private:
    //std::string task_name;
    char task_name[45];
    bool favorite = false;
    bool isCompleted = false;
    sf::Texture circle;
    sf::Sprite circleSpr;
    sf::Texture trash;
    sf::Sprite trashSpr;
    sf::Texture star;
    sf::Sprite starSpr;
    sf::Texture pencil;
    sf::Sprite pencilSpr;
};
#endif
