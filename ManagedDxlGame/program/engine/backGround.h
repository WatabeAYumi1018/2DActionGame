#pragma once
#include "GameEngine.h"

class PlayCamera;

//�w�i��`�悷��
//�V�[�����ƂɕʁX�̔w�i�����[�h�A�`�悷��̂݁B
//�\���̂Ƃ��Ĉ����A�A�N�Z�X��e�Ղɂ���

class BackGround{

public:
	BackGround() { Initialize();}
	virtual ~BackGround() {}

private:
	//-----�����o�ϐ�-----//
	tnl::Vector3 m_pos = { 0,0,0 };
	int m_back_hdl = 0;

public:
	//-----�����o�֐�-----//
	void Initialize();
	void Draw(const PlayCamera* camera);
};
