#include "Enemy.h"
#include <stdio.h>
#include <stdlib.h>

bool Enemy::IsEnemyAlive;

void Enemy::Initialize() {

}

void Enemy::Update()
{
	system("cls");
	if (IsEnemyAlive == false) {
		printf("敵は生きている\n");
	}
	else if (IsEnemyAlive == true) {
		printf("敵は倒された\n");
	}
}

void Enemy::Draw() {

}