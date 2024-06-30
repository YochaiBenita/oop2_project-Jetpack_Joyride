#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingGameObjects.h"
#include "State/PlayerAnimationState.h"



class Player:public MovingGameObjects {
public:
	Player();
	virtual ~Player() {};
	virtual float getHeight() const;
	void setState(std::unique_ptr<PlayerAnimationState>);
	void update(float);
	void playerDie();
	bool avoidCollisions()const;
	void setAvoidStatus(bool);
	virtual void draw(sf::RenderWindow&)const override;
	//virtual sf::Vector2f getPosition() const {};
	virtual void move(sf::Vector2f v2f) override { MovingGameObjects::move(v2f); };
	virtual void move(float x) override { MovingGameObjects::move(x); };


	
private:
	std::unique_ptr<PlayerAnimationState> m_currentState;
	bool m_avoidCollisions = false;
	float moveSpeed = 200.0f;
};