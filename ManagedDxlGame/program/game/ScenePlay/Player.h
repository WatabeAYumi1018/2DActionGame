#pragma once
#include "Character.h"


class Player :public Character {

public:
	Player(Vector3 m_pos, Vector3 m_velocity);
	~Player();

	//-----�����o�ϐ�-----//
private:
	int m_dash;						//�_�b�V���X�s�[�h
	eAttackType m_eAttackType;		//�A�^�b�N�^�C�v�^�O����p
	Camera* m_camera = nullptr;		//�J����

	//-----�����o�֐�-----//
public:
	void Initialize();
	void Update(float delta_time);
	void Draw();
	void Finalize();

};