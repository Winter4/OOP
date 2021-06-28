#include "Timer.h"

Timer::Timer(sf::RenderWindow* window, sf::Font* fontToSet)
{
	this->window = window;

	text.setPosition(sf::Vector2f(1100, 200));
	text.setFillColor(sf::Color::Black);
	text.setFont(*fontToSet);
	text.setCharacterSize(72);

	refresh();
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
	if (time <= 10) text.setFillColor(sf::Color::Red);
	else text.setFillColor(sf::Color::Black);
	window->draw(text);
}