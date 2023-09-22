#pragma once
#include "../../engine/sceneBase.h"


class GameObject;

class SceneSelect : public SceneBase 
{
public:

	SceneSelect();

private:

	//-----�萔-----//
	const int STAGE_NUM = 4;					/*�X�e�[�W��*/

	//-----�����o�ϐ�-----//
	int m_back_hdl = 0;
	int m_stage1_hdl = 0;
	int m_stage2_hdl = 0;
	int m_stage3_hdl = 0;
	int m_boss_hdl = 0;

	int m_selected_stage = 0;					/*�I�𒆃X�e�[�W*/
	
	float m_balloon_time = 0.0f;				/*�I�𒆕��D�̏㉺�^�C�}�[*/
	float m_balloon_offset_y = 10.0f;			/*�㉺�I�t�Z�b�g*/
	float m_balloon_velocity_y = 5.0f;			/*�㉺���x*/
	
	std::vector<std::string> m_stage_names;		/*�X�e�[�W��*/

	//�Q�[���X�e�B�b�N�p
	float normalized_input_x;					/*�A�i���O�X�e�B�b�N�̌X���x�N�g��*/
	int m_input_x;
	int m_input_y;

	const float m_input_cooldown_time = 0.5f;	/*0.5�b�̓��̓N�[���_�E��*/
	const float m_deadzone = 0.2f;				/*20%�̃f�b�h�]�[��(���͖����͈�)*/

	float m_input_cooldown = 0.0f;				/*���̓N�[���_�E���^�C�}�[*/
	float m_previous_input_x = 0.0f;			/*�O��̓��͒l*/


	tnl::Sequence<SceneSelect> sequence_ = tnl::Sequence<SceneSelect>(this, &SceneSelect::SeqIdle);

	//-----�����o�֐�-----//
	bool SeqIdle(float delta_time);
	void MoveBalloon(float delta_time);

public:

	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;

	//-----Setter,Getter-----//
	std::string GetSelectedStage() const { return m_stage_names[m_selected_stage]; };
};

