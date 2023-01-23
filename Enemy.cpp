#include "Enemy.h"
#include <stdio.h>



Enemy::Enemy()
{
	phaseNum = 0;
}

void Enemy::Initialize()
{
	phaseNum = 0;
}

void Enemy::Update()
{
	(this->*pFunc[phaseNum])();
	phaseNum++;
	if (phaseNum > 2) {
		phaseNum = 0;
	}
}

void Enemy::Proximity()
{
	printf("‹ßÚUŒ‚\n");
}

void Enemy::Shooting()
{
	printf("ËŒ‚UŒ‚\n");
}

void Enemy::Secession()
{
	printf("—£’E\n");
}

void (Enemy::* Enemy::pFunc[])() = {
		&Enemy::Proximity, // —v‘f”Ô† 0
		&Enemy::Shooting,  // —v‘f”Ô† 1
		&Enemy::Secession  // —v‘f”Ô† 2
};