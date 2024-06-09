#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Scientists:public Moving_object {
public:
	using Moving_object::collision;

	Scientists(int, int);
	virtual ~Scientists();
	void move_and_change_sprite(float, Object*);


	virtual bool collision(Object&)	override;
	virtual bool collision(Scientists&)	override;
	//virtual bool collision(Cat&)	override;
	//virtual bool collision(Cheese&)	override;
	//virtual bool collision(Door&)	override;
	//virtual bool collision(Gift&)	override;
	//virtual bool collision(Key&)	override;

private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f,0.f);

};