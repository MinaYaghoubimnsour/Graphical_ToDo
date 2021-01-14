#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "functions.hpp"
#include "task.hpp"
using namespace std;

int main()
{
  
  //object of class RenderWindow and Event

  sf::RenderWindow window(sf::VideoMode(1402, 789), "To Do");
  sf::Event event;

  // background
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  backgroundTexture.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/background.jpg");
  backgroundSpr.setTexture(backgroundTexture);

  //icon calendar
  sf::Texture calendarTexture;
  sf::Sprite calendarSpr;
  calendarTexture.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/schedule.png");
  calendarSpr.setTexture(calendarTexture);
  calendarSpr.setPosition(sf::Vector2f(10, 0));

  //date and time
  sf::Text timeTxt;
  sf::Font font;
  font.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/blackjack.otf");
  setTime(timeTxt, font, calendarSpr);
  //a part for add a task
  sf::Text addTxt;
  partOfAddText(window, addTxt, font);

   vector <task> tasks;
   string s,nameOfTask;
  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::EventType::Closed)
      {
        window.close();
      }
if (event.type == sf::Event::MouseButtonReleased)
      {
        if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window).x >= addTxt.getPosition().x &&
            sf::Mouse::getPosition(window).x <= addTxt.getPosition().x + addTxt.getGlobalBounds().width &&
            sf::Mouse::getPosition(window).y >= addTxt.getPosition().y &&
            sf::Mouse::getPosition(window).y <= addTxt.getPosition().y + addTxt.getGlobalBounds().height)
        {
          s = "";
          nameOfTask = "";
          sf::RenderWindow window2(sf::VideoMode(600, 100), "Add Task : ", sf::Style::Titlebar | sf::Style::Close);
          sf::Font window2Font;
          window2Font.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/blackjack.otf");
          sf::Text textMessage;
          textMessage.setFillColor(sf::Color::White);
          textMessage.setFont(window2Font);
          s = "Please enter name of task : \n";
          textMessage.setString(s);
          while (window2.isOpen())
          {
            sf::Event event2;
            sf::Texture ok;
            ok.loadFromFile("/home/yasaman/Desktop/AP/todo_graphical/Graphical_ToDo/ok.png");
            sf::Sprite okSprite;
            okSprite.setTexture(ok);
            okSprite.setOrigin(sf::Vector2f(okSprite.getGlobalBounds().width, okSprite.getGlobalBounds().height));
            okSprite.setPosition(sf::Vector2f(window2.getSize().x, window2.getSize().y));
            while (window2.pollEvent(event2))
            {
              if (event2.type == sf::Event::Closed)
              {
                window2.close();
              }
              if (event2.type == sf::Event::TextEntered)
              {
                if (event2.text.unicode < 128)
                {
                  s += static_cast<char>(event2.text.unicode);
                  nameOfTask += static_cast<char>(event2.text.unicode);
                }
              }
            }
textMessage.setString(s);
            window2.clear(sf::Color::Black);
            window2.draw(textMessage);
            window2.draw(okSprite);
            window2.display();

          }
 task task1(nameOfTask);
          tasks.push_back(task1);
         
        }
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
