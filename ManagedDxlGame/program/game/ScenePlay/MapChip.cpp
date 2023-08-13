#include "MapChip.h"
#include "Collision.h"

MapChip::MapChip() :Object(m_pos) {
	//csv�t�@�C���̓ǂݍ���
	m_map_tile=tnl::LoadCsv<int>(csv_map_tile_data);
	//csv�t�@�C������}�b�v�`�b�v�̏���ǂݍ���(�ꎞ�I�Ȋi�[)
	m_csv_info = tnl::LoadCsv<int>(csv_map_tile_ID);
	Initialize();
}

MapChip::~MapChip() {Finalize();}

void MapChip::Initialize() {
	//�摜�̓ǂݍ���
	LoadDivGraph("graphics/Sprites32.png", MAP_ALL_NUM, MAP_ROW_COL,MAP_ROW_COL, MAP_CHIP_SIZE, MAP_CHIP_SIZE, m_map_hdl);
	//�����蔻��̓ǂݍ���
	LoadMapChipInfo();
	LoadMapChipCollision();
}

void MapChip::Update(float delta_time,float scroll_x) {
	Draw(scroll_x);
}

void MapChip::Draw(float scroll_x) {
	//�}�b�v�摜�̕`��
	for (int i = 0; i < m_map_tile.size(); ++i) {			//�s����m_map_tile�̃T�C�Y�Ɋ�Â�
		for (int j = 0; j < m_map_tile[i].size(); ++j) {	//�񐔂�m_map_tile[i]�̃T�C�Y�Ɋ�Â�
			int posX = j * MAP_CHIP_SIZE - scroll_x;		//�X�N���[���̒l���l��
			int posY = i * MAP_CHIP_SIZE ;			
			DrawGraph(posX, posY, m_map_hdl[m_map_tile[i][j]], TRUE);
			// �f�o�b�O�`��
			DrawFormatString(0, 0, -1, "+");
		}
	}
}

//ID��Collision���݂̂��ꎞ�i�[
void MapChip::LoadMapChipInfo() {
	//�ǂݎ��������vector�Ɋi�[
	for (int i = MAP_CHIP_ID_ROW_START; i < MAP_CHIP_ID_ROW_END; ++i) {
		std::vector<int> row;
		for (int j = MAP_CHIP_ID_COL_START; j < MAP_CHIP_ID_COL_END; ++j) {
			row.emplace_back(m_csv_info[i][j]);
		}
		map_id_collision.emplace_back(row);
	}
}

//�ǂݎ����������ɁA�`�b�v���������g�̔�������悤�ɂ���
void MapChip::LoadMapChipCollision() {
	// �����蔻������i�[���邽�߂ɃT�C�Y��ݒ�
	m_map_chip_collision.resize(m_map_tile.size(),
								std::vector<Collision>(m_map_tile[0].size()));
	for (int i = 0; i < map_id_collision.size(); ++i) {
		for (int j = 0; j < map_id_collision[i].size(); ++j) {
			eCollisionType type = eCollisionType::eCollision_Block;
			//Collision��1��ID��Box
			if (map_id_collision[i][1] == 1) {type = eCollisionType::eCollision_Block;}
			//Collision��2��ID��Line
			else if (map_id_collision[i][1] == 2) {type = eCollisionType::eCollision_Line;}
			//�}�b�v�^�C����ID��Collision�̏����i�[
			m_map_chip_collision[i][j] = Collision(type);
		}
	}
}

void MapChip::Finalize() {
	m_map_tile.clear();
	m_csv_info.clear();
	m_map_chip_collision.clear();
}