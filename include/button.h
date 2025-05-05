#pragma once

#include <SFML/Graphics.hpp>
#include <functional>


class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Color defaultColor;
    sf::Color hoverColor;
    sf::Color clickColor;
    std::function<void()> onClick;
    bool isHovered;
    bool isClicked;

public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, 
           const std::string& buttonText, const sf::Font& font,
           const sf::Color& defaultColor,
           const sf::Color& hoverColor,
           const sf::Color& clickColor);

    void setOnClick(std::function<void()> callback);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

}; 