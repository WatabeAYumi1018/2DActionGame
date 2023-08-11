#include "Player.h"
#include "MapChip.h"

//�L�����N�^�[�̏������q
Player::Player() :Character({ 100,0,0 }, 5, 1,5.0f, {0,500,0})
{
	Initialize();
}

Player::~Player() { Finalize(); }

void Player::Initialize() 
{
	//�~�`�̓����蔻�������
	//m_collision = new Collision(m_pos, 50);
	m_mapchip = new MapChip();

	//���摜�̓ǂݍ���(animLoop�N���X���g�p���ēǂݍ���)�i������̂��ߏC���K�{�j
	animLoop = new Anim("graphics/player/walk_right");
	animLoop2 = new Anim("graphics/player/walk_left");
	animLoop3 = new Anim("graphics/player/jump_right");
	animLoop4 = new Anim("graphics/player/jump_left");
	animLoop5 = new Anim("graphics/player/idle_right");
}
void Player::Update(float delta_time) 
{
	Draw(delta_time);
	Move(delta_time);
}

void Player::Draw(float delta_time) {
	DrawFormatString(10, 30, 1, "Player X: %.2f", m_pos.x);
	//��������@��������̂悤�Ɋ�����c
	 
	//���̂�����͕ʂŐ�p�̃N���X���쐬���āA�����ŏ�������悤�ɂ�������X�}�[�g
	//�����A�j���[�V����
	if(m_is_Ground){
		if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
			animLoop->drawAnimLoopFile(delta_time, m_pos, "graphics/player/walk_right");
		}
		else if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
			animLoop2->drawAnimLoopFile(delta_time, m_pos, "graphics/player/walk_left");
		}
		//�A�j���[�V�����摜�`��
		else{ 
			animLoop5->drawAnimLoopFile(delta_time, m_pos, "graphics/player/idle_right");
		}
	}
	//�W�����v�A�j���[�V����
	else {
		if (tnl::Input::IsKeyDown(eKeys::KB_SPACE) && tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
			animLoop3->drawAnimLoopFile(delta_time, m_pos, "graphics/player/jump_right");
		}
		else if (tnl::Input::IsKeyDown(eKeys::KB_SPACE) && tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
			animLoop4->drawAnimLoopFile(delta_time, m_pos, "graphics/player/jump_left");
		}
		else {
			animLoop3->drawAnimLoopFile(delta_time, m_pos, "graphics/player/jump_right");
		}
	}
}

void Player::Move(float delta_time) {
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
			m_jump_time = 0;
		}
	}
	// �O���E���h�ɒ��n������y���W���C��
	if (m_pos.y >=300) {
		m_pos.y = 300;						
		m_is_Ground = true;					// �n�ʂɐڂ��Ă���t���O��true�ɂ���
		m_jump_velocity.y =0;				// �W�����v���x��0�Ƀ��Z�b�g
		m_jump_time = 0;					// �W�����v���Ԃ�0�Ƀ��Z�b�g
	}
}

void Player::Finalize() 
{
	//�摜�̉��
	delete animLoop;
	animLoop = nullptr;
	delete animLoop2;
	animLoop2 = nullptr;
	delete animLoop3;
	animLoop3 = nullptr;
}