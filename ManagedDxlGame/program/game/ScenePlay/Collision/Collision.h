#pragma once
#include "../../../engine/GameEngine.h"

class Map;
class Character;
class Player;
class Enemy;

//�����蔻��̎��ʂƋ�̓I�������s���N���X
//���ۂ̌v�Z���ɂ��Ă�wta_IsIntersectCalc�ɂĒ�`

class Collision
{

public:
	Collision();
	~Collision() {}

private:
	//-----�����o�ϐ�-----//
	tnl::Vector3 m_last_chara_pos;							/*�O��擾�����L�����N�^�[�̍��W*/
	tnl::Vector3 m_clear_pos;								/*Clear�n�_�̍��W*/
	
	std::vector<std::vector<sCollisionInfo>> m_cachedChips; /*�O��擾���������蔻����*/

public:
	//-----�����o�֐�-----//
	void CollisionCalculate(Character* chara, Map* map, int range);
	void CollisionCharacter(Player* player, Enemy* enemy);
	tnl::Vector3 GetCharacterMapChipPos(const tnl::Vector3& charaPos, const Map* map);

private:

	void CheckBoxCollision(Character* chara, Map* map, const std::vector<std::vector<sCollisionInfo>>& surroundingChips);
	void CheckLineCollision(Character* chara, Map* map, const std::vector<std::vector<sCollisionInfo>>& surroundingChips);
	bool IsRowCollisionExists(const std::vector<sCollisionInfo>& rowChips);
	std::vector<sCollisionInfo> GetRowChips(int chip_x, int i, int range, const Map* map);
	std::vector<std::vector<sCollisionInfo>> GetSurroundingChips(Character* chara, Map* map, int range);

public:

	//-----Getter,Setter-----//
	const tnl::Vector3 GetClearPos() const { return m_clear_pos; }
};

//�����蔻��̏������s���N���X�i�v�Z����namespace�ɂĒ�`�j
//����Character�^�݂̂̑Ή�
