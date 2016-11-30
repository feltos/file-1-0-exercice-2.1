#include "Shapes.h"
#include <cmath>
#include <SFML/Graphics.hpp>


Shapes::Shapes(double x, double y)
{
	this->x = x;
	this->y = y;
}

Shapes::~Shapes()
{
}

double Shapes::get_x()
{
	return this->x;
}

double Shapes::get_y()
{
	return this->y;
}

Rectangle::Rectangle(double width, double heigth, double x,
	double y) :Shapes(x, y)
{
	this->width = width;
	this->heigth = heigth;
	sfml_rectangle = sf::RectangleShape(sf::Vector2f(100, 100));
	sfml_rectangle.setPosition(sf::Vector2f(200.f, 200.f));
	sfml_rectangle.setFillColor(sf::Color::Blue);
}

Rectangle::~Rectangle()
{

}

double Rectangle::get_heigth()
{
	return heigth;
}

double Rectangle::get_width()
{
	return width;
}

bool Rectangle::is_colliding(Shapes*s)
{
	Rectangle* r = dynamic_cast <Rectangle*> (s);
	if (r != NULL)
	{
		return is_colliding(r);
	}

	Circle* c = dynamic_cast <Circle*> (s);
	if (c != NULL)
	{
		return is_colliding(c);
	}
}

bool Rectangle::is_colliding(Circle* c)
{
	return c->is_colliding(this);
}

bool Rectangle::is_colliding(Rectangle* r)
{
	if (this->x < r->x + r->width &&
		this->x + this->width > r->x &&
		this->y < r->y + r->heigth &&
		this->heigth + this->y > r->y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Rectangle::rectangle_red()
{
	sfml_rectangle.setFillColor(sf::Color::Red);
}

void Rectangle::rectangle_blue()
{
	sfml_rectangle.setFillColor(sf::Color::Blue);
}

void Rectangle::draw(sf::RenderWindow& window)
{
	window.draw(sfml_rectangle);
}

//CIRCLE START !

Circle::Circle(double radius, double x, double y) :Shapes(x, y)
{
	this->radius = radius;
	sfml_circle = sf::CircleShape(50.f);
	sfml_circle.setPosition(sf::Vector2f(x, y));
	sfml_circle.setFillColor(sf::Color::Green);

}


double Circle::get_radius()
{
	return radius;
}

bool Circle::is_colliding(Shapes* s)
{
	Rectangle* r = dynamic_cast <Rectangle*> (s);
	if (r != NULL)
	{
		return is_colliding(r);
	}

	Circle* c = dynamic_cast <Circle*> (s);
	if (c != NULL)
	{
		return is_colliding(c);
	}
}

bool Circle::is_colliding(Circle* c)
{
	double dx = this->x - c->x;
	double dy = this->y - c->y;
	double distance = sqrt(dx*dx + dy*dy);
	if (distance < this->radius + c->radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Circle::is_colliding(Rectangle* r)
{
	double circle_distanceX = abs(this->get_x() - r->get_x());
	double circle_distanceY = abs(this->get_y() - r->get_y());

	if (circle_distanceX > (r->get_width() / 2 + get_radius()))
	{
		return false;
	}
	if (circle_distanceY > (r->get_heigth() / 2 + get_radius()))
	{
		return false;
	}
	if (circle_distanceX > (r->get_width() / 2))
	{
		return true;
	}
	if (circle_distanceY > (r->get_heigth() / 2))
	{
		return true;
	}
	double cornerDistance_sq = pow((circle_distanceX - r->get_width() / 2), 2) +
		pow((circle_distanceY - r->get_heigth() / 2), 2);

	return (cornerDistance_sq <= pow((get_radius()), 2));
}

void Circle::circle_red()
{
	sfml_circle.setFillColor( sf::Color::Red);
}

void Circle::circle_green()
{
	sfml_circle.setFillColor(sf::Color::Green);
}

void Circle::draw(sf::RenderWindow& window)
{
	window.draw(sfml_circle);
}

void Circle::move(float delta_X, float delta_Y)
{
	x += delta_X;
	y += delta_Y;
	sfml_circle.setPosition(x, y);
}

Circle::~Circle()
{

}
