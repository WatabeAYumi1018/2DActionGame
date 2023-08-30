#include "Player.h"
#include "PlayCamera.h"


//�L�����N�^�[�̏������q
Player::Player() :
	Character({ PLAYER_POS_X, PLAYER_POS_Y, 0 }, PLAYER_SIZE, PLAYER_HP, { PLAYER_VELOCITY_X, PLAYER_VELOCITY_Y,0 })
{
	Initialize();
}

Player::~Player() 
{ 
	Finalize(); 
}

void Player::Initialize() 
{
	// CSV����A�j���[�V�����f�[�^�����[�h
	animLoader =new wta::DrawAnim("csv/AnimLoad.csv","graphics/animation");
}

void Player::Update(float delta_time)
{
	MoveHandle(delta_time);
	AnimHandle(delta_time);
}

void Player::Draw(float delta_time, const PlayCamera* camera) 
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
	m_pos.y += m_gravity.y * delta_time;

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
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_LEFT))
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
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE))
	{
		m_is_jump = true;
		m_is_ground = false;
		m_jump_velocity.y = 1000.0f;
		m_jump_time = 7.0f;
	}
	//�W�����v��
	if (m_is_jump) 
	{
		m_pos.y -= m_jump_velocity.y * delta_time;			/*�W�����v���x��y���W���グ��*/
		m_jump_velocity.y -= m_gravity.y * delta_time;		/*�W�����v������d�͓K��*/
		m_jump_time -= delta_time;							/*�W�����v�؋󎞊Ԃ����炷*/
		
		//0�ɂȂ�����W�����v�I��
		if (m_jump_time <= 0) 
		{
			m_is_jump = false;
			m_jump_time = 0;
		}
	}
	// �O���E���h�ɒ��n������y���W���C��
	else
	{
		m_is_ground = true;					// �n�ʂɐڂ��Ă���t���O��true�ɂ���
		m_jump_velocity.y = 0;				// �W�����v���x��0�Ƀ��Z�b�g
		m_jump_time = 0;					// �W�����v���Ԃ�0�Ƀ��Z�b�g
	}
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
	delete animLoader;
	animLoader = nullptr;
}

