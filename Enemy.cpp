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
		printf("“G‚Í¶‚«‚Ä‚¢‚é\n");
	}
	else if (IsEnemyAlive == true) {
		printf("“G‚Í“|‚³‚ê‚½\n");
	}
}

void Enemy::Draw() {

}