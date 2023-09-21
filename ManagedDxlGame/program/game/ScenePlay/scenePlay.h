#pragma once
#include "../../engine/sceneBase.h"
#include "../SceneAll/GameObject.h"

//scene���ŕK�v�ȑS�Ă̗v�f���Ǘ�����N���X

class Camera;
class BackGround;
class Map;
class Collision;
class ClearBalloon;
class EnemyLoad;
class Player;
class Enemy;
class EffectPlayer;

class ScenePlay : public SceneBase 
{
public:
	ScenePlay(const std::string& stageName);
	virtual ~ScenePlay();

	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;

	//-----�����o�ϐ�-----//
	BackGround *m_backGround=nullptr;
	Camera *m_camera=nullptr;
	Map *m_map=nullptr;
	Collision *m_collision=nullptr;
	ClearBalloon *m_clearBalloon=nullptr;
	EnemyLoad* m_enemyLoad = nullptr;
	Player *m_player = nullptr;
	Enemy* m_enemy = nullptr;

private:
	
	std::string m_stage_name;

	float m_enemy_respawn_time = 5.0f;

	bool m_is_change_scene = false;

	std::list<GameObject*> m_gameObjects;
	tnl::Sequence<ScenePlay> m_sequence = tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqSceneIdle);
	
	std::list<Enemy*> m_enemies;					// �G�̃��X�g
	std::map<int, sEnemyInfo> m_enemy_infos;			// �G�̏�񃊃X�g

	std::list<EffectPlayer*> m_effects;				/*�G�t�F�N�g*/

	std::list<Enemy*> m_enemiesRemoveList;			/*�폜�\��̓G*/
	std::list<EffectPlayer*> m_effectsRemoveList;	/*�폜�\��̃G�t�F�N�g*/

	void InitEnemy();
	void CreateEffect();
	bool SeqSceneIdle(float delta_time);

	void CollisionCheck(float delta_time);
	void EnemyRespawn(float delta_time);

	bool ClearCheckErea();
	void RemoveAndDeleteEffect(EffectPlayer *effectPlayer);
	void RemoveAndDeleteEnemy(Enemy *enemy);
	void RemoveAndDelete();
};