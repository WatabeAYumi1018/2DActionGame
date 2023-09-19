#pragma once
#include "../engine/GameEngine.h"
#include "../game/SceneAll/GameObject.h"

class Camera;
class Player;

//UI�̏����ꊇ���s���N���X
class UI : public GameObject
{
public:
	UI(Player* player);
	virtual ~UI() {}

private:
	//-----�����o�ϐ�-----//
	int m_extend_x = 500;
	int m_extend_y = 200;

	int m_hp_hdl = 0;

	Player* m_player = nullptr;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Draw(float delta_time, const Camera* camera) override;
	void HpBalloons();
};
