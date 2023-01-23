#include "GameScene.h"
#include <windows.h>

int main() {

	// 関数の宣言
	GameScene* gamescene_ = new GameScene;
	gamescene_->Initialize();

	// ゲームループ
	while (true) {

		// 更新処理
		gamescene_->Update();

		// 描画処理
		gamescene_->Draw();

		// スリープ
		Sleep(1 * 1000);
	}

	delete gamescene_;
	return 0;
}