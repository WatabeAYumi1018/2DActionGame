#pragma once
#include "../../engine/GameEngine.h"

//�v���C���[�Ǐ]�J����

class Character;
class MapManager;

class PlayCamera
{
private:

	//-----�����o�ϐ�-----//
	tnl::Vector3 m_target = { 0, 0, 0 };
	bool is_active = false;

public:
	
	//-----�����o�֐�-----//
	void Update(float delta_time, Character* chara, MapManager* mapChip);

private:
	
	void MoveRange(Character* chara, MapManager* mapChip);
	void Scroll(Character* chara, MapManager* mapChip);

public:

	//-----Getter&Setter-----//
	tnl::Vector3 GetTarget() const { return m_target; }
	void SetTarget(tnl::Vector3 target) { m_target = target; }
};

