#pragma once
#include "Player.h"
#include "Object.h"
#include <map>
#include <typeindex>

typedef bool (*HitFunctionPtr)(Player&, Object&);//maybe we need to erase object
typedef std::map<std::type_index, HitFunctionPtr> HitMap;
//typedef (bool*)(Object&) HitFunctionPtr;

class CollisionHandling
{
public:
	static bool processCollision(Player&, Object&);//����� �� ���� ������ ����� ����������
private:
	static HitFunctionPtr lookup(const std::type_index&);
	static HitMap initializeCollisionMap();
	static bool coinCollision(Player&, Object&);
	//static bool missileCollision(Player&, Object&);
	static bool laserCollision(Player&, Object&);
	static bool scientistCollision(Player&, Object&);
	static bool shieldCollision(Player&, Object&);
	static bool speedCollision(Player&, Object&);
	static bool moneyCollision(Player&, Object&);
	static bool powerCollision(Player&, Object&);
	static bool lightCollision(Player&, Object&);
	//static bool pixelPerfectCollision(const sf::Sprite&, const sf::Sprite&);
	//static std::vector<uint8_t> createBitMask(const sf::Texture& texture) 


};