#pragma once
#include "../../engine/GameEngine.h"
#include "Object.h"

class Character;
class MapChip;

//�v���C���[�Ǐ]�J����
class PlayCamera :public Object{
public:
	PlayCamera(tnl::Vector3 pos, Character* player);
	~PlayCamera();
private:
	//-----�����o�ϐ�-----//
	//float m_height;			//����
	float m_scroll_x;			//�X�N���[����X���W

	//-----�N���X�|�C���^�ϐ�-----//
	Character* m_player = nullptr;	//�v���C���[
	MapChip* m_map_chip = nullptr;	//�}�b�v�`�b�v

public:
	//-----�����o�֐�-----//
	void Update(float delta_time);	//���W�X�V
	void Scroll();	//�X�N���[��
};