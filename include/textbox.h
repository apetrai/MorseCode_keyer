#ifndef TEXTBOX
#define TEXTBOX

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>

/* Predefine Keys */
#define DELETE 8
#define ENTER 13
#define ESCAPE 27
#define CTRL 17


class Textbox {
private:
    sf::RectangleShape rect;
    sf::Text textbox;
    std::string text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;
    std::size_t LimperLine = 20;
    sf::Font font;

    void inputLogic(char charTyped) {
        if (charTyped != DELETE && charTyped != ENTER && charTyped != ESCAPE) {
            text += charTyped;
        }
        else if(charTyped == ENTER) {
            text += "\n";
        }
        else if(charTyped == DELETE) {
            bool ctrlHeld = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
            if(ctrlHeld) {
             if(!text.empty() && text.back() == ' ' && text.length() != 1) {deleteLastChar();}
             else if(text.length() != 0) {
                while(!text.empty() && text.back() != ' ') {
                    deleteLastChar();
                }
              }
              else text.assign("");
            }
            else {
                deleteLastChar();
            }
        }
        textbox.setString(text);
    }

    void deleteLastChar() {
        if (text.length() > 1) {
            text.pop_back(); // Remove the last character directly
        }
        else {
            text.clear();
        }
    }

public:
    Textbox() {}
    Textbox(int size, sf::Color color, bool sel, sf::Vector2f position, sf::Color defaultColor) {
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        isSelected = sel;
        if (sel) {
            textbox.setString("_");
        }
        else {
            textbox.setString("");
        }

        rect.setOrigin({15, 25});
        rect.setPosition(position);
        rect.setFillColor(defaultColor);
        rect.setOutlineThickness(2);
        rect.setOutlineColor(sf::Color(20, 20, 20));
    }

    void setFont(sf::Font &Font) {
        textbox.setFont(Font);
    }

    void setPosition(sf::Vector2f pos) {
        textbox.setPosition(pos);
    }

    void C_setPos(float posX, float posY) { rect.setSize({posX, posY}); }

    void setLimit(bool ToF) {
        hasLimit = ToF;
    }

    void setLimit(bool ToF, int lim) {
        hasLimit = ToF;
        limit = lim;
    }

    void setSelected(bool sel) {
        isSelected = sel;
        if (!sel) {
            textbox.setString(text);
        } else {
            textbox.setString(text + "_");
        }
    }

    std::string getText() { return text; }

    void drawTo(sf::RenderWindow &window) {
         window.draw(rect);
         window.draw(textbox); 
    }

    void typedOn(sf::Event input) {
        if (isSelected) {
            auto charTyped = input.text.unicode;
            if (charTyped < 128)
            {
                if (!hasLimit || (hasLimit && text.length() < limit) || charTyped == DELETE) {
                    inputLogic(charTyped);
                }
            }
        }
    }

    void RoundedTriangle();
};

#endif

