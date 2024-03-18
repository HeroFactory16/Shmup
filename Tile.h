#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile : public sf::Transformable, public sf::Drawable {
protected:
	sf::Sprite _sprite;

public:
	Tile(sf::Texture* _texture);
	Tile(sf::Texture* _texture, sf::IntRect posOnTilemap);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};