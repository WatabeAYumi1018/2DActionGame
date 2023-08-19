#pragma once
#include "../../engine/GameEngine.h"

class MapChip;
class Character;

class CollisionCalc {

public:
	CollisionCalc();
	CollisionCalc(eCollisionType type);
	virtual ~CollisionCalc();

private:
	//-----�����o�ϐ�-----//
	eCollisionType m_type = eCollisionType::eCollision_None;

//public:
	//static tnl::Vector3 HandlePlayerMapCollision(Character* player, MapChip* mapChip);

private:
	//static void CheckCollisionByType(const tnl::Vector3& playerPos, float playerRadius, MapChip* mapChip, int i, int j);

	static eCollisionType GetCollisionTypeMap(Character& character, MapChip& mapChip);

	static void CheckBoxCollision(Character& character, MapChip& mapChip);

	static void CheckLineCollision(Character& character, MapChip& mapChip);

public:

	static void Calculate(Character& character, MapChip& mapChip);


	//-----�����o�֐�-----//
	////�L�����N�^�[�ƒn�`(eCollisionType)�Ƃ̓����蔻��i�~�Ƌ�`�j
	////���W��Ԃ�����tnl::Vector3�ɂ��ׂ�����
	//tnl::Vector3 HitMapBoxCheck(eCollisionType type,Character *chara);

	////�L�����N�^�[�ƒn�`(eCollisionType)�Ƃ̓����蔻��i�~�Ɛ����j
	////HitMapBoxCheck==true�̏ꍇ�̂݁AHitMapLineCheck���Ăяo��
	//tnl::Vector3 HitMapLineCheck(eCollisionType type, Character *chara);

	////�~�Ƌ�`�̓����蔻��v�Z
	//bool IsIntersectCircleBox(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& box, const int boxSize);

	////�~�Ɛ����̓����蔻��v�Z
	//bool IsIntersectCircleLine(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& lineStart, const tnl::Vector3& lineEnd);

	////�~���m�̓����蔻��v�Z
	//bool IsIntersectCircleCircle(const tnl::Vector3& circle01, const int CircleSize01, const tnl::Vector3& circle02, const int CircleSize02);
};