# pragma once
#include "State/PlayerAnimationState.h"
#include "State/JumpAnimationPlayerState.h"
#include "Resources.h"

class Player;
class WalkAnimationPlayerState : public PlayerAnimationState {
public:
    virtual void enter(Player*) = 0;
    virtual void update(Player*, float) = 0;
    //virtual void draw(Player*, sf::RenderWindow&) override;
   // virtual void jump(Player*) = 0;
    //virtual void walk(Player*) override {};

private://����� �� ������ ������ �����
    //std::vector<sf::IntRect> m_walkFrames;
    //int m_currentFrame;
    //float m_frameTime;
    //float m_elapsedTime;
    //bool m_forward = true;
};