#include "../include/render.h"
#include "../include/textbox.h"
#include "../include/button.h"
#include <filesystem>
#include <stdexcept>

#include <SFML/Audio.hpp>
#include <thread>



int main() {
    SetWindow WIN;
    const sf::Vector2u minSize(900, 900);
    const sf::Vector2u maxSize(1920, 1080); //Let text be in the same position when max size is reached.
    sf::Font Roboto;
    if(!Roboto.loadFromFile("bin/Roboto-Medium.ttf")){
            throw std::range_error("File not found!");
        }

    Textbox textbox(30, sf::Color::White, true,
                    {20, 50}, sf::Color(0, 0, 0, 75));
    textbox.setFont(Roboto);
    textbox.setPosition({20,20});

    // Create a button
    Button myButton(
        sf::Vector2f(20, 400),  // Position
        sf::Vector2f(200, 50),   // Size
        "Send",             // Text
        Roboto,                  // Font
        sf::Color(20, 20, 20), // Default color
        sf::Color(200, 200, 200), // Hover color
        sf::Color(150, 150, 150)  // Click color
    );

    // Set button click callback
    myButton.setOnClick([&textbox]() {
        //textbox.setText("Button was clicked!");
    });

    sf::View view(sf::FloatRect(0, 0, 900, 900)); //Default view of the window.

    while (WIN.window.isOpen())
    {
        sf::Event event;

        while(WIN.window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                WIN.window.close();
            } 
           // If window is resized, adjust the view
            else if (event.type == sf::Event::Resized) {
                float newWidth = std::max(event.size.width, minSize.x);
                float newHeight = std::max(event.size.height, minSize.y);

                float maxWidth = std::min(event.size.width, maxSize.x);
                float maxHeight= std::min(event.size.height, maxSize.y);

            if(newWidth == minSize.x || newHeight == minSize.y)
                WIN.window.setSize(sf::Vector2u(newWidth, newHeight)); // Prohibit window size to be less than min.
            else if(maxWidth == maxSize.x || maxHeight == maxSize.y)
                WIN.window.setSize(sf::Vector2u(maxWidth, maxHeight)); // Prohibit window size to be more than max.

            // Maintain the original aspect ratio 1:1
            if (newWidth / newHeight > 900.0f / 900.0f)
            {
                // If the window is too wide, match the height and center horizontally
                view.setSize(900.0f * (newWidth / newHeight), 900.0f);
                WIN.window.setView(view);
                } else {
                    // If the window is too tall, match the width and center vertically
                    view.setSize(900.0f, 900.0f * (newHeight / newWidth));
                    WIN.window.setView(view);
                }

               
            }
            else if (event.type == sf::Event::TextEntered) {
               if (event.text.unicode < 128){
                   textbox.typedOn(event);
                   std::size_t buffer = textbox.getText().length();
                   int count = 10;
                   for (auto i : textbox.getText())
                   {
                    if(i == ENTER) {
                        std::cout << i;
                        count += 10 * count;
                        continue;
                    }
                   }
                   textbox.C_setPos((float)buffer* 15, count);
               }
            }

            // Handle button events
            myButton.handleEvent(event, WIN.window);
        }

        // Update button state
        myButton.update(WIN.window);

        WIN.window.clear(sf::Color(45, 45, 68, 1));
        textbox.drawTo(WIN.window);
        myButton.draw(WIN.window);
        WIN.window.display();
    }

    return 0;
}