#include "Effect.h"
#include "../Character/Character.h"

Effect::Effect(tnl::Vector3 pos, Character* character) :GameObject(pos), m_character(character)
{
	// CSV����A�j���[�V�����f�[�^�����[�h
	animLoader = new wta::DrawAnim("csv/AnimLoad.csv", "graphics/animation");
}

Effect::~Effect()
{
	delete animLoader;
	animLoader = nullptr;
}