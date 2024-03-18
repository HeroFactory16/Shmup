#include <iostream>
#include "Explosion.h"

Explosion::Explosion() {
	if (!_texture.loadFromFile("Assets/kenney_pixel-shmup/Tilemap/tiles_packed.png")) {
		std::cout << "Error loading explosion texture file." << std::endl;
	}

	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(64 + (i%5) * 16, 0, 16, 16));
}

Explosion::Explosion(sf::Vector2f pos) {
	if (!_texture.loadFromFile("Assets/kenney_pixel-shmup/Tilemap/tiles_packed.png")) {
		std::cout << "Error loading explosion texture file." << std::endl;
	}

	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(64 + (i % 5) * 16, 0, 16, 16));

	setPosition(pos);
}

void Explosion::Update() {
		sf::Time elapsed = _animClock.getElapsedTime();
		_sprite.setTextureRect(sf::IntRect(64 + (i % 5) * 16, 0, 16, 16));
		if (elapsed.asSeconds() > 0.1) {
			i++;
			_animClock.restart();
		}
}

void Explosion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();
	target.draw(_sprite, states);
}