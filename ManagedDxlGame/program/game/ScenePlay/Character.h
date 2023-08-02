#pragma once
#include "Object.h"

class Collision;

class Character 
	//:public Object 
{

public:
	Character(Vector3 pos,int hp,int attack, Vector3 jump);
	virtual ~Character();

	//-----�����o�ϐ�-----//
protected:
	int m_graph_hdl;					//�摜�n���h��
	int m_hp;							//HP
	int m_attack;						//�U����
	
	Vector3 m_jump;						//�W�����v��
	Vector3 m_pos;						//���W(Object���f����܂ł̉�)
	//Vector3 velocity;					//���x(�G�t�F�N�g�≓�����̑����̎��Ɏg�p���邩��)
	Vector3 m_gravity = {0,100,0};		//�d��
	Quaternion m_rotation;				//��]
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
	virtual void Draw() ;
	virtual void Finalize() ;

	//-----Getter,Setter-----//
	//void SetIsExit(bool is_exit) { m_is_Exit = is_exit; }
	//bool GetIsExit() const { return m_is_Exit; }
	//
	//void SetIsJump(bool is_jump) { m_is_Jump = is_jump; }
	//bool GetIsJump() const { return m_is_Jump; }
	//
	//void SetIsAttack(bool is_attack) { m_is_Attack = is_attack; }
	//bool GetIsAttack() const { return m_is_Attack; }
};