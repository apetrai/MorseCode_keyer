#include <SFML/Graphics.hpp>
#include "../include/Main_UI.h"

#include <iostream>
#include <sstream>
#include "../include/dictionary.h"
#include "../include/nums.h"
#include <string>
#include <stdexcept>

using namespace sf; //SFML namespace

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
  if (!font.loadFromFile("Roboto-Medium.ttf")) {
       throw std::runtime_error("Font failed to load!");
   } 
   // Create a text object
   sf::Text text;
   text.setFont(font);
   text.setCharacterSize(100); // in pixels
   text.setFillColor(sf::Color::Black);
   text.setPosition(10.f, 10.f);

   // Create a text object for input
   sf::Text inputText;
   inputText.setFont(font);
   inputText.setCharacterSize(100); // in pixels
   inputText.setFillColor(sf::Color::Black);
   inputText.setPosition(10.f, 10.f);

   // Create a text box
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
   buttonText.setCharacterSize(100); // in pixels
   buttonText.setFillColor(sf::Color::White);
   buttonText.setString("Clear Text");

   buttonText.setPosition(button.getPosition().x + 20, button.getPosition().y + 10);

   // Background color
   sf::Color backgroundColor = sf::Color(71, 68, 68);

   std::string input;
   bool textBoxActive = false;

   sf::View view(sf::FloatRect(0, 0, WIDTH, LENGTH));
   window.setView(view);

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.key.control && event.key.code == Keyboard::U ) input.clear();

            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::TextEntered) {
                // Handle text input
                if (event.text.unicode < 128) {
                    if (event.text.unicode == 8 && !input.empty() ) { // Handle backspace
                        input.pop_back();
                    }
                    if (event.text.unicode == 13 ) { // Handle Enter key (new line)
                        input += "\n";
                    }
                    if (event.text.unicode != 8 && event.text.unicode != 13) {
                        input += static_cast<char>(event.text.unicode);
                    }

                }
            }
            
            inputText.setString(input);

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

            if(textBoxActive = false) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        if (textBox.getGlobalBounds().contains(mousePosF)) {
                            textBoxActive = true;
                            inputText.setString(input);
                            // Clear the window with the background color
                            window.clear(backgroundColor);

                            window.draw(textBox);

                            // Draw the text
                            window.draw(inputText);


                            // Draw the button
                            window.draw(button);
                            window.draw(buttonText);

                            // Display the content drawn
                            window.display();
                            continue;


                        }
                    }
                }
    
            }
            if (button.getGlobalBounds().contains(mousePosF)) {
                // Button pressed, clear the text
                input.clear();
                inputText.setString(input);
                // Draw the text box


            }
            if (event.type == sf::Event::Resized)
            {
                // Get the new window size
                float newWidth = event.size.width;
                float newHeight = event.size.height;

                // Calculate new dimensions to maintain aspect ratio
                float newAspectRatio = newWidth / newHeight;
                if (newAspectRatio > aspectRatio)
                {
                    newWidth = newHeight * aspectRatio;
                }
                else
                {
                    newHeight = newWidth / aspectRatio;
                }

                // Center the view
                view.setSize(newWidth, newHeight);
                view.setViewport(sf::FloatRect((event.size.width - newWidth) / (newWidth * event.size.width),
                    ((event.size.height - newHeight) / (newHeight * event.size.height)),
                    (newWidth / event.size.width),
                   (newHeight / event.size.height)));
                
                inputText.setCharacterSize((newWidth / event.size.width) * 100);


                textBox.setPosition(0, 0);
                window.setView(view);
            }
       
            Vector2f winPos(static_cast<Vector2f>(window.getSize()));
            Vector2f winPosF(winPos.x / 10, winPos.y / 10);
   


           // button.setSize(winPosF);
            
            // Clear the window with the background color
            window.clear(backgroundColor);

            window.draw(textBox);

            // Draw the text
            window.draw(inputText);
           

            // Draw the button
            window.draw(button);
            window.draw(buttonText);

            // Display the content drawn
            window.display();
        }
    }

    return 0;
}
