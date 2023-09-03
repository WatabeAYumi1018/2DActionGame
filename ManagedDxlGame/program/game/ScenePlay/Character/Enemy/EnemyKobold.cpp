#include "../../Camera/Camera.h"
#include "EnemyKobold.h"
#include "../Player/Player.h"

EnemyKobold::EnemyKobold(const sEnemyData& data, const sEnemyInfo& info) :
    Enemy(data, info)
{

}

EnemyKobold::~EnemyKobold()
{
    delete animLoader;
}

void EnemyKobold::Update(float delta_time)
{
    //�d�͂ŉ��ɗ�����
    m_pos.y += m_gravity.y * delta_time;

    tnl_sequence_.update(delta_time);
}

void EnemyKobold::Draw(float delta_time, const Camera* camera)
{
    //�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
    tnl::Vector3 draw_pos = m_pos - camera->GetTarget() +
        tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

    animLoader->Draw(delta_time, draw_pos);
}

bool EnemyKobold::SeqMove(float delta_time)
{
    if (m_player) {
        float chance = m_distribution(m_generator);

        //move��idle�̊m��
        if (chance < 0.001f)
        {
            tnl_sequence_.change(&Enemy::SeqIdle);
        }

        //�v���C���[�Ƃ̋����v�Z
        if (std::abs(m_pos.x - m_player->GetPos().x) < 2.0f)
        {
            tnl_sequence_.change(&Enemy::SeqAttack);
        }
        DrawStringEx(0, 0, -1, "move");

        //�o�ߎ��Ԃ��J�E���g
        m_moveTimeCounter += delta_time;

        if (m_moveTimeCounter <= 2.0f)
        {
            TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
                {
                    DrawStringEx(0, 50, -1, "right");
                    m_pos.x += m_velocity.x * delta_time;
                });
        }
        else if (m_moveTimeCounter > 2.0f && m_moveTimeCounter <= 4.0f)
        {
            TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
                {
                    DrawStringEx(0, 50, -1, "left");
                    m_pos.x -= m_velocity.x * delta_time;
                });
        }
        else if (m_moveTimeCounter > 4.0f)
        {
            m_moveTimeCounter = 0.0f;
        }
        tnl_sequence_.change(&Enemy::SeqMove);
        TNL_SEQ_CO_END;
    }
}

bool EnemyKobold::SeqIdle(float delta_time)
{
    DrawStringEx(0, 0, -1, "idle");

    TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
        {
            animLoader->SetAnimation(18);   /*����Ȋ�����*/
        });
    tnl_sequence_.change(&Enemy::SeqMove);
    TNL_SEQ_CO_END;
}

bool EnemyKobold::SeqAttack(float delta_time)
{
    DrawStringEx(0, 0, -1, "attack");

    TNL_SEQ_CO_TIM_YIELD_RETURN(1, delta_time, [&]()
        {
            //�U���A�j���[�V�����Đ�
        });

    tnl_sequence_.change(&Enemy::SeqMove);
    TNL_SEQ_CO_END;
}

