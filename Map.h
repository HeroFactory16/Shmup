#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map : public sf::Transformable, public sf::Drawable {
protected:
	std::vector<Tile*> _tileMap;
	sf::Texture _texture;
	sf::Sprite _sprite;
	int collumn = 0;

public:
	Map(sf::View mainView);
	void AddTile(Tile* tile);
	sf::Texture getTexture();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};