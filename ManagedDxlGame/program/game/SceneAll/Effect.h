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
	tnl::Vector3 m_velocity = {1000,0,0};	/*���x*/
	bool m_is_finished = false;				/*�I���t���O*/
	float duration = 3.0f;					/*�G�t�F�N�g�̎�������*/
	float elapsed_time = 0.0f;				/*�o�ߎ���*/
	eEffectType m_type;						/*�G�t�F�N�g�̎��*/

	Player* m_player = nullptr;				/*�v���C���[*/

public:
	int GetSize() const { return m_size; }
	bool GetIsFinished() const { return m_is_finished; }
	void SetIsFinished(bool is_finished) { m_is_finished = is_finished; }
};