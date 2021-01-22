
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "task.hpp"
void setTime(sf::Text &, sf::Font &, sf::Sprite &);
void partOfAddText(sf::RenderWindow &, sf::Text &, sf::Font &);
void setFirstLine(sf::RenderWindow &, sf::RectangleShape &, sf::Sprite &);
void manage_window3(sf::RenderWindow &, std::vector<task> &, sf::Font &, int);
void manage_window4(sf::RenderWindow &, std::vector<task> &, sf::Font &, int);
void errorWindow(std::string, sf::Font &);
void ReadFromFile(std::ifstream &file, std::vector<task> &tasks, std::vector<sf::Text> &taskName, sf::Font &font, std::vector<sf::RectangleShape> &rect);
//void writeInFile(std::ofstream&, std::vector<task> &);
#endif // FUNCTIONS_HPP
