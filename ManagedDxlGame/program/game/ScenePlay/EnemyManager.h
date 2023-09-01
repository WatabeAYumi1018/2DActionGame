#pragma once
#include "../../engine/GameEngine.h"
#include "../SceneAll/GameObjectManager.h"

class MapManager;
class Camera;
class Enemy;

//�G�̓ǂݎ����Ǘ�����N���X
class EnemyManager : public GameObjectManager
{

public:
	EnemyManager();
	~EnemyManager();

private:
	std::vector<std::vector<int>> m_enemy_csv;						//�G�ꏊ�̓ǂݎ��p
	std::vector<sEnemyData> m_enemy_info;							//�G�ꏊ�̏��i�[�p
	
	MapManager* m_mapmanager = nullptr;		//�}�b�v�}�l�[�W���[
	Enemy* m_enemy = nullptr;				//�G�L����

public:

	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override {}
	void Draw(float delta_time, const Camera* camera) override;
	
	void LoadEnemy();							//�G�L��������
};