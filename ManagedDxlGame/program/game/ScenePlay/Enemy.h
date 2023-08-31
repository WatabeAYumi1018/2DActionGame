#pragma once
#include <random>
#include "../../engine/GameEngine.h"
#include "Character.h"

//主に敵のAIを管理するクラス

class MapManager;
class PlayCamera;

class Enemy :public Character
{
public:
	Enemy();
	virtual ~Enemy();

private:
	//-----メンバ変数-----//
	int m_size = 30;
	float m_moveTimeCounter = 0.0f;
	
	std::default_random_engine m_generator;								//ジェネレーター（乱数分布と組み合わせて生成）
	std::uniform_real_distribution<float> m_distribution{ 0.0f, 1.0f};	//乱数の分布（特定の範囲内で生成）
	TNL_CO_SEQUENCE(Enemy,&Enemy::SeqBaseAction);						//コルーチンシーケンス

	std::vector<std::vector<int>> m_enemy_csv;							//敵場所の読み取り用
	std::vector<sEnemyData> m_enemy_info;							//敵場所の情報格納用

	Character* m_player = nullptr;		//審議
	MapManager *m_mapmanager = nullptr;	//マップマネージャー

public:
	//-----メンバ関数-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const PlayCamera* camera) override;
	void Finalize() override;


	void LoadEnemy();							//敵キャラ生成
	float DistanceCalc();						//プレイヤーとの距離計算
	bool SeqBaseAction(const float delta_time);	//基本行動01（通常）
	bool SeqNextAction(const float delta_time);	//基本行動02（通常〜遷移がある場合のみ使用）
	bool SeqAttack(const float delta_time);		//攻撃処理(プレイヤーが一定以上近づくと攻撃)
};
	
//eAttackType m_eAttackType;										//アタックタイプタグ判定用