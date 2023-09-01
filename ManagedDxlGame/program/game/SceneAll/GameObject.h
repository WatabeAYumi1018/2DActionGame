#pragma once
#include "../engine/GameEngine.h"

class Camera;

//�Q�[���I�u�W�F�N�g�̊��N���X

class GameObject
{

public:

	GameObject(const tnl::Vector3& pos) : m_pos(pos) {}
	virtual ~GameObject() {  }

protected:

	// ---- �����o�ϐ� ---- //
	tnl::Vector3 m_pos;

public:

	//-----�����o�֐�-----//
	virtual void Initialize() {}
	virtual void Update(float delta_time) { }
	virtual void Draw(float delta_time, const Camera* camera) {}
	virtual void Finalize() {}

	//-----Setter&Getter-----//
	const tnl::Vector3 GetPos() const { return m_pos; }
	void SetPos(const tnl::Vector3 pos) { m_pos = pos; }
};
