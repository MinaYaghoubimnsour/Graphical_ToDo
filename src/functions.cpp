#include "functions.hpp"
using namespace std;
void setTime(sf::Text &timeTxt, sf::Font &timeFont, sf::Sprite &calendarSpr)
{
    time_t timetoday;
    time(&timetoday);
    string str = static_cast<string>(asctime(localtime(&timetoday)));
    timeTxt.setFont(timeFont);
    timeTxt.setFillColor(sf::Color::Black);
    timeTxt.setCharacterSize(timeTxt.getCharacterSize() + 15);
    timeTxt.setString(str);
    timeTxt.setPosition(sf::Vector2f((calendarSpr.getGlobalBounds().width + 20), 0));
}

void partOfAddText(sf::RenderWindow &window, sf::Text &addTxt, sf::Font &font)
{
    addTxt.setFont(font);
    addTxt.setFillColor(sf::Color::Black);
    addTxt.setString("+ add a task");
    addTxt.setCharacterSize(addTxt.getCharacterSize() + 15);

    addTxt.setPosition(sf::Vector2f(0, window.getSize().y - 2 * addTxt.getGlobalBounds().height));
}

void setFirstLine(sf::RenderWindow &window, sf::RectangleShape &line, sf::Sprite &calendarSpr)
{
    line.setFillColor(sf::Color::Black);
    line.setSize(sf::Vector2f(window.getSize().x, 4));
    line.setPosition(sf::Vector2f(0, calendarSpr.getGlobalBounds().height + 20));
}

