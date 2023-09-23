#pragma once
#include "../../engine/sceneBase.h"
#include "../SceneAll/Music/MusicManager.h"
#include "../SceneAll/Balloon.h"

class GameObject;

class SceneTitle : public SceneBase 
{
private:

	//-----�萔-----//
	const int MAX_BOUNDE = 2; // �ő�o�E���h��
	const float GROUND_Y = 50;		// �n�ʂ�Y�ʒu
	const float BOUND_RATE = -1.0f;					// �o�E���h���̑��x�̌�����
	const float DISPLAY_TIME = 100;
	const int BALLOON_SPAWN = 20; // �o���[���̐�����
	const float SPAWN_INTERVSL = 0.5f; //�o���[�������Ԋu

	//-----�����o�ϐ�-----//
	int m_back_hdl = 0;
	int m_logo_hdl = 0;
	int m_palloon_hdl = 0;
	
	int m_bound_count = 0;								// �o�E���h������
	
	float m_current_width = 0;
	float m_balloon_spawn_timer = 0.0f;

	tnl::Vector3 m_chara_pos = { 0,-360,0 };			// �C���X�g�̏���Y�ʒu�B��ʊO�㕔�ɐݒ�
	tnl::Vector3 m_velocity = {0,1.0f,0};					// �����̉������̑��x
	tnl::Vector3 m_gravity = {0,0.1f,0};				// �d�͂̋���

	bool m_is_logo_displayed = false;

	std::vector<Balloon> balloons; // �o���[���̔z�� 

	MusicManager m_musicManager;

	tnl::Sequence<SceneTitle> sequence_ = tnl::Sequence<SceneTitle>(this, &SceneTitle::SeqIdle);

public:
	//-----�����o�֐�-----//
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;

private:

	bool SeqIdle(float delta_time);
	void LogoHandle(float delta_time);
	void BoundHandle(float delta_time);
	void SpawnBalloon();
};
