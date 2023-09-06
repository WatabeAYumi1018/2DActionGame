#include "Player.h"
#include "../../Camera/Camera.h"

//�L�����N�^�[�̏������q
Player::Player() :
	Character
	(
		{ PLAYER_POS_X, PLAYER_POS_Y, 0 },
		PLAYER_SIZE,
		PLAYER_MAX_HP,
		{ PLAYER_VELOCITY_X, PLAYER_VELOCITY_Y,0 }
	)
{
	Initialize();
}

Player::~Player()
{
	Finalize();
}

void Player::Initialize()
{

}

void Player::Update(float delta_time)
{
	MoveHandle(delta_time);
	AnimHandle(delta_time);
}

void Player::Draw(float delta_time, const Camera* camera)
{
	tnl::Vector3 draw_pos =
		m_pos - camera->GetTarget() + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	//�A�j���[�V�����̕`��
	animLoader->Draw(delta_time, draw_pos);
	//���f�o�b�O�p
	DrawFormatString(0, 30, 1, "Player_x: %.2f", draw_pos.x);
	DrawFormatString(0, 50, 1, "Player_y: %.2f", draw_pos.y);
	//DrawCircle(draw_pos.x, draw_pos.y, m_size, -1, TRUE);
}

void Player::MoveHandle(float delta_time)
{
	//�d�͂ŉ��ɗ�����
	m_pos.y += m_gravity.y * delta_time ;

	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT))
	{
		m_is_dirction_right = true;

		if (tnl::Input::IsKeyDown(eKeys::KB_LSHIFT))
		{
			m_pos.x += PLAYER_VELOCITY_X * delta_time * 2;
		}
		else
		{
			m_pos.x += PLAYER_VELOCITY_X * delta_time;
		}
		//�E�Ə�𓯎��ɉ����{Line�̓����蔻�肪�������Ă���ꍇ�͎΂ߏ�ֈړ�
		if (tnl::Input::IsKeyDown(eKeys::KB_UP)) 
		{
		
		}
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT))
	{
		m_is_dirction_right = false;

		if (tnl::Input::IsKeyDown(eKeys::KB_LSHIFT))
		{
			m_pos.x -= PLAYER_VELOCITY_X * delta_time * 2;
		}
		else
		{
			m_pos.x -= PLAYER_VELOCITY_X * delta_time;
		}
	}
	//z�L�[�ōU��
	if (tnl::Input::IsKeyDown(eKeys::KB_Z))
	{
		//�U������
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_SPACE))//&& m_jump_count < PLAYER_JUMP_MAX_COUNT
	{
			m_pos.y -= PLAYER_VELOCITY_Y * delta_time*5;
	}
	//���Ƃ�
	//	m_is_jump = true;
	//	m_is_ground = false;
	//	m_jump_count++;
	//}
	////�W�����v��
	//if (m_is_jump)
	//{
	//	if (m_jump_time > 0)
	//	{
	//		m_pos.y -= m_jump_height.y * delta_time;
	//		m_jump_height.y -= m_gravity.y  * delta_time;
	//		m_jump_time -= delta_time;
	//	}
	//	else
	//	{
	//		//m_is_falling = true;						// �W�����v�㏸�I����A�}���ɗ���
	//		m_is_jump = true;
	//		//m_pos.y += (m_gravity.y * delta_time) * 5;	// ������5�͋}���ɗ������鑬�x�̔{��
	//	}
	//}
	////���n
	//else
	//{
	//	m_is_jump = false;
	//	m_is_falling = false;
	//	m_is_ground = true;
	//	m_jump_count = 0;								//�J�E���g���Z�b�g
	//	m_jump_height.y= 200;			//�W�����v�̍��������Z�b�g
	//	m_jump_time = 10;					//�W�����v���Ԃ����Z�b�g
	//}
}

//�󋵂ɂ���ăZ�b�g����A�j���[�V����ID��ς���(ID�ԍ���csv�ɂĊm�F)
void Player::AnimHandle(float delta_time)
{
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT))
	{
		if (tnl::Input::IsKeyDown(eKeys::KB_LSHIFT))
		{
			animLoader->SetAnimation(4);	 /*dash_right*/
		}
		else if (tnl::Input::IsKeyDown(eKeys::KB_SPACE))
		{
			animLoader->SetAnimation(6);	 /*jump_right*/
		}
		else
		{
			animLoader->SetAnimation(2);    /*walk_right*/
		}
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_LEFT))
	{
		if (tnl::Input::IsKeyDown(eKeys::KB_LSHIFT))
		{
			animLoader->SetAnimation(5);	 /*dash_right*/
		}
		else if (tnl::Input::IsKeyDown(eKeys::KB_SPACE))
		{
			animLoader->SetAnimation(7);	 /*jump_left*/
		}
		else
		{
			animLoader->SetAnimation(3);	 /*walk_left*/
		}
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_SPACE))
	{
		if (m_is_dirction_right)
		{
			animLoader->SetAnimation(6);	 /*jump_right*/
		}
		else
		{
			animLoader->SetAnimation(7);	 /*jump_left*/
		}
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_Z))
	{
		if (m_is_dirction_right)
		{
			animLoader->SetAnimation(16);	 /*roll_right*/
			//�Đ���A�t���O�𗧂ĂăA�C�h���ɖ߂�
			//animLoader->SetAnimation(0);	 /*idle_right*/
		}
		else
		{
			animLoader->SetAnimation(8);	 /*roll_left*/
			//animLoader->SetAnimation(1);	 /*idle_left*/
		}
	}
	else
	{
		if (m_is_dirction_right)
		{
			animLoader->SetAnimation(0);	 /*idle_right*/
		}
		else
		{
			animLoader->SetAnimation(1);	 /*idle_left*/
		}
	}
}

void Player::Finalize()
{

}

