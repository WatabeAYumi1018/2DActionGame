#pragma once
#include "../../engine/sceneBase.h"
#include "../SceneAll/GameObject.h"

class GameObjectManager;
class Camera;
class MapManager;
class Collision;
class Character;
//class EnemyLoad;

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
	Camera*m_camera=nullptr;
	MapManager *m_map_chip_manager=nullptr;
	Collision *m_collision=nullptr;
	Character *m_player =nullptr;
	GameObjectManager *m_enemy_manager = nullptr;
	//Character *m_enemy = nullptr;
	//EnemyLoad *m_enemy_manager = nullptr;

private:
	std::vector<GameObject*> gameObjects;
	tnl::Sequence<ScenePlay> sequence_ = tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqIdle);
	bool SeqIdle(float delta_time);

	//�J�ڌ�Aback,Map,UI,Player,Enemy�Ȃǂ�`�悷��
	//���݂̃V�[���ŕ`�悷��O���t�B�b�N��ς���
	int graph_hdl = 0;
};