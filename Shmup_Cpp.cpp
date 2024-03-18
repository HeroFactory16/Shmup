#include <iostream>
#include <SFML/Graphics.hpp>
#include "Starship.h"
#include "Explosion.h"
#include "Shoot.h"
#include "Map.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Shmup");
    sf::View globalView(sf::Vector2f(0, 0), sf::Vector2f(400.f, 900.f));

    float viewY = round(window.getSize().y * globalView.getSize().x / window.getSize().x);
    globalView.setSize(globalView.getSize().x, viewY);
    globalView.setCenter(round(globalView.getSize().x / 2), round(globalView.getSize().y / 2));

    window.setView(globalView);

    Starship ship = Starship(globalView);
    Map map = Map(globalView);
    Enemy enemy = Enemy();

    std::cout << "Ship with x = " << ship.getPosition().x << " and y = " << ship.getPosition().x << std::endl;

	while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ship.Update();
        if (ship.isDead()) {
            ship.getExplosion()->Update();
        }

        for (int i = 0; i < ship.getAmosFired().size(); ++i) {
            ship.getAmosFired()[i]->Update();
        }

        window.clear(sf::Color::Black);

        window.draw(map);
        window.draw(ship);
        window.draw(enemy);

        for (int i = 0; i < ship.getAmosFired().size(); ++i) {
            window.draw(*ship.getAmosFired()[i]);
        }
        if (ship.isDead()) {
            window.draw(*ship.getExplosion());
        }
        window.display();
	}
}