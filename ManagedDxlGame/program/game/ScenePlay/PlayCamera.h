#pragma once
#include "../../engine/GameEngine.h"

class Character;
class MapManager;

//�v���C���[�Ǐ]�J����
//���W�擾����␳�܂őS�ĊǗ�

class PlayCamera{

public:
	PlayCamera(Character *player);
	virtual ~PlayCamera();

private:
	//-----�����o�ϐ�-----//
	float m_scroll_x;				//�X�N���[����X���W
	Character *m_player=nullptr;	//�v���C���[�Ǐ]�p

public:
	//-----�����o�֐�-----//
	void Update(float delta_time);	//�X�V
	void Scroll();					//�X�N���[��
	void PosRevise();				//���W�␳

	//-----Getter-----//
	float GetScrollX() const { return m_scroll_x; }
};
