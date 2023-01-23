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
	default:// �K���Ȃ̂ɂȂ����玀��
		Enemy::IsEnemyAlive = true;
		break;
	}

	enemy->Update();
	enemy2->Update();
	enemy3->Update();
}

void GameScene::Draw(){

}