#include "../include/button.h"

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size,
               const std::string& buttonText, const sf::Font& font,
               const sf::Color& defaultColor, const sf::Color& hoverColor,
               const sf::Color& clickColor)
    : defaultColor(defaultColor), hoverColor(hoverColor), clickColor(clickColor),
      isHovered(false), isClicked(false) {
    
    // Set up the button shape
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(defaultColor);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color(20, 20, 20));

    // Set up the button text
    text.setString(buttonText);
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // Center the text in the button
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                  textBounds.top + textBounds.height / 2.0f);
    text.setPosition(position.x + size.x / 2.0f,
                    position.y + size.y / 2.0f);
}

void Button::setOnClick(std::function<void()> callback) {
    onClick = callback;
}

void Button::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (shape.getGlobalBounds().contains(mousePos)) {
                isClicked = true;
                shape.setFillColor(clickColor);
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (isClicked) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (shape.getGlobalBounds().contains(mousePos) && onClick) {
                    onClick();
                }
                isClicked = false;
                shape.setFillColor(isHovered ? hoverColor : defaultColor);
            }
        }
    }
}

void Button::update(const sf::RenderWindow& window) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    bool wasHovered = isHovered;
    isHovered = shape.getGlobalBounds().contains(mousePos);

    if (isHovered != wasHovered) {
        if (!isClicked) {
            shape.setFillColor(isHovered ? hoverColor : defaultColor);
            text.setFillColor(isHovered ? sf::Color(20, 20, 20) : hoverColor);
        }
    }
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(text);
} 