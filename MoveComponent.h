#pragma once
#include "Component.h"
#include "Game.h"
#include "CubeActor.h"

class MoveComponent : public Component
{
public:
	
	MoveComponent(class Actor* newOwner, int updateOrder = 10);
	void Update(float deltaTime) override;

	void Collided();

	void MoveEnemy();
	
	float GetHorizontalMove() const {
		return horizontalMove;
	}

	float GetVerticalMove() const {
		return verticalMove;
	}

	void SetHorizontalMove(float move) { 
		horizontalMove = move;
	}

	void SetVerticalMove(float move) {
		verticalMove = move;
	}

private:
	float horizontalMove;
	float verticalMove;
	Game* game;
	vector<class CubeActor*> enemies;
};