#pragma once
#include"State/JumpAnimationPlayerState.h"

class RegularJumpState : public JumpAnimationPlayerState {
public:
    virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
        //virtual void draw(Player*, sf::RenderWindow&) override;
        //virtual void jump(Player*) override;

private:

};