#include "Enemy.h"
#include <stdio.h>

bool Enemy::IsEnemyAlive;

void Enemy::Initialize() {

}

void Enemy::Update()
{
	if (IsEnemyAlive == false) {
		printf("“G‚Í¶‚«‚Ä‚¢‚é\n");
	}
	else if (IsEnemyAlive == true) {
		printf("“G‚Í“|‚³‚ê‚½\n");
	}
}

void Enemy::Draw() {

}