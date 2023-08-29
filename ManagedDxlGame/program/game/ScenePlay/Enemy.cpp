#include "Enemy.h"
#include <random>	

Enemy::Enemy() : Character(m_pos,m_size,m_hp,m_velocity){

}

Enemy::~Enemy(){}

void Enemy::Initialize() {

}

void Enemy::Update(float delta_time) {

}

void Enemy::Draw(float delta_time, const PlayCamera* camera) {

}

void Enemy::Finalize() {

}

bool Enemy::SeqBaseAction(const float delta_time) { 
	
    float chance = distribution(generator);

    //move��idle�̊m��
    if (chance < 0.001f) {
        tnl_sequence_.change(&Enemy::SeqNextAction);
        return true;
    }

    //�v���C���[�Ƃ̋����v�Z
    if (std::abs(m_pos.x - m_player->GetPos().x) < 10.0f) {
        tnl_sequence_.change(&Enemy::SeqAttack);
        return true;
    }
    DrawStringEx(0, 0, -1, "move");

    //�o�ߎ��Ԃ��J�E���g
    m_moveTimeCounter += delta_time;

    //idle��move���邽�шړ������̏��������Z�b�g����Ă��܂�
    //�r����idle�Ɉڍs�����ꍇ���A���Z�b�g������������Đ�������
    if (m_moveTimeCounter <= 2.0f) {

        TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]() {
            DrawStringEx(0, 50, -1, "right");
            m_pos.x += m_velocity.x * delta_time;
        });
    }
    else if (m_moveTimeCounter > 2.0f && m_moveTimeCounter <= 4.0f) {

        TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]() {
            DrawStringEx(0, 50, -1, "left");
            m_pos.x -= m_velocity.x * delta_time;
        });
        m_moveTimeCounter = 0.0f;   //���s����Ă��Ȃ�
    }
    tnl_sequence_.change(&Enemy::SeqBaseAction);
    TNL_SEQ_CO_END;
}

bool Enemy::SeqNextAction(const float delta_time) { 

	DrawStringEx(0, 0, -1, "idle");

    TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]() {
        //�A�j���[�V�����摜�Đ��\���Ƃ�
    });
    
    tnl_sequence_.change(&Enemy::SeqBaseAction);
    TNL_SEQ_CO_END;
}

bool Enemy::SeqAttack(const float delta_time) { 

    DrawStringEx(0, 0, -1, "attack");

    TNL_SEQ_CO_TIM_YIELD_RETURN(1, delta_time, [&]() {
        //�U���A�j���[�V�����Đ�
    });

    tnl_sequence_.change(&Enemy::SeqBaseAction);
    TNL_SEQ_CO_END;
}
