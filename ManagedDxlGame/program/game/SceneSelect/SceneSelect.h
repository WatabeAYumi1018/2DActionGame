#pragma once
#include "../../engine/sceneBase.h"


class GameObject;

class SceneSelect : public SceneBase {

private:

	//-----�����o�ϐ�-----//
	int m_back_hdl = 0;
	int m_stage1_hdl = 0;
	int m_stage2_hdl = 0;
	int m_stage3_hdl = 0;
	int m_boss_hdl = 0;

	int m_selected_stage = 0; // �I������Ă���X�e�[�W (0: stage1, 1: stage2, ...)
	float m_balloon_timer = 0.0f; // �I������Ă��镗�D�̏㉺�̃^�C�}�[
	float m_balloon_offset_y = 10.0f; // �I������Ă��镗�D�̏㉺�I�t�Z�b�g
	float m_balloon_velocity_y = 100.0f; // �I������Ă��镗�D�̏㉺�̑��x
	
	tnl::Sequence<SceneSelect> sequence_ = tnl::Sequence<SceneSelect>(this, &SceneSelect::SeqIdle);

public:
	//-----�����o�֐�-----//
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;

private:

	bool SeqIdle(float delta_time);
	void MoveBalloon(float delta_time);
};

