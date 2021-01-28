#include "functions.hpp"
using namespace std;
void setTime(sf::Text &timeTxt, sf::Font &timeFont, sf::Sprite &calendarSpr)
{
  time_t timetoday;
  time(&timetoday);
  // string str contains current date and time
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

// if user clicks on "add a task" text , this function will be called
void manage_window2(sf::RenderWindow & window, sf::RenderWindow & window2, std::vector<task> & tasks, sf::Font & font, vector<sf::Text> & taskName, vector<sf::RectangleShape> & rect)
{
  // string s contains all text that we can see in window2
  string s = "";

  // string nameOfTask only contains name of task
  // that we want to set for an object of task class
  string nameOfTask = "";

  // background of window2
  sf::Texture background_window2;
  sf::Sprite background_window2_Sprite;
  background_window2.loadFromFile("../images/background2.jpg");
  background_window2_Sprite.setTexture(background_window2);

  // textMessage text contains "Please enter name of task : \n" and name of task
  sf::Text textMessage, ok, cancel;

  // set color of "textMessage" , "ok" and "cancel" text
  textMessage.setFillColor(sf::Color::Black);
  ok.setFillColor(sf::Color::Black);
  cancel.setFillColor(sf::Color::Black);

  // set size of "ok" and "cancel" text (size of "textMessage" default)
  ok.setCharacterSize(40);
  cancel.setCharacterSize(40);

  // set font of our three text
  textMessage.setFont(font);
  ok.setFont(font);
  cancel.setFont(font);

  s = "Please enter name of task : \n";

  // set string of our three text
  textMessage.setString(s);
  ok.setString("OK");
  cancel.setString("CANCEL");

  // set origin of "cancel" text (origin of "ok" text default)
  cancel.setOrigin(sf::Vector2f(cancel.getGlobalBounds().width, 0));

  // set position of "ok" and "cancel" text (position of "textMessage" default)
  cancel.setPosition(sf::Vector2f(window2.getSize().x / 2 - 20, 500));
  ok.setPosition(sf::Vector2f(window2.getSize().x / 2 + 20, 500));

  bool isOk = false;
  //while user dose not click on the close button, OK
  // or CANCEL , window2 is open
  while (window2.isOpen())
  {
    sf::Event event2;

    while (window2.pollEvent(event2))
    {
      isOk = false;
      // if user clicks on the close button, window2 will be closed
      if (event2.type == sf::Event::Closed)
      {
        window2.close();
        isOk = false;
      }
      if (event2.type == sf::Event::TextEntered)// for get input
      {
        if (event2.text.unicode < 128)
        {
          // if user enters backspace key
          if (event2.text.unicode == 8)
          {
            if (nameOfTask.size() != 0)
            {
              s.erase(s.begin() + s.size() - 1);
              nameOfTask.erase(nameOfTask.begin() + nameOfTask.size() - 1);
            }
          } //end of if (event2.text.unicode == 8)
          else if (nameOfTask.size() <= 40)
          {
            s += static_cast<char>(event2.text.unicode);
            nameOfTask += static_cast<char>(event2.text.unicode);
          }
          else // if size of nameOfTask greater than 40
          {
            errorWindow("too long name for task!", font);
          }
        } // end of if (event2.text.unicode < 128)
      } //end of if (event2.type == sf::Event::TextEntered)

      // if user clicks on the OK , task name will be set and window2 will be closed
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

      // if user clicks on the CANCEL , just window2 will be closed
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
    } // end of while (window2.pollEvent(event2))
    textMessage.setString(s);
    window2.clear();
    window2.draw(background_window2_Sprite);
    window2.draw(textMessage);
    window2.draw(ok);
    window2.draw(cancel);
    window2.display();
  } // end of while(window2.isOpen())

  if (isOk == true) // if user clicks on OK
  {
  if (nameOfTask.empty()) // if nameOfTask is an empty string
  {
  errorWindow("task name is empty!", font);
  }
  else // if nameOfTask is not empty
  {
    task task1(nameOfTask);//an object of task for push_back in the tasks vector
    tasks.push_back(task1);
    sf::Text taskName1;//an object of Text for push_back in the taskName vector
    taskName1.setFont(font);
    taskName1.setString(nameOfTask);
    taskName1.setFillColor(sf::Color::Black);
    taskName.push_back(taskName1);
    sf::RectangleShape rectangle;//an object of RectangleShape for push_back in the rect vector
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(window.getSize().x, 4));
    rect.push_back(rectangle);
  } // end of else
} // end of if (isOk == true)
} // end of function manage_window2
void manage_window3(sf::RenderWindow &window3, vector<task> &tasks, sf::Font &font, int i)
{
  // background od window3
  sf::Texture window3BackgroundTexture;
  sf::Sprite window3BackgroundSprite;
  window3BackgroundTexture.loadFromFile("../images/background2.jpg");
  window3BackgroundSprite.setTexture(window3BackgroundTexture);
  sf::Event event;
  sf::Text message, yes, no;

  // set font of "message", "yes" and "no" Text
  message.setFont(font);
  yes.setFont(font);
  no.setFont(font);

  // set size of "yes" and "no" Text(size of "message" default)
  yes.setCharacterSize(40);
  no.setCharacterSize(40);

  // set string of "message", "yes" and "no" Text
  string str = tasks[i].get_task_name();
  message.setString("Are you sure to delete below task : \n" + str);
  yes.setString("YES");
  no.setString("NO");

  // set color of "message", "yes" and "no" Text
  message.setFillColor(sf::Color::Black);
  yes.setFillColor(sf::Color::Black);
  no.setFillColor(sf::Color::Black);

  yes.setOrigin(sf::Vector2f(yes.getGlobalBounds().width, 0));
  // set position of "yes" and "no" Text("message" default)
  yes.setPosition(sf::Vector2f(window3.getSize().x / 2 - 20, 500));
  no.setPosition(sf::Vector2f(window3.getSize().x / 2 + 20, 500));

  //while user dose not click on the close button, YES
  // or NO , window3 is open
  while (window3.isOpen())
  {
    while (window3.pollEvent(event))
    {
      // if user clicks on the close button, window3 will be closed
      if (event.type == sf::Event::EventType::Closed)
      {
        window3.close();
      }
      // if user clicks on "NO", window3 will be closed
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
      // if user clicks on "YES", task will be deleted and window3 will be closed
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
    } // end of while(window3.pollEvent(event))
    window3.draw(window3BackgroundSprite);
    window3.draw(message);
    window3.draw(yes);
    window3.draw(no);
    window3.display();
  } // end of while(window3.isOpen())
} // end of manage_window3 function

void manage_window4(sf::RenderWindow &window4, vector<task> &tasks, sf::Font &font, int i)
{
  // background of window4
  sf::Texture window4BackgroundTexture;
  sf::Sprite window4BackgroundSprite;
  window4BackgroundTexture.loadFromFile("../images/background2.jpg");
  window4BackgroundSprite.setTexture(window4BackgroundTexture);

  sf::Event event;
  sf::Text message, ok, cancel;
  // set font of "message", "ok" and "cancel" Text
  message.setFont(font);
  ok.setFont(font);
  cancel.setFont(font);

  string s = "Please enter new name of task : \n";
  string nameOfTask = "";

  // set string of "message", "ok" and "cancel" Text
  message.setString(s);
  ok.setString("OK");
  cancel.setString("CANCEL");

  // set size of "ok" and "cancel" Text(size of "message" default)
  ok.setCharacterSize(40);
  cancel.setCharacterSize(40);

  // set color of our three Text
  message.setFillColor(sf::Color::Black);
  ok.setFillColor(sf::Color::Black);
  cancel.setFillColor(sf::Color::Black);

  cancel.setOrigin(sf::Vector2f(cancel.getGlobalBounds().width, 0));
  // set position of "ok" and "cancel"
  cancel.setPosition(sf::Vector2f(window4.getSize().x / 2 - 20, 500));
  ok.setPosition(sf::Vector2f(window4.getSize().x / 2 + 20, 500));

  //while user dose not click on the close button, OK
  // or CANCEL , window4 is open
  while (window4.isOpen())
  {
    while (window4.pollEvent(event))
    {
      // if user clicks on the close button , window4 will be closed
      if (event.type == sf::Event::EventType::Closed)
      {
        window4.close();
      }
      if (event.type == sf::Event::TextEntered)// for  get input
      {
        if (event.text.unicode < 128)
        {
          // if user enters backspace key
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
          else // if size of nameOfTask greater than 40
          {
            errorWindow("too long name for task!", font);
          }
        }
      } // end of if (event.type == sf::Event::TextEntered)

      // if user clicks on the ok , task name will be changed and window4 will be closed
      if (event.type == sf::Event::EventType::MouseButtonPressed)
      {
        if (event.key.code == sf::Mouse::Left && sf::Mouse::getPosition(window4).x >= ok.getPosition().x &&
            sf::Mouse::getPosition(window4).x <= ok.getPosition().x + ok.getGlobalBounds().width &&
            sf::Mouse::getPosition(window4).y >= ok.getPosition().y &&
            sf::Mouse::getPosition(window4).y <= ok.getPosition().y + ok.getGlobalBounds().height)
        {
          // if nameOfTask string be empty
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

      // if user clicks on the CANCEL , only window4 will be closed
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

  // background of errorWindow
  sf::Texture errorBackground;
  sf::Sprite errorBackgroundSpr;
  errorBackground.loadFromFile("../images/erroBackground.jpg");
  errorBackgroundSpr.setTexture(errorBackground);

  sf::Text errorMessage, ok;

  // set font, string, color, origin and position of errorMessage Text
  errorMessage.setFont(font);
  errorMessage.setString(error);
  errorMessage.setFillColor(sf::Color::Red);
  errorMessage.setOrigin(sf::Vector2f(errorMessage.getGlobalBounds().width / 2, 0));
  errorMessage.setPosition(sf::Vector2f(errorWindow.getSize().x / 2, 30));

  //set font, string, color, origin and position of ok Text
  ok.setFont(font);
  ok.setString("OK");
  ok.setFillColor(sf::Color::Red);
  ok.setOrigin(sf::Vector2f(ok.getGlobalBounds().width / 2, 0));
  ok.setPosition(sf::Vector2f(errorWindow.getSize().x / 2, 120));

  //while user dose not click on the close button
  // or OK , errorWindow is open
  while (errorWindow.isOpen())
  {
    while (errorWindow.pollEvent(event))
    {
      // if user clicks on the close button, errorWindow will be closed
      if (event.type == sf::Event::EventType::Closed)
      {
        errorWindow.close();
      }

      // if user clicks on the OK, errorWindow will be closed
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
}// end of errorWindow function

void ReadFromFile(ifstream &file, vector<task> &tasks, vector<sf::Text> &taskName, sf::Font &font, vector<sf::RectangleShape> &rect)
{
  file.seekg(0, ios::beg);
  int i = 0;
  task temp("");// an object of task class for push_back to tasks vector
  file.tellg();
  file.seekg(0 * sizeof(task), ios::beg);
  file.tellg();
  // read first record from file.txt
  file.read(reinterpret_cast<char *>(&temp), sizeof(task));
  cout << "matn task -> " << temp.get_task_name() << endl;
  cout << "_______________________" << endl;
  // read other records from file.txt
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
    // push_back last readed record to tasks vector
    tasks.push_back(temp);
    // an object of Text for push_back to taskName vector
    sf::Text taskName1;
    taskName1.setFont(font);
    taskName1.setString(tasks[tasks.size() - 1].get_task_name());
    taskName1.setFillColor(sf::Color::Black);
    taskName.push_back(taskName1);
    // an object of RectangleShape for push_back to rect vector
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
    // read all records except of first record
    file.read(reinterpret_cast<char *>(&temp), sizeof(task));
    if (!file.good())
      break;
    cout << "matn task -> " << temp.get_task_name() << endl;
    cout << "_______________________" << endl;
  }
  file.clear();
} // end of ReadFromFile function

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
} // end of writeInFile function
