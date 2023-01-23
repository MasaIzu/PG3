#pragma once
#include <stdio.h>
#include "Enemy.h"

class GameScene
{

public:
	//ƒƒ“ƒoŠÖ”
	~GameScene();
	void Initialize();
	void Update();
	void Draw();
private:
	//ƒƒ“ƒo•Ï”
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;

	int deadOrALive = 0;

};
