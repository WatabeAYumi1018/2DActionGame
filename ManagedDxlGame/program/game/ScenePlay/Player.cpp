#include "Player.h"

//�L�����N�^�[�̏������q
Player::Player(Vector3 pos) :
	Character(m_pos, PLAYER_HP,m_attack, m_jump_velocity)
{
	Initialize();
}

Player::~Player() { Finalize(); }

void Player::Initialize() 
{
	//�~�`�̓����蔻�������
	//m_collision = new Collision(m_pos, 50);


	m_graph_hdl = LoadGraph("graphics/slimeA_idle00.png");
}
void Player::Update(float delta_time) 
{
	Draw();
	Move(delta_time);

}

void Player::Draw() {

	////�摜��Y����]
	//if (Input::IsKeyDown(eKeys::KB_RIGHT)) {
	//	// Y����]��K�p�����摜��`��
	//	Matrix mat = m_rotation.getMatrix();

	//	DrawGraph(m_pos.x, m_pos.y, m_graph_hdl, TRUE);}
	//else if (Input::IsKeyDown(eKeys::KB_LEFT)) {DrawGraph(m_pos.x, m_pos.y, m_graph_hdl, TRUE);}
	//else {
		DrawGraph(m_pos.x, m_pos.y, m_graph_hdl, TRUE);
//}
}

void Player::Move(float delta_time) {

	//�L�����N�^�[�̈ړ�
	if (Input::IsKeyDown(eKeys::KB_RIGHT)) { m_pos.x += PLAYER_SPEED_WALK * delta_time; }
	if (Input::IsKeyDown(eKeys::KB_LEFT)) { m_pos.x -= PLAYER_SPEED_WALK * delta_time; }

	//�d�͂ŉ��ɗ�����
	m_pos.y += m_gravity.y * delta_time;

	if (m_is_Ground) {
		//�X�y�[�X�{�^���ŃW�����v
		if (Input::IsKeyDownTrigger(eKeys::KB_SPACE)) {
 			m_is_Jump = true;
			m_is_Ground = false;
			m_jump_velocity.y = 200.0f;
		}
	}
	if (m_is_Jump) {
		m_pos.y -= m_jump_velocity.y * delta_time;
		m_jump_velocity.y -= m_gravity.y * delta_time;		//�W�����v������d�͓K��
	}
	if (m_pos.y >=300) {
		m_pos.y = 300;						// �O���E���h�ɒ��n������y���W���C��
		m_is_Ground = true;					// �n�ʂɐڂ��Ă���t���O��true�ɂ���
		m_is_Jump = false;
		m_jump_velocity.y =0;
	}
}

void Player::Finalize() 
{
	DeleteGraph(m_graph_hdl);
}