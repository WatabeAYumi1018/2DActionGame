#pragma once
#include "../../../wta_library/wta_DrawAnim.h"
#include "../engine/GameEngine.h"
#include "Effect.h"

class Enemy;
class Player;

class EffectBoss : public Effect
{
public:

    EffectBoss(Enemy* enemy,Player* player);
    ~EffectBoss();

private:

    //-----�萔-----//
    const int FIREBALL_SIZE = 100;  // �t�@�C�A�[�{�[���̑傫��
    const float FIREBALL_SPEED = 10.0f;  // �t�@�C�A�[�{�[���̑��x

    //-----�����o�ϐ�-----//
    tnl::Vector3 m_fireball_pos;  // �t�@�C�A�[�{�[���̈ʒu
    tnl::Vector3 m_offset_flame = {600,-100,0};     // �Ή����˂̈ʒu
    tnl::Vector3 m_offset_fireball = { 200,0,0 };  // �t�@�C�A�[�{�[���̈ʒu
    tnl::Vector3 m_fireball_dir; // �t�@�C�A�[�{�[������ԕ���

    std::vector<tnl::Vector3> m_collision_circles_pos;		/*5�̉~�̍��W*/

    eEffectBossType e_effectType = eEffectBossType::None;

    //-----�|�C���^�ϐ�-----//
    Enemy* m_enemy = nullptr;				
    Player* m_player = nullptr;				

    //-----�����o�֐�-----//
    void FireballHandle();
    void FlameHandle();
    void EffectHandle();

public:

    void CalculateCollisionCircles();

    void Update(float delta_time) override;
    void Draw(float delta_time, const Camera* camera) override;
};