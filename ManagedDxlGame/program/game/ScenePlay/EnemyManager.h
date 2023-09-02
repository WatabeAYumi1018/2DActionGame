#pragma once
#include "../SceneAll/GameObjectManager.h"
#include "Enemy.h"

class Camera;
class EnemyLoad;

//Enemy����ɃX�|�[���A�X�V�Ȃ�

class EnemyManager : public GameObjectManager 
{
public:

    EnemyManager();
	~EnemyManager();

private:
    
    EnemyLoad* m_enemyLoad;
    std::vector<Enemy*> m_enemies;
    std::map<int, sEnemyInfo> m_enemyInfos;

public:
    void Initialize() override;
    void Update(float delta_time) override;
    void Draw(float delta_time, const Camera* camera) override;
    void Finalize() override;
    
//
//public:
//    EnemyManager(MapManager* mapManager);
//	~EnemyManager();
//
//private:
//    std::map<int, sEnemyInfo> m_enemy_info;
//    std::vector<sEnemyData> m_enemy_data;
//
//public:
//    void AddEnemyData(const sEnemyData& enemy_data){ m_enemy_info[enemy_data.s_type_id] = enemy_data;}
//    // �G�̃C���X�^���X��ǉ�
//    void AddEnemy(const sEnemyData& data){m_enemy_data.emplace_back(data);}
//
//    // �����ID�̓G�̎�ނ����݂��邩�`�F�b�N
//    bool HasEnemyType(int id) const {return m_enemy_info.find(id) != m_enemy_info.end();}
//
//    void Update(float delta_time) override;
//    void Draw(float delta_time, const Camera* camera) override;
//    void Finalize() override;
    
 //   void CreateEnemies(const EnemyLoad *m_enemy_load);
};


//class EnemyManager {
//private:
//    std::vector<Enemy*> enemies;
//
//public:
//    void loadEnemies(const std::string& dataFile) {
//        EnemyDataReader reader;
//        std::vector<EnemyInfo> enemyData = reader.readDataFromCSV(dataFile);
//
//        for (const EnemyInfo& info : enemyData) {
//            enemies.push_back(new Enemy(info));
//        }
//    }
//
//    void updateAllEnemies() {
//        for (Enemy* enemy : enemies) {
//            enemy->update();
//        }
//    }
//
//    void drawAllEnemies() {
//        for (Enemy* enemy : enemies) {
//            enemy->draw();
//        }
//    }
//
//    ~EnemyManager() {
//        for (Enemy* enemy : enemies) {
//            delete enemy;
//        }
//        enemies.clear();
//    }
//};
