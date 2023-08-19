#include "MapChip.h"

MapChip::MapChip() :Object(m_pos) {
	//csv�t�@�C���̃}�b�v�^�C���`�����ǂݍ���
	m_csv_map_tile=tnl::LoadCsv<int>(csv_map_tile_data);
	//csv�t�@�C������}�b�v�`�b�v�̏���ǂݍ���(�ꎞ�I�Ȋi�[)
	m_csv_collision = tnl::LoadCsv<int>(csv_map_tile_ID);
	Initialize();
}

MapChip::~MapChip() {Finalize();}

void MapChip::Initialize() {
	//�摜�̓ǂݍ���
	LoadDivGraph("graphics/Sprites32.png", MAP_ALL_NUM, MAP_ROW_COL,MAP_ROW_COL, MAP_CHIP_SIZE, MAP_CHIP_SIZE, m_map_hdl);
	//�����蔻��̓ǂݍ���
	LoadMapChipCollisionType();
}

void MapChip::Update(float delta_time,float scroll_x) {Draw(scroll_x);}

void MapChip::Draw(float scroll_x) {
	//�}�b�v�摜�̕`��
	for (int i = 0; i < m_csv_map_tile.size(); ++i) {			//�s����m_map_tile�̃T�C�Y�Ɋ�Â�
		for (int j = 0; j < m_csv_map_tile[i].size(); ++j) {	//�񐔂�m_map_tile[i]�̃T�C�Y�Ɋ�Â�
			int posX = j * MAP_CHIP_SIZE - scroll_x;		//�X�N���[���̒l���l��
			int posY = i * MAP_CHIP_SIZE ;			
			DrawGraph(posX, posY, m_map_hdl[m_csv_map_tile[i][j]], TRUE);
		}
	}
}

//ID���擾���A�����l��Ԃ�
eCollisionType MapChip::GetCollisionTypeById(int id) {
	if (m_id_map_collision_type.find(id) != m_id_map_collision_type.end()) {
		return m_id_map_collision_type[id];
	}
	return eCollisionType::eCollision_None;
}

//ID��Collision���֘A�t����
void MapChip::LoadMapChipCollisionType() {
	for (int i = MAP_CHIP_ID_ROW_START; i < MAP_CHIP_ID_ROW_END; ++i) {
		//csv�ɂ�ID��0��ڂɊi�[
		int id = m_csv_collision[i][0];
		//csv�ɂ�CollisionType��1��ڂɊi�[
		eCollisionType type = static_cast<eCollisionType>(m_csv_collision[i][1]);
		m_id_map_collision_type[id] = type;
	}
}

int MapChip::GetIdAt(int row, int col) {
	if (row < 0 || row >= m_csv_map_tile.size() || col < 0 || col >= m_csv_map_tile[row].size())
	{
		return -1;  //�����ȍ��W���w�肳�ꂽ�ꍇ��-1��Ԃ�
	}
	return m_csv_map_tile[row][col];
}

void MapChip::Finalize() {
	m_csv_map_tile.clear();
	m_csv_collision.clear();
}

//�C�x���g�`�b�v���㏑�����Ēǉ��C�x���g�Ƃ�������
////LoadMapChipInfo()�֐��œǂݎ����������ɁA�`�b�v���������g�̔�������悤�ɂ�����
//void MapChip::LoadMapChipCollision() {
//	// �����蔻������i�[���邽�߂ɃT�C�Y��ݒ�
//	//m_map_chip_collision.resize(m_map_tile.size(), std::vector<Collision>(m_map_tile[0].size()));
//	//�`�悵�Ă���`�b�vID�ɑΉ�����Collision�����i�[�i�����蔻�����Ǝ��ŊǗ����邽�߁j
//	for (int i = 0; i < m_map_tile.size(); ++i) {
//		for (int j = 0; j < m_map_tile[i].size(); ++j) {
//			//�}�b�v�`�b�v��ID���擾
//			int chipID = m_map_tile[i][j];
//			if(chipID==-1)continue;
//			else {
//				eCollisionType type = m_map_chip_collision[chipID]; // �}�b�v���瓖���蔻����擾
//				//�I�u�W�F�N�g�w���ɂ͂Ȃ邯�ǁA�}�b�v�S�̂ƂȂ�Ɣ�����i����͌�����Z���j
//				//m_map_tile[i][j] = type;
//			}
//		}
//	}
//}
