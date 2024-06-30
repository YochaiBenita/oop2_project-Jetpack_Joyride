#include "CollisionHandling.h"
//#include <runtime_error>
#include <stdexcept>
#include "Coin.h"
#include "Objects/Missile.h"
#include "Objects/Laser.h"
#include "Scientists.h"
#include "Objects/Light.h"
#include "Gshield.h"
#include "Gspeed.h"
#include "Gmoney.h"
#include "Gpower.h"
#include "Controller.h"
#include "State/TankJumpState.h"
#include "State/TankWalkState.h"
//#include "State/DeadPlayerState.h"
#include <iostream>
#include "Resources.h"
#include <SFML/Audio.hpp>


sf::Sound CollisionHandling::m_currSound;

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
    colideMap[typeid(Missile)] = &missileCollision;
    colideMap[typeid(Laser)] = &laserCollision;
    colideMap[typeid(Scientists)] = &scientistCollision;
    colideMap[typeid(Gshield)] = &shieldCollision;
    colideMap[typeid(Gspeed)] = &speedCollision;
    colideMap[typeid(Gmoney)] = &moneyCollision;
    colideMap[typeid(Gpower)] = &powerCollision;
    colideMap[typeid(Light)] = &lightCollision;

    return colideMap;
}

bool CollisionHandling::coinCollision(Player& player, Object& obj)
{
    Controller::addToCoins();
    play_sound(Resources::getInstance().getSoundBuffer(CoinSound_t));
    return true;
}

bool CollisionHandling::missileCollision(Player& player, Object& obj)
{
    std::cout << "missile\n";
    play_sound(Resources::getInstance().getSoundBuffer(MissileHitSound_t));
    player.playerDie();
    return true;
}

bool CollisionHandling::laserCollision(Player& player, Object& obj)
{

    std::cout << "laser Collision\n";
    play_sound(Resources::getInstance().getSoundBuffer(LaserHitSound_t));
    player.playerDie();
    //player.setState(std::make_unique<DeadPlayerState>());
    return true;
   /* if (Laser* laser = dynamic_cast <Laser*>(&obj))
    {
        return pixelPerfectCollision(player.getSprite(), laser->getSprite());
    }*/
    //else exep
   
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

bool CollisionHandling::moneyCollision(Player&, Object& obj)
{
    play_sound(Resources::getInstance().getSoundBuffer(PiggySound_t));

    Gmoney& gift = dynamic_cast<Gmoney&> (obj);
 
    Controller::addToCoins(gift.getValue());
    return true;
}

bool CollisionHandling::powerCollision(Player& player, Object&)
{
    // adding random between all options
    

    //change texture and jump?
    play_sound(Resources::getInstance().getSoundBuffer(PowerSound_t));
    player.setState(std::make_unique<TankJumpState>());
    
    return true;
}

bool CollisionHandling::lightCollision(Player&, Object&)
{
    return false;
}

void CollisionHandling::play_sound(const sf::SoundBuffer* sound)
{
    m_currSound.setBuffer(*sound);
    m_currSound.play();
}

//bool CollisionHandling::pixelPerfectCollision(const sf::Sprite& player, const sf::Sprite& laser)
//{
//    sf::Image playerImage = player.getTexture()->copyToImage();
//    sf::Image laserImage = laser.getTexture()->copyToImage();
//
//    sf::FloatRect playerRect = player.getGlobalBounds();
//    sf::FloatRect laserRect = laser.getGlobalBounds();
//
//    // ����� ����� ��� ��� �-sprites
//    sf::FloatRect intersection;
//    if (playerRect.intersects(laserRect, intersection)) {
//        for (int x = intersection.left; x < intersection.left + intersection.width; x++) {
//            for (int y = intersection.top; y < intersection.top + intersection.height; y++) {
//                // ����������� ����� ����� ������
//                int xPlayer = x - playerRect.left;
//                int yPlayer = y - playerRect.top;
//                int xLaser = x - laserRect.left;
//                int yLaser = y - laserRect.top;
//
//                // ����� ������ ��������
//                if (xPlayer >= 0 && xPlayer < playerImage.getSize().x && yPlayer >= 0 && yPlayer < playerImage.getSize().y &&
//                    xLaser >= 0 && xLaser < laserImage.getSize().x && yLaser >= 0 && yLaser < laserImage.getSize().y)
//                {
//                    if (playerImage.getPixel(xPlayer, yPlayer).a != 0 && laserImage.getPixel(xLaser, yLaser).a != 0) 
//                    {
//                        std::cout << "collision pixel" << std::endl;
//                        return true; // �� �������
//                    }
//                }
//               
//            }
//        }
//    }
//    return false;
//}
