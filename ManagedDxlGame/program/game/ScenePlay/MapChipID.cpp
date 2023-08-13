#include "MapChipID.h"

MapChipID::MapChipID() {
	//csv�t�@�C������}�b�v�`�b�v�̏���ǂݍ���
	m_map_tile_ID = tnl::LoadCsv<int>(csv_map_tile_ID);
	Initialize();
}

MapChipID::~MapChipID() {}

void MapChipID::Initialize() {
	//csv�t�@�C�����瓖���蔻��̏���ǂݍ���
	LoadMapChipID();
}

void MapChipID::LoadMapChipID() {
	//�ǂݎ��������vector�Ɋi�[
	for (int i = MAP_CHIP_ID_ROW_START; i < MAP_CHIP_ID_ROW_END; ++i) {
		for (int j = MAP_CHIP_ID_COL_START; j < MAP_CHIP_ID_COL_END; ++j) {
			std::vector<int> map_info;
			//�}�b�v�^�C����ID��Collision�̏����i�[
			map_info.push_back(m_map_tile_ID[i][j]);
		}
	}
}

void MapChipID::LoadMapChipCollision() {
	//vector�Ɋi�[�����������ɁA�����蔻����O���[�v���Ƃɕ����Ċi�[
	for (int i = 0; i < m_map_tile_ID.size(); ++i) {
		for (int j = 0; j < m_map_tile_ID[i].size(); ++j) {
			//�}�b�v�`�b�v��ID��0�̏ꍇ�A�����蔻��Ȃ�
			if (m_map_tile_ID[i][1] == 0) {break;}
			//�}�b�v�`�b�v��ID��1�̏ꍇ�A�����蔻�肠��
			else if (m_map_tile_ID[i][1] == 1 || m_map_tile_ID[i][1] == 2) {
				std::vector<int> map_collision;
				//�}�b�v�^�C����ID��Collision�̏����i�[
				map_collision.push_back(m_map_tile_collision[i][j]);
			}
		}
	}
}

void MapChipID::Fainalize() {}

