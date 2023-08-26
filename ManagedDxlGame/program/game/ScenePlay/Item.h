#pragma once
#include "Object.h"

class Item :public Object {

public:
	Item(tnl::Vector3 m_pos, tnl::Vector3 m_velocity);
	virtual ~Item();

	//-----�����o�ϐ�-----//
private:
	int m_item_type;			//�A�C�e���^�C�v

	//-----�����o�֐�-----//
public:
	void Initialize();
	void Update(float delta_time);
	void Draw();
	void Finalize();
};