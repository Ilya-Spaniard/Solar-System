#ifndef PLANET_H
#define PLANET_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <string>
#include <math.h>
#include <time.h>

#include "Movement.hpp"

using namespace std;

class Planet : public Movement
{
protected:
  double iteration, speed_planet, speed_rotation;
  int x, y, radius_planet, distance;
  string name;
  sf::Image image;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Shape *shape;

  inline void initialization()
  {
    x = rand() % 1500;
    y = rand() % 1500;
    speed_planet = 0;
  }

public:
  void CircleMovement() override {}
  void rotateShape() override {}
  Planet()
  {
    initialization();
    shape = new sf::CircleShape(0);
  }

  int getX()
  {
    return x;
  }
  int getY()
  {
    return y;
  }
  void setX(int value)
  {
    x = value;
  }
  void setY(int value)
  {
    y = value;
  }

  void Position()
  {
    x = 0;
    y = 0;
  }

  sf::Drawable *getDrawable()
  {
    shape->setPosition(x, y);
    return shape;
  }
};

#endif