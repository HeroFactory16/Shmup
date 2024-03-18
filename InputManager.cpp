#include "InputManager.h"

sf::Keyboard::Key InputManager::getKeyboardInput() {
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << "Poogie fires!" << std::endl;
			//return sf::Keyboard::Space;
			//space = true;
		}
		//else
		//	space = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			std::cout << "Poogie goes left" << std::endl;
			return sf::Keyboard::Left;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			std::cout << "Poogie goes right" << std::endl;
			return sf::Keyboard::Right;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			std::cout << "Poogie goes up" << std::endl;
			return sf::Keyboard::Up;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			std::cout << "Poogie goes down" << std::endl;
			return sf::Keyboard::Down;
		}
	}
};