#include "../../Camera/Camera.h"
#include "EnemyDoragon.h"
#include "../Player/Player.h"

EnemyDoragon::EnemyDoragon(const sEnemyData& data, const sEnemyInfo& info, Player* player, Map* map, Collision* collision, Camera* camera) :
    Enemy(data, info, player, map, collision, camera)
{

}

EnemyDoragon::~EnemyDoragon()
{

}

void EnemyDoragon::Update(float delta_time)
{
    //�d�͂ŉ��ɗ�����
    m_pos.y += m_gravity.y * delta_time;

    //tnl_sequence_.update(delta_time);
}

void EnemyDoragon::Draw(float delta_time, const Camera* camera)
{
    //�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
    tnl::Vector3 draw_pos = m_pos - camera->GetTarget() +
        tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

    animLoader->Draw(delta_time, draw_pos);
}
