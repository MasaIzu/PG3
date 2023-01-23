#include "GameScene.h"

GameScene::~GameScene()
{
	delete enemy1;
	delete enemy2;
	delete enemy3;
}

void GameScene::Initialize()
{
	enemy1->Initialize();
	enemy2->Initialize();
	enemy3->Initialize();
}

void GameScene::Update()
{
	printf("���������E�����A�I��ł��������B\n�P�Ԃ̏ꍇ�����c�点��\n�Q�Ԃ̏ꍇ�|��\n");
	scanf_s("%d", &deadOrALive);

	switch (deadOrALive)
	{
	case 1:// ������
		Enemy::IsEnemyAlive = false;
		break;
	case 2:// ����
		Enemy::IsEnemyAlive = true;
		break;
	default:
		break;
	}

	enemy1->Update();
	enemy2->Update();
	enemy3->Update();
}

void GameScene::Draw(){

}