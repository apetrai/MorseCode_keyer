#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional> // For std::function

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    sf::Color idleColor, hoverColor, activeColor;

    // Callback for button action
    std::function<void()> onClick;

public:
    Button(float x, float y, float width, float height,
           const std::string& buttonText,
           const sf::Color& idle, const sf::Color& hover, const sf::Color& active,
           const std::string& fontPath,
           std::function<void()> callback)
        : onClick(callback) {
        shape.setPosition(x, y);
        shape.setSize({width, height});
        shape.setFillColor(idle);

        if (!font.loadFromFile(fontPath)) {
            throw std::runtime_error("Error loading font");
        }

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);

        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                       textBounds.top + textBounds.height / 2.0f);
        text.setPosition(x + width / 2.0f, y + height / 2.0f);

        idleColor = idle;
        hoverColor = hover;
        activeColor = active;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    void update(const sf::Vector2i& mousePos, bool isClicked) {
        if (shape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            if (isClicked) {
                shape.setFillColor(activeColor);
                if (onClick) { // Ensure a callback is set
                    onClick();
                }
            } else {
                shape.setFillColor(hoverColor);
            }
        } else {
            shape.setFillColor(idleColor);
        }
    }
};

#endif // BUTTON_H
