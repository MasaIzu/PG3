#pragma once
#include <stdio.h>
#include "Enemy.h"

class GameScene
{

public:
	//メンバ関数
	~GameScene();
	void Initialize();
	void Update();
	void Draw();
private:
	//メンバ変数
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;

	int deadOrALive = 0;

};
