#pragma once
#include "../../engine/GameEngine.h"
#include "Player.h"

class Object;

//�v���C���[�Ǐ]�J����
class PlayCamera :public Object{
public:
	PlayCamera(tnl::Vector3 pos,Player* player);
	~PlayCamera();
private:
	//-----�����o�ϐ�-----//
	tnl::Vector3 m_up;			//�����
	tnl::Vector3 m_right;		//�E����
	tnl::Vector3 m_front;		//�O����
	tnl::Vector3 m_move;		//�ړ���
	float m_height;				//����
	float m_speed;				//�ړ����x
	Player* m_player;			//�v���C���[

public:
	//-----�����o�֐�-----//
	void Update(float delta_time);	//���W�X�V

	//-----Setter,Getter-----//
	void SetMove(tnl::Vector3 move) { m_move = move; }
	tnl::Vector3 GetMove () { return m_move; }
	void SetHeight(float height) { m_height = height; }
	float GetHeight () { return m_height; }
	void SetSpeed(float speed) { m_speed = speed; }
	float GetSpeed () { return m_speed; }
	void SetUp(tnl::Vector3 up) { m_up = up; }
	tnl::Vector3 GetUp () { return m_up; }
	void SetRight(tnl::Vector3 right) { m_right = right; }
	tnl::Vector3 GetRight () { return m_right; }
	void SetFront(tnl::Vector3 front) { m_front = front; }
	tnl::Vector3 GetFront () { return m_front; }
};