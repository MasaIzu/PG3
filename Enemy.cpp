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
		printf("�G�͐����Ă���\n");
	}
	else if (IsEnemyAlive == true) {
		printf("�G�͓|���ꂽ\n");
	}
}

void Enemy::Draw() {

}