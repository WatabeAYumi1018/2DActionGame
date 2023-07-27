#pragma once
#include "../../engine/GameEngine.h"
#include "Character.h"


class Enemy :public Character {

public:
	Enemy(Vector3 pos);
	~Enemy();

private:
	//-----�����o�ϐ�-----//
	eAttackType m_eAttackType;		//�A�^�b�N�^�C�v�^�O����p

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw() override;
	void Finalize() override;
};

