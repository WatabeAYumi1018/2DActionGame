#pragma once
#include "../../engine/sceneBase.h"
#include "../SceneAll/GameObject.h"

class Camera;
class BackGround;
class Map;
class Collision;
class EnemyLoad;
class Player;
class Enemy;
class EffectPlayer;

class ScenePlay : public SceneBase 
{
public:
	ScenePlay();
	virtual ~ScenePlay();

	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;

	//-----�����o�ϐ�-----//
	BackGround *m_backGround=nullptr;
	Camera*m_camera=nullptr;
	Map *m_map=nullptr;
	Collision *m_collision=nullptr;
	EnemyLoad* m_enemyLoad = nullptr;
	Player *m_player = nullptr;
	Enemy* m_enemy = nullptr;

private:
	
	std::list<GameObject*> m_gameObjects;
	tnl::Sequence<ScenePlay> m_sequence = tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqSceneIdle);
	
	std::list<Enemy*> m_enemies;					// �G�̃��X�g
	std::map<int, sEnemyInfo> m_enemyInfos;			// �G�̏�񃊃X�g
	std::list<EffectPlayer*> m_effects;				/*�G�t�F�N�g*/

	std::list<Enemy*> m_enemiesRemoveList;			/*�폜�\��̓G*/
	std::list<EffectPlayer*> m_effectsRemoveList;	/*�폜�\��̃G�t�F�N�g*/

	void InitEnemy();
	void CreateEffect();
	bool SeqSceneIdle(float delta_time);

	void CollisionCheck(float delta_time);
	void RemoveAndDeleteEffect(EffectPlayer *effectPlayer);
	void RemoveAndDeleteEnemy(Enemy *enemy);
	void RemoveAndDelete();

	//int m_graph_hdl = 0;
};