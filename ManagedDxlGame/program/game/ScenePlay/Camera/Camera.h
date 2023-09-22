#pragma once
#include "../../../engine/GameEngine.h"

//�v���C���[�Ǐ]�J����

class Player;
class Map;

class Camera
{

private:

	//-----�����o�ϐ�-----//
	tnl::Vector3 m_target = { 0, 0, 0 };	/*�Ǐ]�^�[�Q�b�g*/
	bool m_is_scroll = false;				/*�J�����X�N���[���O��*/

	//-----�����o�֐�-----//
	void MoveRange(Player* player, Map* map);
	void Scroll(Player* player, Map* map);

public:

	void Update(float delta_time, Player* player, Map* map);

	//-----Getter&Setter-----//
	tnl::Vector3 GetTarget() const { return m_target; }
};

