#pragma once

#include "GameObject.h"

class Effect : public GameObject

{
public:
	Effect(tnl::Vector3 m_pos);
	virtual ~Effect();

	//-----�����o�֐�-----//

	void Update(float delta_time);
	void Draw(float delta_time, const Camera* camera);
};