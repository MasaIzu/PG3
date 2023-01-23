#include "GameScene.h"
#include <stdlib.h>

GameScene::~GameScene()
{
	delete enemy;
	delete enemy2;
	delete enemy3;
}

void GameScene::Initialize()
{
	enemy->Initialize();
	enemy2->Initialize();
	enemy3->Initialize();
}

void GameScene::Update()
{
	system("cls");
	printf("¶‚©‚·‚©ŽE‚·‚©A‘I‚ñ‚Å‚­‚¾‚³‚¢B\n‚P”Ô‚Ìê‡¶‚«Žc‚ç‚¹‚é\n‚Q”Ô‚Ìê‡“|‚·\n");
	scanf_s("%d", &deadOrALive);

	switch (deadOrALive)
	{
	case 1:// ¶‚«‚é
		Enemy::IsEnemyAlive = false;
		break;
	case 2:// Ž€‚Ê
		Enemy::IsEnemyAlive = true;
		break;
	default:// “K“–‚È‚Ì‚É‚È‚Á‚½‚çŽ€‚Ê
		Enemy::IsEnemyAlive = true;
		break;
	}

	enemy->Update();
	enemy2->Update();
	enemy3->Update();
}

void GameScene::Draw(){

}