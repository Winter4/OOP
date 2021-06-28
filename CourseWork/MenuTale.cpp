#include "MenuTale.h"

MenuTale::MenuTale(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* textureToLink, sf::Font* fontToSet, const std::string textToSet) 
	: TextureLinker(window, position, textureToLink)
{
	sprite.setTexture(*textureToLink);

	text.setFont(*fontToSet);
	text.setCharacterSize(24);
	text.setString(textToSet);
	text.setFillColor(sf::Color::White);

	// center text
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2.0f,
		sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2.0f));
}

void MenuTale::draw()
{
	TextureLinker::draw();
	window->draw(text);
}

sf::IntRect MenuTale::getRectangle()
{
	return sf::IntRect(sprite.getGlobalBounds());
}

void MenuTale::setColor(sf::Color color)
{
	sprite.setColor(color);
}