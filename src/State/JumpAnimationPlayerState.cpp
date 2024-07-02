#include "Resources.h"
#include "State/JumpAnimationPlayerState.h"
#include "Player.h"

JumpAnimationPlayerState::JumpAnimationPlayerState(Player* player, object_code code, std::string rectString)
{
    m_sp.setTexture(*Resources::getInstance().getTextureObject(code));
    m_frames = Resources::getInstance().getIntRect(rectString);

    m_sp.setTextureRect(m_frames->at(0));
    m_texutre_timer = 0;
    m_curr_frame = -1;

    animate(ANIMATION_RATE);

    //m_gravity = 400.0f;
}

void JumpAnimationPlayerState::update(Player* player, float deltaTime)
{
    //player->animate(deltaTime);
    animate(deltaTime);

    auto v2move = sf::Vector2f(deltaTime, deltaTime);

    // Update jump movement
    if ((player->getPosition().y - player->getHeight() + deltaTime * player->getVelocity()) < TOP_SCREEN_LIMIT) //add texture height
    {
        player->setVelocity(0);
    }
    else
    {
        //v2move.y = deltaTime;
        player->addVelocity(GRAVITY * deltaTime);
    }
    //change to member and calculate right speed



    player->move(v2move);

}

void JumpAnimationPlayerState::draw(const Player* player, sf::RenderWindow& wind)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        auto pos = player->getPosition();
        pos.x += getFlameOffset().x;
        pos.y += getFlameOffset().y;
        m_sp.setPosition(pos);

        wind.draw(m_sp);
    }

}

void JumpAnimationPlayerState::animate(float time)
{
    m_texutre_timer += time;

    if (m_texutre_timer >= ANIMATION_RATE)
    {
        m_texutre_timer -= ANIMATION_RATE;
        m_curr_frame = (m_curr_frame + 1) % m_frames->size();
        m_sp.setTextureRect(m_frames->at(m_curr_frame));
    }
}

