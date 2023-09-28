#include "EffectBoss.h"
#include "../Character/Player/Player.h"

EffectBoss::EffectBoss(Player* player, eEffectBossType effectType) :
    Effect(tnl::Vector3(0, 0, 0), player), m_effectType(effectType)
{

}

EffectBoss::~EffectBoss()
{

}

void EffectBoss::Update(float delta_time)
{
    if (m_is_active)
    {
        m_pos = m_player->GetPos();

        EffectHandle();
        run_time += delta_time;

        if (run_time > active_time)
        {
            m_is_active = false;
        }
    }
}

void EffectBoss::Draw(float delta_time, const Camera* camera)
{
    // EffectPlayer�Ɠ��l�̕`�惍�W�b�N���K�p�\�ł��B
    // �K�v�ɉ����Ē������Ă��������B
}

void EffectBoss::CalculateFireballs()
{
    m_fireball_positions.clear();

    tnl::Vector3 fireball_pos;

    // 5�̉΂̋ʂ̈ʒu���v�Z���郍�W�b�N 
    // �Q�[���̗v���ɉ����Ē������Ă��������B
}

void EffectBoss::FireballHandle()
{
    if (m_is_fireball)
    {
        // �΂̋ʂ̃A�j���[�V�����̃��W�b�N
    }
}

void EffectBoss::FlameHandle()
{
    if (m_is_flame)
    {
        // ���ˏ�̉Ή��̃A�j���[�V�����̃��W�b�N
    }
}

void EffectBoss::EffectHandle()
{
    if (m_effectType == eEffectBossType::Flame)
    {
        FlameHandle();
    }
    else if (m_effectType == eEffectBossType::FireBall)
    {
        FireballHandle();
    }
}