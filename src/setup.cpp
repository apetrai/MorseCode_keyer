#include "../include/setup.h"


void USER_ACCOUNT::main_WIN() {
    SetWindow WIN;
      sf::Sound startup;
        sf::SoundBuffer buffer;
        //buffer.loadFromFile("media/Windows2000Beta3Startup.wav");
        startup.setBuffer(buffer);
        startup.play(); 
        Textbox WTEXT(30, sf::Color::White, false);
    sf::Font font;
    font.loadFromFile("bin/Roboto-Medium.ttf");
    WTEXT.setFont(font);
    WTEXT.setPosition({250.f, 250.f});
    WTEXT.textbox.setString("Welcome Guest!");
    WIN.window.setFramerateLimit(FRAME_LIM);

    const sf::Vector2u minSize(900, 900);
    const sf::Vector2u maxSize(1920, 1080); //Let text be in the same position when max size is reached.
    sf::Font Roboto;

    sf::View view(sf::FloatRect(0, 0, 900, 900)); //Default view of the window.

    while (WIN.window.isOpen())
    {
        sf::Event event;
        bool mouseClicked = false;
        while (WIN.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){  WIN.window.close();  }

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

        

               
            }
          
            sf::Vector2i mousePos = sf::Mouse::getPosition(WIN.window);


            
            WIN.window.setVerticalSyncEnabled(true);
            WTEXT.setPosition({0, 0});

            WIN.window.clear(sf::Color(45, 45, 68, 1));

            WTEXT.drawTo(WIN.window);
            WIN.window.display();
        }
    }
}

bool USER_ACCOUNT::setup() {
    SetWindow WIN;
    sf::Sound startup;
    sf::SoundBuffer buffer;
    //buffer.loadFromFile("media/setup.wav");
    startup.setBuffer(buffer);
    startup.setLoop(true);
    startup.play();

    WIN.window.setFramerateLimit(FRAME_LIM);


    Textbox WTEXT(30, sf::Color::White, false);
    sf::Font font;
    font.loadFromFile("bin/Roboto-Medium.ttf");
    WTEXT.setFont(font);
    WTEXT.setPosition({250.f, 250.f});
    WTEXT.textbox.setString("Welcome to Morse Code chatting\n Chat in Privacy");

    Button Guest(20.0f, 100.0f, 200.0f, 80.0f, "Sign in as Guest", sf::Color::Blue, sf::Color::Cyan, sf::Color::Green, "bin/Roboto-Medium.ttf", [this](){});

    const sf::Vector2u minSize(900, 900);
    const sf::Vector2u maxSize(1920, 1080); //Let text be in the same position when max size is reached.
    sf::Font Roboto;

    sf::View view(sf::FloatRect(0, 0, 900, 900)); //Default view of the window.

    while (WIN.window.isOpen())
    {
        sf::Event event;
        bool mouseClicked = false;
        while (WIN.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){  WIN.window.close();  }

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
                view.setViewport(sf::FloatRect(0, 0, 1, 1));
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                 WIN.window.setView(sf::View(visibleArea)); //Show more contents of the window.
             
                } else {
                    // If the window is too tall, match the width and center vertically
                    view.setSize(900.0f * (newWidth / newHeight), 900.0f);
                    WIN.window.setView(view);
                }

               
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {  
                mouseClicked = true;
                
                WIN.window.setVerticalSyncEnabled(true);
                WTEXT.setPosition({0, 0});

                WIN.window.clear(sf::Color(45, 45, 68, 1));

                WTEXT.drawTo(WIN.window);
                Guest.draw(WIN.window);
                WIN.window.display();

                WIN.window.close();
                break;
            }
                sf::Vector2i mousePos = sf::Mouse::getPosition(WIN.window);
                Guest.update(mousePos, mouseClicked);

                WIN.window.setVerticalSyncEnabled(true);
                WTEXT.setPosition({0, 0});

                WIN.window.clear(sf::Color(45, 45, 68, 1));

                WTEXT.drawTo(WIN.window);
                Guest.draw(WIN.window);
                WIN.window.display();
        }
    }

    return true;
}