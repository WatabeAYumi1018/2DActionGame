#pragma once
#include "../../SceneAll/GameObject.h"



class Wind
{
	enum class sWindState
	{
		Blowing,
		Stopped
	};

public:

	Wind();

private:

	//-----�����o�ϐ�-----//
	int m_direction;								/*���̕���*/
	float m_wind_strength=2.0f;						/*���̋���*/
	float m_time;									/*��������*/
	const float BLOWING_TIME = 2.0f;				/*������������*/
	const float STOPPED_TIME = 10.0f;				/*�����~�ގ���*/
	sWindState s_wind_state= sWindState::Stopped;	/*���̏��*/

public:

	//-----�����o�֐�-----//
	void Update(float delta_time);	/*���̋����̍X�V*/

	//-----Getter&Setter-----//
	int GetDirection() const { return m_direction; }
	float GetWindStrength() const { return m_wind_strength; }
};