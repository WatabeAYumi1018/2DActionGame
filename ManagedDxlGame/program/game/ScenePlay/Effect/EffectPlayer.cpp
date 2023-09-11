#include "../Character/Player/Player.h"
#include "../Camera/Camera.h"
#include "EffectPlayer.h"

EffectPlayer::EffectPlayer(Player *player, eEffectPlayerType effectType):
	Effect(tnl::Vector3(0, 0, 0), player), m_effectType(effectType)
{
	// CSV����A�j���[�V�����f�[�^�����[�h
	animLoader = new wta::DrawAnim("csv/AnimLoad.csv", "graphics/animation");
}

EffectPlayer::~EffectPlayer()
{
	delete animLoader;
	animLoader = nullptr;
}

void EffectPlayer::Update(float delta_time)
{
	EffectHandle();
	
	if (m_is_moved) 
	{
		elapsed_time += delta_time;

		if (elapsed_time > duration) 
		{
			m_is_moved = false;
		}
	}
}

void EffectPlayer::Draw(float delta_time, const Camera* camera)
{
	if (m_player->GetIsDirectionRight())
	{
		tnl::Vector3 draw_pos =
			m_pos + m_offset - camera->GetTarget() + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
		
		animLoader->Draw(delta_time * 2, draw_pos);
	}
	else
	{
		tnl::Vector3 draw_pos =
			m_pos - m_offset - camera->GetTarget() + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

		animLoader->Draw(delta_time * 2, draw_pos);
	}
}

void EffectPlayer::EffectFireHandle()
{
	if (m_is_moved)
	{
		if (m_player->GetIsDirectionRight())
		{
			animLoader->SetAnimation(42);  /*effect_beam_right*/
		}
		else
		{
			animLoader->SetAnimation(43);  /*effect_beam_left*/
		}
	}
}

void EffectPlayer::EffectBeamHandle()
{
	if (m_is_moved)
	{
		if (m_player->GetIsDirectionRight())
		{
			animLoader->SetAnimation(44);  /*effect_beam_right*/
		}
		else
		{
			animLoader->SetAnimation(45);  /*effect_beam_left*/
		}
	}
}

void EffectPlayer::EffectHandle()
{
	switch (m_effectType)
	{
	case eEffectPlayerType::Fire:

		EffectFireHandle();

		break;
		
	case eEffectPlayerType::Beam:
		
		EffectBeamHandle();
			
		break;
	}
}