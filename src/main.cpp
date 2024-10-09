#include <SFML/Graphics.hpp>
#include "../include/Main_UI.h"

#include <iostream>
#include <sstream>
#include "../include/dictionary.h"
#include "../include/nums.h"
#include <string>
#include <stdexcept>

using namespace sf; // SFML namespace

#define FRAME_LIMIT 120

#define WIDTH 1000
#define LENGTH 1000
constexpr unsigned char aspectRatio = 1;

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    RenderWindow window(VideoMode(WIDTH, LENGTH), "Morse Code Keyer");

    // Set the frame rate limit
    window.setFramerateLimit(FRAME_LIMIT);

    // Load a font (make sure the font file is in the correct directory)
    sf::Font font;
    if (!font.loadFromFile("bin/Roboto-Medium.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Create a text object for displaying input
    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(20); // in pixels
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(20.f, 20.f); // Updated position for better visibility

    // Create a text box for input
    sf::RectangleShape textBox(sf::Vector2f(780, 100));
    textBox.setPosition(10.f, 10.f);
    textBox.setFillColor(sf::Color(255, 255, 255));
    textBox.setOutlineThickness(2);
    textBox.setOutlineColor(sf::Color(0, 0, 0));

    // Create a button
    sf::RectangleShape button(sf::Vector2f(200, 50));
    button.setPosition(300.f, 500.f);
    button.setFillColor(sf::Color(100, 100, 250));

    // Create a text object for the button
    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setCharacterSize(20); // in pixels
    buttonText.setFillColor(sf::Color::White);
    buttonText.setString("Clear Text");
    buttonText.setPosition(button.getPosition().x + 20, button.getPosition().y + 10);

    // Placeholder text
    sf::Text placeholderText;
    placeholderText.setFont(font);
    placeholderText.setString("Enter text here...");
    placeholderText.setCharacterSize(20);
    placeholderText.setFillColor(sf::Color(150, 150, 150)); // Light gray for placeholder
    placeholderText.setPosition(20.f, 20.f); // Position matching inputText

    // Background color
    sf::Color backgroundColor = sf::Color(71, 68, 68);

    std::string input;
    bool textBoxActive = false;

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (textBox.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
                    {
                        textBoxActive = true;
                    }
                    else
                    {
                        textBoxActive = false; // Deactivate if clicked outside
                    }
                }
            }

            if (textBoxActive)
            {
                if (event.type == Event::TextEntered)
                {
                    // Handle text input
                    if (event.text.unicode < 128) // Ensure character is valid
                    {
                        if (event.text.unicode == 8 && !input.empty()) // Handle backspace
                        {
                            input.pop_back();
                        }
                        else if (event.text.unicode == 13) // Handle Enter key (new line)
                        {
                            input += "\n";
                        }
                        else if (event.text.unicode != 8 && event.text.unicode != 13)
                        {
                            input += static_cast<char>(event.text.unicode);
                        }
                    }
                }
            }

            if (button.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)) && event.type == Event::MouseButtonPressed)
            {
                // Button pressed, clear the text
                input.clear();
            }

            // Update inputText to show current input
            inputText.setString(input);
        }

        // Clear the window with the background color
        window.clear(backgroundColor);

        // Draw the text box
        window.draw(textBox);

        // Draw the input text or placeholder
        if (input.empty() && !textBoxActive)
        {
            window.draw(placeholderText);
        }
        else
        {
            window.draw(inputText);
        }

        // Draw the button and button text
        window.draw(button);
        window.draw(buttonText);

        // Display the content drawn
        window.display();
    }

    return 0;
}
