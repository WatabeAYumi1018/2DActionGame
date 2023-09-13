#pragma once
#include "../../../wta_library/wta_DrawAnim.h"
#include "../engine/GameEngine.h"
#include "../../SceneAll/Effect.h"

class Player;

class EffectPlayer : public Effect
{
public:

	EffectPlayer(Player *player, eEffectPlayerType effectType);
	~EffectPlayer();

	wta::DrawAnim* animLoader = nullptr;		//�A�j���[�V�����f�[�^�����[�h

private:

	std::vector<tnl::Vector3> m_collision_circles_pos;  // 5�̉~�̍��W

	eEffectPlayerType m_effectType = eEffectPlayerType::None;
	
public:

	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;

	void CalculateCollisionCircles();	//�~�̍��W���v�Z����֐�(�r�[���̏ꍇ

private:

	void EffectBeamHandle();
	void EffectFireHandle();
	void EffectHandle();


public:
	//-----Getter,Setter-----//
	std::vector<tnl::Vector3> GetCollisionCirclesPos() const { return m_collision_circles_pos; }
};