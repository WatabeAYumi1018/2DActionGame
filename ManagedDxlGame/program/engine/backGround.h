#pragma once
#include "GameEngine.h"

//�w�i��`�悷��
//�V�[�����ƂɕʁX�̔w�i�����[�h�A�`�悷��̂݁B
//�\���̂Ƃ��Ĉ����A�A�N�Z�X��e�Ղɂ���

struct BackGround{
	//-----�����o�ϐ�-----//
	int s_back_hdl = 0;
	tnl::Vector3 s_pos = { 0,0,0 };
	
	//-----�����o�֐�-----//
	void Initialize() {s_back_hdl = LoadGraph("image/backGround.png");}
	void Draw() {DrawGraph(s_pos.x, s_pos.y, s_back_hdl, TRUE);}
};
