#pragma once
#include "../../game/ScenePlay/Character/Player/Player.h"
#include "../engine/GameEngine.h"
#include "../game/SceneAll/GameObject.h"

class Camera;
class Balloon;

//UI�̏����ꊇ���s���N���X
class UI : public GameObject
{
public:
	UI();
	virtual ~UI() {}

private:
	//-----�����o�ϐ�-----//
	int m_ui_hdl = 0;
	int m_extend_x = 500;
	int m_extend_y = 200;

	Player m_player;
	Balloon* m_balloon = nullptr;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Draw(float delta_time, const Camera* camera) override;
	void HpBalloons();
};
