#include "../../wta_library/wta_Animation.h"
#include "CollisionCalc.h"
#include "../ScenePlay/Character.h"
#include "../ScenePlay/MapChip.h"


//�L�����N�^�[�ʒu���擾���A�}�b�vID���瓖���蔻��̃^�C�v���擾
eCollisionType CollisionCalc::GetCollisionTypeMap(Character* chara, MapChip* mapChip) {
    // �L�����N�^�[�̃��[���h���W���}�b�v�̃O���b�h���W�ɕϊ�
    int charaRow = chara->GetPos().y / MapChip::MAP_CHIP_SIZE;
    int charaCol = chara->GetPos().x / MapChip::MAP_CHIP_SIZE;
    // ���Y�ʒu��ID���擾
    int cellId = mapChip->GetChipId(charaRow, charaCol);
    // ID���g�p���ē����蔻��̃^�C�v���m�F
    return mapChip->GetCollisionTypeById(cellId);
}

//�L�����N�^�[�̎��͂̃}�b�v�`�b�v���擾����(�����蔻�菈���y���̂���)
//��ʓI�ɃL�����𒆐S��(2*range+1)*(2*range+1)�͈̔͂̃}�b�v�`�b�v���擾����
std::vector<tnl::Vector3> CollisionCalc::GetSurroundingChips(Character* chara, MapChip* mapChip, int range) {
    std::vector<tnl::Vector3> chips;
    tnl::Vector3 pos = chara->GetPos();
    //�O���b�h���W�ɕϊ�
    int row = pos.y / mapChip->MAP_CHIP_SIZE;
    int col = pos.x / mapChip->MAP_CHIP_SIZE;
    //�L�������W�𒆐S��5*5�͈̔͂̃}�b�v�`�b�v���擾
    for (int i = row - range; i <= row + range; ++i) {
        for (int j = col - range; j <= col + range; ++j) {
            //�͈͊O�̓X�L�b�v
            if (i < 0 || i >= mapChip->getMapChip().size() || j < 0 || j >= mapChip->getMapChip()[i].size())
            {
                continue;
            }
            chips.emplace_back(tnl::Vector3(j, i, 0));
        }
    }
    return chips;
}

//��`�Ƃ̓����蔻��
void CollisionCalc::CheckBoxCollision(Character* chara, MapChip* mapChip, int range) {
    //����͈͓��̃}�b�v�`�b�v���擾
    auto tiles = GetSurroundingChips(chara, mapChip, range);
    for (const auto& tile : tiles) {
        //Vector3��int�^�ɕϊ�
        int row = static_cast<int>(tile.x);
        int col = static_cast<int>(tile.y);
        if (wta::IsIntersectCircleBox(chara->GetPos(), chara->GetSize(), mapChip->GetChipPos(row, col), mapChip->MAP_CHIP_SIZE))
        {
            // �Փˉ�������
            DrawStringEx(0, 50, -1, "boxhit");
        }
    }
}

//�����Ƃ̓����蔻��
//��`�Ɠ����������s�����߂ɁA��������d�ɂȂ��Ă��܂����A�ǐ��ƕێ琫���l���ɂ��Ă���
void CollisionCalc::CheckLineCollision(Character* chara, MapChip* mapChip, int range) {
    auto tiles = GetSurroundingChips(chara, mapChip, range);
    for (const auto& tile : tiles) {
        int row = static_cast<int>(tile.x);
        int col = static_cast<int>(tile.y);
        //�����̎n�_�ƏI�_���擾
        tnl::Vector3 lineStart, lineEnd;
        mapChip->GetTileLineSegment(row, col, lineStart, lineEnd);
        if (wta::IsIntersectCircleLine(chara->GetPos(), chara->GetSize(), lineStart, lineEnd))
        {
            // �Փˉ�������
            DrawStringEx(0, 70, -1, "linehit");
        }
    }
}

//�����蔻��ɉ����ĕ��򏈗�
void CollisionCalc::CollisionCalculate(Character *chara, MapChip *mapChip,int range) {
    // �L�����N�^�[�ƒn�`�Ƃ̓����蔻��̃^�C�v���擾
    eCollisionType collisionType= GetCollisionTypeMap(chara, mapChip);
    // �����蔻��̃^�C�v�Ɋ�Â��ď���
    switch (collisionType) {
    case eCollisionType::eCollision_Box:
        CheckBoxCollision(chara,mapChip,range);
        break;
    case eCollisionType::eCollision_Line:
        //��`�̔����������ŁA�����̔�����s��
        CheckBoxCollision(chara, mapChip, range);
        CheckLineCollision(chara, mapChip, range);
        break;
    default:
        break;
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
