#pragma once
#include "../../engine/GameObject.h"

//Player,Enemy�̊��N���X�i���ۃN���X�j

class Character :public GameObject
{
public:
	Character(const tnl::Vector3 pos, int size, int hp,const tnl::Vector3 velocity) :
		GameObject(pos), m_size(size), m_hp(hp), m_velocity(velocity){}
	virtual ~Character() {}

	//-----�����o�ϐ�-----//
protected:
	std::string m_name;							//���O
	int m_size;									//�����蔻��p�T�C�Y
	int m_hp;									//HP

	tnl::Vector3 m_gravity = {0,100,0};			//�d��
	tnl::Vector3 m_velocity = { 100,0,0 };				//���x(�G�t�F�N�g�≓�����̑����̎��Ɏg�p���邩��)

	eCharaType e_chara_type = eCharaType::Max;	//�L�����^�C�v����p

	bool m_is_ground=true;						//�ڒn��
	bool m_is_attack=false;						//�U����

public:
	//-----Setter,Getter-----//
	std::string GetName() const { return m_name; }
	int GetSize() const { return m_size; }
	int GetHp() const { return m_hp; }

	eCharaType GetTag() const { return e_chara_type; }
	void SetTag(eCharaType charaType) { e_chara_type = charaType; }
	
	tnl::Vector3 GetVelocity() const { return m_velocity; }
	void SetVelocity(tnl::Vector3 velocity) { m_velocity = velocity; }
};

//Effect* effect = nullptr;

//Character�N���X�̃f�X�g���N�^�����ʂȌ㏈����K�v�Ƃ��Ȃ��ꍇ�A
//virtual ~Character() = default;�̂悤�ɖ����I��= default���g�p���邱�Ƃ́A
//���̈Ӑ}�𖾊m�ɓ`���邽�߂ɗL���ł��B
