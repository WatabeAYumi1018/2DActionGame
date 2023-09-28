#pragma once
#include "../engine/GameEngine.h"
#include "Effect.h"

class Player;

class EffectPlayer : public Effect
{
public:

	EffectPlayer(Player *player, eEffectPlayerType effectType);
	~EffectPlayer();

private:

	//-----�����o�ϐ�-----//
	std::vector<tnl::Vector3> m_collision_circles_pos;			/*5�̉~�̍��W*/

	eEffectPlayerType m_effectType = eEffectPlayerType::None;	/*�G�t�F�N�g�̎��*/
	
	//-----�����o�֐�-----//
	void EffectBeamHandle();
	void EffectFireHandle();
	void EffectHandle();

	Player* m_player = nullptr;				/*�v���C���[*/

public:

	void CalculateCollisionCircles();							/*�~�̍��W���v�Z����֐�*/

	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;

public:
	//-----Getter,Setter-----//
	std::vector<tnl::Vector3> GetCollisionCirclesPos() const { return m_collision_circles_pos; }
};