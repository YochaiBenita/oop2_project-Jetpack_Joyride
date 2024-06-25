#include "Command/CommandInterface.h"
#include "Menu.h"
#include "Resources.h"

CommandInterface::CommandInterface(Menu* menu, std::string name)
	:m_menu(menu), m_name(name, *Resources::getInstance().getFont(), 40)
{
	m_sp.setTexture(*Resources::getInstance().getTextureButtons(0));
}

//void CommandInterface::setSptire(sf::Vector2f pos, int index)
//{
//	m_sp.setTexture(*Resources::getInstance().getTextureButtons(index));
//	m_sp.setOrigin({m_sp.getGlobalBounds().width / 2 ,m_sp.getGlobalBounds().height / 2 });
//	m_sp.setPosition(pos);
//}

void CommandInterface::setPosition(sf::Vector2f pos)
{
	m_sp.setOrigin({ m_sp.getGlobalBounds().width / 2 ,m_sp.getGlobalBounds().height / 2 });
	m_sp.setPosition(pos);

	m_name.setOrigin({ m_name.getGlobalBounds().width / 2 ,m_name.getGlobalBounds().height / 2 });
	m_name.setPosition(pos);
}

bool CommandInterface::contains(sf::Vector2f v2p)
{
	return m_sp.getGlobalBounds().contains(v2p);
}

void CommandInterface::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_sp);
	wind.draw(m_name);
}


