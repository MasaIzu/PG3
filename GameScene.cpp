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
	printf("生かすか殺すか、選んでください。\n１番の場合生き残らせる\n２番の場合倒す\n");
	scanf_s("%d", &deadOrALive);

	switch (deadOrALive)
	{
	case 1:// 生きる
		Enemy::IsEnemyAlive = false;
		break;
	case 2:// 死ぬ
		Enemy::IsEnemyAlive = true;
		break;
	default:// 適当なのになったら死ぬ
		Enemy::IsEnemyAlive = true;
		break;
	}

	enemy->Update();
	enemy2->Update();
	enemy3->Update();
}

void GameScene::Draw(){

}