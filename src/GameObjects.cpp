#include "GameObjects.h"

GameObjects::GameObjects(object_code obj, sf::Vector2f loc)
	: Object(Resources::getInstance().getTextureObject(obj),
		loc,
		Resources::getInstance().getIntRect(obj))
{
	//m_sp.setTexture(*Resources::getInstance().getTextureObject(obj));
	//m_sp.setTextureRect(Resources::getInstance().getIntRect(obj));
	//m_sp.setPosition(loc);
	//m_sp.setOrigin(sf::Vector2f(0, Resources::getInstance().getIntRect(obj).height));
}

//sf::Vector2f GameObjects::getPosition() const
//{
//	return m_sp.getPosition();
//}

//void GameObjects::draw(sf::RenderWindow& wind) const
//{
//	wind.draw(m_sp);
//}

//void GameObjects::setSpriteRect(sf::IntRect rect)
//{
//	m_sp.setTextureRect(rect);
//}

void GameObjects::move(sf::Vector2f move)
{
	m_sp.move(move);
}