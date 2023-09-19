#include "Camera.h"
#include "../Character/Player/Player.h"
#include "../Map/Map.h"

void Camera::Update(float delta_time, Player* player, Map* map)
{
	Scroll(player, map);
	MoveRange(player, map);
}

void Camera::MoveRange(Player* player, Map* map)
{
	const float halfWidth = DXE_WINDOW_WIDTH >> 1;
	const float halfHeight = DXE_WINDOW_HEIGHT >> 1;
	const float maxX = map->MAP_CHIP_SIZE * map->GetMapChipX() - halfWidth;
	const float maxY = map->MAP_CHIP_SIZE * map->GetMapChipY() - halfHeight;

	//clamp�֐��Ŕ͈͓��Ɏ��߂�Bclamp(�l, �ŏ��l, �ő�l)
	if (halfWidth < maxX)
	{
		m_target.x = std::clamp(m_target.x, halfWidth, maxX);
	}
	else
	{
		//csv�t�@�C���̃T�C�Y��max�ƂȂ�
		m_target.x = maxX;
	}
	m_target.y = std::clamp(m_target.y, halfHeight, maxY);
	//float distance_y = halfHeight - maxY;

	//if (distance_y < map->MAP_CHIP_SIZE)
	//{
	//	m_target.y = maxY;
	//}
	//else
	//{
	//	m_target.y = std::clamp(m_target.y, halfHeight, maxY);
	//}

}

//���w�i�ƃ`�b�v�̃X�N���[���l���߂��邱��
void Camera::Scroll(Player* player, Map* map)
{
	if (!m_is_active)
	{
		if (player->GetPos().x > DXE_WINDOW_WIDTH >> 1 ||
			player->GetPos().y > DXE_WINDOW_HEIGHT >> 1)
		{
			m_target = player->GetPos();
			m_is_active = true;
		}
	}
	else
	{
		m_target += (player->GetPos() - m_target) * 0.1f;

		if ((player->GetPos().x <= DXE_WINDOW_WIDTH >> 1 &&
			player->GetPos().y <= DXE_WINDOW_HEIGHT >> 1))
		{
			m_is_active = false;
		}
	}
}
