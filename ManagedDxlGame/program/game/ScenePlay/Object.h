#pragma once
#include "../../engine/GameEngine.h"

class Object {
	Object(Vector3 pos);
	virtual ~Object();

protected:
	Vector3 m_pos;						//座標
	Mesh* m_mesh;						//メッシュ

public:
	 void Initialize() {}
	 void Update(float delta_time) {}
	 void Draw() {}
	 void Finalize() {}
};