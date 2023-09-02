#pragma once
#include <random>
#include "../../engine/GameEngine.h"
#include "Character.h"

//主に敵のAIを管理するクラス

class EnemyLoad;
class Camera;

class Enemy :public Character
{

public:

	Enemy(const sEnemyData& data);
	~Enemy() {}

private:

	//-----メンバ変数-----//
	float m_moveTimeCounter = 0.0f;
	eEnemyType m_type = eEnemyType::None;					/*敵のタイプ*/

	std::default_random_engine m_generator;								//ジェネレーター（乱数分布と組み合わせて生成）
	std::uniform_real_distribution<float> m_distribution{ 0.0f, 1.0f};	//乱数調節（idle→move）
	TNL_CO_SEQUENCE(Enemy,&Enemy::SeqBaseAction);						//コルーチンシーケンス

	Character* m_player = nullptr;		//審議
	EnemyLoad *m_enemyLoad = nullptr;	//敵読み取り

public:
	//-----メンバ関数-----//
	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;

	float DistanceCalc();						//プレイヤーとの距離計算
	bool SeqBaseAction(const float delta_time);	//基本行動01（通常）
	bool SeqNextAction(const float delta_time);	//基本行動02（通常〜遷移がある場合のみ使用）
	bool SeqAttack(const float delta_time);		//攻撃処理(プレイヤーが一定以上近づくと攻撃)
};
	