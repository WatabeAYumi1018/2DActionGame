#pragma once
#include "Object.h"

class Collision;

class Character :public Object {

public:
	Character(Vector3 m_pos, Vector3 m_velocity);
	virtual ~Character();

	//-----�����o�ϐ�-----//
protected:
	int m_graph_hdl;					//�摜�n���h��
	int m_hp;							//HP
	int m_attack;						//�U����
	int m_defence;						//�h���
	int m_jump;							//�W�����v��

	Vector3 m_velocity;					//���x
	Vector3 m_gravity;					//�d��
	Vector3 m_size;						//�T�C�Y

	bool m_is_Exit;						//���݃t���O
	bool m_is_Jump;						//�W�����v��
	bool m_is_Attack;					//�U����

	Collision* collision = nullptr;		//�����蔻��
	//Effect* effect = nullptr;

	//-----�����o�֐�-----//
public:
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw() override;
	void Finalize() override;
};