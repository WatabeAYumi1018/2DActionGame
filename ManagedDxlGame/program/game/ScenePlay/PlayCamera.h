#pragma once
#include "../../engine/GameEngine.h"

class Character;
class MapChip;

//�v���C���[�Ǐ]�J����
class PlayCamera{
public:
	PlayCamera(Character *player);
	~PlayCamera();

private:
	//-----�����o�ϐ�-----//
	float m_scroll_x;			//�X�N���[����X���W

	//-----�N���X�|�C���^�ϐ�-----//
	Character *m_player=nullptr;	//�v���C���[

public:
	//-----�����o�֐�-----//
	void Update(float delta_time);	//���W�X�V
	void Scroll();	//�X�N���[��

	//-----Getter-----//
	float GetScrollX() const { return m_scroll_x; }

};