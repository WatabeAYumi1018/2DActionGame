#pragma once
#include "../../engine/GameEngine.h"

class MapManager;
class Character;

//�����蔻��̎��ʂƋ�̓I�������s���N���X
//���ۂ̌v�Z���ɂ��Ă�wta_IsIntersectCalc�ɂĒ�`

class CollisionCalc
{
public:
	CollisionCalc() {}
	virtual ~CollisionCalc() {}

	//-----�����o�֐�-----//
	 static void CollisionCalculate(Character *chara, MapManager*mapChip,int range);

private:

	static std::vector<std::vector<sCollisionInfo>> GetSurroundingChips(Character *chara, MapManager*mapChip, int range);

	static void CheckBoxCollision(Character *chara, MapManager*mapChip, const std::vector<std::vector<sCollisionInfo>>& surroundingChips);

	static void CheckLineCollision(Character *chara, MapManager*mapChip, const std::vector<std::vector<sCollisionInfo>>& surroundingChips);
	
};

//�����蔻��̏������s���N���X�i�v�Z����namespace�ɂĒ�`�j
//����Character�^�݂̂̑Ή�
