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

void manage_window3(sf::RenderWindow &window3, vector<task> &tasks, sf::Font &font, int i)
{
  sf::Texture window3BackgroundTexture;
  sf::Sprite window3BackgroundSprite;
  window3BackgroundTexture.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/test/Graphical_ToDo/background2.jpg");
  window3BackgroundSprite.setTexture(window3BackgroundTexture);
  sf::Event event;
  sf::Text message, yes, no;

  message.setFont(font);
  yes.setFont(font);
  no.setFont(font);

  yes.setCharacterSize(40);
  no.setCharacterSize(40);

  string str = tasks[i].get_task_name();
  message.setString("Are you sure to delete below task : \n" + str);
  yes.setString("YES");
  no.setString("NO");

  message.setFillColor(sf::Color::Black);
  yes.setFillColor(sf::Color::Black);
  no.setFillColor(sf::Color::Black);

  yes.setOrigin(sf::Vector2f(yes.getGlobalBounds().width, 0));
  yes.setPosition(sf::Vector2f(window3.getSize().x / 2 - 20, 500));
  no.setPosition(sf::Vector2f(window3.getSize().x / 2 + 20, 500));

  while (window3.isOpen())
  {
    while (window3.pollEvent(event))
    {
      if (event.type == sf::Event::EventType::Closed)
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

void manage_window4(sf::RenderWindow &window4, vector<task> &tasks, sf::Font &font, int i)
{
  sf::Texture window4BackgroundTexture;
  sf::Sprite window4BackgroundSprite;
  window4BackgroundTexture.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/test/Graphical_ToDo/background2.jpg");
  window4BackgroundSprite.setTexture(window4BackgroundTexture);
  sf::Event event;
  sf::Text message, ok, cancel;
  message.setFont(font);
  ok.setFont(font);
  cancel.setFont(font);

  string s = "Please enter new name of task : \n";
  string nameOfTask = "";

  message.setString(s);
  ok.setString("OK");
  cancel.setString("CANCEL");

  ok.setCharacterSize(40);
  cancel.setCharacterSize(40);

  message.setFillColor(sf::Color::Black);
  ok.setFillColor(sf::Color::Black);
  cancel.setFillColor(sf::Color::Black);

  cancel.setOrigin(sf::Vector2f(cancel.getGlobalBounds().width, 0));
  cancel.setPosition(sf::Vector2f(window4.getSize().x / 2 - 20, 500));
  ok.setPosition(sf::Vector2f(window4.getSize().x / 2 + 20, 500));

  while (window4.isOpen())
  {
    while (window4.pollEvent(event))
    {
      // if user click on the close button , window4 will be closed
      if (event.type == sf::Event::EventType::Closed)
      {
        window4.close();
      }
      if (event.type == sf::Event::TextEntered)
      {
        if (event.text.unicode < 128)
        {
          if (event.text.unicode == 8)
          {
            if (nameOfTask.size() != 0)
            {
              s.erase(s.begin() + s.size() - 1);
              nameOfTask.erase(nameOfTask.begin() + nameOfTask.size() - 1);
            }
          }
          else if (nameOfTask.size() <= 40)
          {
            s += static_cast<char>(event.text.unicode);
            nameOfTask += static_cast<char>(event.text.unicode);
          }
          else
          {
            errorWindow("too long name for task!", font);
          }
        }
      }
      // if user click on the ok , task name will be changed and window4 will be closed
      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
        if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window4).x >= ok.getPosition().x &&
            sf::Mouse::getPosition(window4).x <= ok.getPosition().x + ok.getGlobalBounds().width &&
            sf::Mouse::getPosition(window4).y >= ok.getPosition().y &&
            sf::Mouse::getPosition(window4).y <= ok.getPosition().y + ok.getGlobalBounds().height)
        {
          if (nameOfTask.empty())
          {
            errorWindow("task name is empty !", font);
          }
          else
          {
            tasks[i].set_task_name(nameOfTask);
            window4.close();
          }
        }
      }
      // if user click on the cancel , only window4 will be closed
      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
        if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window4).x >= cancel.getPosition().x - cancel.getGlobalBounds().width &&
            sf::Mouse::getPosition(window4).x <= cancel.getPosition().x &&
            sf::Mouse::getPosition(window4).y >= cancel.getPosition().y &&
            sf::Mouse::getPosition(window4).y <= cancel.getPosition().y + cancel.getGlobalBounds().height)
        {
          window4.close();
        }
      }

    } // end of while(window4.pollEvent(event))
    message.setString(s);
    window4.clear();
    window4.draw(window4BackgroundSprite);
    window4.draw(message);
    window4.draw(ok);
    window4.draw(cancel);
    window4.display();

  } // end of while(window4.isOpen())
}
void errorWindow(string error, sf::Font &font)
{
  sf::RenderWindow errorWindow(sf::VideoMode(284, 177), "Error :");
  sf::Event event;

  sf::Texture errorBackground;
  sf::Sprite errorBackgroundSpr;
  errorBackground.loadFromFile("/mnt/c/Users/Parsian.system/Desktop/test/Graphical_ToDo/erroBackground.jpg");
  errorBackgroundSpr.setTexture(errorBackground);

  sf::Text errorMessage, ok;
  errorMessage.setFont(font);
  errorMessage.setString(error);
  errorMessage.setFillColor(sf::Color::Red);
  errorMessage.setOrigin(sf::Vector2f(errorMessage.getGlobalBounds().width / 2, 0));
  errorMessage.setPosition(sf::Vector2f(errorWindow.getSize().x / 2, 30));

  ok.setFont(font);
  ok.setString("OK");
  ok.setFillColor(sf::Color::Red);
  ok.setOrigin(sf::Vector2f(ok.getGlobalBounds().width / 2, 0));
  ok.setPosition(sf::Vector2f(errorWindow.getSize().x / 2, 120));

  while (errorWindow.isOpen())
  {
    while (errorWindow.pollEvent(event))
    {
      if (event.type == sf::Event::EventType::Closed)
      {
        errorWindow.close();
      }
      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
        if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(errorWindow).x >= ok.getPosition().x &&
            sf::Mouse::getPosition(errorWindow).x <= ok.getPosition().x + ok.getGlobalBounds().width &&
            sf::Mouse::getPosition(errorWindow).y >= ok.getPosition().y &&
            sf::Mouse::getPosition(errorWindow).y <= ok.getPosition().y + ok.getGlobalBounds().height)
        {
          errorWindow.close();
        }
      }

    } // end of while(errorWindow.pollEvent(event))
    errorWindow.draw(errorBackgroundSpr);
    errorWindow.draw(errorMessage);
    errorWindow.draw(ok);
    errorWindow.display();
  } // end of while(errorWindow.isOpen())
}

void ReadFromFile(ifstream &file, vector<task> &tasks, vector<sf::Text> &taskName, sf::Font &font, vector<sf::RectangleShape> &rect)
{
  file.seekg(0, ios::beg);
  int i = 0;
  task temp("");
  file.tellg();
  file.seekg(0 * sizeof(task), ios::beg);
  file.tellg();
  file.read(reinterpret_cast<char *>(&temp), sizeof(task));
  cout << "matn task -> " << temp.get_task_name() << endl;
  cout << "_______________________" << endl;
  while (!file.eof())
  {
    if (file.eof())
    {
      file.tellg();
      file.clear();
      break;
    }
    ++i;
    file.tellg();
    file.seekg(i * sizeof(task), ios::beg);
    file.tellg();
    tasks.push_back(temp);
    sf::Text taskName1;
    taskName1.setFont(font);
    taskName1.setString(tasks[tasks.size() - 1].get_task_name());
    taskName1.setFillColor(sf::Color::Black);
    taskName.push_back(taskName1);
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(1402, 4));
    rect.push_back(rectangle);
    if (file.eof())
    {
      file.tellg();
      file.clear();
      break;
    }
    file.read(reinterpret_cast<char *>(&temp), sizeof(task));
    if (!file.good())
      break;
    cout << "matn task -> " << temp.get_task_name() << endl;
    cout << "_______________________" << endl;
  }
  file.clear();
}

void writeInFile(ofstream &file, vector<task> &tasks)
{
  file.seekp(0, ios::beg);
  int size = 0;
  while (size < tasks.size())
  {
    file.seekp(size * sizeof(task), ios::beg);
    file.write((char *)&tasks[size], sizeof(tasks[size]));
    ++size;
    fflush;
  }
  file.clear();
}
