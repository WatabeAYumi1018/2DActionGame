#include "../../library/tnl_csv.h"
#include "EnemyLoad.h"
#include "Camera.h"
#include "MapManager.h"
#include "Enemy.h"


EnemyLoad::EnemyLoad(MapManager* m_mapManager):m_mapManager(m_mapManager)
{
     Initialize();
}

EnemyLoad::~EnemyLoad()
{

}

void EnemyLoad::Initialize()
{
    //�G�̃X�|�[���ʒu��csv����ǂݍ���
    m_enemy_csv = tnl::LoadCsv<int>("csv/stage1-1enemy.csv");
    //std::map<int, sEnemyInfo> enemyInfoMap = tnl::LoadCsv<CsvCell>("csv/enemyInfo.csv");
    LoadEnemy();
}

//void EnemyLoad::Draw(float delta_time, const Camera* camera)
//{
//    for (auto& enemy : m_enemy_info)
//    {
//        //�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
//        tnl::Vector3 draw_pos = enemy.s_pos - camera->GetTarget() +
//            tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
//
//        switch (enemy.s_type)
//        {
//        case eEnemyType::None:
//            break;
//        case eEnemyType::Slim:
//        
//            //DrawCircle(draw_pos.x, draw_pos.y, m_enemy->GetSize(), -1);
//        
//            break;
//    defalut:
//        break;
//        }
//    }
//}

//csv�t�@�C���������ǂݎ��A�\���̂Ɗ֘A�t��
void EnemyLoad::LoadEnemy()
{
    //�t�@�C����̐��l��S�ēǂݍ���
    for (int i = 0; i < m_enemy_csv.size(); ++i)
    {
        for (int j = 0; j < m_enemy_csv[i].size(); ++j)
        {
            //���[���h���W�ɕϊ�
            float posX = j * m_mapManager->MAP_CHIP_SIZE;
            float posY = i * m_mapManager->MAP_CHIP_SIZE;
            //eEnemyTypeType�Ɠǂݎ�����������֘A�t����i���������ŘA�����₷���悤�Ɂj
            eEnemyType type = static_cast<eEnemyType>(m_enemy_csv[i][j]);
            //�����蔻��̏����e�}�b�v�`�b�v�Ɋi�[
            sEnemyData data;
            data.s_pos = tnl::Vector3(posX, posY, 0);
            data.s_type = type;
            m_enemy_info.emplace_back(data);
        }
    }
}

std::map<int, sEnemyInfo> LoadEnemyInfo(const std::string& csvPath) {
    std::map<int, sEnemyInfo> infoMap;
    auto csvData = tnl::LoadCsv(csvPath);

    if (!csvData.empty()) {
        csvData.erase(csvData.begin());
    }

    for (const auto& row : csvData) {
        sEnemyInfo info;
        info.s_name = row[1].getString();
        info.s_color = row[2].getString();
        info.s_hp = row[3].getInt();
        info.s_size = row[4].getInt();
        infoMap[row[0].getInt()] = info;
    }
    return infoMap;
}
