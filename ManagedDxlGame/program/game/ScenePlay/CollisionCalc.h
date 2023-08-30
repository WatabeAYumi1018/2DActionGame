#pragma once
#include "../../engine/GameEngine.h"

class MapManager;
class Character;

//�����蔻��̎��ʂƋ�̓I�������s���N���X
//���ۂ̌v�Z���ɂ��Ă�wta_IsIntersectCalc�ɂĒ�`

class CollisionCalc
{
private:
	//-----�����o�ϐ�-----//
	eCollisionType m_type = eCollisionType::None;

private:

	static std::vector<std::vector<sCollisionInfo>> GetSurroundingChips(Character *chara, MapManager*mapChip, int range);

public:
	static void CheckBoxCollision(Character *chara, MapManager*mapChip, const std::vector<std::vector<sCollisionInfo>>& surroundingChips);

	static void CheckLineCollision(Character *character, MapManager*mapChip, const std::vector<std::vector<sCollisionInfo>>& surroundingChips);
	
	static void CollisionCalculate(Character *character, MapManager*mapChip,int range);
};

//�����蔻��̏������s���N���X�i�v�Z����namespace�ɂĒ�`�j
//����Character�^�݂̂̑Ή�
