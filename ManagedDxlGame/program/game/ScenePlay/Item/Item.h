#pragma once
#include "../../SceneAll/GameObject.h"

class Item :public GameObject
{
public:
	Item(tnl::Vector3 m_pos);
	virtual ~Item();

private:
	//-----�����o�ϐ�-----//
	int m_item_type;			//�A�C�e���^�C�v


};