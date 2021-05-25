#include "Timer.h"

Timer::Timer(sf::RenderWindow* window)
{
	this->window = window;
	if (not font.loadFromFile("gilroy.ttf")) throw std::runtime_error("Error while font loading.");

	text.setPosition(sf::Vector2f(1100, 200));
	text.setFillColor(sf::Color::Black);
	text.setFont(font);
	text.setCharacterSize(72);

	time = 60;
}

void Timer::substractSecond()
{
	time--;
}

void Timer::refresh()
{
	time = 60;
}

sf::Time Timer::getElapsedTime()
{
	return timer.getElapsedTime();
}

void Timer::restart()
{
	timer.restart();
}

short Timer::getTime()
{
	return time;
}

void Timer::draw()
{
	text.setString(std::to_string(time));
	window->draw(text);
}