#include "TextureOwner.h"

TextureOwner::TextureOwner(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName) 
	: Object(window, position)
{
	// loading a texture
	if (!texture.loadFromFile(textureFileName)) throw std::exception("Texture init error");
	// setting the texture
	sprite.setTexture(texture);
}

void TextureOwner::draw()
{
	Object::draw();
}