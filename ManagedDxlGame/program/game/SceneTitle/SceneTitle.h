#pragma once
#include "../../engine/sceneBase.h"
#include "../SceneAll/Balloon.h"

class GameObject;

class SceneTitle : public SceneBase {

private:
	//-----�����o�ϐ�-----//
	int m_back_hdl = 0;
	int m_logo_hdl = 0;
	int m_palloon_hdl = 0;
	int m_bounceCount = 0;								// �o�E���h������

	float m_current_width = 0;
	
	tnl::Vector3 m_chara_pos = { 0,-360,0 };			// �C���X�g�̏���Y�ʒu�B��ʊO�㕔�ɐݒ�
	tnl::Vector3 m_velocity = {0,1.0f,0};					// �����̉������̑��x
	tnl::Vector3 m_gravity = {0,0.1f,0};				// �d�͂̋���

	bool m_is_logo_displayed = false;

	const int m_maxBounce = 2; // �ő�o�E���h��
	const float m_ground_y = 50;		// �n�ʂ�Y�ʒu
	const float m_bounceRate = -1.0f;					// �o�E���h���̑��x�̌�����
	const float m_display_time = 100;

	std::vector<Balloon> balloons; // �o���[���̔z�� 

	tnl::Sequence<SceneTitle> sequence_ = tnl::Sequence<SceneTitle>(this, &SceneTitle::SeqIdle);

public:
	//-----�����o�֐�-----//
	void Update(float delta_time) override;
	void Draw(float delta_time) override;

private:

	bool SeqIdle(float delta_time);
	void logoHandle(float delta_time);
	void bounceHandle(float delta_time);
	void SpawnBalloon();
};
