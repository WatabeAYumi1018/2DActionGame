#pragma once
#include "../engine/GameEngine.h"
#include "GameObject.h"

class Camera;

//�w�i��`�悷��
//�V�[�����ƂɕʁX�̔w�i�����[�h�A�`�悷��̂݁B
//�\���̂Ƃ��Ĉ����A�A�N�Z�X��e�Ղɂ���

class BackGround : public GameObject
{

public:
	BackGround();
	virtual ~BackGround();

private:
	//-----�����o�ϐ�-----//
	float m_scroll_speed = 0.05f;
	int m_stage_hdl = 0;

public:
	//-----�����o�֐�-----//
	void SetBackground(const std::string& backgroundPath);

	void Initialize() override;
	void Draw(float delta_time, const Camera* camera) override;
	void Finalize() override;
};
