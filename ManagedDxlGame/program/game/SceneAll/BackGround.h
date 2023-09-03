#pragma once
#include "../engine/GameEngine.h"

class Camera;

//�w�i��`�悷��
//�V�[�����ƂɕʁX�̔w�i�����[�h�A�`�悷��̂݁B
//�\���̂Ƃ��Ĉ����A�A�N�Z�X��e�Ղɂ���

class BackGround
{

public:
	BackGround();
	virtual ~BackGround();

private:
	//-----�����o�ϐ�-----//
	tnl::Vector3 m_pos = { 0,0,0 };
	float m_scroll_speed = 0.05f;
	int m_back_hdl = 0;

public:
	//-----�����o�֐�-----//
	void Initialize();
	void Draw(float delta_time, const Camera* camera);
	void Finalize();
};
