#include <stdio.h>
#include <Windows.h>
#include "SceneManager.h"
int main() {
	
	SceneManager* sceneManager = SceneManager::GetInstance();
	int NowScene = 0;

	while (1) {
		if (NowScene > 3) {
			NowScene = 0;
		}

		sceneManager->ChangeScene(NowScene);
		NowScene++;
		Sleep(1 * 1000);
	}

	system("pause");
	return 0;

}