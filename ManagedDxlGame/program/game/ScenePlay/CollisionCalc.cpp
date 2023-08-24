#include "../../wta_library/wta_IsIntersectCalc.h"
#include "CollisionCalc.h"
#include "../ScenePlay/Character.h"
#include "../ScenePlay/MapChip.h"


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

//�L�����N�^�[�̎��͂̃}�b�v�`�b�v���擾����(�����蔻�菈���y���̂���)
//��ʓI�ɃL�����𒆐S��(2*range+1)*(2*range+1)�͈̔͂̃}�b�v�`�b�v���擾����
std::vector<std::vector<CollisionInfo>> CollisionCalc::GetSurroundingChips(Character *chara, MapChip *mapChip, int range) {
    std::vector<std::vector<CollisionInfo>> chips;
    tnl::Vector3 pos = chara->GetPos();
    //�O���b�h���W�ɕϊ�
    int chip_x = static_cast<int>(pos.x / mapChip->MAP_CHIP_SIZE);
    int chip_y = static_cast<int>(pos.y / mapChip->MAP_CHIP_SIZE);
    //�L�������W�𒆐S��5*5�͈̔͂̃}�b�v�`�b�v���擾
    for (int i = chip_y - range; i <= chip_y + range; ++i) {
        std::vector<CollisionInfo> rowChips;
        for (int j = chip_x - range; j <= chip_x + range; ++j) {
            //�͈͊O�̓X�L�b�v
            if (i < 0 || i >= mapChip->GetCollisionInfo().size() || j < 0 || j >= mapChip->GetCollisionInfo()[i].size())
            {
                rowChips.emplace_back(CollisionInfo());  // None type��CollisionInfo��ǉ�
                 continue;
            }
            rowChips.emplace_back(mapChip->GetCollisionInfo()[i][j]);
        }
        chips.emplace_back(rowChips);        
    }
    return chips;
}
//��`�Ƃ̓����蔻��v�Z
void CollisionCalc::CheckBoxCollision(Character *chara, MapChip *mapChip, const std::vector<std::vector<CollisionInfo>>& surroundingChips) {
    for (const auto& row : surroundingChips) {
        for (const auto& info : row) {
            if (info.type == eCollisionType::eCollision_None) { continue; }
            tnl::Vector3 nearly_point = tnl::GetNearestRectPoint(info.pos, info.size, info.size, chara->GetPos());
            if ((nearly_point - chara->GetPos()).length() < chara->GetSize()) {
                tnl::Vector3 normalize = tnl::Vector3::Normalize(chara->GetPos() - nearly_point);
                chara->SetPos(nearly_point + normalize * chara->GetSize());
                //�Փˉ�������
                DrawStringEx(0, 50, -1, "boxhit");
            }
        }
    }
}

//�����Ƃ̓����蔻��
//��`�Ɠ����������s�����߂ɁA��������d�ɂȂ��Ă��܂����A�ǐ��ƕێ琫���l���ɂ��Ă���
//void CollisionCalc::CheckLineCollision(Character* chara, MapChip* mapChip, int range) {
//    auto tiles = GetSurroundingChips(chara, mapChip, range);
//    for (const auto& tile : tiles) {
//        int x = static_cast<int>(tile.x);
//        int y = static_cast<int>(tile.y);
//        //�����̎n�_�ƏI�_���擾
//        tnl::Vector3 lineStart, lineEnd;
//        mapChip->GetTileLineSegment(y, x, lineStart, lineEnd);
//        if (wta::IsIntersectCircleLine(chara->GetPos(), chara->GetSize(), lineStart, lineEnd))
//        {
//            // �Փˉ�������
//            DrawStringEx(0, 70, -1, "linehit");
//        }
//    }
//}

////�����蔻��ɉ����ĕ��򏈗�
void CollisionCalc::CollisionCalculate(Character *chara, MapChip *mapChip,int range) {
    //����͈͓��̃}�b�v�`�b�v���擾
    auto surroundingChips = GetSurroundingChips(chara, mapChip, range);
    for (const auto& row : surroundingChips) {
        for (const auto& info : row) {
            // �����蔻��̃^�C�v�Ɋ�Â��ď���
            switch (info.type) {
            case eCollisionType::eCollision_Box:
                CheckBoxCollision(chara, mapChip, surroundingChips);
                break;
            case eCollisionType::eCollision_Line:
                //��`�̔����������ŁA�����̔�����s��
                CheckBoxCollision(chara, mapChip, surroundingChips);
                //CheckLineCollision(chara, mapChip, range);
                break;
            default:
                break;
            }
        }               
    }
}

//�����蔻��̗���
//�@�}�b�v�`�b�v��ID���擾�iMapChip�N���X�j
//�A�@���瓖���蔻��̃^�C�v���擾�iMapChip�N���X�j
//�B�L�����N�^�[�̍��W�𒆐S�Ƃ��ĂT�~�T�͈̔͂̃}�b�v�`�b�v���擾�iCollisionCalc�N���X�j
//�C�B���瓖���蔻��̃^�C�v���擾�iMapChip�N���X�j
//�D�A�ƇC���r���A�����蔻��̃^�C�v������iCollisionCalc�N���X�j
//�E�D����^�C�v�ɉ����������蔻��̔���A�v�Z���s���iCollisionCalc�N���X�j
//�F�E����L�����N�^�[�̍��W���X�V�iCollisionCalc�N���X�j   ���L�����������o�������͖�����
