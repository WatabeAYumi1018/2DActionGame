#pragma once
#include "../../engine/GameObject.h"

class Item :public GameObject
{
public:
	Item(tnl::Vector3 m_pos);
	virtual ~Item();

private:
	//-----�����o�ϐ�-----//
	int m_item_type;			//�A�C�e���^�C�v

	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const PlayCamera* camera) override;
	void Finalize() override;
};