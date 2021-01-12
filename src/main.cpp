#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
  //object of class RenderWindow and Event

  sf::RenderWindow window(sf::VideoMode(605, 800), "To Do");
  sf::Event event;

  // background
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  backgroundTexture.loadFromFile("/home/fn/exercise5_991/background.jpg");
  backgroundSpr.setTexture(backgroundTexture);
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
    window.display(); // display window
  }
  return 0;
}
