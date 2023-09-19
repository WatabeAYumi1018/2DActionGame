#include "../../dxlib_ext/dxlib_ext.h"
#include "SceneSelect.h"
#include "../ScenePlay/scenePlay.h"
#include "../../engine/SceneManager.h"


SceneSelect::SceneSelect() : m_selected_stage(0)
{
	m_stage_names.emplace_back("stage1");
	m_stage_names.emplace_back("stage2");
	m_stage_names.emplace_back("stage3");
	m_stage_names.emplace_back("boss");
};

void SceneSelect::Update(float delta_time)
{
	sequence_.update(delta_time);

	MoveBalloon(delta_time);
}

void SceneSelect::Draw(float delta_time)
{
	DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, m_back_hdl, TRUE);

	DrawGraph(50, 100 + (m_selected_stage == 0 ? m_balloon_offset_y : 0), m_stage1_hdl, TRUE);
	DrawGraph(350, 300 + (m_selected_stage == 1 ? m_balloon_offset_y : 0), m_stage2_hdl, TRUE);
	DrawGraph(650, 100 + (m_selected_stage == 2 ? m_balloon_offset_y : 0), m_stage3_hdl, TRUE);
	DrawGraph(950, 300 + (m_selected_stage == 3 ? m_balloon_offset_y : 0), m_boss_hdl, TRUE);
}

bool SceneSelect::SeqIdle(float delta_time)
{
	if (sequence_.isStart())
	{
		m_back_hdl   = LoadGraph("graphics/title/title.png");
		m_stage1_hdl = LoadGraph("graphics/select/stage1.png");
		m_stage2_hdl = LoadGraph("graphics/select/stage2.png");
		m_stage3_hdl = LoadGraph("graphics/select/stage3.png");
		m_boss_hdl   = LoadGraph("graphics/select/stage_boss.png");
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN))
	{
		auto scene = SceneManager::GetInstance();
		//�I�񂾃X�e�[�W�ɂ���Đ؂�ւ���
		scene->ChangeScene(new ScenePlay(GetSelectedStage()));
	}
	return true;
}

void SceneSelect::MoveBalloon(float delta_time)
{
	// �L�[���͂̏���
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT))
	{
		m_selected_stage = (m_selected_stage + 1) % STAGE_NUM;
	}
	else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT))
	{
		m_selected_stage = (m_selected_stage - 1 + STAGE_NUM) % STAGE_NUM;
	}

	// �^�C�}�[�̑���
	m_balloon_timer += delta_time * m_balloon_velocity_y; // 2.0f�͕��D�̓����̑����𒲐����邽�߂̒l�ł��B�K�؂ɒ������Ă��������B

	// sin�֐����g�p���ĕ��D�̏㉺�̃I�t�Z�b�g���v�Z
	m_balloon_offset_y = sin(m_balloon_timer) * 10.0f;
}

void SceneSelect::Finalize()
{
	DeleteGraph(m_back_hdl);
	DeleteGraph(m_stage1_hdl);
	DeleteGraph(m_stage2_hdl);
	DeleteGraph(m_stage3_hdl);
	DeleteGraph(m_boss_hdl);
}