#include "MovingObject.h"

MovingObject::MovingObject(object_code obj, sf::Vector2f loc)
	:Object(Resources::getInstance().getTextureObject(obj), loc, Resources::getInstance().getIntRect(obj))
{}