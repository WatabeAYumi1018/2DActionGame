#include "../../wta_library/wta_IsIntersectCalc.h"
#include "CollisionCalc.h"
#include "../ScenePlay/Character.h"
#include "../ScenePlay/MapChip.h"


//�L�����N�^�[�ʒu���擾���A�}�b�vID���瓖���蔻��̃^�C�v���擾
//eCollisionType CollisionCalc::GetCollisionTypeMap(Character* chara, MapChip* mapChip) {
eCollisionType CollisionCalc::GetCollisionTypeMap(int px, int py, MapChip* mapChip) {
    // �L�����N�^�[�̃��[���h���W���}�b�v�̃O���b�h���W�ɕϊ�
    int chara_x = px / MapChip::MAP_CHIP_SIZE;
    int chara_y = py / MapChip::MAP_CHIP_SIZE;

    int mx[3] = { chara_x - 1, chara_x, chara_x + 1 };
    int my[3] = { chara_y - 1, chara_y, chara_y + 1 };

    for (int i = 0; i < 3; ++i) {
        for (int k = 0; k < 3; ++k) {
            if (mx[k] < 0) continue;
            if (mx[k] >= MapChip::MAP_CHIP_SIZE) continue;
            if (mx[i] < 0) continue;
            if (mx[i] >= MapChip::MAP_CHIP_SIZE) continue;

            int cellId = mapChip->GetChipId(mx[k], my[i]);
            if (-1 != cellId) {
                DrawStringEx(10, 10, -1, "m = %d", cellId);
                return mapChip->GetCollisionTypeById(cellId);
            }
        }
    }
    return eCollisionType::eCollision_None;

}

//�L�����N�^�[�̎��͂̃}�b�v�`�b�v���擾����(�����蔻�菈���y���̂���)
//��ʓI�ɃL�����𒆐S��(2*range+1)*(2*range+1)�͈̔͂̃}�b�v�`�b�v���擾����
std::vector<tnl::Vector3> CollisionCalc::GetSurroundingChips(Character* chara, MapChip* mapChip, int range) {
    std::vector<tnl::Vector3> chips;
    tnl::Vector3 pos = chara->GetPos();
    //�O���b�h���W�ɕϊ�
    int chip_x = pos.x / mapChip->MAP_CHIP_SIZE;
    int chip_y = pos.y / mapChip->MAP_CHIP_SIZE;
    //�L�������W�𒆐S��5*5�͈̔͂̃}�b�v�`�b�v���擾
    for (int i = chip_y - range; i <= chip_y + range; ++i) {
        for (int j = chip_x - range; j <= chip_x + range; ++j) {
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
        int x = static_cast<int>(tile.x);
        int y = static_cast<int>(tile.y);
        //tnl::Vector3 character_y= chara->GetPos() + tnl::Vector3(0, 15, 0);
        //�����蔻��ƕ␳���W�擾
        tnl::Vector3 nearly_point = tnl::GetNearestRectPoint(mapChip->GetChipPos(x, y), mapChip->MAP_CHIP_SIZE, mapChip->MAP_CHIP_SIZE, chara->GetPos());
        if ((nearly_point - chara->GetPos()).length() < chara->GetSize())
        {
            tnl::Vector3 normalize = tnl::Vector3::Normalize(chara->GetPos() - nearly_point);
            chara->SetPos( nearly_point + normalize * chara->GetSize() );
            //�Փˉ�������
            DrawStringEx(0, 50, -1, "boxhit");
        }
    }
   


}

//�����Ƃ̓����蔻��
//��`�Ɠ����������s�����߂ɁA��������d�ɂȂ��Ă��܂����A�ǐ��ƕێ琫���l���ɂ��Ă���
void CollisionCalc::CheckLineCollision(Character* chara, MapChip* mapChip, int range) {
    auto tiles = GetSurroundingChips(chara, mapChip, range);
    for (const auto& tile : tiles) {
        int x = static_cast<int>(tile.x);
        int y = static_cast<int>(tile.y);
        //�����̎n�_�ƏI�_���擾
        tnl::Vector3 lineStart, lineEnd;
        mapChip->GetTileLineSegment(y, x, lineStart, lineEnd);
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
    eCollisionType collisionType= GetCollisionTypeMap(chara->GetPos().x, chara->GetPos().y, mapChip);
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
    {
        int a = 0;
        a++;
    }
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
