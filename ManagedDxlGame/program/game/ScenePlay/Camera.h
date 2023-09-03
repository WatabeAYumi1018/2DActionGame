#pragma once
#include "../../engine/GameEngine.h"

//�v���C���[�Ǐ]�J����

class Player;
class Map;

class Camera
{

private:

	//-----�����o�ϐ�-----//
	tnl::Vector3 m_target = { 0, 0, 0 };
	bool is_active = false;

public:
	
	//-----�����o�֐�-----//
	void Update(float delta_time, Player* player, Map* map);

private:
	
	void MoveRange(Player* player, Map* map);
	void Scroll(Player* player, Map* map);

public:

	//-----Getter&Setter-----//
	tnl::Vector3 GetTarget() const { return m_target; }
	void SetTarget(tnl::Vector3 target) { m_target = target; }
};

