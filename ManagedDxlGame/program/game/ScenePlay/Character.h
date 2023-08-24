#pragma once
#include "Object.h"

class CollisionCalc;

class Character {
public:
	Character(tnl::Vector3 pos, int size, int hp, float jump_time, tnl::Vector3 jump_velocity) :
		m_pos(pos), m_size(size), m_hp(hp), m_jump_time(jump_time), m_jump_velocity(jump_velocity)
	{
	}
	virtual ~Character() {}

	//-----�����o�ϐ�-----//
protected:
	int m_size;								//�T�C�Y
	int m_hp;								//HP
	int m_jump_time;						//�W�����v����
	
	tnl::Vector3 m_jump_velocity;			//�W�����v���x
	tnl::Vector3 m_pos;						//���W(Object���f����܂ł̉�)
	tnl::Vector3 m_gravity = {0,100,0};		//�d��
	tnl::Vector3 velocity;					//���x(�G�t�F�N�g�≓�����̑����̎��Ɏg�p���邩��)

	bool m_is_Exit=false;					//���݃t���O
	bool m_is_Ground=true;					//�ڒn��
	bool m_is_Jump=false;					//�W�����v��
	bool m_is_Attack=false;					//�U����

	CollisionCalc* m_collision = nullptr;	//�����蔻��

public:
	//-----�����o�֐�-----//
	virtual void Initialize() = 0;
	virtual void Update(float delta_time) = 0;
	virtual void Draw(float delta_time) = 0;
	virtual void Finalize() = 0;

	//-----Setter,Getter-----//
	tnl::Vector3 GetPos() const { return m_pos; }
	void SetPos(tnl::Vector3 pos) { m_pos = pos; }
	tnl::Vector3 GetVelocity() const { return velocity; }
	int GetSize() const { return m_size; }
};

//Effect* effect = nullptr;

//Character�N���X�̃f�X�g���N�^�����ʂȌ㏈����K�v�Ƃ��Ȃ��ꍇ�A
//virtual ~Character() = default;�̂悤�ɖ����I��= default���g�p���邱�Ƃ́A
//���̈Ӑ}�𖾊m�ɓ`���邽�߂ɗL���ł��B
