#pragma once
#include "../../SceneAll/GameObject.h"

class Player;

class Effect : public GameObject
{
public:
	Effect(tnl::Vector3 m_pos, Player* player) :GameObject(m_pos), m_player(player) {}
	virtual ~Effect() {}

protected:
	//-----�����o�ϐ�-----//
	int m_size = 30;						/*�T�C�Y*/

	float active_time = 0.8f;				/*�G�t�F�N�g�̎�������*/
	float run_time = 0.0f;					/*�o�ߎ���*/

	tnl::Vector3 m_offset;					/*�I�t�Z�b�g*/

	bool m_is_active = false;				/*�������t����*/

	eEffectPlayerType m_type;				/*�G�t�F�N�g�̎��*/

	//-----�|�C���^�ϐ�-----//
	Player* m_player = nullptr;				/*�v���C���[*/

public:
	//-----Getter,Setter-----//
	int GetSize() const { return  m_size; }

	void SetOffset(tnl::Vector3 offset) { m_offset = offset; }

	bool GetIsActive() const { return m_is_active; }
	void SetIsActive(bool is_moved) { m_is_active = is_moved; }
};