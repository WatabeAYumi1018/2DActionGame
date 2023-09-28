#pragma once
#include "../../../wta_library/wta_DrawAnim.h"
#include "../engine/GameEngine.h"
#include "Effect.h"

class Enemy;

class EffectBoss : public Effect
{
public:

    EffectBoss(Enemy* enemy, eEffectBossType effectType);
    ~EffectBoss();

private:

    //-----�萔-----//
    const int FIREBALL_SIZE = 100;  // �t�@�C�A�[�{�[���̑傫��
    const float FIREBALL_SPEED = 10.0f;  // �t�@�C�A�[�{�[���̑��x

    //-----�����o�ϐ�-----//
    tnl::Vector3 m_fireball_pos;  // �t�@�C�A�[�{�[���̈ʒu
    tnl::Vector3 m_fireball_direction; // �t�@�C�A�[�{�[������ԕ���

    std::vector<tnl::Vector3> m_collision_circles_pos;		/*5�̉~�̍��W*/

    
    eEffectBossType e_effectType = eEffectBossType::None;

    Enemy* m_enemy = nullptr;				/*�v���C���[*/


    bool m_is_fireball = false;  /*�Ή��{�[��*/
    bool m_is_flame = false;     /*�Ή�����*/

    void FireballHandle();
    void FlameHandle();
    void EffectHandle();

public:

    void CalculateCollisionCircles();

    void Update(float delta_time) override;
    void Draw(float delta_time, const Camera* camera) override;
};