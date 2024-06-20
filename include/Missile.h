#pragma once
#include <SFML/Graphics.hpp>
#include "MovingGameObjects.h"

class Missile:public MovingGameObjects {
public:
	//using StatedObject::collision;

	Missale(int, int);
	virtual ~Missile();
	void move_and_change_sprite(float, Object*);
	

	virtual bool collision(Object&)	override;
	virtual bool collision(Missile&)	override;
	//virtual bool collision(Cat&)	override;
	//virtual bool collision(Cheese&)	override;
	//virtual bool collision(Door&)	override;
	//virtual bool collision(Gift&)	override;
	//virtual bool collision(Key&)	override;

private:

};