#include <windows.h>
#include "Enemy.h"

int main() {
	Enemy* enemy = new Enemy;

	// 初期化処理
	enemy->Initialize();

	while (true)
	{
		// 更新処理
		enemy->Update();

		// スリープ
		Sleep(1.2 * 1000);
	}

	system("pause");
	return 0;
}