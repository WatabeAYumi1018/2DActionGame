#pragma once

class Camera;

//�escene�ŃT�uManager�N���X���Ǘ����邽�߂̊��N���X

class GameObjectManager
{

public:

	//-----�����o�֐�-----//
	virtual void Update(float delta_time) { }
	virtual void Draw(float delta_time, const Camera* camera) {}
};