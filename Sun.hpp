#ifndef SUN_H
#define SUN_H

#include <string.h>
#include <math.h>

#include "Star.hpp"

class Sun : public Star
{
protected:
  string path;

public:
  Sun(int x_val = 960, int y_val = 540, int radius_val = 170, int n_distance = 1, double rotation_val = 0.001, double speed_val = 0.00001, string n_name = "sun.jpg")
      : Star(x_val, y_val, radius_val, n_distance, rotation_val, speed_val, n_name)
  {
    image.loadFromFile("texture/" + name);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    shape = new sf::CircleShape(radius_star);
    shape->setOrigin(radius_star, radius_star);
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
    iteration += speed_star;
    shape->setPosition(sf::Vector2f(x, y));
  }

  void rotateShape() override
  {
    shape->rotate(speed_rotation);
  }
};

#endif