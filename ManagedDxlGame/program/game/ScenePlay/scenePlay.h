#pragma once
#include "../../engine/sceneBase.h"
#include "../SceneAll/GameObject.h"
#include "../SceneAll/Music/MusicManager.h"

//scene内で必要な全ての要素を管理するクラス

class Camera;
class BackGround;
class Map;
class Collision;
class BalloonInstruction;
class ClearBalloon;
class EnemyLoad;
class Player;
class Enemy;
class EffectPlayer;
class EffectBoss;
class Wind;
class UI;
class Logo;

class ScenePlay : public SceneBase 
{
public:

	ScenePlay(const std::string& stageName);

	//-----メンバ関数-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;

	//-----メンバ変数-----//
	BackGround *m_backGround=nullptr;
	Camera *m_camera=nullptr;
	Map *m_map=nullptr;
	Collision *m_collision=nullptr;
	BalloonInstruction *m_balloonInstruction=nullptr;
	ClearBalloon *m_clearBalloon=nullptr;
	EnemyLoad* m_enemyLoad = nullptr;
	Player *m_player = nullptr;
	Enemy* m_enemy = nullptr;
	EffectPlayer* m_effectPlayer_beam = nullptr;
	EffectPlayer* m_effectPlayer_fire = nullptr;
	EffectBoss* m_effectBoss = nullptr;
	Wind* m_wind = nullptr;
	UI* m_ui = nullptr;
	Logo* m_logo = nullptr;

private:

	std::string m_stage_name;

	int m_clear_logo_hdl = 0;
	int m_burst_logo_hdl = 0;
	int m_fall_logo_hdl = 0;
	int m_clear_botton_hdl = 0;

	float m_respawn_time= 0.0f;

	bool m_is_change_scene = false;
	bool m_is_respawn = false;

	bool m_is_effect = false;

	std::list<GameObject*> m_gameObjects;
	
	std::list<Enemy*> m_enemies;								/*生成した敵*/
	std::map<int, sEnemyInfo> m_enemy_infos;					/*敵の情報*/

	std::list<Enemy*> m_enemies_remove_list;					/*削除予定の敵*/

	std::list<std::pair<Enemy*, float>> m_enemies_respawn_list;	/*リスポーン敵と秒数*/
	
	int m_total_respawns = 0;  // すべての敵の再生成回数をカウント
	const int max_total_respawns = 10;  // 最大再生成回数

	tnl::Sequence<ScenePlay> m_sequence = tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqIdle);

	void InitEnemy();
	void InitMusic();

	void CreateEffect();
	void CreateEnemy(float delta_time);

	void CollisionCheckBoss();
	void CollisionCheck(float delta_time);
	
	void RemoveAndDeleteEnemy(Enemy *enemy);
	void RemoveAndDelete();
	
	bool SeqIdle(float delta_time);
};