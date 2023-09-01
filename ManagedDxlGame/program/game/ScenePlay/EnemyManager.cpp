#include "EnemyManager.h"
#include "Camera.h"
#include "MapManager.h"
#include "Enemy.h"

EnemyManager::EnemyManager() 
{
     Initialize();
}

EnemyManager::~EnemyManager()
{
	delete m_enemy;
}

void EnemyManager::Initialize()
{
    //�G�̃X�|�[���ʒu��csv����ǂݍ���
    m_enemy_csv = tnl::LoadCsv<int>("csv/TileStageEnemy1-1.csv");
    LoadEnemy();
}

void EnemyManager::Draw(float delta_time, const Camera* camera)
{
    for (auto& enemy : m_enemy_info)
    {
        //�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
        tnl::Vector3 draw_pos = enemy.s_pos - camera->GetTarget() +
            tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

        switch (enemy.s_type)
        {
        case eEnemyType::None:
            break;
        case eEnemyType::Slim:
        
            //DrawCircle(draw_pos.x, draw_pos.y, m_enemy->GetSize(), -1);
        
            break;
    defalut:
        break;
        }
    }
}

//�J�����ɉf���Ă���ԓG�𐶐�����
void EnemyManager::LoadEnemy()
{
    //�t�@�C����̐��l��S�ēǂݍ���
    for (int i = 0; i < m_enemy_csv.size(); ++i)
    {
        for (int j = 0; j < m_enemy_csv[i].size(); ++j)
        {
            //�����蔻��̒��S���W���v�Z
            int posX = j * m_mapmanager->MAP_CHIP_SIZE + (m_mapmanager->MAP_CHIP_SIZE >> 1);
            int posY = i * m_mapmanager->MAP_CHIP_SIZE + (m_mapmanager->MAP_CHIP_SIZE >> 1);
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
