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

private:
	
	std::vector<GameObject*> m_gameObjects;
	tnl::Sequence<ScenePlay> m_sequence = tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqIdle);
	
	std::vector<Enemy*> m_enemies;			 // �G�̃��X�g
	std::map<int, sEnemyInfo> m_enemyInfos;  // �G�̏�񃊃X�g
	std::vector<EffectPlayer*> m_effects;	 /*�G�t�F�N�g*/

	void EnemyInit();
	void EffectInit();
	bool SeqIdle(float delta_time);


	//�J�ڌ�Aback,Map,UI,Player,Enemy�Ȃǂ�`�悷��
	//���݂̃V�[���ŕ`�悷��O���t�B�b�N��ς���
	int m_graph_hdl = 0;
};