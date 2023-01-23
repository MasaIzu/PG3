#pragma once
#include <stdio.h>
#include "Enemy.h"

class GameScene
{

public:
	//�����o�֐�
	~GameScene();
	void Initialize();
	void Update();
	void Draw();
private:
	//�����o�ϐ�
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;

	int deadOrALive = 0;

};
