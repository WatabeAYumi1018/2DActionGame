#pragma once
#include "../../engine/GameEngine.h"
#include "Character.h"

//��ɓG��AI���Ǘ�����N���X

class Enemy :public Character {

public:
	Enemy();
	virtual ~Enemy();

private:
	//-----�����o�ϐ�-----//
	eAttackType m_eAttackType;		//�A�^�b�N�^�C�v�^�O����p

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;
};