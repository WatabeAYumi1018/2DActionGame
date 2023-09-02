#include <random>
#include "Enemy.h"
#include "Player.h"
#include "MapManager.h"
#include "Camera.h"

Enemy::Enemy(const sEnemyData& data) : Character(m_pos, m_size, m_hp, m_velocity)
{
    //csvで読み取ったデータを代入
    this->m_pos = data.s_pos;
    this->m_type = data.s_type;
}

void Enemy::Update(float delta_time) 
{
    tnl_sequence_.update(delta_time);
}

void Enemy::Draw(float delta_time, const Camera* camera)
{
    //カメラの位置に合わせて描画位置をずらす
    tnl::Vector3 draw_pos = m_pos - camera->GetTarget() +
        tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
   
    switch (m_type)
    {
    case eEnemyType::None:

        break;
    
    case eEnemyType::Slim:
           
        DrawCircle(draw_pos.x, draw_pos.y, 30, -1);
           
        break;
    
    defalut:
        break;
    }
}

float Enemy::DistanceCalc()
{
    float distance = std::sqrt
    (
        //powは2乗（三平方の定理）
        std::pow(m_pos.x - m_player->GetPos().x, 2) +
        std::pow(m_pos.y - m_player->GetPos().y, 2)
    );
    return distance;
}

bool Enemy::SeqBaseAction(const float delta_time) 
{ 
    if (m_player) {
        float chance = m_distribution(m_generator);

        //move→idleの確率
        if (chance < 0.001f)
        {
            tnl_sequence_.change(&Enemy::SeqNextAction);
        }

        //プレイヤーとの距離計算
        if (std::abs(m_pos.x - m_player->GetPos().x) < 2.0f)
        {
            tnl_sequence_.change(&Enemy::SeqAttack);
        }
        DrawStringEx(0, 0, -1, "move");

        //経過時間をカウント
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
        tnl_sequence_.change(&Enemy::SeqBaseAction);
        TNL_SEQ_CO_END;
    }
}

bool Enemy::SeqNextAction(const float delta_time)
{ 
	DrawStringEx(0, 0, -1, "idle");

    TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
    {
        //アニメーション画像再生表示とか
    });
    tnl_sequence_.change(&Enemy::SeqBaseAction);
    TNL_SEQ_CO_END;
}

bool Enemy::SeqAttack(const float delta_time)
{ 
    DrawStringEx(0, 0, -1, "attack");

    TNL_SEQ_CO_TIM_YIELD_RETURN(1, delta_time, [&]()
    {
        //攻撃アニメーション再生
    });

    tnl_sequence_.change(&Enemy::SeqBaseAction);
    TNL_SEQ_CO_END;
}

