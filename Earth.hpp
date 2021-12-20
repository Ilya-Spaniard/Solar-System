#ifndef EARTH_H
#define EARTH_H

#include <string.h>
#include <math.h>

#include "Planet.hpp"

class Earth : public Planet
{
protected:
  string path;
public:
  Earth()
  {
    shape = new sf::CircleShape (radius_planet);
    shape->setOrigin(radius_planet, radius_planet);
  }

  Earth(int x_val = 980, int y_val = 540, int radius_val = 50, int n_distance = 100, double rotation_val = 0.5, double speed_val = 0.5, string n_name = "venus.jpg")
  {
    radius_planet = radius_val;
    speed_rotation = rotation_val;
    distance = n_distance + 170;
    x = x_val;
    y = y_val;
    speed_planet = speed_val;
    name = n_name;
    image.loadFromFile("texture/" + name);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(x_val, y_val);
    shape = new sf::CircleShape(radius_planet);
    shape->setOrigin(radius_planet, radius_planet);
    shape->setTexture(&texture);
  }

  void CircleMovement() override
  {
    if (iteration == 360)
    {
      iteration = 0;
    }
    x = 980 + round(distance * cos(iteration * 3.14 / 180));
    y = 540 + round(distance * sin(iteration * 3.14 / 180));
    iteration += speed_planet;
    shape->setPosition(sf::Vector2f(x, y));
  }

  void rotateShape() override
  {
    shape->rotate(speed_rotation);
  }
};

#endif