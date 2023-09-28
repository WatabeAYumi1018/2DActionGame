#include "Effect.h"
#include "../Character/Player/Player.h"

Effect::Effect(tnl::Vector3 m_pos, Player* player) :GameObject(m_pos), m_player(player)
{
	// CSV����A�j���[�V�����f�[�^�����[�h
	animLoader = new wta::DrawAnim("csv/AnimLoad.csv", "graphics/animation");
}

Effect::~Effect()
{
	delete animLoader;
	animLoader = nullptr;
}