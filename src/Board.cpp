#include "Board.h"
#include "JumpAnimationPlayerState.h"
#include "WalkAnimationPlayerState.h"
#include <iostream>
#include <fstream>
#include <memory>
#include "ObjectFactory.h"
#include "Gift.h";
#include "Gshield.h";
#include "Gspeed.h";
#include "Gpower.h";
#include "Gmoney.h";
#include "Utilities.h"



Board::Board()
{
	m_objects.clear();
	m_player = std::make_unique<Player>();

}

void Board::play(sf::RenderWindow& wind, float timer, float delta_time)//���� �� ��� �� ����� ��� ����
{

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//{
	//	//m_player->jump();
	//}

	m_player->update(delta_time);

	//check collision

	//std::for_each(m_objects.begin(), m_objects.end(), [&](auto &obj) {if (obj!=nullptr) obj->move_and_change_sprite(delta_time, &(*m_player)); });

	m_objTimer -= delta_time;

	if (m_objTimer < 0)
	{
		readLevel(wind);
		m_objTimer = 1;
	}

	int xView = wind.getView().getCenter().x - SCREEN_SIZE.x;
	m_objects.remove_if(outOfView(xView));

}

void Board::draw(sf::RenderWindow& wind) const
{

	std::for_each(m_objects.begin(), m_objects.end(), [&wind](auto& obj)  { /*if (obj != nullptr)*/ obj->draw(wind); });
	
	m_player->draw(wind);
	//wind.draw(m_player->getDrawable());
	//std::for_each(m_objects.begin(), m_objects.end(), [&wind](auto &obj) {if (obj != nullptr) wind.draw(obj->getDrawable()); });

}

bool Board::checkCollision()
{
	return false;
}

void Board::readLevel(sf::RenderWindow& wind)
{
	auto x = wind.getView().getCenter().x + SCREEN_SIZE.x;

	m_objects.push_back(ObjectFactory::create(Coin_t, x, 500));
	//m_objects.push_back(ObjectFactory::create(Gmoney_t, x, 500));

	m_objects.push_back(ObjectFactory::create(Gspeed_t, x, 350));
	m_objects.push_back(ObjectFactory::create(Gshield_t, x, 300));
	m_objects.push_back(ObjectFactory::create(Gmoney_t, x, 550));
	m_objects.push_back(ObjectFactory::create(Gpower_t, x, 450));

	m_objects.push_back(ObjectFactory::create(Scientists_t, x, 600));

	/*switch (rand() % NUM_OF_GIFTS)
	{
	case 0:
		m_objects.push_back(ObjectFactory::create(Gmoney_t, x, 350));
		break;
	case 1:
		m_objects.push_back(ObjectFactory::create(Gpower_t, x, 450));
		break;
	case 2:
		m_objects.push_back(ObjectFactory::create(Gshield_t, x, 400));
		break;
	case 3:
		m_objects.push_back(ObjectFactory::create(Gspeed_t, x, 350));
		break;
	}*/



	////for now the func will read level from txt file, hopfully 
	////the game will ganarate its levels
	//char c;
	//auto file = std::ifstream("level.txt");
	//int col = 0;
	//int row = 0;

	//while (file.get(c))
	//{
	//	if (c == '\n')
	//	{
	//		row = 0;
	//		col++;
	//		continue;
	//	}

	//	else if (c != '-')
	//	{
	//		auto temp = ObjectFactory::create(c);
	//		if (temp != nullptr) {
	//			m_objects.push_back(std::move(temp));
	//		}
	//		
	//	}
	//	row++;
	//}
}

bool Board::alive() const
{
	return true;
}

sf::Vector2f Board::getPlayerLoc() const
{
	return m_player->getPosition();
}

//void Board::deleteObjects(sf::RenderWindow& wind)
//{
//	int xView = wind.getView().getCenter().x - SCREEN_SIZE.x;
//
//	for (auto& obj : m_objects) 
//	{
//		if (obj->getPosition().x < xView) {
//
//		}
//
//	}
//
//	
//
//	for (int i = 0; i < m_objects.size(); i++) {
//		{
//
//		}
//	}
//}

