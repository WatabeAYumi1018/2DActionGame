#include "../../dxlib_ext/dxlib_ext.h"
#include "SceneTitle.h"
#include "../ScenePlay/scenePlay.h"
#include "../../engine/SceneManager.h"

void SceneTitle::Update(float delta_time) 
{
	sequence_.update(delta_time);
	logoHandle(delta_time);
	bounceHandle(delta_time);

	for (auto& balloon : balloons)
	{
		balloon.Update(delta_time);
	}
	SpawnBalloon(); // ���D�𐶐�
}

void SceneTitle::Draw(float delta_time) 
{
	DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, m_back_hdl, TRUE);

	//for (const auto& balloon : balloons)
	//{
	//	DrawExtendGraph(m_pos.x, m_pos.y, m_pos.x + m_size, m_pos.y + m_size, m_balloon_hdl, TRUE);
	//}

	int logoHeight; // ���S�̍������擾
	GetGraphSize(m_logo_hdl, NULL, &logoHeight); // ���S�̍������擾
	DrawRectExtendGraph(300, 400, 400 + m_current_width, 400 + logoHeight, 0, 0, m_current_width, logoHeight, m_logo_hdl, TRUE);
	DrawGraph(400, m_chara_pos.y, m_palloon_hdl, TRUE);
}

bool SceneTitle::SeqIdle(float delta_time) 
{
	if (sequence_.isStart())

		//balloon->Initialize();
	{
		m_back_hdl = LoadGraph("graphics/title/Titleback.jpg");
		m_logo_hdl = LoadGraph("graphics/title/TitleLogo.png");
		m_palloon_hdl= LoadGraph("graphics/title/PALLOON.png");
		
		m_current_width = 0;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) 
	{
		auto scene = SceneManager::GetInstance();
		scene->ChangeScene(new ScenePlay());
	}
	return true;
}

void SceneTitle::logoHandle(float delta_time)
{
	// ���S�̕������X�ɑ��₷
	m_current_width += m_display_time * delta_time * 5;

	// ���S�̕�����ʕ��𒴂������ʕ��ɌŒ�
	if (m_current_width > DXE_WINDOW_WIDTH) 
	{
		m_current_width = DXE_WINDOW_WIDTH;

		if (!m_is_logo_displayed) 
		{
			m_is_logo_displayed = true;  // ���S�̕`�悪�I������̂Ńt���O��ݒ�
		}
	}
}

void SceneTitle::bounceHandle(float delta_time)
{
	// ���S�����S�ɕ\������Ă���L�������o�E���h������
	if (!m_is_logo_displayed) return;

	if (m_bounceCount < m_maxBounce)
	{
		m_velocity.y += m_gravity.y; // �d�͂𑬓x�ɉ�����
		m_chara_pos.y += m_velocity.y; // ���x���ʒu�ɉ�����

		// �C���X�g���n�ʂɓ��B������o�E���h������
		if (m_chara_pos.y >= m_ground_y)
		{
			m_chara_pos.y = m_ground_y; // �ʒu��n�ʂɐݒ�
			m_velocity.y *= m_bounceRate; // �o�E���h�����邽�߂ɑ��x�𔽓]&����������
			m_bounceCount++; // �o�E���h�񐔂𑝂₷
		}
	}
	else
	{
		// �ő�o�E���h�񐔂𒴂����ꍇ�A�C���X�g����ʒ����ɌŒ肷��
		m_chara_pos.y = m_ground_y;
	}
}

void SceneTitle::SpawnBalloon() 
{
	
}