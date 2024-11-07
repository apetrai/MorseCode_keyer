#ifndef TEXTBOX
#define TEXTBOX

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>

/*Predefine Keys*/
#define DELETE 8
#define ENTER 13
#define ESCAPE 27

class Textbox {
	private:
		sf::Text textbox;
		std::ostringstream text;
		bool isSelected = false;
		bool hasLimit = false;
		int limit;



	void inputLogic(sf::Uint32 charTyped) {
			if(charTyped != DELETE && charTyped != ENTER && charTyped != ESCAPE) {
				text << static_cast<char>(charTyped);
			} else if (charTyped == DELETE) {
				if(text.str().length() > 0) {
					deleteLastChar();
				}
			}
			textbox.setString(text.str()); //Text bar to see if textbox is  selected.
	}
	void deleteLastChar() {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < (t.length() - 1); i++)
		{
			newT += t[i];
		}
		text.str("");
		text << newT;
		textbox.setString(text.str());
	}

	public:
		Textbox() {}
		Textbox(int size, sf::Color color, bool sel) {
			textbox.setCharacterSize(size);
			textbox.setColor(color);
			isSelected = sel;
			if (sel) {
				textbox.setString("_");
			} else {
				textbox.setString("");
			}
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
				std::string t = text.str();
				std::string newT = "";
				for (int i = 0; i < t.length() - 1; i++)
				{
					newT += t[i];
				}
				textbox.setString(newT);
			}
		}
		std::string getText() { return text.str(); }
		void drawTo(sf::RenderWindow &window) { window.draw(textbox); }
		void typedOn(sf::Event input) {

			if(isSelected) {
				auto charTyped = input.text.unicode;
				
				if (charTyped < 128)
				{
					if (hasLimit) {
						if (text.str().length() <= limit) {
							inputLogic(charTyped);
						} else if (text.str().length() > limit && charTyped == DELETE) {
							deleteLastChar();
						} else {
							inputLogic(charTyped);
						}
					}
				}
			}
		}
};

#endif
