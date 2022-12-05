#include "TestSingleton.h"
#include<stdio.h>

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
	//関数内static変数として宣言する
	static SceneManager instance;

	return &instance;
}

void SceneManager::TitleScene(){


}

void SceneManager::NewGameScene(){


}

void SceneManager::GamePlayScene(){


}

void SceneManager::GameClear(){


}

void SceneManager::ChangeScene(int nextScene){

	switch (nextScene){
	case 0:
		TitleScene();

		break;
	case 1:
		NewGameScene();

		break;
	case 2:
		GamePlayScene();

		break;
	case 3:
		GameClear();

		break;
	default:
		break;
	}

}
