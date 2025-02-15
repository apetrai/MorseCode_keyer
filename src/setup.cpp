#include "../include/setup.h"


void USER_ACCOUNT::main_WIN() {
    WIN.window.display();
    sf::Sound startup;
    sf::SoundBuffer buffer;
     buffer.loadFromFile("media/Windows2000Beta3Startup.wav");
    startup.setBuffer(buffer);
    startup.play();
    
    Textbox WTEXT(30, sf::Color::White, false, font);
    WTEXT.setFont(font);
    WTEXT.setPosition({250.f, 250.f});
    WTEXT.textbox.setString("Welcome Guest!");
    WIN.window.setFramerateLimit(FRAME_LIM);

    sf::View view(sf::FloatRect(0, 0, 800, 600)); // Default view of the window.

    Textbox USER_MESSAGE(15, sf::Color::White, true, font);
    bool isMessageSel = false;
    USER_MESSAGE.setPosition({250, 250});

    while (WIN.window.isOpen())
    {
        sf::Event event;
        bool mouseClicked = false;
        while (WIN.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){  WIN.window.close(); return; }

// If window is resized, adjust the view
            if(event.type == sf::Event::Resized){ WIN.ResizeWindow(WIN.window, view); }

            sf::Vector2i mousePos = sf::Mouse::getPosition(WIN.window);

           
            if(event.type == sf::Event::TextEntered) {
                USER_MESSAGE.typedOn(event);
            }

            WIN.window.setVerticalSyncEnabled(true);
            WTEXT.setPosition({0, 0});

            WIN.window.clear(sf::Color(45, 45, 68, 1));

            WTEXT.drawTo(WIN.window);
            USER_MESSAGE.drawTo(WIN.window);
            WIN.window.setView(view);
            WIN.window.display();
        }
    }
}

bool USER_ACCOUNT::setup() {
    sf::Sound startup;
    sf::SoundBuffer buffer;
    buffer.loadFromFile("media/setup.wav");
    startup.setBuffer(buffer);
    startup.setLoop(true);
    startup.play();

    WIN.window.setFramerateLimit(FRAME_LIM);

    Textbox WTEXT(30, sf::Color::White, false, font);
    WTEXT.setFont(font);
    WTEXT.setPosition({250.f, 250.f});
    WTEXT.textbox.setString("Welcome to Morse Code chatting\n Chat in Privacy");

    Button Guest(
        20.0f, 100.0f, 200.0f, 80.0f, 
        "Sign in as Guest",  
        sf::Color(69, 69, 70), 
        sf::Color(81, 199, 236),  
        sf::Color(68, 161, 255),  
        "bin/Roboto-Medium.ttf", 
    [this](){});


    sf::View view(sf::FloatRect(0, 0, 800, 600)); //Default view of the window.

    while (WIN.window.isOpen())
    {
        sf::Event event;
        bool mouseClicked = false;
        while (WIN.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                WIN.window.close();
                return false;
            }

 // If window is resized, adjust the view
            if(event.type == sf::Event::Resized){ WIN.ResizeWindow(WIN.window, view); }           

            
             sf::Vector2i mousePos = sf::Mouse::getPosition(WIN.window);
             Guest.update(mousePos, mouseClicked);
             if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
             {
                 mouseClicked = true;
             }
            if (mouseClicked) {
            Guest.update(mousePos, mouseClicked);
                // Transition to main_WIN
                return true;
            }

                WIN.window.setVerticalSyncEnabled(true);
                WTEXT.setPosition({0, 0});

                WIN.window.clear(sf::Color(45, 45, 68, 1));

                WTEXT.drawTo(WIN.window);
                Guest.draw(WIN.window);
                WIN.window.setView(view);
                WIN.window.display();
        }
    }

    return true;
}