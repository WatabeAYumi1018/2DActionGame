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
	m_graph_hdl = LoadGraph("graphics/slimeA_idle00.png");
}
void Player::Update(float delta_time) 
{
	Draw();

	//�L�����N�^�[�̈ړ�
	if(Input::IsKeyDown(eKeys::KB_RIGHT)){m_pos.x += PLAYER_SPEED_WALK * delta_time;}
	if(Input::IsKeyDown(eKeys::KB_LEFT)){m_pos.x -= PLAYER_SPEED_WALK * delta_time;}

	//�X�y�[�X�{�^���ŃW�����v
	if(m_is_Jump && Input::IsKeyDownTrigger(eKeys::KB_SPACE)){
		m_pos.y -= m_jump_velocity.y * delta_time;
		m_jump_velocity.y-= m_gravity.y * delta_time;			//�W�����v������d�͓K��
	}

	//�d�͂ŉ��ɗ�����
	if (!m_is_Jump) {m_pos.y += m_gravity.y * delta_time;}
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

void Player::Finalize() 
{
	DeleteGraph(m_graph_hdl);
}