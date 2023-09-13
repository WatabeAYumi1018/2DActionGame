#include "Player.h"
#include "../../Camera/Camera.h"
#include "../../Collision/Collision.h"
#include "../../Map/Map.h"

//�L�����N�^�[�̏������q
Player::Player(Collision* collision, Map* map):
	Character({ PLAYER_POS_X, PLAYER_POS_Y, 0 },PLAYER_SIZE,
				PLAYER_MAX_HP,{ PLAYER_VELOCITY_X, PLAYER_VELOCITY_Y,0 }),
				m_collision(collision), m_map(map)
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
	m_is_ground = CheckIsGround();
	Gravity(delta_time);
	MoveRange();

	//if (m_landing_time >= 1.0f)
	//{
	//	m_landing_time += delta_time;
	//	m_hover_end_drawed = false;
	//}

	ActionHandle(delta_time);
	Invincible(delta_time);

}

void Player::Draw(float delta_time, const Camera* camera)
{
	tnl::Vector3 draw_pos =
		m_pos - camera->GetTarget() + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

	//�A�j���[�V�����̕`��
	if (m_is_invincible)
	{
		// 0.1�b���Ƃɕ\���E��\����؂�ւ��邱�Ƃœ_�ł�����
		if (static_cast<int>(m_invincible_time * 10) % 2 == 0)
		{
			animLoader->Draw(delta_time, draw_pos);
		}
	}
	else
	{
		animLoader->Draw(delta_time, draw_pos);
	}
	
	//���f�o�b�O�p
	DrawFormatString(0, 30, 1, "Player_x: %.2f", draw_pos.x);
	DrawFormatString(0, 50, 1, "Player_y: %.2f", draw_pos.y);
	//DrawCircle(draw_pos.x, draw_pos.y, m_size, -1, TRUE);
}

void Player::ActionHandle(float delta_time)
{
	// 1�b�����̏ꍇ�A�A�N�V������ύX���Ȃ�
	//if (m_landing_time < 1.0f) return;

	MoveHandle(delta_time);

	switch (e_currentAction)
	{
	case ePlayerAction::Move_right:

		animLoader->SetAnimation(2);  /*move_right*/

		break;
	
	case ePlayerAction::Move_left:
		
		animLoader->SetAnimation(3);  /*move_left*/
		
		break;

	case ePlayerAction::Dash_right:
	
		animLoader->SetAnimation(4);  /*dash_right*/
	
		break;
	
	case ePlayerAction::Dash_left:

		animLoader->SetAnimation(5);  /*dash_left*/

		break;

	case ePlayerAction::Idle_right:

		animLoader->SetAnimation(0);  /*idle_left*/

		break;

	case ePlayerAction::Idle_left:

		animLoader->SetAnimation(1);  /*idle_left*/

		break;

	case ePlayerAction::Hover_right:

		animLoader->SetAnimation(6);  /*jump_right*/

		break;

	case ePlayerAction::Hover_left:

		animLoader->SetAnimation(7);  /*jump_left*/

		break;

	case ePlayerAction::Hover_end_right:

		animLoader->SetAnimation(8);  /*jump_end_right*/

		break;

	case ePlayerAction::Hover_end_left:

		animLoader->SetAnimation(9);  /*jump_end_left*/

		break;

	case ePlayerAction::Beam_right:

		animLoader->SetAnimation(16);  /*beam_right*/

		break;

	case ePlayerAction::Beam_left:

		animLoader->SetAnimation(17);  /*beam_left*/

		break;

	default:

		break;
	}
}

void Player::MoveHandle(float delta_time)
{
	//�A�i���O�X�e�B�b�N�̓��͒l���擾
	GetJoypadAnalogInput(&m_input_x, &m_input_y, DX_INPUT_PAD1);

	normalized_input_x = m_input_x / 1000.0f;

	if (tnl::Input::IsKeyDown(eKeys::KB_SPACE) || tnl::Input::IsPadDown(ePad::KEY_3))
	{
		m_is_hovering = true;
	}

	if (m_is_hovering)
	{
		Hovering(delta_time);
		HoveringDirection(delta_time);
	}
		//HoveringEnd();

	if (CheckIsGround() && !m_is_hovering)
	{
		if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT) || normalized_input_x > 0)
		{
			m_is_direction_right = true;

			if (tnl::Input::IsKeyDown(eKeys::KB_LSHIFT) || normalized_input_x > DASH_THRESHOLD)
			{
				m_pos.x += PLAYER_VELOCITY_X * delta_time * 2;
				e_currentAction = ePlayerAction::Dash_right;
			}
			else
			{
				m_pos.x += PLAYER_VELOCITY_X * delta_time;
				e_currentAction = ePlayerAction::Move_right;
			}
		}
		else if (tnl::Input::IsKeyDown(eKeys::KB_LEFT) || normalized_input_x < 0)
		{
			m_is_direction_right = false;

			if (tnl::Input::IsKeyDown(eKeys::KB_LSHIFT) || abs(normalized_input_x) > DASH_THRESHOLD)
			{
				m_pos.x -= PLAYER_VELOCITY_X * delta_time * 2;
				e_currentAction = ePlayerAction::Dash_left;
			}
			else
			{
				m_pos.x -= PLAYER_VELOCITY_X * delta_time;
				e_currentAction = ePlayerAction::Move_left;
			}
		}
		else
		{
			if (m_is_direction_right)
			{
				e_currentAction = ePlayerAction::Idle_right;
			}
			else
			{
				e_currentAction = ePlayerAction::Idle_left;
			}
		}
	}
	else 
	{
		if (!m_hover_end_drawed) 
		{
			if (tnl::Input::IsKeyDown(eKeys::KB_Z))
			{
				if (m_is_direction_right)
				{
					e_currentAction = ePlayerAction::Beam_right;
				}
				else
				{
					e_currentAction = ePlayerAction::Beam_left;
				}
			}
		}
	}
}

void Player::MoveRange()
{
	//�v���C���[�̈ړ��͈͂𐧌�
	if (m_pos.x < PLAYER_SIZE)
	{
		m_pos.x = PLAYER_SIZE;
	}
	if (m_pos.x > (m_map -> GetMapChipX() * m_map->MAP_CHIP_SIZE - PLAYER_SIZE))
	{
		m_pos.x = m_map->GetMapChipX()* m_map->MAP_CHIP_SIZE - PLAYER_SIZE;
	}
	if (m_pos.y < PLAYER_SIZE)
	{
		m_pos.y = PLAYER_SIZE;
	}
	if (m_pos.y >= (m_map->GetMapChipY() * m_map->MAP_CHIP_SIZE - PLAYER_SIZE))
	{
		m_pos.x = PLAYER_POS_X;
		m_pos.y = PLAYER_POS_Y;
		//�J���������Z�b�g
		//UI�����Z�b�g

	}
}

void Player::Gravity(float delta_time)
{
	//�d�͂ŉ��ɗ�����
	if (m_is_hovered)
	{
		m_pos.y += 2 * m_gravity.y * delta_time;    // ��C���������ꍇ�A�d�͂̉e����2�{�ɂ���
	}
	else
	{
		m_pos.y += m_gravity.y * delta_time;
	}
}

void Player::Hovering(float delta_time)
{
	if (m_is_ground)
	{
		m_hovering_force = PLAYER_INITIAL_HOVER_FORCE; // �n�ʂɂ���Ƃ��͕��V�͂����Z�b�g
	}
	if (m_hovering_force > 0)
	{
		m_pos.y -= m_hovering_force * PLAYER_VELOCITY_Y * delta_time; // ���V�͂Ɋ�Â��Ĉʒu���X�V
		m_hovering_force -= PLAYER_HOVER_DECAY_RATE * delta_time; // ���V�͂�����������
		m_hovering_force = max(m_hovering_force, 0.0f); // 0�ȉ��ɂ͂Ȃ�Ȃ��悤�ɂ���
	}
	else
	{
		m_hovering_force = 0.0f; // �L�[�������ꂽ�畂�V�͂�0�Ƀ��Z�b�g
		m_is_hovering = false;
		m_is_hovered = false;
	}
}

void Player::HoveringDirection(float delta_time)
{
	// �z�o�����O��
	if (m_hovering_force > 0)
	{
		if (m_is_direction_right)
		{
			HoveringStartRight(delta_time);
		}
		else
		{
			HoveringStartLeft(delta_time);
		}
	}
	//���~��
	else
	{
		if (m_is_direction_right)
		{
			HoveringStartRight(delta_time);
		}
		else
		{
			HoveringStartLeft(delta_time);
		}
	}
}

void Player::HoveringStartRight(float delta_time)
{
	e_currentAction = ePlayerAction::Hover_right;

	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT) || normalized_input_x > 0)
	{
		m_pos.x += PLAYER_VELOCITY_X * delta_time;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT) || normalized_input_x < 0)
	{
		e_currentAction = ePlayerAction::Hover_left;
		m_pos.x -= PLAYER_VELOCITY_X * delta_time;
	}
}

void Player::HoveringStartLeft(float delta_time)
{
	e_currentAction = ePlayerAction::Hover_left;

	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT) || normalized_input_x < 0)
	{
		m_pos.x -= PLAYER_VELOCITY_X * delta_time;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT) || normalized_input_x > 0)
	{
		e_currentAction = ePlayerAction::Hover_right;
		m_pos.x += PLAYER_VELOCITY_X * delta_time;
	}
}

void Player::HoveringEnd()
{
	if (CheckIsGround())
	{
		//m_landing_time = 0.0f; // ���n�����u�ԂɃ^�C�}�[�����Z�b�g

		if (m_is_direction_right)
		{
			e_currentAction = ePlayerAction::Hover_end_right;
		}
		else
		{
			e_currentAction = ePlayerAction::Hover_end_left;
		}
		m_is_hovering = false;
		m_hover_end_drawed = true;
	}
	else
	{
		m_is_hovering = false;
	}
}

bool Player::CheckIsGround()
{
	tnl::Vector3 foot_pos = m_pos + tnl::Vector3(0, PLAYER_SIZE, 0);
	DrawBoxEx(foot_pos,30,30);
	tnl::Vector3 chip_pos = m_collision->GetCharacterMapChipPos(foot_pos, m_map);
	sCollisionInfo foot_collision = m_map->GetCollisionInfo()[chip_pos.y][chip_pos.x];

	return (foot_collision.s_type == eMapCollisionType::Box ||
				foot_collision.s_type == eMapCollisionType::Line);
}

void Player::Invincible(float delta_time)
{
	// ���G���Ԃ��X�V
	if (m_is_invincible)
	{
		m_invincible_time += delta_time;

		if (m_invincible_time >= 5.0f)
		{
			m_is_invincible = false;
		}
	}
}

void Player::Finalize()
{

}

