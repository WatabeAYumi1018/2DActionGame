#pragma once
#include "GameObject.h"

class Player;

class Effect : public GameObject
{
public:
	Effect(tnl::Vector3 m_pos,Player *player) :GameObject(m_pos), m_player(player) {}
	virtual ~Effect() {}

protected:
	//-----�����o�ϐ�-----//
	int m_size = 20;						/*�T�C�Y*/
	float duration = 0.8f;					/*�G�t�F�N�g�̎�������*/
	float elapsed_time = 0.0f;				/*�o�ߎ���*/
	
	tnl::Vector3 m_offset;					/*�I�t�Z�b�g*/
	
	bool m_is_moved = false;				/*�I���t���O*/

	eEffectPlayerType m_type;				/*�G�t�F�N�g�̎��*/

	Player* m_player = nullptr;				/*�v���C���[*/

public:

	int GetSize() const { return m_size; }

	void SetOffset(tnl::Vector3 offset) { m_offset = offset; }

	bool GetIsMoved() const { return m_is_moved; }
	void SetIsMoved(bool is_moved) { m_is_moved = is_moved; }
	
	float GetElapsedTime() const { return elapsed_time; }
	
	float GetDuration() const { return duration; }
};