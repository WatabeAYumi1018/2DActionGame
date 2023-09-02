#pragma once
#include "../../engine/GameEngine.h"
#include "../SceneAll/GameObjectManager.h"

class MapManager;
class Camera;
class Enemy;

//敵の読み取りを管理するクラス
class EnemyLoad 
{

public:
	EnemyLoad(MapManager* m_mapManager);
	~EnemyLoad();

private:
	
	std::vector<std::vector<int>> m_enemy_csv;			/*敵場所の読み取り用*/
	std::vector<sEnemyData> m_enemy_info;				/*敵場所の情報格納用*/	

    std::map<int, sEnemyInfo> enemyInfoMap;			/*ID*/


	MapManager* m_mapManager = nullptr;

public:

	//-----メンバ関数-----//
	void Initialize() ;
	void Update(float delta_time)  {}
	void LoadEnemy();
	const std::vector<sEnemyData>& GetEnemyData() const;
    //std::map<int, sEnemyInfo> LoadEnemyInfo(const std::string& csvPath);
	
	//-----Getter&Setter-----//
	const std::vector<sEnemyData>& GetEnemyInfo() const { return m_enemy_info; }
};
	//void Draw(float delta_time, const Camera* camera) override;
