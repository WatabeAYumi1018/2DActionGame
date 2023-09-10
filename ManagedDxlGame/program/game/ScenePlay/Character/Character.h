#pragma once
#include "../../SceneAll/GameObject.h"
#include "../../../wta_library/wta_DrawAnim.h"


//Player,Enemy�̊��N���X

class Character :public GameObject
{

public:
	Character(const tnl::Vector3 pos, int size, int hp, const tnl::Vector3 velocity);
	virtual ~Character();

	//-----�����o�ϐ�-----//
protected:
	int m_size;										/*�����蔻��p�T�C�Y*/
	int m_hp;										/*HP*/

	tnl::Vector3 m_velocity = { 100,0,0 };			/*���x*/
	tnl::Vector3 m_gravity = { 0,100,0 };			/*�d��*/

	float m_invincible_time = 0.0f;					/*���G����*/

	bool m_is_ground = true;						/*�ڒn��*/
	bool m_is_jump = false;							/*�W�����v��*/
	bool m_is_attack = false;						/*�U����*/
	bool m_is_dead = false;							/*���S*/
	bool m_is_direction_right = true;				/*�E����*/
	bool m_is_invincible = false;					/*���G*/



	wta::DrawAnim* animLoader = nullptr;		//�A�j���[�V�����f�[�^�����[�h

public:
	//-----�����o�֐�-----//
	void DecreaseHP(int damage);
	void MakeInvincible();

	//-----Setter,Getter-----//
	int GetSize() const { return m_size; }
	int GetHp() const { return m_hp; }

	int GetIsDead() const { return m_is_dead; }
	void SetIsDead(bool is_dead) { m_is_dead = is_dead; }

	tnl::Vector3 GetVelocity() const { return m_velocity; }
	void SetVelocity(tnl::Vector3 velocity) { m_velocity = velocity; }

	bool GetIsInvincible() const { return m_is_invincible; }
};


//Character�N���X�̃f�X�g���N�^�����ʂȌ㏈����K�v�Ƃ��Ȃ��ꍇ�A
//virtual ~Character() = default;�̂悤�ɖ����I��= default���g�p���邱�Ƃ́A
//���̈Ӑ}�𖾊m�ɓ`���邽�߂ɗL���ł��B
