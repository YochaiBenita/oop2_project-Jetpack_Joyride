#include "State/TankWalkState.h"
#include "State/TankJumpState.h"
#include "Player.h"

TankWalkState::TankWalkState(Player* player)
{
	player->setNewSprite("walking tank", Tank_t);
}

void TankWalkState::update(Player* player, float delta_time)
{
	WalkAnimationPlayerState::update(player, delta_time);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		player->setState(std::make_unique<TankJumpState>(player));
	}
}
