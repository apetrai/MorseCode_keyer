#ifndef MAIN_UI
#define MAIN_UI

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../src/MAIN_UI.cpp"

#define X 1000;
#define Y 1000;

#include <string>

using namespace sf;

namespace UI {
	class MAIN {
	public:
		struct Constraints {
			Vector2f WIN_SIZE = {}; //default initialised
		};
	public:
		constexpr inline void CreateTextBox() noexcept;
		inline void ChangeTextBox(RenderWindow& window, Constraints* constraints) noexcept;


	};
}


#endif //MAIN_UI