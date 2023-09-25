#pragma once
#include "../../engine/sceneBase.h"
#include "../SceneAll/GameObject.h"
#include "../SceneAll/Music/MusicManager.h"

//scene���ŕK�v�ȑS�Ă̗v�f���Ǘ�����N���X

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

class ScenePlay : public SceneBase 
{
public:

	ScenePlay(const std::string& stageName);

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
	BalloonInstruction *m_balloonInstruction=nullptr;
	ClearBalloon *m_clearBalloon=nullptr;
	EnemyLoad* m_enemyLoad = nullptr;
	Player *m_player = nullptr;
	Enemy* m_enemy = nullptr;

private:
	
	std::string m_stage_name;

	bool m_is_change_scene = false;

	std::list<GameObject*> m_gameObjects;
	
	std::list<Enemy*> m_enemies;					/*���������G*/
	std::map<int, sEnemyInfo> m_enemy_infos;		/*�G�̏��*/

	std::list<EffectPlayer*> m_effects;				/*�G�t�F�N�g*/

	std::list<Enemy*> m_enemiesRemoveList;			/*�폜�\��̓G*/
	std::list<EffectPlayer*> m_effectsRemoveList;	/*�폜�\��̃G�t�F�N�g*/

	tnl::Sequence<ScenePlay> m_sequence = tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqIdle);

	void InitEnemy();
	void InitMusic();

	void CreateEffect();

	void CollisionCheck(float delta_time);
	
	void RemoveAndDeleteEffect(EffectPlayer *effectPlayer);
	void RemoveAndDeleteEnemy(Enemy *enemy);
	void RemoveAndDelete();
	
	bool SeqIdle(float delta_time);
};