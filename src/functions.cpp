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
void manage_window3(sf::RenderWindow & window3, vector<task> & tasks, sf::Font & font, int i)
{
  sf::Texture window3BackgroundTexture;
  sf::Sprite window3BackgroundSprite;
  window3BackgroundTexture.loadFromFile("/home/fn/exercise5_991/Graphical_ToDo/background_window3.jpg");
  window3BackgroundSprite.setTexture(window3BackgroundTexture);
  sf::Event event;
  sf::Text message, yes, no;
  message.setFont(font);
  yes.setFont(font);
  no.setFont(font);
  yes.setCharacterSize(100);
  no.setCharacterSize(100);
  string str = tasks[i].get_task_name();
  message.setString("Are you sure to delete " + str + " task ?");
  yes.setString("YES");
  no.setString("NO");
  message.setFillColor(sf::Color(250, 150, 200));
  yes.setFillColor(sf::Color(250, 150, 200));
  no.setFillColor(sf::Color(250, 150, 200));
  yes.setOrigin(sf::Vector2f(yes.getGlobalBounds().width, 0));
  yes.setPosition(sf::Vector2f(window3.getSize().x/2 - 20 , 250));
  no.setPosition(sf::Vector2f(window3.getSize().x/2 + 20 , 250));

  while(window3.isOpen())
  {
    while(window3.pollEvent(event))
    {
      if(event.type == sf::Event::EventType::Closed)
      {
        window3.close();
      }
      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
         if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window3).x >= no.getPosition().x &&
           sf::Mouse::getPosition(window3).x <= no.getPosition().x + no.getGlobalBounds().width &&
           sf::Mouse::getPosition(window3).y >= no.getPosition().y &&
           sf::Mouse::getPosition(window3).y <= no.getPosition().y + no.getGlobalBounds().height)
         {
           window3.close();
         }
    }
    if (event.type == sf::Event::EventType::MouseButtonPressed)
    {
       if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window3).x >= yes.getPosition().x - yes.getGlobalBounds().width &&
         sf::Mouse::getPosition(window3).x <= yes.getPosition().x &&
         sf::Mouse::getPosition(window3).y >= yes.getPosition().y &&
         sf::Mouse::getPosition(window3).y <= yes.getPosition().y + yes.getGlobalBounds().height)
       {

         window3.close();
         tasks.erase(tasks.begin() + i);
       }
    }
  }
    window3.draw(window3BackgroundSprite);
    window3.draw(message);
    window3.draw(yes);
    window3.draw(no);
    window3.display();
  }
}
