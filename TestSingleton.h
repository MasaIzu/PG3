#pragma once

class SceneManager final{
private:
	//コンストラクタをprivateにする
	SceneManager();
	//デストラクタをprivateにする
	~SceneManager();

public:
	//コピーコンストラクタを無効にする
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子を無効にする
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	void TitleScene();
	void NewGameScene();
	void GamePlayScene();
	void GameClear();

	void ChangeScene(int nextScene);

};