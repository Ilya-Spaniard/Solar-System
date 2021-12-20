#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <string>
#include <math.h>
#include <time.h>

using namespace std;

class Movement
{
public:
    virtual void CircleMovement() {}
    virtual void rotateShape() {}
};

#endif