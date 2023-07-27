#pragma once
#include "Character.h"

class Enemy :public Character {

public:
	Enemy(Vector3 m_pos, Vector3 m_velocity);
	~Enemy();
	//-----�����o�ϐ�-----//

private:
	eAttackType m_eAttackType;		//�A�^�b�N�^�C�v�^�O����p

	//-----�����o�֐�-----//
public:
	void Initialize();
	void Update(float delta_time);
	void Draw();
	void Finalize();
};

