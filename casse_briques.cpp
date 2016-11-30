// casse_briques.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shapes.h"


int main()
{
	double radius;
	double x;
	double y;
	double width;
	double heigth;
	

	sf::RenderWindow window(sf::VideoMode(500,500),"TEST");
	
	Circle* circle = new Circle(50, 400, 0);
	Rectangle* rectangle = new Rectangle(100, 100, 200, 200);
		

	while (window.isOpen())//GAME LOOP
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			float delta_X = 0.0f;
			float delta_Y = 0.0f;
			float speed = 10.00f;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				delta_X = -speed;
				 
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				delta_X = speed;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				delta_Y = -speed;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				delta_Y = speed;
			}
			circle->move(delta_X, delta_Y);
			if (event.type == sf::Event::Closed)
				window.close();
			if ((circle)->is_colliding(rectangle))
			{
				circle->circle_red();
				rectangle->rectangle_red();
			}
			else
			{

				circle->circle_green();
				rectangle->rectangle_blue();
			}

		}
		
		window.clear();
		circle->draw(window);
		rectangle->draw(window);
		window.display();
	}
	delete circle;
	delete rectangle;
	system("pause");
	return 0;
}
