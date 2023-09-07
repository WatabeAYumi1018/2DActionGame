#include "../../Camera/Camera.h"
#include "EnemySlim.h"
#include "../Player/Player.h"

EnemySlim::EnemySlim(const sEnemyData& data, const sEnemyInfo& info,Player* player, Map* map, Collision* collision) :
    Enemy(data, info, player,map,collision)
{
    
}

EnemySlim::~EnemySlim() 
{

}

void EnemySlim::Update(float delta_time)
{
	//�d�͂ŉ��ɗ�����
	m_pos.y += (m_gravity.y * delta_time)*0.1f;

	tnl_sequence_.update(delta_time);
}

void EnemySlim::Draw(float delta_time, const Camera* camera)
{
	//�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
	tnl::Vector3 draw_pos = m_pos - camera->GetTarget() +
		tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

    animLoader->Draw(delta_time, draw_pos);
}

bool EnemySlim::SeqMove(float delta_time)
{
    if (tnl_sequence_.isStart())
    {
        


        
    }

    if (m_player) 
    {
        //�v���C���[�Ƃ̋����v�Z
        if (std::abs(m_pos.x - m_player->GetPos().x) < 100.0f)
        {
            tnl_sequence_.change(&EnemySlim::SeqAttack);
        }
        DrawStringEx(0, 0, -1, "move");

        //�o�ߎ��Ԃ��J�E���g
        //m_moveTimeCounter += delta_time;

        TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
        {
                animLoader->SetAnimation(20);
                
                //�����̓����蔻�����Ɍv�Z�i�����蔻���ID���擾����΂��������j

                m_pos.x += m_velocity.x * delta_time;

                m_is_dirction_right = true;
        });

        TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
        {
                animLoader->SetAnimation(21);
                m_pos.x -= m_velocity.x * delta_time;

                m_is_dirction_right = false;
        });

        tnl_sequence_.change(&EnemySlim::SeqIdle);

#if 0
        if (m_moveTimeCounter <= 2.0f)
        {
            TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
            {
                    animLoader->SetAnimation(20);
                    m_pos.x += m_velocity.x * delta_time;

                    m_is_dirction_right = true;
            });
        }
        else if (m_moveTimeCounter > 2.0f && m_moveTimeCounter <= 4.0f)
        {
            TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
            {
                    animLoader->SetAnimation(21);
                    m_pos.x -= m_velocity.x * delta_time;

                    m_is_dirction_right = false;
            });
        }
        else if (m_moveTimeCounter > 4.0f)
        {
            m_moveTimeCounter = 0.0f;
        }
#endif

        TNL_SEQ_CO_END;
    }
}

//���E�ł��ꂼ��ʁX�ɍ��
//ScenePlay�ɂ�Collision���聨�ړ���������̒n�`�݂ā��ړ����邩�ǂ���

bool EnemySlim::SeqIdle(float delta_time)
{
    DrawStringEx(0, 50, -1, "idle");

    TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]()
    {
        if (m_is_dirction_right) 
        {
            animLoader->SetAnimation(18);
        }
        else
        {
			animLoader->SetAnimation(19);
		}
    });

    tnl_sequence_.change(&EnemySlim::SeqMove);
    TNL_SEQ_CO_END;
}

bool EnemySlim::SeqAttack(float delta_time)
{
    DrawStringEx(0, 0, -1, "attack");

    TNL_SEQ_CO_TIM_YIELD_RETURN(1, delta_time, [&]()
    {
        if (m_is_dirction_right)
        {
			animLoader->SetAnimation(22);
            m_pos.x += m_velocity.x * delta_time;
		}
        else
        {
			animLoader->SetAnimation(23);
            m_pos.x -= m_velocity.x * delta_time;
		}
    });

    tnl_sequence_.change(&EnemySlim::SeqMove);
    TNL_SEQ_CO_END;
}

