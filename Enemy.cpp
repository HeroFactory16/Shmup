#include "Enemy.h"

Enemy::Enemy() {
	if (!_texture.loadFromFile("Assets/kenney_pixel-shmup/Tilemap/ships_packed.png")) {
		std::cout << "Error loading starship texture file." << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));

	setPosition(sf::Vector2f(40, 40));
	setOrigin(sf::Vector2f(16.f, 16.f));
}
void Enemy::move() {}
void Enemy::shoot() {}