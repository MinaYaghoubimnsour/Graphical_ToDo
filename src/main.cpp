#include <iostream>
#include <chrono>
#include <ctime>
#include "functions.hpp"
#include "task.hpp"
using namespace std;

int main()
{ //font
  sf::Font font;
  font.loadFromFile("../images/blackjack.otf");
  //-----------------
  vector<task> tasks;
  vector<sf::Text> taskName;
  vector<sf::RectangleShape> rect;
  //call ReadFromFile for reading information from file
  ifstream file("../other_files/file.txt", ios::in);
  ReadFromFile(file, tasks, taskName, font, rect);
  file.close();
  //*******************************
  //object of class RenderWindow and Event
  sf::RenderWindow window(sf::VideoMode(1402, 789), "To Do");
  sf::Event event;

  // background
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  backgroundTexture.loadFromFile("../images/background.jpg");
  backgroundSpr.setTexture(backgroundTexture);
  //icon calendar

  sf::Texture calendarTexture;
  sf::Sprite calendarSpr;
  calendarTexture.loadFromFile("../images/schedule.png");
  calendarSpr.setTexture(calendarTexture);
  calendarSpr.setPosition(sf::Vector2f(10, 0));

  //date and time

  sf::Text timeTxt;
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
  nameFont.loadFromFile("../font/blackjack.otf");
  nameTxt.setFont(nameFont);
  nameTxt.setFillColor(sf::Color::Black);

  // fstream file;
  // readFromFile(file, tasks);
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
          sf::RenderWindow window2(sf::VideoMode(1150, 647), "Add Task : ", sf::Style::Titlebar | sf::Style::Close);
          sf::Texture background_window2;
          sf::Sprite background_window2_Sprite;
          background_window2.loadFromFile("../images/background2.jpg");
          background_window2_Sprite.setTexture(background_window2);

          sf::Text textMessage, ok, cancel;
          textMessage.setFillColor(sf::Color::Black);
          ok.setFillColor(sf::Color::Black);
          cancel.setFillColor(sf::Color::Black);

          ok.setCharacterSize(40);
          cancel.setCharacterSize(40);

          textMessage.setFont(font);
          ok.setFont(font);
          cancel.setFont(font);

          s = "Please enter name of task : \n";

          textMessage.setString(s);
          ok.setString("OK");
          cancel.setString("CANCEL");

          cancel.setOrigin(sf::Vector2f(cancel.getGlobalBounds().width, 0));
          cancel.setPosition(sf::Vector2f(window2.getSize().x / 2 - 20, 500));
          ok.setPosition(sf::Vector2f(window2.getSize().x / 2 + 20, 500));

          bool isOk = false;
          while (window2.isOpen())
          {
            sf::Event event2;

            while (window2.pollEvent(event2))
            {
              isOk = false;
              if (event2.type == sf::Event::Closed)
              {
                window2.close();
                isOk = false;
              }
              if (event2.type == sf::Event::TextEntered)
              {
                if (event2.text.unicode < 128)
                {
                  if (event2.text.unicode == 8)
                  {
                    if (nameOfTask.size() != 0)
                    {
                      s.erase(s.begin() + s.size() - 1);
                      nameOfTask.erase(nameOfTask.begin() + nameOfTask.size() - 1);
                    }
                  }
                  else if (nameOfTask.size() <= 40)
                  {
                    s += static_cast<char>(event2.text.unicode);
                    nameOfTask += static_cast<char>(event2.text.unicode);
                  }
                  else
                  {
                    errorWindow("too long name for task!", font);
                  }
                }
              }
              // if user click on the ok , task name will be changed and window4 will be closed
              if (event2.type == sf::Event::EventType::MouseButtonPressed)
              {
                if (event2.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window2).x >= ok.getPosition().x &&
                    sf::Mouse::getPosition(window2).x <= ok.getPosition().x + ok.getGlobalBounds().width &&
                    sf::Mouse::getPosition(window2).y >= ok.getPosition().y &&
                    sf::Mouse::getPosition(window2).y <= ok.getPosition().y + ok.getGlobalBounds().height)
                {
                  isOk = true;
                  window2.close();
                }
              }
              // if user click on the cancel , only window2 will be closed
              if (event2.type == sf::Event::EventType::MouseButtonPressed)
              {
                if (event2.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window2).x >= cancel.getPosition().x - cancel.getGlobalBounds().width &&
                    sf::Mouse::getPosition(window2).x <= cancel.getPosition().x &&
                    sf::Mouse::getPosition(window2).y >= cancel.getPosition().y &&
                    sf::Mouse::getPosition(window2).y <= cancel.getPosition().y + cancel.getGlobalBounds().height)
                {
                  isOk = false;
                  window2.close();
                }
              }
            }
            textMessage.setString(s);
            window2.clear();
            window2.draw(background_window2_Sprite);
            window2.draw(textMessage);
            window2.draw(ok);
            window2.draw(cancel);
            window2.display();
          }
          if (isOk == true)
          {
            if (nameOfTask.empty())
            {
              errorWindow("task name is empty!", font);
            }
            else
            {
              task task1(nameOfTask);
              tasks.push_back(task1);
              sf::Text taskName1;
              taskName1.setFont(font);
              taskName1.setString(nameOfTask);
              taskName1.setFillColor(sf::Color::Black);
              taskName.push_back(taskName1);
              sf::RectangleShape rectangle;
              rectangle.setFillColor(sf::Color::Black);
              rectangle.setSize(sf::Vector2f(window.getSize().x, 4));
              rect.push_back(rectangle);
            }
          }
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
            sf::RenderWindow window3(sf::VideoMode(1150, 647), "confirm to delete task");
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

      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
        for (size_t i = 0; i < tasks.size(); i++)
        {
          if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window).x >= tasks[i].get_PencilSprite().getPosition().x &&
              sf::Mouse::getPosition(window).x <= tasks[i].get_PencilSprite().getPosition().x + tasks[i].get_PencilSprite().getGlobalBounds().width &&
              sf::Mouse::getPosition(window).y >= tasks[i].get_PencilSprite().getPosition().y &&
              sf::Mouse::getPosition(window).y <= tasks[i].get_PencilSprite().getPosition().y + tasks[i].get_PencilSprite().getGlobalBounds().height)
          {
            sf::RenderWindow window4(sf::VideoMode(1150, 647), "Edit task : ");
            manage_window4(window4, tasks, font, i);
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
      tasks[i].loadCircleTexture();
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].setTextureCircleSpr();
    }
    // trash icon
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].loadTrashTexture();
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].setTextureTrashSpr();
    }
    // star icon of every task that shows task is favorite  or not.
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].loadStarTexture();
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].setTextureStarSpr();
    }
    // pencil icon
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].loadPencilTexture();
    }
    for (size_t i = 0; i < tasks.size(); i++)
    {
      tasks[i].setTexturePencilSpr();
    }

    if (!tasks.empty())
    {
      taskName[0].setString(tasks[0].get_task_name());
      taskName[0].setPosition(sf::Vector2f(70, line.getPosition().y + 10));
      rect[0].setPosition(sf::Vector2f(0, taskName[0].getPosition().y + 60));
      tasks[0].setPositionCircleSpr(10, line.getPosition().y + 10);
      tasks[0].setPositionTrashSpr(window.getSize().x - 50, line.getPosition().y + 10);
      tasks[0].setPositionStarSpr(window.getSize().x - 70 - tasks[0].get_PencilSprite().getGlobalBounds().width - tasks[0].get_trashSprite().getGlobalBounds().width, line.getPosition().y + 10);
      tasks[0].setPositionPencilSpr(window.getSize().x - 65 - tasks[0].get_trashSprite().getGlobalBounds().width,
                                    line.getPosition().y + 10);
      window.draw(taskName[0]);
      window.draw(tasks[0].get_circleSprite());
      window.draw(tasks[0].get_trashSprite());
      window.draw(tasks[0].get_starSprite());
      window.draw(tasks[0].get_PencilSprite());
      window.draw(rect[0]);
    }
    for (size_t i = 1; i < tasks.size(); i++)
    {
      taskName[i].setString(tasks[i].get_task_name());
      taskName[i].setPosition(sf::Vector2f(70, rect[i - 1].getPosition().y + 10));
      rect[i].setPosition(sf::Vector2f(0, taskName[i].getPosition().y + 60));
      tasks[i].setPositionCircleSpr(10, rect[i - 1].getPosition().y + 10);
      tasks[i].setPositionTrashSpr(window.getSize().x - 50, rect[i - 1].getPosition().y + 10);
      tasks[i].setPositionStarSpr(window.getSize().x - 70 - tasks[i].get_PencilSprite().getGlobalBounds().width - tasks[i].get_trashSprite().getGlobalBounds().width, rect[i - 1].getPosition().y + 10);
      tasks[i].setPositionPencilSpr(window.getSize().x - 65 - tasks[i].get_trashSprite().getGlobalBounds().width,
                                    rect[i - 1].getPosition().y + 10);
      window.draw(taskName[i]);
      window.draw(tasks[i].get_circleSprite());
      window.draw(tasks[i].get_trashSprite());
      window.draw(tasks[i].get_starSprite());
      window.draw(tasks[i].get_PencilSprite());
      window.draw(rect[i]);
    }
    window.display(); // display window
  }
  remove("../other_filese/file.txt");
  ofstream file2("../other_filese/file.txt", ios::out);
  writeInFile(file2, tasks);
  file2.clear();
  file2.close();
  return 0;
}
