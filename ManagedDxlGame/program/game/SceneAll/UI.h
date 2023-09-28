#pragma once
#include "../engine/GameEngine.h"
#include "../game/SceneAll/GameObject.h"

class Camera;
class Player;
class Enemy;

//UI�̏����ꊇ���s���N���X
class UI : public GameObject
{
public:
	UI(Player* player,Enemy* enemy);
	virtual ~UI() {}

private:
	//-----�����o�ϐ�-----//
	int m_extend_x = 500;
	int m_extend_y = 200;

	int m_hp_player_hdl = 0;
	int m_hp_boss_hdl = 0;

	bool m_is_draw = false;

	Player* m_player = nullptr;
	Enemy* m_enemy = nullptr;

public:
	
	//-----�����o�֐�-----//
	void Initialize() override;
	void Draw(float delta_time, const Camera* camera) override;
	
	void HpPlayerBalloons();
	void HpBossBallons();

	//-----Getter,Setter-----//

	void SetIsDraw(bool is_draw) { m_is_draw = is_draw; }
};
