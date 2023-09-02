#pragma once
#include "../../engine/GameEngine.h"
#include "../SceneAll/GameObjectManager.h"

class MapManager;
class Camera;
class Enemy;

//�G�̓ǂݎ����Ǘ�����N���X
class EnemyLoad 
{

public:
	EnemyLoad(MapManager* m_mapManager);
	~EnemyLoad();

private:
	
	std::vector<std::vector<int>> m_enemy_csv;			/*�G�ꏊ�̓ǂݎ��p*/
	std::vector<sEnemyData> m_enemy_info;				/*�G�ꏊ�̏��i�[�p*/	

    std::map<int, sEnemyInfo> enemyInfoMap;			/*ID*/


	MapManager* m_mapManager = nullptr;

public:

	//-----�����o�֐�-----//
	void Initialize() ;
	void Update(float delta_time)  {}
	void LoadEnemy();
	const std::vector<sEnemyData>& GetEnemyData() const;
    //std::map<int, sEnemyInfo> LoadEnemyInfo(const std::string& csvPath);
	
	//-----Getter&Setter-----//
	const std::vector<sEnemyData>& GetEnemyInfo() const { return m_enemy_info; }
};
	//void Draw(float delta_time, const Camera* camera) override;
