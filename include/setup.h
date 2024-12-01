#ifndef USER
#define USER

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <iostream>

#include "render.h"
#include "textbox.h"
#include "button.h"

#define FRAME_LIM 120

class USER_ACCOUNT {
    std::string first_Name;
    std::string second_Name;
    std::string email;
    
    bool signedIn = false;

    SetWindow WIN;
    sf::Font font;

public:
    USER_ACCOUNT() {
        font.loadFromFile("bin/Roboto-Medium.ttf");
       while (WIN.window.isOpen()) {
        if (!signedIn) {
            signedIn = setup();
        } else {
            main_WIN();
        }
    }
    }

    bool setup();
    void main_WIN();
};

#endif