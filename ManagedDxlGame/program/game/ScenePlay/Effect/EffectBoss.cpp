#include "EffectBoss.h"
#include "../Character/Enemy/Enemy.h"
#include "../Camera/Camera.h"


EffectBoss::EffectBoss(Enemy* enemy, eEffectBossType effectType) :
    Effect(tnl::Vector3(0, 0, 0), enemy), e_effectType(effectType)
{
    //if (e_effectType == eEffectBossType::FireBall)
    //{
    //    m_fireball_pos = m_enemy->GetPos();
    //    //�v���C���[�̍��W���擾
    //    tnl::Vector3 playerPos = m_player->GetPos();
    //    m_fireball_direction = (playerPos - m_fireball_pos).tnl::normalized();
    //}
}

EffectBoss::~EffectBoss()
{

}

void EffectBoss::Update(float delta_time)
{
    if (m_is_active)
    {
        m_pos = m_enemy->GetPos();

        EffectHandle();

        run_time += delta_time;

        if (run_time > active_time)
        {
            run_time = 0;
            m_is_active = false;
        }
        //�t�@�C�A�{�[���̍��W�X�V
        if (m_is_fireball && e_effectType == eEffectBossType::FireBall)
        {
            m_fireball_pos += m_fireball_direction * FIREBALL_SPEED;
        }
    }
}

void EffectBoss::Draw(float delta_time, const Camera* camera)
{
    if (m_is_active)
    {
        tnl::Vector3 draw_pos;

            draw_pos = m_pos - m_offset - camera->GetTarget() +
                tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

        animLoader->Draw(delta_time * 2, draw_pos);
    }
}

void EffectBoss::CalculateCollisionCircles()
{
    m_collision_circles_pos.clear();

    tnl::Vector3 circle_pos;

    const int DRAGON_FIRE_SIZE = 100; //�Ή��T�C�Y

    if (e_effectType == eEffectBossType::Flame)
    {
        //�E�F�P�̉~
        circle_pos = -m_pos;
        m_collision_circles_pos.emplace_back(circle_pos);

        //�����F�Q�̉~
        for (int i = 1; i <= 2; i++)
        {
            circle_pos = m_pos - tnl::Vector3(i * DRAGON_FIRE_SIZE, 0, 0);
            m_collision_circles_pos.emplace_back(circle_pos);
        }

        //���F�R�̉~
        for (int i = 1; i <= 3; i++)
        {
            circle_pos = m_pos - tnl::Vector3((i + 2) * DRAGON_FIRE_SIZE, 0, 0);
            m_collision_circles_pos.emplace_back(circle_pos);
        }
    }

    else if (e_effectType == eEffectBossType::FireBall)
    {
        m_collision_circles_pos.clear();
        m_collision_circles_pos.emplace_back(m_fireball_pos);
    }
}
void EffectBoss::FlameHandle()
{
    if (m_is_flame)
    {
        animLoader->SetAnimation(63);
    }
}

void EffectBoss::FireballHandle()
{
    if (m_is_fireball)
    {
        animLoader->SetAnimation(64);  
    }
}

void EffectBoss::EffectHandle()
{
    if (e_effectType == eEffectBossType::Flame)
    {
        FlameHandle();
    }
    else if (e_effectType == eEffectBossType::FireBall)
    {
        FireballHandle();
    }
}