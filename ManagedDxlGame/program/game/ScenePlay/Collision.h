#pragma once
#include "../../engine/GameEngine.h"

class Object;

class Collision {

public:
	Collision(int width,int height);
	virtual ~Collision();

private:
	//-----��`�����蔻��-----//
	int m_width = 0;
	int m_height = 0;

public:
	//-----�����o�֐�-----//
	//�L�����N�^�[���m�̓����蔻����`�F�b�N
	bool HitCheck(const Vector3& pos,const Object* other);
	//�L�����N�^�[�Ə��̓����蔻����`�F�b�N
	bool HitCheckFloor(const Vector3& pos, const Object* other);

	//-----Setter,Getter-----//
	void SetWidth(int width) { m_width = width; }
	int GetWidth() { return m_width; }

	void SetHeight(int height) { m_height = height; }
	int GetHeight() { return m_height; }
};