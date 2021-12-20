#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <string.h>
#include <time.h>

#include "Movement.hpp"
#include "Planet.hpp"
#include "Star.hpp"
#include "Sun.hpp"
#include "Mercury.hpp"
#include "Venus.hpp"
#include "Earth.hpp"
#include "Mars.hpp"
#include "Jupiter.hpp"
#include "Saturn.hpp"
#include "Uranium.hpp"
#include "Neptune.hpp"

int main()
{
	srand(time(NULL));

	Star **shape = new Star *[1];
	shape[0] = new Sun();

	Planet **shapes = new Planet *[8];
	shapes[0] = new Mercury(960, 540, 12, 80, 0.1, 0.09, "mercury.jpg");
	shapes[1] = new Venus(960, 540, 20, 130, 0.2, 0.08, "venus.jpg");
	shapes[2] = new Earth(960, 540, 35, 200, 0.3, 0.07, "earth.jpg");
	shapes[3] = new Mars(960, 540, 28, 270, 0.4, 0.06, "mars.jpg");
	shapes[4] = new Jupiter(960, 540, 65, 400, 0.5, 0.05, "jupiter.jpg");
	shapes[5] = new Saturn(960, 540, 58, 530, 0.6, 0.04, "saturn.jpg");
	shapes[6] = new Uranium(960, 540, 48, 670, 0.7, 0.03, "uranium.jpg");
	shapes[7] = new Neptune(960, 540, 42, 770, 0.8, 0.02, "neptune.jpg");

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Planet");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color(1, 0, 45));

		for (int i = 0; i < 1; i++)
		{
			shape[i]->CircleMovement();
			shape[i]->rotateShape();
			window.draw(*shape[i]->getDrawable());
		}

		for (int i = 0; i < 8; i++)
		{
			shapes[i]->CircleMovement();
			shapes[i]->rotateShape();
			window.draw(*shapes[i]->getDrawable());
		}
		window.display();
	}
	return 0;
}