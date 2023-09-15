#include "ClearBalloon.h"
#include "../ScenePlay/Character/Player/Player.h"
#include "../ScenePlay/Collision/Collision.h"

ClearBalloon::ClearBalloon(Collision *collision) : 
	GameObject(collision->GetClearPos()), m_collision(collision)
{
	Initialize();
}

void ClearBalloon::Initialize()
{
	m_balloon_hdl = LoadGraph("graphics/balloon/clear_balloon.png");
	m_balloon_clear_hdl = LoadGraph("graphics/balloon/clear_palloon.png");
}

void ClearBalloon::Update(float delta_time)
{
	if(m_player_attached)
	{ 
		//�܂������㏸������
		m_pos.y+= delta_time * m_balloon_velocity_y;
	}
	else 
	{
		//���̏�ŏ��X�ӂ�ӂ킳����
		m_balloon_timer += delta_time * m_balloon_velocity_y; 

		// sin�֐����g�p���ĕ��D�̏㉺�̃I�t�Z�b�g���v�Z
		m_balloon_offset_y = sin(m_balloon_timer) * 5.0f;
	}
}

void ClearBalloon::Draw(float delta_time, const Camera* camera)
{
	if (m_player_attached)
	{
		DrawGraph(m_pos.x, m_pos.y , m_balloon_clear_hdl, true);
	}
	else
	{
		DrawGraph(m_pos.x, m_pos.y, m_balloon_hdl, true);
	}
}

void ClearBalloon::Finalize()
{
	DeleteGraph(m_balloon_hdl);
	DeleteGraph(m_balloon_clear_hdl);
}