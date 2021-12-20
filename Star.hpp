#ifndef STAR_H
#define STAR_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <string>
#include <math.h>
#include <time.h>

#include "Movement.hpp"

using namespace std;

class Star : public Movement
{
protected:
  double iteration, speed_star, speed_rotation, distance;
  int x, y, radius_star;
  string name;
  sf::Image image;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Shape *shape;

public:
  void CircleMovement() override {}
  void rotateShape() override {}
  Star(int x_val, int y_val, int radius_val, int n_distance, double rotation_val, double speed_val, string n_name)
      : x(x_val), y(y_val), radius_star(radius_val), distance(n_distance), speed_rotation(rotation_val), speed_star(speed_val), name(n_name)
  {
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