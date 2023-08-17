#pragma once
#include "../../engine/GameEngine.h"


class Character;

class CollisionCalc {

public:
	CollisionCalc();
	CollisionCalc(eCollisionType type);
	virtual ~CollisionCalc();

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
	//�L�����N�^�[�ƒn�`(eCollisionType)�Ƃ̓����蔻��i�~�Ƌ�`�j
	//���W��Ԃ�����tnl::Vector3�ɂ��ׂ�����
	tnl::Vector3 HitMapBoxCheck(eCollisionType type,Character *chara);

	//�L�����N�^�[�ƒn�`(eCollisionType)�Ƃ̓����蔻��i�~�Ɛ����j
	//HitMapBoxCheck==true�̏ꍇ�̂݁AHitMapLineCheck���Ăяo��
	tnl::Vector3 HitMapLineCheck(eCollisionType type, Character *chara);

	//�~�Ƌ�`�̓����蔻��v�Z
	bool IsIntersectCircleBox(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& box, const int boxSize);

	//�~�Ɛ����̓����蔻��v�Z
	bool IsIntersectCircleLine(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& lineStart, const tnl::Vector3& lineEnd);

	//�~���m�̓����蔻��v�Z
	bool IsIntersectCircleCircle(const tnl::Vector3& circle01, const int CircleSize01, const tnl::Vector3& circle02, const int CircleSize02);
	
	//-----Setter,Getter-----//
	void SetWidth(int width) { m_width = width; }
	int GetWidth() { return m_width; }
	void SetHeight(int height) { m_height = height; }
	int GetHeight() { return m_height; }
};