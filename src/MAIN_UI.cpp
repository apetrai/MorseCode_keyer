#include "../include/Main_UI.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;
using namespace UI;

inline void MAIN::CreateTextBox() noexcept {
	// Create a text box
	sf::RectangleShape textBox(sf::Vector2f(780, 100));
	textBox.setPosition(10.f, 10.f);
	textBox.setFillColor(sf::Color(255, 255, 255));
	textBox.setOutlineThickness(2);
	textBox.setOutlineColor(sf::Color(0, 0, 0));
}

inline void MAIN::ChangeTextBox(RenderWindow& window, Constraints* constraints) noexcept {

}