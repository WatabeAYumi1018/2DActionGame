#include "../../dxlib_ext/dxlib_ext.h"
#include "SceneTitle.h"
#include "../sceneSelect/SceneSelect.h"
#include "../../engine/SceneManager.h"
#include "../SceneAll/Music/MusicManager.h"

SceneTitle::~SceneTitle()
{
	Finalize();
}

void SceneTitle::Update(float delta_time) 
{
	sequence_.update(delta_time);
	LogoHandle(delta_time);
	BoundHandle(delta_time);

	m_balloon_spawn_timer += delta_time;

	if (m_balloon_spawn_timer >= SPAWN_INTERVSL)
	{
		m_balloon_spawn_timer = 0.0f; // �^�C�}�[�����Z�b�g
	}

	for (auto& balloon : balloons)
	{
		balloon.Update(delta_time);
	}
}

void SceneTitle::Draw(float delta_time) 
{
	DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, m_back_hdl, TRUE);

	for (const auto& balloon : balloons)
	{
		DrawExtendGraph(balloon.GetPos().x, balloon.GetPos().y,balloon.GetPos().x + balloon.GetSize(),
						balloon.GetPos().y + balloon.GetSize(), balloon.GetHdl(), TRUE);
	}

	int logo_height; // ���S�̍������擾
	GetGraphSize(m_logo_hdl, NULL, &logo_height); // ���S�̍������擾
	DrawRectExtendGraph(300, 400, 400 + m_current_width, 400 + logo_height, 0, 0, m_current_width, logo_height, m_logo_hdl, TRUE);
	DrawGraph(400, m_chara_pos.y, m_palloon_hdl, TRUE);
}

bool SceneTitle::SeqIdle(float delta_time) 
{
	if (sequence_.isStart())
	{
		MusicManager::GetInstance().LoadBGM("music/title.mp3");
		MusicManager::GetInstance().LoadSE("start","music/pushStart.wav");

		m_back_hdl = LoadGraph("graphics/title/title.png");
		m_logo_hdl = LoadGraph("graphics/title/TitleLogo.png");
		m_palloon_hdl= LoadGraph("graphics/title/PALLOON.png");
		
		SpawnBalloon();

		MusicManager::GetInstance().PlayBGM();

		m_current_width = 0;
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)|| tnl::Input::IsPadDownTrigger(ePad::KEY_1))
	{
		MusicManager::GetInstance().PlaySE("start");

		auto scene = SceneManager::GetInstance();
		scene->ChangeScene(new SceneSelect());
	}
	return true;
}

void SceneTitle::LogoHandle(float delta_time)
{
	// ���S�̕������X�ɑ��₷
	m_current_width += DISPLAY_TIME * delta_time * 5;

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

void SceneTitle::BoundHandle(float delta_time)
{
	// ���S�����S�ɕ\������Ă���L�������o�E���h������
	if (!m_is_logo_displayed) return;

	if (m_bound_count < MAX_BOUNDE)
	{
		m_velocity.y += m_gravity.y; // �d�͂𑬓x�ɉ�����
		m_chara_pos.y += m_velocity.y; // ���x���ʒu�ɉ�����

		// �C���X�g���n�ʂɓ��B������o�E���h������
		if (m_chara_pos.y >= GROUND_Y)
		{
			m_chara_pos.y = GROUND_Y; // �ʒu��n�ʂɐݒ�
			m_velocity.y *= BOUND_RATE; // �o�E���h�����邽�߂ɑ��x�𔽓]&����������
			m_bound_count++; // �o�E���h�񐔂𑝂₷
		}
	}
	else
	{
		// �ő�o�E���h�񐔂𒴂����ꍇ�A�C���X�g����ʒ����ɌŒ肷��
		m_chara_pos.y = GROUND_Y;
	}
}

void SceneTitle::SpawnBalloon() 
{
	for (int i = 0; i < BALLOON_SPAWN; ++i)
	{
		balloons.emplace_back(); // �����̃o���[�����X�|�[��
	}
}

void SceneTitle::Finalize()
{
	DeleteGraph(m_back_hdl);
	DeleteGraph(m_logo_hdl);
	DeleteGraph(m_palloon_hdl);

	balloons.clear();
}