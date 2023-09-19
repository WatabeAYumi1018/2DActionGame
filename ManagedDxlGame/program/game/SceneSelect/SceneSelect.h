#pragma once
#include "../../engine/sceneBase.h"


class GameObject;

class SceneSelect : public SceneBase 
{
public:

	SceneSelect();

private:

	//-----�萔-----//
	const int STAGE_NUM = 4; // �X�e�[�W�̐�

	//-----�����o�ϐ�-----//
	int m_back_hdl = 0;
	int m_stage1_hdl = 0;
	int m_stage2_hdl = 0;
	int m_stage3_hdl = 0;
	int m_boss_hdl = 0;

	int m_selected_stage = 0; // �I������Ă���X�e�[�W (0: stage1, 1: stage2, ...)
	float m_balloon_timer = 0.0f; // �I������Ă��镗�D�̏㉺�̃^�C�}�[
	float m_balloon_offset_y = 10.0f; // �I������Ă��镗�D�̏㉺�I�t�Z�b�g
	float m_balloon_velocity_y = 5.0f; // �I������Ă��镗�D�̏㉺�̑��x
	
	std::vector<std::string> m_stage_names; // �X�e�[�W��

	tnl::Sequence<SceneSelect> sequence_ = tnl::Sequence<SceneSelect>(this, &SceneSelect::SeqIdle);

public:
	//-----�����o�֐�-----//
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;

private:

	bool SeqIdle(float delta_time);
	void MoveBalloon(float delta_time);

public:
	std::string GetSelectedStage() const { return m_stage_names[m_selected_stage]; };
};

