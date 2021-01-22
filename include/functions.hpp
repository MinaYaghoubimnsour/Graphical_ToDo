
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "task.hpp"
void setTime(sf::Text &, sf::Font &, sf::Sprite &);
void partOfAddText(sf::RenderWindow &, sf::Text &, sf::Font &);
void setFirstLine(sf::RenderWindow &, sf::RectangleShape &, sf::Sprite &);
void manage_window2(sf::RenderWindow & ,sf::RenderWindow & , std::vector<task> & ,std::vector<sf::RectangleShape> & rect , std :: vector<sf::Text>& , sf::Font &  );
void manage_window3(sf::RenderWindow &, std::vector<task> &, sf::Font &, int);
void manage_window4(sf::RenderWindow & , std::vector<task> & , sf::Font & , int );


#endif // FUNCTIONS_HPP
