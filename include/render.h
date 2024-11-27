#ifndef RENDERED
#define RENDERED

#include <iostream>
#include <SFML/Graphics.hpp>


class SetWindow {
    public:
        sf::RenderWindow window;
    public:
        SetWindow() {
            sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
            this->window.create(sf::VideoMode(900, 900), "Morse Code Chat", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
            this->window.setPosition(centerWindow);
        }
        ~SetWindow() {
            this->window.clear();
            this->window.close();
        }
};

#endif