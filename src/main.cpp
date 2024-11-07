#include "../include/render.h"
#include "../include/textbox.h"
#include <filesystem>
#include <stdexcept>



int main() {
    SetWindow WIN;
    sf::Font Roboto;
    if(!Roboto.loadFromFile("bin/Roboto-Medium.ttf")){
            throw std::range_error("FIle not found!");
        }

    Textbox textbox(15, sf::Color::White, true);
    textbox.setFont(Roboto);
    textbox.setPosition({250,250});
    while (WIN.window.isOpen())
    {
        sf::Event event;

        while(WIN.window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                WIN.window.close();
            }
            else if (sf::Event::TextEntered) {
               if (event.text.unicode < 128){
                   textbox.setSelected(true);
                   textbox.typedOn(event);
               }
            }

            WIN.window.clear();
            textbox.drawTo(WIN.window);
            WIN.window.display();
        }
    }

    return 0;
}