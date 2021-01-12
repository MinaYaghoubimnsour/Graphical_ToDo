#include <iostream>
#include <SFML/Graphics.hpp>
#include "functions.hpp"
using namespace std;

int main()
{
  //object of class RenderWindow and Event

  sf::RenderWindow window(sf::VideoMode(1402, 789), "To Do");
  sf::Event event;

  // background
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  backgroundTexture.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git2/Graphical_ToDo/background.jpg");
  backgroundSpr.setTexture(backgroundTexture);

  //icon calendar
  sf::Texture calendarTexture;
  sf::Sprite calendarSpr;
  calendarTexture.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git2/Graphical_ToDo/schedule.png");
  calendarSpr.setTexture(calendarTexture);
  calendarSpr.setPosition(sf::Vector2f(10, 0));

  //date and time
  sf::Text timeTxt;
  sf::Font font;
  font.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/git2/Graphical_ToDo/blackjack.otf");
  setTime(timeTxt, font, calendarSpr);
  //a part for add a task
  sf::Text addTxt;
  partOfAddText(window, addTxt, font);
  
  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::EventType::Closed)
      {
        window.close();
      }
    }
    window.draw(backgroundSpr); // draw picture of background
    window.draw(calendarSpr);   // draw calendar icon
    window.draw(timeTxt);       // draw date and time
    window.draw(addTxt);        //draw +add task at end of the window
    window.display();           // display window
  }
  return 0;
}
