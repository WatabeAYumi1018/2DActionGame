#include "Player.h"
#include "MapChip.h"


//�L�����N�^�[�̏������q
Player::Player() :Character({ 100,0,0 },5, 5, 1,5.0f, {0,500,0})
{
	Initialize();
}

Player::~Player() { Finalize(); }

void Player::Initialize() 
{
	// CSV����A�j���[�V�����f�[�^�����[�h
	animLoader =new wta::AnimLoad("csv/AnimLoad.csv","graphics/animation");
}
void Player::Update(float delta_time) 
{
	Draw(delta_time);
	Move(delta_time);
}

void Player::Draw(float delta_time) {
	//���f�o�b�O�p
	DrawFormatString(10, 30, 1, "Player X: %.2f", m_pos.x);
	//�A�j���[�V�����̕`��
	animLoader->Draw(delta_time, m_pos);
}

void Player::Move(float delta_time) {
	//�󋵂ɂ���ăZ�b�g����A�j���[�V����ID��ς���(ID�ԍ���csv�ɂĊm�F)
	animLoader->SetAnimation(0); //idle_right
	
	//�L�����N�^�[�̈ړ�
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) { m_pos.x += PLAYER_SPEED_WALK * delta_time; }
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) { m_pos.x -= PLAYER_SPEED_WALK * delta_time; }

	//�d�͂ŉ��ɗ�����
	m_pos.y += m_gravity.y * delta_time;

	//���n��
	if (m_is_Ground) {
		//�X�y�[�X�{�^���ŃW�����v
		if (tnl::Input::IsKeyDown(eKeys::KB_SPACE)) {
 			m_is_Jump = true;
			m_is_Ground = false;
			m_was_Ground = false;
			m_jump_velocity.y = 1000.0f;
			m_jump_time = 10.0f;
		}
	}
	//�W�����v��
	if (m_is_Jump) {
		m_pos.y -= m_jump_velocity.y * delta_time;			//�W�����v���x��y���W���グ��
		m_jump_velocity.y -= m_gravity.y * delta_time;		//�W�����v������d�͓K��
		m_jump_time -= delta_time;							//�W�����v�؋󎞊Ԃ����炷
		//0�ɂȂ�����W�����v�I��
		if (m_jump_time <= 0) {
			m_is_Jump = false;
			m_was_Ground = false;
			m_jump_time = 0;
		}
	}
	// �O���E���h�ɒ��n������y���W���C��
	if (m_pos.y >= 500) {
		m_pos.y = 500;
		m_is_Ground = true;					// �n�ʂɐڂ��Ă���t���O��true�ɂ���
		m_was_Ground = true;				// �n�ʂɐڂ��Ă���t���O��false�ɂ���
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

