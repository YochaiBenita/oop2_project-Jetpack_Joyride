#include "Board.h"
#include <iostream>
Board::Board()
{
	m_objects.clear();
	readLevel();
	readLevel();
}

void Board::play(sf::RenderWindow& wind, float timer, float delta_time)
{
	if (auto event = sf::Event(); wind.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Space)
		{
			//flyyyyyyyyyy
		}
		else
		{
			//walk
		}
	}

	//cheack collision
	std::for_each(m_objects.begin(), m_objects.end(), [&](auto &obj) {obj->move_and_change_sprite(delta_time, &m_player); });

	moveBackground(delta_time, wind);
	if (m_objects.size() < MIN_AMOUNT)
	{
		readLevel();
	}
}

void Board::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_player.getDrawable());//���� �� ������ ����� ��� �����, ����� �� ��� ���.
	std::for_each(m_objects.begin(), m_objects.end(), [&wind](auto &obj) {wind.draw(obj->getDrawable()); });

}

bool Board::checkCollision()
{
	return false;
}

void Board::readLevel()
{
}

bool Board::alive() const
{
	return true;
}

void Board::moveBackground(float delta_time, sf::RenderWindow& wind) //�����. ���� �����
{
	// ���� �������� �� ����
	auto background = Resources::getInstance().getBackground(1);
	sf::Vector2u backgroundSize = background->getSize();
	sf::Sprite sprite;
	sprite.setTexture(*background);
	float scrollSpeed = 200.f;

	// ����� ����� ������� ������ �� ������ ������ ����� ����
	static float offsetX = 0.f;
	offsetX += scrollSpeed * delta_time;

	// �� ����� ����� �� ���� ����, ����� ����
	if (offsetX >= backgroundSize.x)
		offsetX -= backgroundSize.x;

	// ���� �� ���� ������
	for (float i = -offsetX; i < wind.getSize().x; i += backgroundSize.x)
	{
		for (unsigned int j = 0; j < wind.getSize().y; j += backgroundSize.y)
		{
			sprite.setPosition(i, j);
			wind.draw(sprite);
		}
	}
}
