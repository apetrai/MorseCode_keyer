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

public:
    USER_ACCOUNT() {
        if (signedIn == false)
        {
            signedIn = setup(); //If setup returns true the user will be signed in.
            if(signedIn == true ){main_WIN();}
        
        }
        else {
            main_WIN();
        }
    }

    bool setup();
    void main_WIN();
};

#endif