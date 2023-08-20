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
	//���摜�̓ǂݍ���(animLoop�N���X���g�p���ēǂݍ���)�i�璷�C���̂��ߏC���K�{���ȂƁj
	//csv�t�@�C���ł܂Ƃ߂�
	//animLoop  = new AnimLoad("graphics/player/walk_right",true);
	//animLoop2 = new AnimLoad("graphics/player/walk_left",true);
	//animLoop3 = new AnimLoad("graphics/player/jump_right",true);
	//animLoop4 = new AnimLoad("graphics/player/jump_left",true);
	//animLoop5 = new AnimLoad("graphics/player/idle_right",true);
	//animLoop6 = new AnimLoad("graphics/player/idle_left",true);
	//animLoop7 = new AnimLoad("graphics/player/run_right",true);
	//animLoop8 = new AnimLoad("graphics/player/run_left",true);
	//animLoop9 = new AnimLoad("graphics/player/touchdown_right",false);
	//animLoop10= new AnimLoad("graphics/player/touchdown_left",false);
}
void Player::Update(float delta_time) 
{
	Draw(delta_time);
	Move(delta_time);
}

//void Player::Draw(float delta_time) {
//	DrawFormatString(10, 30, 1, "Player X: %.2f", m_pos.x);
//	//��������@��������̂悤�Ɋ�����c
//
//		//�n�ʂɂ��鎞�̃A�j���[�V����
//	if (m_is_Ground) {
//		if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
//			if (tnl::Input::IsKeyDown(eKeys::KB_LSHIFT)) {
//				animLoop7->drawAnimFile(delta_time, m_pos);
//			}
//			else animLoop->drawAnimFile(delta_time, m_pos);
//		}
//		else if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
//			if (tnl::Input::IsKeyDown(eKeys::KB_LSHIFT)) {
//				animLoop8->drawAnimFile(delta_time, m_pos);
//			}
//			else animLoop2->drawAnimFile(delta_time, m_pos);
//		}
//		//�A�j���[�V�����摜�`��
//		else { animLoop5->drawAnimFile(delta_time, m_pos); }
//	}
//	//�W�����v���A�j���[�V����(�v����)
//	else {
//		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE) && tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
//			//animLoop3->drawAnimLoopFile(delta_time, m_pos);
//		}
//		else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE) && tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
//			animLoop4->drawAnimFile(delta_time, m_pos);
//		}
//		else { animLoop3->drawAnimFile(delta_time, m_pos); }
//		if (m_pos.y == 500) { animLoop9->drawAnimFile(delta_time, m_pos); }
//	}
//}

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
	//delete animLoop;
	//animLoop = nullptr;
	//delete animLoop2;
	//animLoop2 = nullptr;
	//delete animLoop3;
	//animLoop3 = nullptr;
	//delete animLoop4;
	//animLoop4 = nullptr;
	//delete animLoop5;
	//animLoop5 = nullptr;
	//delete animLoop6;
	//animLoop6 = nullptr;
	//delete animLoop7;
	//animLoop7 = nullptr;
	//delete animLoop8;
	//animLoop8 = nullptr;
	//delete animLoop9;
	//animLoop9 = nullptr;
	//delete animLoop10;
	//animLoop10 = nullptr;
}