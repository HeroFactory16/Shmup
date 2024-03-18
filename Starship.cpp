#include <iostream>
#include "Starship.h"
#include "Shoot.h"
#include "InputManager.h"

Starship::Starship() {
	if (!_texture.loadFromFile("Assets/kenney_pixel-shmup/Tilemap/ships_packed.png")) {
		std::cout << "Error loading starship texture file." << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	setPosition(sf::Vector2f(64, 64));
	setOrigin(sf::Vector2f(16.f, 16.f));
}

Starship::Starship(sf::View mainView) {
	if (!_texture.loadFromFile("Assets/kenney_pixel-shmup/Tilemap/ships_packed.png")) {
		std::cout << "Error loading starship texture file." << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	setPosition(sf::Vector2f(round(mainView.getSize().x / 2), round(mainView.getSize().y / 2)));
	setOrigin(sf::Vector2f(16.f, 16.f));
}

void Starship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform = getTransform();
	target.draw(_sprite, states);
}

void Starship::move() {

	_direction = sf::Vector2f(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		_direction = sf::Vector2f(-1, 0);
		_lastDir = sf::Vector2f(-1, 0);
		setRotation(270.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_direction = sf::Vector2f(1, 0);
		_lastDir = sf::Vector2f(1, 0);
		setRotation(90.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		_direction = sf::Vector2f(0, -1);
		_lastDir = sf::Vector2f(0, -1);
		setRotation(0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_direction = sf::Vector2f(0, 1);
		_lastDir = sf::Vector2f(0, 1);
		setRotation(180.f);
	}
}

void Starship::shoot() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _shootClock.getElapsedTime().asSeconds() > .5f) {
		_shootClock.restart();
		std::cout << "Fire time" << std::endl;
		Shoot* shoot = new Shoot();
		shoot->setDirection(_lastDir);
		shoot->setPosition(getPosition());
		shoot->setRotation(getRotation());
		_amosFired.push_back(shoot);
		std::cout << "Missile position x = " << shoot->getPosition().x << " and y = " << shoot->getPosition().y << std::endl;
	}
}

std::vector<Shoot*> Starship::getAmosFired() {
	return _amosFired;
}

void Starship::Update() {
	sf::Time elapsed = _moveClock.restart();
	if (!isDead()) {
		shoot();
		move();
		setPosition(getPosition() + _direction * elapsed.asSeconds() * _speed);
	}
	else {
		OnDeath();
	}
}

bool Starship::isDead() {
	return _lifepoints <= 0;
}

void Starship::OnDeath() {
	_deathAnim = new Explosion(getPosition());
}

Explosion* Starship::getExplosion() {
	return _deathAnim;
}