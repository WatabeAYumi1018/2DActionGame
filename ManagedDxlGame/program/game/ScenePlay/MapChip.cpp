#include "MapChip.h"
#include "Character.h"
#include "PlayCamera.h"

MapChip::MapChip() :Object(m_pos) {Initialize();}

MapChip::~MapChip() {Finalize();}

void MapChip::Initialize() {
	//csv�t�@�C���̃}�b�v�^�C���`�����ǂݍ���
	m_csv_map_tile = tnl::LoadCsv<int>("csv/TileStage_1-1re32.csv");
	//csv�t�@�C������}�b�v�`�b�v�̏���ǂݍ���(�ꎞ�I�Ȋi�[)
	m_csv_collision = tnl::LoadCsv<int>("csv/TileStage_1-1re32Collision.csv");
	//�摜�̓ǂݍ���
	LoadDivGraph("graphics/Sprites32.png", MAP_ALL_NUM, MAP_ROW_COL,MAP_ROW_COL, MAP_CHIP_SIZE, MAP_CHIP_SIZE, m_map_hdl);
	//�����蔻��̓ǂݍ���
	//LoadMapChipCollisionType();
	//�����蔻��̏���ǂݍ���
	//LoadMapCollision();
}

void MapChip::Update(float delta_time, const PlayCamera *camera) {
	Draw(camera);
	LoadMapCollision();//�����蔻��̒n�`�m�F�p
}

void MapChip::Draw(const PlayCamera *camera) {
	//�}�b�v�摜�̕`��
	for (int i = 0; i < m_csv_map_tile.size(); ++i) {			//�s����m_map_tile�̃T�C�Y�Ɋ�Â�
		for (int j = 0; j < m_csv_map_tile[i].size(); ++j) {	//�񐔂�m_map_tile[i]�̃T�C�Y�Ɋ�Â�
			int posX = j * MAP_CHIP_SIZE - static_cast<int>(camera->GetScrollX());
			int posY = i * MAP_CHIP_SIZE;
			DrawGraph(posX, posY, m_map_hdl[m_csv_map_tile[i][j]], TRUE);
		}
	}
}

//�����蔻��̓ǂݍ���
void MapChip::LoadMapCollision() {
	// �T�C�Y�������im_csv_collision.size()�ōŏ���0��ڂ̃T�C�Y��ǂݎ��A���ꂪsize�̗񕪂�������j
	m_collision_info.resize(m_csv_collision.size(), std::vector<CollisionInfo>(m_csv_collision[0].size()));
	//�t�@�C����̐��l��S�ēǂݍ���
	for (int i = 0; i < m_csv_collision.size(); ++i) {
		for (int j = 0; j < m_csv_collision[i].size(); ++j) {
			int posX = j * MAP_CHIP_SIZE;
			int posY = i * MAP_CHIP_SIZE;
			//eCollisionType�Ɠǂݎ�����������֘A�t����i���������ŘA�����₷���悤�Ɂj
			eCollisionType type = static_cast<eCollisionType>(m_csv_collision[i][j]);
			//�\���̌^�Ɋe������
			CollisionInfo info;
			info.pos = tnl::Vector3(posX, posY,0);
			info.size = MAP_CHIP_SIZE;
			info.type= type;
			//�����蔻��̏����e�}�b�v�`�b�v�Ɋi�[
			m_collision_info[i][j]=info;
			if (type != eCollisionType::eCollision_None) {
				DrawBoxEx(info.pos, info.size, info.size);
			}
		}
	}
}

void MapChip::Finalize() {
	m_csv_map_tile.clear();
	m_csv_collision.clear();
}

////�}�b�v�`�b�v��ID���擾
//int MapChip::GetChipId(int y, int x) {
//	if (y < 0 || y >= m_csv_map_tile.size() || x < 0 || x >= m_csv_map_tile[y].size())
//	{
//		return -1;  //�󔒂Ȃ�-1
//	}
//	return m_csv_map_tile[y][x];
//}
//
////ID���擾���A�����l��Ԃ�
//eCollisionType MapChip::GetCollisionTypeById(int id) {
//	if (m_id_map_collision_type.find(id) != m_id_map_collision_type.end()) {
//		return m_id_map_collision_type[id];
//	}
//	return eCollisionType::eCollision_None;
//}
//
////ID��Collision���֘A�t����
//void MapChip::LoadMapChipCollisionType() {
//	for (int i = MAP_CHIP_ID_ROW_START; i < MAP_CHIP_ID_ROW_END; ++i) {
//		//csv�ɂ�ID��0��ڂɊi�[
//		int id = m_csv_collision[i][0];
//		//csv�ɂ�CollisionType��1��ڂɊi�[
//		eCollisionType type = static_cast<eCollisionType>(m_csv_collision[i][1]);
//		m_id_map_collision_type[id] = type;
//	}
//}
//
////�ΐ��Ƃ̓����蔻��̂��߁A�}�b�v�`�b�v�̍����ƉE��̍��W���擾
//void MapChip::GetTileLineSegment(int y, int x, tnl::Vector3& start, tnl::Vector3& end) {
//	// �}�b�v�`�b�v�̍����̍��W���擾
//	start.x = x * MAP_CHIP_SIZE;
//	start.y = y * MAP_CHIP_SIZE;
//	// �}�b�v�`�b�v�̉E��̍��W���擾
//	end.x = start.x + MAP_CHIP_SIZE;
//	end.y = start.y + MAP_CHIP_SIZE;
//}


//��������
// �C�x���g�`�b�v���㏑�����Ēǉ��C�x���g�Ƃ�������
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
