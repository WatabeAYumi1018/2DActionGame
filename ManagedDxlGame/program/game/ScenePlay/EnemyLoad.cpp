#include "../../library/tnl_csv.h"
#include "EnemyLoad.h"
#include "Camera.h"
#include "MapManager.h"
#include "Enemy.h"


std::map<int, sEnemyInfo> EnemyLoad::LoadEnemyInfo(const std::string& file_path) 
{
    std::map<int, sEnemyInfo> enemyInfo;

    // �G�̃p�����[�^�[�Ȃǂ�CSV����ǂݍ���
    auto data = tnl::LoadCsv(file_path);

    // �ŏ���0�s�ڂ͓ǂݎ��s�v�̂��ߍ폜
    if (!data.empty())
    {
        data.erase(data.begin());
    }
    
    for (const auto& row : data) 
    {
        sEnemyInfo info;
        info.s_id = row[0].getInt();
        info.s_name = row[1].getString();
        info.s_color = row[2].getString();
        info.s_hp = row[3].getInt();
        info.s_size = row[4].getInt();

        enemyInfo[info.s_id] = info;
    }
    return enemyInfo;
}

std::vector<sEnemyData> EnemyLoad::LoadEnemyData(const std::string& file_path)
{
    std::vector<sEnemyData> enemyData;

    // CSV��ǂݎ��
    auto csvData = tnl::LoadCsv(file_path);

    // �񎟌��z������[�v�ŉ�
    for (int i= 0; i < csvData.size(); ++i) 
    {
        for (int j = 0; j < csvData[i].size(); ++j) 
        {
            // 0�ł͂Ȃ��ꍇ�A�G�f�[�^�Ƃ��ĕۑ�
            if (csvData[i][j].getInt() != 0) 
            {
                sEnemyData data;

                //�����蔻��̒��S���W���v�Z
                int posX = j * m_mapmanager->MAP_CHIP_SIZE;
                int posY = i * m_mapmanager->MAP_CHIP_SIZE;

                data.s_pos = tnl::Vector3(posX, posY,0); 
                data.s_type_id = csvData[i][j].getInt();
                enemyData.emplace_back(data);
            }
        }
    }
    return enemyData;
}

//
//
//EnemyLoad::EnemyLoad(MapManager* m_mapManager):m_mapManager(m_mapManager)
//{
//     Initialize();
//}
//
//EnemyLoad::~EnemyLoad()
//{
//
//}
//
//void EnemyLoad::Initialize()
//{
//    //�G�̃X�|�[���ʒu��csv����ǂݍ���
//    m_enemy_csv = tnl::LoadCsv<int>("csv/stage1-1enemy.csv");
//    //std::map<int, sEnemyInfo> enemyInfoMap = tnl::LoadCsv<CsvCell>("csv/enemyInfo.csv");
//    LoadEnemy();
//}
//
////void EnemyLoad::Draw(float delta_time, const Camera* camera)
////{
////    for (auto& enemy : m_enemy_info)
////    {
////        //�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
////        tnl::Vector3 draw_pos = enemy.s_pos - camera->GetTarget() +
////            tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
////
////        switch (enemy.s_type)
////        {
////        case eEnemyType::None:
////            break;
////        case eEnemyType::Slim:
////        
////            //DrawCircle(draw_pos.x, draw_pos.y, m_enemy->GetSize(), -1);
////        
////            break;
////    defalut:
////        break;
////        }
////    }
////}
//
////csv�t�@�C���������ǂݎ��A�\���̂Ɗ֘A�t��
//void EnemyLoad::LoadEnemy()
//{
//    //�t�@�C����̐��l��S�ēǂݍ���
//    for (int i = 0; i < m_enemy_csv.size(); ++i)
//    {
//        for (int j = 0; j < m_enemy_csv[i].size(); ++j)
//        {
//            //���[���h���W�ɕϊ�
//            float posX = j * m_mapManager->MAP_CHIP_SIZE;
//            float posY = i * m_mapManager->MAP_CHIP_SIZE;
//            //eEnemyTypeType�Ɠǂݎ�����������֘A�t����i���������ŘA�����₷���悤�Ɂj
//            eEnemyType type = static_cast<eEnemyType>(m_enemy_csv[i][j]);
//            //�����蔻��̏����e�}�b�v�`�b�v�Ɋi�[
//            sEnemyData data;
//            data.s_pos = tnl::Vector3(posX, posY, 0);
//            data.s_type = type;
//            m_enemy_info.emplace_back(data);
//        }
//    }
//}
//
//std::map<int, sEnemyInfo> LoadEnemyInfo(const std::string& csvPath) {
//    std::map<int, sEnemyInfo> infoMap;
//    auto csvData = tnl::LoadCsv(csvPath);
//
//    if (!csvData.empty()) {
//        csvData.erase(csvData.begin());
//    }
//
//    for (const auto& row : csvData) {
//        sEnemyInfo info;
//        info.s_name = row[1].getString();
//        info.s_color = row[2].getString();
//        info.s_hp = row[3].getInt();
//        info.s_size = row[4].getInt();
//        infoMap[row[0].getInt()] = info;
//    }
//    return infoMap;
//}
