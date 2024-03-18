#include <iostream>
#include "Shoot.h"

Shoot::Shoot() {
	if (!_texture.loadFromFile("Assets/kenney_pixel-shmup/Tilemap/tiles_packed.png")) {
		std::cout << "Error loading shoot texture file." << std::endl;
	}

	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
	setOrigin(sf::Vector2f(8.f, 8.f));
}

void Shoot::setDirection(sf::Vector2f newDir) {
	_direction = newDir;
}

void Shoot::Update() {
	sf::Time elapsed = _moveClock.restart();

	setPosition(getPosition() + _direction * elapsed.asSeconds() * _speed);
}

void Shoot::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();
	target.draw(_sprite, states);
}