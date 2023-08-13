#pragma once
#include "../../engine/GameEngine.h"
#include "Player.h"

class Object;
class Player;

enum class eCollisionType {
	eCollision_None,
	eCollision_Block,
	eCollision_Line,
	eCollision_Max
};

class Collision {

public:
	Collision(tnl::Vector3 pos,int radius);
	Collision(eCollisionType type);		//�}�b�v�����蔻��
	virtual ~Collision();

private:
	//-----�����o�ϐ�-----//
	tnl::Vector3 m_pos;
	eCollisionType m_type = eCollisionType::eCollision_None;
	//-----��`�����蔻��-----//
	int m_width = 0;
	int m_height = 0;
	//-----�~�����蔻��-----//
	int m_radius = 0;
	//-----���������蔻��-----//
	int m_lineStart = 0;
	int m_lineEnd = 0;

public:
	//-----�����o�֐�-----//
	//�L�����N�^�[���m�A�G�t�F�N�g�Ƃ̓����蔻��i�~���m�j
	bool HitCheck(const tnl::Vector3& circle01, const Object* circle02) {}
	//�L�����N�^�[�Ə��̓����蔻��i�~�Ƌ�`�j
	bool HitCheckFloor(const tnl::Vector3& circle, const Object* box) {}
	//�L�����N�^�[�Ɛ����̓����蔻��i�~�Ɛ����j
	bool HitCircleLine(const tnl::Vector3& circle, const Object& line);
	
	//�L�����N�^�[�ƒn�`�Ƃ̓����蔻��i�~�Ƌ�`�j
	//csv�}�b�v�`�b�v�f�[�^ID��1,2�͓����蔻�肠��A0�͂Ȃ�
	bool HitCheckMap(const tnl::Vector3& circle, const Object* box);

	//-----Setter,Getter-----//
	void SetWidth(int width) { m_width = width; }
	int GetWidth() { return m_width; }
	void SetHeight(int height) { m_height = height; }
	int GetHeight() { return m_height; }
};