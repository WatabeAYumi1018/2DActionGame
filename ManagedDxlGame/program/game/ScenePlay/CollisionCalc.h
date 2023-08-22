#pragma once
#include "../../engine/GameEngine.h"

class MapChip;
class Character;

class CollisionCalc {

public:
	CollisionCalc() {}
	~CollisionCalc() {}

	static std::vector<tnl::Vector3> GetSurroundingChips(Character* chara, MapChip* mapChip, int range);

private:
	//-----�����o�ϐ�-----//
	eCollisionType m_type = eCollisionType::eCollision_None;

private:

	//static std::vector<tnl::Vector3> GetSurroundingChips(Character* chara, MapChip* mapChip, int range);

	static eCollisionType GetCollisionTypeMap(int px, int py, MapChip* mapChip);


	static void CheckBoxCollision(Character* character, MapChip* mapChip,int range);

	static void CheckLineCollision(Character* character, MapChip* mapChip, int range);

public:

	static void CollisionCalculate(Character* character, MapChip* mapChip,int range);
};

//�����蔻��̏������s���N���X�i�v�Z����namespace�ɂĒ�`�j
//����Character�^�݂̂̑Ή�
