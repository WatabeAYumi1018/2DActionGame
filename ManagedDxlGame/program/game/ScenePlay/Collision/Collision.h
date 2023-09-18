#pragma once
#include "../../../engine/GameEngine.h"

class Map1;
class Character;
class Player;
class Enemy;

//当たり判定の識別と具体的処理を行うクラス
//実際の計算式についてはwta_IsIntersectCalcにて定義

class Collision
{

public:
	Collision();
	~Collision() {}

private:
	//-----メンバ変数-----//
	tnl::Vector3 m_last_chara_pos;							/*前回取得したキャラクターの座標*/
	tnl::Vector3 m_clear_pos;								/*Clear地点の座標*/
	
	bool m_is_clear=false;


	std::vector<std::vector<sCollisionInfo>> m_cachedChips; /*前回取得した当たり判定情報*/

public:
	//-----メンバ関数-----//
	void CollisionCalculate(Character* chara, Map1* map, int range);
	void CollisionCharacter(Player* player, Enemy* enemy);
	tnl::Vector3 GetCharacterMapChipPos(const tnl::Vector3& charaPos, const Map1* map);

	void ResetClearFlag() { m_is_clear = false; }

private:

	void CheckBoxCollision(Character* chara, Map1* map, const std::vector<std::vector<sCollisionInfo>>& surroundingChips);
	void CheckLineCollision(Character* chara, Map1* map, const std::vector<std::vector<sCollisionInfo>>& surroundingChips);
	bool IsRowCollisionExists(const std::vector<sCollisionInfo>& rowChips);
	std::vector<sCollisionInfo> GetRowChips(int chip_x, int i, int range, const Map1* map);
	std::vector<std::vector<sCollisionInfo>> GetSurroundingChips(Character* chara, Map1* map, int range);

public:

	//-----Getter,Setter-----//
	const tnl::Vector3 GetClearPos() const { return m_clear_pos; }
	bool GetIsClear() const { return m_is_clear; }
};

//当たり判定の処理を行うクラス（計算式はnamespaceにて定義）
//現状Character型のみの対応
