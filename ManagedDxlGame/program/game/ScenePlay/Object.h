#pragma once
#include "../../engine/GameEngine.h"

class Object {
	Object(Vector3 pos);
	virtual ~Object();

protected:
	Vector3 m_pos;						//���W
	Mesh* m_mesh;						//���b�V��

public:
	 void Initialize() {}
	 void Update(float delta_time) {}
	 void Draw() {}
	 void Finalize() {}
};