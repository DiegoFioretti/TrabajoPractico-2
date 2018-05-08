#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#ifdef DEBUG
	#include <vld.h>
#endif
#include <iostream>
using namespace std;
#define windowHeight 700
#define windowWidth 1024
#define playerSpeed 400
#define playerCode 1
#define enemyCode 2
#define coinCode 3
#define enemyArray 10

sf::Texture playerTexture;
sf::Texture enemyTexture;
sf::Texture coinTexture;
sf::Sprite player;
sf::Sprite coin;
sf::Sprite enemies[enemyArray];

void CreateTextures() {
	if (!playerTexture.loadFromFile("Resource/playerShip.png")){
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	if (!coinTexture.loadFromFile("Resource/boss.png")) {
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	if (!enemyTexture.loadFromFile("Resource/enemyBullet.png")) {
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
}
void SetSprite(sf::Sprite &sprite, sf::Texture &texture, int code) {
	
	sprite.setTexture(texture);

	switch (code){
		case playerCode:
			//position
			sprite.setPosition(sf::Vector2f((windowWidth / 2) - 50, (windowHeight / 2) + 200)); // absolute position
			//scale
			sprite.setScale(sf::Vector2f(1.f, 1.f)); // absolute scale factor
			sprite.scale(sf::Vector2f(0.25f, 0.25f)); // factor relative to the current scale
			//origin
			sprite.setOrigin(sf::Vector2f(181, 154.5f));
		break;
		case coinCode:
			//position
			sprite.setPosition(sf::Vector2f((windowWidth / 2) - 150, -100.f)); // absolute position
			//scale
			sprite.setScale(sf::Vector2f(0.5f, 0.5f)); // absolute scale factor
			sprite.scale(sf::Vector2f(0.5f, 0.5f)); // factor relative to the current scale
		break;
		case enemyCode:
			//position
			//sprite.setPosition(sf::Vector2f((windowWidth / 2) - 50, (windowHeight / 2) + 200)); // absolute position
			//scale
			sprite.setScale(sf::Vector2f(1.f, 1.f)); // absolute scale factor
			sprite.scale(sf::Vector2f(0.25f, 0.25f)); // factor relative to the current scale
			break;
	}
}
void PlayerControl(sf::Time deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getPosition().x > 0) {
		player.move(-playerSpeed * deltaTime.asSeconds(), 0);
		player.setRotation(270);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getPosition().x < windowWidth - 100) {
		player.move(playerSpeed * deltaTime.asSeconds(), 0);
		player.setRotation(90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.getPosition().y > 0) {
		player.move(0, -playerSpeed * deltaTime.asSeconds());
		player.setRotation(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.getPosition().y < windowHeight - 80) {
		player.move(0, playerSpeed * deltaTime.asSeconds());
		player.setRotation(180);
	}
}
void init(){
	CreateTextures();
	SetSprite(player, playerTexture, playerCode);
	SetSprite(coin, coinTexture, coinCode);
	for (size_t i = 0; i < enemyArray; i++){
		SetSprite(enemies[i], enemyTexture, enemyCode);
	}
}
int main(){
	init();

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
	window.setFramerateLimit(60);
	sf::Clock clock;

	while (window.isOpen()){
		sf::Time elapsed = clock.getElapsedTime();
		clock.restart();
		sf::Event event;
		while (window.pollEvent(event)){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				window.close();
			}
			PlayerControl(elapsed);
		}
		window.clear();
		window.draw(player);
		window.draw(coin);
		for (size_t i = 0; i < enemyArray; i++) {
			window.draw(enemies[i]);
		}
		window.display();
	}

	return 0;
}