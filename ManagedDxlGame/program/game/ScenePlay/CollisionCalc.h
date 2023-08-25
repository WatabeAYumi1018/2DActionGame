#pragma once
#include "../../engine/GameEngine.h"

class MapChip;
class Character;

//�����蔻��̎��ʂƋ�̓I�������s���N���X
//���ۂ̌v�Z���ɂ��Ă�wta_IsIntersectCalc�ɂĒ�`

class CollisionCalc {

public:
	CollisionCalc() {}
	~CollisionCalc() {}


private:
	//-----�����o�ϐ�-----//
	eCollisionType m_type = eCollisionType::eCollision_None;

private:

	static std::vector<std::vector<CollisionInfo>> GetSurroundingChips(Character *chara, MapChip *mapChip, int range);

	//static eCollisionType GetCollisionTypeMap(int px, int py, MapChip* mapChip);



	static void CheckLineCollision(Character *character, MapChip *mapChip, int range);

public:
	static void CheckBoxCollision(Character *chara, MapChip *mapChip, const std::vector<std::vector<CollisionInfo>>& surroundingChips);

	static void CollisionCalculate(Character *character, MapChip *mapChip,int range);
};

//�����蔻��̏������s���N���X�i�v�Z����namespace�ɂĒ�`�j
//����Character�^�݂̂̑Ή�
