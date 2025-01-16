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

class Textbox {
public:
    sf::Text textbox;
    std::string text = "";
    bool isSelected = false;
    bool hasLimit = false;
    int limit;
    sf::Font font;

    void inputLogic(char charTyped) {
        if (charTyped != DELETE && charTyped != ENTER && charTyped != ESCAPE) {
            text += charTyped;
        }
        else if (charTyped == DELETE) {
            if (text.length() > 0) {
                deleteLastChar();
            }
        }
        else if(charTyped == ENTER) {
            text += "\n";
        }
        textbox.setString(text);
    }

    void deleteLastChar() {
        if (!text.empty()) {
            text.pop_back(); // Remove the last character directly
            textbox.setString(text);
        }
    }

public:
    Textbox() {}
    Textbox(int size, sf::Color color, bool sel, sf::Font &fnt) {
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        isSelected = sel;
        this->font = fnt;
        textbox.setFont(font);
    }

    void setFont(sf::Font &Font) {
        textbox.setFont(Font);
    }

    void setPosition(sf::Vector2f pos) {
        textbox.setPosition(pos);
    }

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

    void drawTo(sf::RenderWindow &window) { window.draw(textbox); }

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
};

#endif

