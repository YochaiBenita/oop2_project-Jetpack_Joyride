#include "CollisionHandling.h"
//#include <runtime_error>
#include <stdexcept>
#include "Coin.h"
//#include "Missile.h"
//#include "Laser.h"
#include "Scientists.h"
#include "Gshield.h"
#include "Gspeed.h"
#include "Gmoney.h"
#include "Gpower.h"
#include "Controller.h"

bool CollisionHandling::processCollision(Player& player, Object& obj)
{
    auto colideFunc = lookup(typeid(obj));
    if (!colideFunc)
    {
        throw std::runtime_error("unknown collision!");
    }
	return colideFunc(player, obj);
}

HitFunctionPtr CollisionHandling::lookup(const std::type_index& obj)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(obj);
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

HitMap CollisionHandling::initializeCollisionMap()
{
    static HitMap colideMap;
    colideMap[typeid(Coin)] = &coinCollision;
    //colideMap[typeid(Missile)] = &missileCollision;
    //colideMap[typeid(Laser)] = &laserCollision;
    colideMap[typeid(Scientists)] = &scientistCollision;
    colideMap[typeid(Gshield)] = &shieldCollision;
    colideMap[typeid(Gspeed)] = &speedCollision;
    colideMap[typeid(Gmoney)] = &moneyCollision;
    colideMap[typeid(Gpower)] = &powerCollision;

    return colideMap;
}

bool CollisionHandling::coinCollision(Player& player, Object& obj)
{
    Controller::addToCoins();
    return true;
}

bool CollisionHandling::scientistCollision(Player&, Object&)
{
    return false;
}

bool CollisionHandling::shieldCollision(Player&, Object&)
{
    //change texture?
    return true;
}

bool CollisionHandling::speedCollision(Player&, Object&)
{
    //more speed
    return true;
}

bool CollisionHandling::moneyCollision(Player&, Object&)
{
    //piggy with money
    return true;
}

bool CollisionHandling::powerCollision(Player&, Object&)
{
    //change texture and jump?
    return true;
}
