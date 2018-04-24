#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
using namespace std;
int windowHeight=500;
int windowWidth=1000;
int playerSpeed = 50;
int gravity = 9.10;

sf::Texture texture;
sf::Sprite player;
//sf::Clock clock;

void CreateTexture() {
	if (!texture.loadFromFile("Resource/dog.png"))
	{
		std::cout << "Load failed" << std::endl;

		system("pause");
	}
}
void SetSprite(sf::Sprite &sprite) {
	sprite.setTexture(texture);
	/*
	// position
	sprite.setPosition(sf::Vector2f(10, 50)); // absolute position
	sprite.move(sf::Vector2f(5, 10)); // offset relative to the current position

	// rotation
	sprite.setRotation(90); // absolute angle
	sprite.rotate(15); // offset relative to the current angle

	// scale
	sprite.setScale(sf::Vector2f(0.5f, 2.f)); // absolute scale factor
	sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
	*/
}
void PlayerMovement() {
	//player.move(0, gravity);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player.move(-playerSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player.move(playerSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player.move(0, -playerSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player.move(0, playerSpeed);
	}
}

int main(){
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

	CreateTexture();
	SetSprite(player);


	while (window.isOpen())
	{
		//sf::Time elapsed = clock.restart();
		//updateGame(elapsed);
		sf::Event event;
		while (window.pollEvent(event))
		{		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				window.close();
			}
			PlayerMovement();
		}

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}