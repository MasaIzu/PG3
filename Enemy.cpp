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
	printf("�ߐڍU��\n");
}

void Enemy::Shooting()
{
	printf("�ˌ��U��\n");
}

void Enemy::Secession()
{
	printf("���E\n");
}

void (Enemy::* Enemy::pFunc[])() = {
		&Enemy::Proximity, // �v�f�ԍ� 0
		&Enemy::Shooting,  // �v�f�ԍ� 1
		&Enemy::Secession  // �v�f�ԍ� 2
};