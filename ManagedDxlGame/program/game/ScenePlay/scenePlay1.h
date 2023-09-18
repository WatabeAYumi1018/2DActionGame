#pragma once
#include "../../engine/sceneBase.h"
#include "../SceneAll/GameObject.h"

//scene���ŕK�v�ȑS�Ă̗v�f���Ǘ�����N���X
//��Map�Ɠ��l�A����͊�����������D�悵�A�������e�őf�ނ̈قȂ镡���R�s�[�N���X���쐬�B
//�����̂܂܂ł͍ė��p�����F���̂��߁A������߂ďC�����A�ЂƂ̃X�e�[�W�ɂ܂Ƃ߂�����ɕύX����B

class Camera;
class BackGround;
class Map1;
class Collision;
class ClearBalloon;
class EnemyLoad;
class Player;
class Enemy;
class EffectPlayer;

class ScenePlay1 : public SceneBase 
{
public:
	ScenePlay1();
	virtual ~ScenePlay1();

	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;

	//-----�����o�ϐ�-----//
	BackGround *m_backGround=nullptr;
	Camera*m_camera=nullptr;
	Map1*m_map=nullptr;
	Collision *m_collision=nullptr;
	ClearBalloon *m_clearBalloon=nullptr;
	EnemyLoad* m_enemyLoad = nullptr;
	Player *m_player = nullptr;
	Enemy* m_enemy = nullptr;

private:
	
	bool m_is_change_scene = false;

	std::list<GameObject*> m_gameObjects;
	tnl::Sequence<ScenePlay1> m_sequence = tnl::Sequence<ScenePlay1>(this, &ScenePlay1::SeqSceneIdle);
	
	std::list<Enemy*> m_enemies;					// �G�̃��X�g
	std::map<int, sEnemyInfo> m_enemyInfos;			// �G�̏�񃊃X�g
	std::list<EffectPlayer*> m_effects;				/*�G�t�F�N�g*/

	std::list<Enemy*> m_enemiesRemoveList;			/*�폜�\��̓G*/
	std::list<EffectPlayer*> m_effectsRemoveList;	/*�폜�\��̃G�t�F�N�g*/

	void InitEnemy();
	void CreateEffect();
	bool SeqSceneIdle(float delta_time);

	void CollisionCheck(float delta_time);
	bool ClearCheckErea();
	void RemoveAndDeleteEffect(EffectPlayer *effectPlayer);
	void RemoveAndDeleteEnemy(Enemy *enemy);
	void RemoveAndDelete();
};