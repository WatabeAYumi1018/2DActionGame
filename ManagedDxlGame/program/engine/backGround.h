#pragma once
#include "GameEngine.h"

class PlayCamera;

//�w�i��`�悷��
//�V�[�����ƂɕʁX�̔w�i�����[�h�A�`�悷��̂݁B
//�\���̂Ƃ��Ĉ����A�A�N�Z�X��e�Ղɂ���

class BackGround
{
public:
	BackGround() { Initialize();}
	virtual ~BackGround() {}

private:
	//-----�����o�ϐ�-----//
	tnl::Vector3 m_pos = { 0,0,0 };
	int m_back_hdl = 0;
	//�X�N���[��(�t�B���^�[���������摜��ۑ�����p)�n���h��
	int m_screen_handle = 0;
	//���邳�N���b�v�t�B���^�[�Ɏg�p����臒l
	int m_bright_border = 0;

public:
	//-----�����o�֐�-----//
	void Initialize();
	void Draw(const PlayCamera* camera);
	void Movie(const PlayCamera* camera);
};
