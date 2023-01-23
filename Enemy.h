#pragma once
class Enemy
{
public:
	Enemy();

	void Initialize();
	void Update();
	void Proximity();
	void Shooting();
	void Secession();

private:
	// ƒƒ“ƒoŠÖ”ƒ|ƒCƒ“ƒ^
	static void (Enemy::* pFunc[])();
	int phaseNum = 0;
};