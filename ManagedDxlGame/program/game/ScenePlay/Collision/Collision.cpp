#include "../../../wta_library/wta_IsIntersectCalc.h"
#include "../Character/Character.h"
#include "../Character/Player/Player.h"
#include "../Character/Enemy/Enemy.h"
#include "../Map/Map.h"
#include "Collision.h"

Collision::Collision() : m_last_chara_pos(0, 0, 0)
{

}

tnl::Vector3 Collision::GetCharacterMapChipPos(const tnl::Vector3& charaPos, const Map* map)
{
    //�L�����̈ʒu����O���b�h���W���擾
    float chip_x = charaPos.x / map->MAP_CHIP_SIZE;
    float chip_y = charaPos.y / map->MAP_CHIP_SIZE;

    return tnl::Vector3(chip_x, chip_y, 0.0f);
}

std::vector<sCollisionInfo> Collision::GetRowChips(int chip_x, int i, int range, const Map* map)
{
    std::vector<sCollisionInfo> rowChips;

    //�L�����̍��W������͂̃}�b�v�`�b�v���擾
    for (int j = chip_x - range; j <= chip_x + range; ++j)
    {
        //�͈͊O�͖���
        if (j < 0 || j >= map->GetCollisionInfo()[i].size())
        {
            continue;
        }

        sCollisionInfo info = map->GetCollisionInfo()[i][j];

        //�����蔻�肪�Ȃ��ꍇ�͖���
        if (info.s_type != eMapCollisionType::None)
        {
            rowChips.emplace_back(info);
        }
    }
    return rowChips;
}

bool Collision::IsRowCollisionExists(const std::vector<sCollisionInfo>& rowChips)
{
    //�󂶂�Ȃ��ꍇ�̂ݐ�ɐi��
    return !rowChips.empty();
}

//�L�����N�^�[�̎��͂̃}�b�v�`�b�v���擾����(�����蔻�菈���y���̂���)
//��ʓI�ɃL�����𒆐S��(2*range+1)*(2*range+1)�͈̔͂̃}�b�v�`�b�v���擾����
std::vector<std::vector<sCollisionInfo>> Collision::GetSurroundingChips(Character* chara, Map* map, int range)
{
    tnl::Vector3 current_pos = chara->GetPos();
    //���݂̍��W����O�̍��W�������āA�}�b�v�`�b�v�̃T�C�Y��菬�����ꍇ�̓L���b�V����Ԃ�
    if ((current_pos - m_last_chara_pos).length() < map->MAP_CHIP_SIZE)
    {
        return m_cachedChips;
    }

    std::vector<std::vector<sCollisionInfo>> chips;

    //�L�����̍��W����O���b�h���W���擾
    tnl::Vector3 chip_pos = GetCharacterMapChipPos(current_pos, map);

    for (int i = chip_pos.y - range; i <= chip_pos.y + range; ++i)
    {
        //�͈͊O�͖���
        if (i < 0 || i >= map->GetCollisionInfo().size())
        {
            continue;
        }

        auto rowChips = GetRowChips(chip_pos.x, i, range, map);

        if (IsRowCollisionExists(rowChips))
        {
            chips.emplace_back(rowChips);
        }
    }
    m_cachedChips = chips;
    m_last_chara_pos = current_pos;

    return chips;
}

//��`�Ƃ̓����蔻��v�Z
void Collision::CheckBoxCollision(Character* chara, Map* map, const std::vector<std::vector<sCollisionInfo>>& surroundingChips)
{
    for (const auto& row : surroundingChips)
    {
        for (const auto& info : row)
        {
            if (info.s_type == eMapCollisionType::None || info.s_type == eMapCollisionType::Line ||
                info.s_type == eMapCollisionType::Clear)
            {
                continue;
            }
            tnl::Vector3 nearly_point = tnl::GetNearestRectPoint(info.s_pos, info.s_size, info.s_size, chara->GetPos());

            if ((nearly_point - chara->GetPos()).length() < chara->GetSize())
            {
                tnl::Vector3 normalize = tnl::Vector3::Normalize(chara->GetPos() - nearly_point);
                chara->SetPos(nearly_point + normalize * chara->GetSize());
            }
        }
    }
}

//�����Ƃ̓����蔻��
void Collision::CheckLineCollision(Character* chara, Map* map, const std::vector<std::vector<sCollisionInfo>>& surroundingChips)
{
    for (const auto& row : surroundingChips)
    {
        for (const auto& info : row)
        {
            if (info.s_type == eMapCollisionType::None || info.s_type == eMapCollisionType::Clear)
            {
                continue;
            }
            tnl::Vector3 nearly_point =

                tnl::GetNearestPointLine
                (
                    chara->GetPos(),
                    { info.s_pos.x - (info.s_size >> 1),info.s_pos.y + (info.s_size >> 1),0 },
                    { info.s_pos.x + (info.s_size >> 1),info.s_pos.y - (info.s_size >> 1),0 }
                );

            if ((nearly_point - chara->GetPos()).length() < chara->GetSize())
            {
                tnl::Vector3 normalize = tnl::Vector3::Normalize(chara->GetPos() - nearly_point);
                chara->SetPos(nearly_point + normalize * chara->GetSize());
            }
        }
    }
}

//�����蔻��ɉ����ĕ��򏈗�
void Collision::CollisionCalculate(Character* chara, Map* map, int range)
{
    auto surrounding_chips = GetSurroundingChips(chara, map, range);

    for (const auto& row : surrounding_chips) 
    {
        for (const auto& info : row) 
        {
            if (info.s_type == eMapCollisionType::Clear) 
            {
                 m_clear_pos = info.s_pos;
                m_is_clear = true;
                
                break;
            }
        }
        // ����Clear�ʒu�����o�����̂ŁA���̃��[�v���I��
        if (m_is_clear)
        {
            break;
        }
    }
    // ��x����Box��Line�̓����蔻����Ăяo��
    CheckBoxCollision(chara, map, surrounding_chips);
    CheckLineCollision(chara, map, surrounding_chips);
}

void Collision::CollisionCharacter(Player* player, Enemy* enemy)
{
    tnl::Vector3 player_pos = player->GetPos();
    float player_size = player->GetSize();

    tnl::Vector3 enemy_pos = enemy->GetPos();
    float enemy_size = enemy->GetSize();

    // 2�̃L�����N�^�[���Փ˂��Ă��邩�`�F�b�N
    if (wta::IsIntersectCircleCircle(player_pos, player_size, enemy_pos, enemy_size))
    {
        if (!player->GetIsInvincible())
        {
            if (enemy_pos.y > player_pos.y)
            {
                //�v���C���[���G�𓥂�ł���Ɛݒ�
                player->SetIsStamp(true);
                enemy->SetIsDead(true);
            }

            else if (player->GetIsRolling())
            {
				//�v���C���[����]���Ȃ�G��|��
				enemy->SetIsDead(true);
			}

            else
            {
                //�v���C���[��HP�����炷
                player->DecreaseHP(1);
                player->MakeInvincible();
            }
        }
    }
}

//////�����蔻��ɉ����ĕ��򏈗�
//void Collision::CollisionCalculate(Character* chara, Map* map, int range) {
//
//    //����͈͓��̃}�b�v�`�b�v���擾
//    auto surroundingChips = GetSurroundingChips(chara, map, range);
//
//    bool hasClearCollision = false;
//
//    for (const auto& row : surroundingChips)
//    {
//        for (const auto& info : row)
//        {
//            // �����蔻��̃^�C�v�Ɋ�Â��ď���
//            switch (info.s_type)
//            {
//            case eMapCollisionType::Box:
//
//                CheckBoxCollision(chara, map, surroundingChips);
//
//                break;
//
//            case eMapCollisionType::Line:
//
//                CheckLineCollision(chara, map, surroundingChips);
//
//            case eMapCollisionType::Clear:
//
//                //Clear�̍��W��ێ�
//                m_clear_pos = info.s_pos;
//
//                break;
//            }
//        }
//    }
//}
