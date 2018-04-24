#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int windowHeight=500;
int windowWidth=1000;

sf::Texture texture;
sf::Sprite sprite;

void CreateTexture() {
	if (!texture.loadFromFile("dog.png")){
		// error...
	}
}
void SetSprite() {
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

int main(){
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

	texture.loadFromFile("dog.png");
	sprite.setTextureRect(sf::IntRect(10, 10, 32, 32));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}