#ifndef RENDERED
#define RENDERED

#include <iostream>
#include <SFML/Graphics.hpp>

#define VIEW_HEIGHT 600.0f

class SetWindow {
    public:
        sf::RenderWindow window;
    public:
        SetWindow() {
            sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
            this->window.create(sf::VideoMode(800, 600), "Morse Code Chat - Alpha v0.0.2", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
            this->window.setPosition(centerWindow);
        }
        ~SetWindow() {
            this->window.clear();
            this->window.close();
        }

        void ResizeWindow(sf::RenderWindow &win, sf::View &view);
};

#endif