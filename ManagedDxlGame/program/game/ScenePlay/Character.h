#pragma once
#include "Object.h"

class Collision;

class Character 
//	:public Object 
{

public:
	Character(tnl::Vector3 pos,int hp,int attack, float jump_time, tnl::Vector3 jump_velocity);
	virtual ~Character();

	//-----�����o�ϐ�-----//
protected:
	int m_graph_hdl;					//�摜�n���h��
	int m_hp;							//HP
	int m_attack;						//�U����
	int m_jump_time;					//�W�����v����
	
	tnl::Vector3 m_jump_velocity;			//�W�����v���x
	tnl::Vector3 m_pos;						//���W(Object���f����܂ł̉�)
	tnl::Vector3 m_gravity = {0,100,0};		//�d��
	tnl::Quaternion m_rotation;				//��]

	//Vector3 velocity;					//���x(�G�t�F�N�g�≓�����̑����̎��Ɏg�p���邩��)
	//Vector3 m_size;					//�T�C�Y

	bool m_is_Exit=false;				//���݃t���O
	bool m_is_Ground=true;				//�ڒn��
	bool m_is_Jump=false;				//�W�����v��
	bool m_is_Attack=false;				//�U����

	Collision* m_collision = nullptr;		//�����蔻��
	//Effect* effect = nullptr;

	//-----�����o�֐�-----//
public:
	virtual void Initialize() ;
	virtual void Update(float delta_time) ;
	virtual void Draw(float delta_time) ;
	virtual void Finalize() ;
};