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
