#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Controller.h"
#include "Command/CommandInterface.h"
#include <vector>

class Menu {
public:
	Menu();
	~Menu();
	void showMenu();
	void newGame();
	void highScore();
	void showHelp();

private:
	//sf::RectangleShape m_button[NUM_OF_BUTTONS_MENU];
	sf::RectangleShape m_background;
	sf::RenderWindow m_wind;
	Controller* m_controller;
	std::vector<std::unique_ptr<CommandInterface>> m_buttons;

	int handleClick(sf::Vector2f) const;
	//void drawButtons(sf::RenderWindow&) const;


};