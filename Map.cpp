#include <iostream>
#include "Map.h"

Map::Map(sf::View mainView) {
	if (!_texture.loadFromFile("Assets/kenney_pixel-shmup/Tilemap/tiles_packed.png")) {
		std::cout << "Error loading map texture file." << std::endl;
	}

	for (int i = 0; i < mainView.getSize().y; i += 16) {
		for (int j = 0; j < mainView.getSize().x; j += 16) {
			Tile* tile = new Tile(&_texture);
			tile->setPosition(sf::Vector2f(j, i));
			_tileMap.push_back(tile);
		}
	}
}

sf::Texture Map::getTexture() {
	return _texture;
}

void Map::AddTile(Tile* tile) {
	_tileMap.push_back(tile);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();
	for (Tile* tile : _tileMap) {
		target.draw(*tile, states);
	}
}