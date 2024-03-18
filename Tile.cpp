#include "Tile.h"

Tile::Tile(sf::Texture* texture) {
	_sprite.setTexture(*texture);
	_sprite.setTextureRect(sf::IntRect(16, 48, 16, 16));
}

Tile::Tile(sf::Texture* texture, sf::IntRect posOnTilemap) {
	_sprite.setTexture(*texture);
	_sprite.setTextureRect(posOnTilemap);
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	states.transform.combine(getTransform());
	target.draw(_sprite, states);
}