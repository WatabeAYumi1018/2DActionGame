#include "Player.h"
#include "PlayCamera.h"


//�L�����N�^�[�̏������q
Player::Player() : Character({ PLAYER_POS_X, PLAYER_POS_Y, 0 }, PLAYER_SIZE, PLAYER_HP, { PLAYER_VELOCITY_X, PLAYER_VELOCITY_Y,0 })
{
	Initialize();
}

Player::~Player() { Finalize(); }

void Player::Initialize() 
{
	// CSV����A�j���[�V�����f�[�^�����[�h
	animLoader =new wta::DrawAnim("csv/AnimLoad.csv","graphics/animation");
}

void Player::Update(float delta_time)
{
	Move(delta_time);
}

void Player::Draw(float delta_time, const PlayCamera* camera) {
	tnl::Vector3 draw_pos = m_pos - camera->target + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	//�A�j���[�V�����̕`��
	animLoader->Draw(delta_time, draw_pos);
	//���f�o�b�O�p
	DrawFormatString(0, 30, 1, "Player_x: %.2f", draw_pos.x);
	DrawFormatString(0, 50, 1, "Player_y: %.2f", draw_pos.y);
	DrawCircle(draw_pos.x, draw_pos.y, m_size, -1, TRUE);
}

void Player::Move(float delta_time) {
	//�󋵂ɂ���ăZ�b�g����A�j���[�V����ID��ς���(ID�ԍ���csv�ɂĊm�F)
	animLoader->SetAnimation(0); //idle_right
	//�L�����N�^�[�̈ړ�
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) { m_pos.x += PLAYER_VELOCITY_X * delta_time; }
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) { m_pos.x -= PLAYER_VELOCITY_X * delta_time; }

	//�d�͂ŉ��ɗ�����
	m_pos.y += m_gravity.y * delta_time;

	//���n��
	
	//if (m_is_Ground) {
		//�X�y�[�X�{�^���ŃW�����v
		if (tnl::Input::IsKeyDown(eKeys::KB_SPACE)) {
 			m_is_jump = true;
			m_is_ground = false;
			m_was_ground = false;
			m_jump_velocity.y = 1000.0f;
			m_jump_time = 10.0f;
		}
	//}
	//�W�����v��
	if (m_is_jump) {
		m_pos.y -= m_jump_velocity.y * delta_time;			//�W�����v���x��y���W���グ��
		m_jump_velocity.y -= m_gravity.y * delta_time;		//�W�����v������d�͓K��
		m_jump_time -= delta_time;							//�W�����v�؋󎞊Ԃ����炷
		//0�ɂȂ�����W�����v�I��
		if (m_jump_time <= 0) {
			m_is_jump = false;
			m_was_ground = false;
			m_jump_time = 0;
		}
	}
	// �O���E���h�ɒ��n������y���W���C��
	else{
		m_is_ground = true;					// �n�ʂɐڂ��Ă���t���O��true�ɂ���
		m_was_ground = true;				// �n�ʂɐڂ��Ă���t���O��false�ɂ���
		m_jump_velocity.y = 0;				// �W�����v���x��0�Ƀ��Z�b�g
		m_jump_time = 0;					// �W�����v���Ԃ�0�Ƀ��Z�b�g
	}
}

void Player::Finalize() 
{
	//�摜�̉��
	delete animLoader;
	animLoader = nullptr;
}

