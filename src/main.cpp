#include <iostream>
#include <chrono>
#include <ctime>
#include "functions.hpp"
#include "task.hpp"
using namespace std;
// struct shape
// {
//   sf::Texture circleTxt;
//   sf::Sprite circleSpr;
// };

int main()
{
  //*******************************
  vector<task> tasks;
  vector<sf::RectangleShape> rect;
  vector<sf::Text> taskName;
  vector<sf::Texture> circleTexture;
  vector<sf::Sprite> circleSprite;
  //object of class RenderWindow and Event

  sf::RenderWindow window(sf::VideoMode(1402, 789), "To Do");
  sf::Event event;

  // background
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  backgroundTexture.loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/background.jpg");
  backgroundSpr.setTexture(backgroundTexture);
  //icon calendar

  sf::Texture calendarTexture;
  sf::Sprite calendarSpr;
  calendarTexture.loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/schedule.png");
  calendarSpr.setTexture(calendarTexture);
  calendarSpr.setPosition(sf::Vector2f(10, 0));

  //date and time

  sf::Text timeTxt;
  sf::Font font;
  font.loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/blackjack.otf");
  setTime(timeTxt, font, calendarSpr);

  //A line after date and time
  sf::RectangleShape line;
  setFirstLine(window, line, calendarSpr);
  //a part for add a task
  sf::Text addTxt;
  partOfAddText(window, addTxt, font);
  // print name of task
  sf::Text nameTxt;
  sf::Font nameFont;
  nameFont.loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/blackjack.otf");
  nameTxt.setFont(nameFont);
  nameTxt.setFillColor(sf::Color::Black);

  // fillTaskNameAndRectVectors(window, font, tasks, taskName, rect);

  string s, nameOfTask = "";

  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::EventType::Closed)
      {
        window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed)
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
          window2Font.loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/blackjack.otf");
          sf::Text textMessage;
          textMessage.setFillColor(sf::Color::White);
          textMessage.setFont(window2Font);
          s = "Please enter name of task : \n";
          textMessage.setString(s);
          while (window2.isOpen())
          {
            sf::Event event2;
            sf::Sprite okSprite;
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
            window2.display();
          }
          task task1(nameOfTask);
          tasks.push_back(task1);
          sf::Text taskName1;
          taskName1.setFont(font);
          taskName1.setString(nameOfTask);
          taskName.push_back(taskName1);
          sf::RectangleShape rectangle;
          rectangle.setFillColor(sf::Color::Black);
          rectangle.setSize(sf::Vector2f(window.getSize().x, 4));
          rect.push_back(rectangle);
        }
      }
      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
        for (size_t i = 0; i < tasks.size(); i++)
        {
          if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window).x >= tasks[i].get_circleSprite().getPosition().x &&
              sf::Mouse::getPosition(window).x <= tasks[i].get_circleSprite().getPosition().x + tasks[i].get_circleSprite().getGlobalBounds().width &&
              sf::Mouse::getPosition(window).y >= tasks[i].get_circleSprite().getPosition().y &&
              sf::Mouse::getPosition(window).y <= tasks[i].get_circleSprite().getPosition().y + tasks[i].get_circleSprite().getGlobalBounds().height)
          {
            // cout << "i ->" << i << endl;
            tasks[i].set_isCompleted(!tasks[i].get_isCompleted());
          }
        }
      }
      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
        for (size_t i = 0; i < tasks.size(); i++)
        {
          if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window).x >= tasks[i].get_trashSprite().getPosition().x &&
              sf::Mouse::getPosition(window).x <= tasks[i].get_trashSprite().getPosition().x + tasks[i].get_trashSprite().getGlobalBounds().width &&
              sf::Mouse::getPosition(window).y >= tasks[i].get_trashSprite().getPosition().y &&
              sf::Mouse::getPosition(window).y <= tasks[i].get_trashSprite().getPosition().y + tasks[i].get_trashSprite().getGlobalBounds().height)
          {
            sf::RenderWindow window3(sf::VideoMode(1402, 500), "confirm to delete task");
            manage_window3(window3, tasks, font, i);
          }
        }
      }
      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
        for (size_t i = 0; i < tasks.size(); i++)
        {
          if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window).x >= tasks[i].get_starSprite().getPosition().x &&
              sf::Mouse::getPosition(window).x <= tasks[i].get_starSprite().getPosition().x + tasks[i].get_starSprite().getGlobalBounds().width &&
              sf::Mouse::getPosition(window).y >= tasks[i].get_starSprite().getPosition().y &&
              sf::Mouse::getPosition(window).y <= tasks[i].get_starSprite().getPosition().y + tasks[i].get_starSprite().getGlobalBounds().height)
          {
            tasks[i].set_favorite(!tasks[i].get_favorite());
          }
        }
      }
    }
    window.clear();
    window.draw(backgroundSpr); // draw picture of background
    window.draw(calendarSpr);   // draw calendar icon
    window.draw(timeTxt);       // draw date and time
    window.draw(addTxt);        // draw + add a task
    // circle icon of every task that shows complete or incomplete
    for (size_t i = 0; i < tasks.size(); i++)
    {
      if (tasks[i].get_isCompleted())
      {
        tasks[i].get_circleTexture().loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/checkmark.png");
      }
      else
      {
        tasks[i].get_circleTexture().loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/circle.png");
      }
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].get_circleSprite().setTexture(tasks[i].get_circleTexture());
    }
    // trash icon
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].get_trashTexture().loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/trash.png");
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].get_trashSprite().setTexture(tasks[i].get_trashTexture());
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].loadStarTexture();
    }
    for (size_t i = 0; i < tasks.size(); i++) {
      tasks[i].setTextureStarSpr();
    }
    if (!tasks.empty())
    {
      tasks[0].get_circleSprite().setPosition(sf::Vector2f(10, line.getPosition().y + 10));
      tasks[0].get_trashSprite().setPosition(sf::Vector2f(window.getSize().x - 50, line.getPosition().y + 10));
      tasks[0].setPositionStarSpr(window.getSize().x - 65 - tasks[0].get_trashSprite(). getGlobalBounds(). width,
        line.getPosition().y + 10);
      taskName[0].setString(tasks[0].get_task_name());
      taskName[0].setPosition(sf::Vector2f(70, line.getPosition().y + 10));
      rect[0].setPosition(sf::Vector2f(0, taskName[0].getPosition().y + 60));
      window.draw(taskName[0]);
      window.draw(tasks[0].get_circleSprite());
      window.draw(tasks[0].get_trashSprite());
      window.draw(tasks[0].get_starSprite());
      window.draw(rect[0]);
    }
    for (size_t i = 1; i < tasks.size(); i++)
    {
      tasks[i].get_trashSprite().setPosition(sf::Vector2f(window.getSize().x - 50,  rect[i - 1].getPosition().y + 10));
      tasks[i].get_circleSprite().setPosition(sf::Vector2f(10, rect[i - 1].getPosition().y + 10));
      tasks[i].setPositionStarSpr(window.getSize().x - 65 - tasks[i].get_trashSprite(). getGlobalBounds(). width,
        rect[i - 1].getPosition().y + 10);
      taskName[i].setString(tasks[i].get_task_name());
      taskName[i].setPosition(sf::Vector2f(70, rect[i - 1].getPosition().y + 10));
      rect[i].setPosition(sf::Vector2f(0, taskName[i].getPosition().y + 60));
      window.draw(taskName[i]);
      window.draw(tasks[i].get_circleSprite());
      window.draw(tasks[i].get_trashSprite());
      window.draw(tasks[i].get_starSprite());
      window.draw(rect[i]);
    }
    window.display(); // display window
  }
  return 0;
}
