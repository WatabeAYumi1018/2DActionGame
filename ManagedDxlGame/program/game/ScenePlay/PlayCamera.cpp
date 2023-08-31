#include "PlayCamera.h"
#include "Character.h"
#include "MapManager.h"

void PlayCamera::Update(float delta_time, Character* chara, MapManager* mapChip)
{
	Scroll(chara, mapChip);
	MoveRange(chara, mapChip);
}

void PlayCamera::MoveRange(Character* chara, MapManager* mapChip)
{
	const float halfWidth = DXE_WINDOW_WIDTH >> 1;
	const float halfHeight = DXE_WINDOW_HEIGHT >> 1;
	const float maxX = mapChip->MAP_CHIP_SIZE * mapChip->GetMapChipX() - halfWidth;
	const float maxY = mapChip->MAP_CHIP_SIZE * mapChip->GetMapChipY() - halfHeight;

	//clamp�֐��Ŕ͈͓��Ɏ��߂�Bclamp(�l, �ŏ��l, �ő�l)
	m_target.x = std::clamp(m_target.x, halfWidth, maxX);
	m_target.y = std::clamp(m_target.y, halfHeight, maxY);
}

//���w�i�ƃ`�b�v�̃X�N���[���l���߂��邱��
void PlayCamera::Scroll(Character* chara, MapManager* mapChip)
{
	if (!is_active)
	{
		if (chara->GetPos().x > DXE_WINDOW_WIDTH >> 1 || 
				chara->GetPos().y > DXE_WINDOW_HEIGHT >> 1)
		{
			m_target = chara->GetPos();
			is_active = true;
		}
	}
	else
	{
		m_target += (chara->GetPos() - m_target) * 0.1f;
		
		if ((chara->GetPos().x <= DXE_WINDOW_WIDTH >> 1 &&
				chara->GetPos().y <= DXE_WINDOW_HEIGHT >> 1))
		{
			is_active = false; 
		}
	}
}
