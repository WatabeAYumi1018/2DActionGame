#include "../../wta_library/wta_IsIntersectCalc.h"
#include "Collision.h"
#include "../ScenePlay/Character.h"
#include "../ScenePlay/MapManager.h"

Collision::Collision(): m_lastCharaPos(0.0f, 0.0f, 0.0f)
{

}

tnl::Vector3 Collision::GetCharacterMapChipPos(const tnl::Vector3& charaPos, const MapManager* mapChip) 
{
	//�L�����̈ʒu����O���b�h���W���擾
	float chip_x = charaPos.x / mapChip->MAP_CHIP_SIZE;
	float chip_y = charaPos.y / mapChip->MAP_CHIP_SIZE;

	return tnl::Vector3(chip_x, chip_y, 0.0f);
}

std::vector<sCollisionInfo> Collision::GetRowChips(int chip_x, int i, int range, const MapManager* mapChip)
{
    std::vector<sCollisionInfo> rowChips;

    //�L�����̍��W������͂̃}�b�v�`�b�v���擾
    for (int j = chip_x - range; j <= chip_x + range; ++j)
    {
        //�͈͊O�͖���
        if (j < 0 || j >= mapChip->GetCollisionInfo()[i].size()) 
        {
            continue;
        }

        sCollisionInfo info = mapChip->GetCollisionInfo()[i][j];
        
        //�����蔻�肪�Ȃ��ꍇ�͖���
        if (info.s_type != eCollisionType::None)
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
std::vector<std::vector<sCollisionInfo>> Collision::GetSurroundingChips(Character* chara, MapManager* mapChip, int range)
{
    tnl::Vector3 currentPos = chara->GetPos();
    //���݂̍��W����O�̍��W�������āA�}�b�v�`�b�v�̃T�C�Y��菬�����ꍇ�̓L���b�V����Ԃ�
    if ((currentPos - m_lastCharaPos).length() < mapChip->MAP_CHIP_SIZE)
    {
        return m_cachedChips;
    }

    std::vector<std::vector<sCollisionInfo>> chips;
    
    //�L�����̍��W����O���b�h���W���擾
    tnl::Vector3 chipPos = GetCharacterMapChipPos(currentPos, mapChip);

    for (int i = chipPos.y - range; i <= chipPos.y + range; ++i)
    {
        //�͈͊O�͖���
        if (i < 0 || i >= mapChip->GetCollisionInfo().size()) 
        {
            continue;
        }

        auto rowChips = GetRowChips(chipPos.x, i, range, mapChip);
        
        if (IsRowCollisionExists(rowChips))
        {
            chips.emplace_back(rowChips);
        }
    }

    m_cachedChips = chips;
    m_lastCharaPos = currentPos;

    return chips;
}

//��`�Ƃ̓����蔻��v�Z
void Collision::CheckBoxCollision(Character *chara, MapManager*mapChip, const std::vector<std::vector<sCollisionInfo>>& surroundingChips)
{
    for (const auto& row : surroundingChips)
    {
        for (const auto& info : row)
        {
            if (info.s_type == eCollisionType::None)
            { 
                continue;
            }
            tnl::Vector3 nearly_point = tnl::GetNearestRectPoint(info.s_pos, info.s_size, info.s_size, chara->GetPos());

            if ((nearly_point - chara->GetPos()).length() < chara->GetSize())
            {
                tnl::Vector3 normalize = tnl::Vector3::Normalize(chara->GetPos() - nearly_point);
                chara->SetPos(nearly_point + normalize * chara->GetSize());
                //�Փˉ�������
                DrawStringEx(0, 70, -1, "boxhit");
            }
        }
    }
}

//�����Ƃ̓����蔻��
void Collision::CheckLineCollision(Character* chara, MapManager* mapChip, const std::vector<std::vector<sCollisionInfo>>& surroundingChips)
{
    for (const auto& row : surroundingChips) 
    {
        for (const auto& info : row) 
        {
          if (info.s_type == eCollisionType::None || info.s_type == eCollisionType::Box)
          {
              continue; 
          }
          tnl::Vector3 nearly_point = 

              tnl::GetNearestPointLine
              (
                  chara->GetPos() ,
                  { info.s_pos.x - (info.s_size >> 1),info.s_pos.y + (info.s_size>> 1 ),0 },
                  { info.s_pos.x + (info.s_size >> 1),info.s_pos.y - (info.s_size >> 1),0 }
              );
           
          if ((nearly_point - chara->GetPos()).length() < chara->GetSize())
           {
              tnl::Vector3 normalize = tnl::Vector3::Normalize(chara->GetPos() - nearly_point);
              chara->SetPos(nearly_point + normalize * chara->GetSize());
              //�Փˉ�������
              DrawStringEx(0, 90, -1, "linehit");
          }
        }
    }
}

////�����蔻��ɉ����ĕ��򏈗�
void Collision::CollisionCalculate(Character *chara, MapManager*mapChip,int range) {
    //����͈͓��̃}�b�v�`�b�v���擾
    auto surroundingChips = GetSurroundingChips(chara, mapChip, range);

    for (const auto& row : surroundingChips)
    {
        for (const auto& info : row)
        {
            // �����蔻��̃^�C�v�Ɋ�Â��ď���
            switch (info.s_type)
            {
            case eCollisionType::Box:
               
                CheckBoxCollision(chara, mapChip, surroundingChips);
               
                break;
            
            case eCollisionType::Line:

                CheckLineCollision(chara, mapChip, surroundingChips);
               
                break;
            
            default:
                break;
            }
        }               
    }
}

//-----------------------------�������Ă�������--------------------------------//

////�L�����N�^�[�ʒu���擾���A�}�b�vID���瓖���蔻��̃^�C�v���擾
////eCollisionType CollisionCalc::GetCollisionTypeMap(Character* chara, MapChip* mapChip) {
//eCollisionType CollisionCalc::GetCollisionTypeMap(int px, int py, MapChip* mapChip) {
//    // �L�����N�^�[�̃��[���h���W���}�b�v�̃O���b�h���W�ɕϊ�
//    int chara_x = px / mapChip->MAP_CHIP_SIZE;
//    int chara_y = py / mapChip->MAP_CHIP_SIZE;
//
//    int mx[3] = { chara_x - 1, chara_x, chara_x + 1 };
//    int my[3] = { chara_y - 1, chara_y, chara_y + 1 };
//
//    for (int i = 0; i < 3; ++i) {
//        for (int k = 0; k < 3; ++k) {
//            if (mx[k] < 0) continue;
//            if (mx[k] >= mapChip->MAP_CHIP_SIZE) continue;
//            if (mx[i] < 0) continue;
//            if (mx[i] >= mapChip->MAP_CHIP_SIZE) continue;
//
//            int cellId = mapChip->GetChipId(mx[k], my[i]);
//            if (-1 != cellId) {
//                DrawStringEx(10, 10, -1, "m = %d", cellId);
//                return mapChip->GetCollisionTypeById(cellId);
//            }
//        }
//    }
//    return eCollisionType::eCollision_None;
//
//}
