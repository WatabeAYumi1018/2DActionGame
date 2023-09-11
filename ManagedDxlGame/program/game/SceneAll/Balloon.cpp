#include "../game/ScenePlay/Camera/Camera.h"
#include "../game/SceneAll/Balloon.h"

Balloon::Balloon() : GameObject(tnl::Vector3(0, 0, 0))
{
    Initialize();
}

void Balloon::Initialize()
{
    // �o���[���̉摜�����[�h
    m_balloon_hdl = LoadGraph("graphics/balloon/balloon_red.png");
    //��ʂ̕��Ɋ�Â��ă����_����X�ʒu��ݒ�
    m_pos.x = rand() % 640;
    //��ʂ̉������烉���_���Ȉʒu�ŊJ�n
    m_pos.y = 480 + rand() % 100;
    //1����3�̊ԂŃ����_���ȏ�������x
    m_hover_velocity = -(rand() % 3 + 1);
}

void Balloon::Update(float delta_time)
{
    //Spawn();
    m_pos.y += m_hover_velocity.y;

    //�ӂ�ӂ킳���邽�߂̏����������_���ȕϓ���������
    m_hover_velocity.y += (rand() % 3 - 1) * 0.1f;
}

void Balloon::Draw(float delta_time, const Camera* camera)
{
    //�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
    tnl::Vector3 draw_pos = m_pos - camera->GetTarget() +
        tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

    DrawExtendGraph(draw_pos.x, draw_pos.y, draw_pos.x + m_size, draw_pos.y + m_size, m_balloon_hdl, TRUE);
}

void Balloon::Finalize()
{
	// �o���[���̉摜���폜
	DeleteGraph(m_balloon_hdl);
}
