#pragma once
#include "../../engine/GameEngine.h"


class Object {
	Object(Vector3 m_pos);
	virtual ~Object();

protected:
	Vector3 m_pos;						//座標
	Mesh* m_mesh;						//メッシュ

public:
	virtual void Initialize();
	virtual void Update(float delta_time);
	virtual void Draw();
	virtual void Finalize();
};