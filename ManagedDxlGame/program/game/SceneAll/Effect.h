#pragma once
#include "GameObject.h"

class Player;

class Effect : public GameObject
{
public:
	Effect(tnl::Vector3 m_pos,Player *player) :GameObject(m_pos){}
	virtual ~Effect() {}

protected:
	//-----�����o�ϐ�-----//
	int m_size = 20;						/*�T�C�Y*/
	tnl::Vector3 m_velocity = {1000,0,0};		/*���x*/
	eEffectType m_type;				/*�G�t�F�N�g�̎��*/

	Player* m_player = nullptr;		/*�v���C���[*/
};