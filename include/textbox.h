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
    sf::RectangleShape cursor;
    sf::Text textbox;
    std::string text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;
    std::size_t LimperLine = 20;
    sf::Font font;
    float rectSX = 0, rectSY = 10;
    sf::Clock cursorClock;
    bool cursorVisible = true;
    
    void inputLogic(char charTyped) {
        if (charTyped != DELETE && charTyped != ENTER && charTyped != ESCAPE) {
            text += charTyped;
            this->setLimit(100);
        }
        else if(charTyped == ENTER) {
            text += "\n";
        }

        else if(charTyped == DELETE) {
            bool ctrlHeld = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
            if(ctrlHeld) {
             if(!text.empty() && text.length() != 1 && text.back() == '\n') {deleteLastChar();}
             else if(text.length() != 0) {
                while ((!text.empty() && text.back() == ' ' )) {deleteLastChar();} //Remove trailing spaces
                while ((!text.empty() && text.back() != ' ' ) && text.back() != '\n')
                    {deleteLastChar();} //Remove words
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
        isSelected = sel; //TODO: When multiple stuffs have been added add a selection cursor
        
        cursor.setSize({2.f, (float)size});      // width, height
        cursor.setFillColor(sf::Color::White);
        cursor.setPosition(position);

        rect.setOrigin({position});
        rect.setPosition(position);
        rect.setFillColor(defaultColor);
        rect.setOutlineThickness(2);
        rect.setOutlineColor(sf::Color(20, 20, 20));
        rect.setSize(sf::Vector2f(20.f, 15.f));

        textbox.setPosition(position);
    }

    void setFont(sf::Font &Font) {
        textbox.setFont(Font);
    }

    void C_setsize(float sX, float sY) { rect.setSize({sX, sY}); }

void setLimit(int lim)
{
    if (text.empty())
        return;

    // find last line break
    size_t lastNewline = text.find_last_of('\n');

    // compute current line length
    size_t currentLineLength;

    if (lastNewline == std::string::npos)
        currentLineLength = text.length();
    else
        currentLineLength = text.length() - lastNewline - 1;

    // wrap condition
    if (currentLineLength >= (size_t)lim)
    {
        text += '\n';
        //adjust rect size
        rectSY += 5;
            sf::Vector2f buffer = {rectSX, rectSY};
            rect.setSize(buffer);
    }
}

    void setSelected(bool sel) {
        isSelected = sel;
        if (!sel) {
            textbox.setString(text);
        } else {
            textbox.setString(text + "_");
        }
    }
    void update() {
        if (!isSelected)
            return;

        if (cursorClock.getElapsedTime().asSeconds() >= 0.5f)
        {
            cursorVisible = !cursorVisible;   // Toggle true <-> false
            cursorClock.restart();
        }
    }

    std::string& getText() { return text; }

    void drawTo(sf::RenderWindow &window) {
         window.draw(rect);
         window.draw(textbox);
         if (cursorVisible)
             window.draw(cursor);
    }

    void typedOn(sf::Event input) {
        if (isSelected) {
            auto charTyped = input.text.unicode;
            if (charTyped < 128)
            {
                if (!hasLimit || charTyped == DELETE)
                {
                    inputLogic(charTyped);
                    hasLimit = false;
                }
            }
        }
    }

    void RoundedTriangle();
    void AdjustRectBounds(float padding) {
        sf::FloatRect bounds = textbox.getLocalBounds();

     if(bounds.height < 350) {
        rect.setSize({
            bounds.width + padding * 2,
            bounds.height + padding * 2
        });
     } else
         hasLimit = true;

        //Update cursor
        sf::Vector2f pos = textbox.findCharacterPos(text.size());
        cursor.setPosition(pos.x, pos.y);

    }
};

#endif

