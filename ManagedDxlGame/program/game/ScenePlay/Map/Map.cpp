#include "Map.h"
#include "../Character/Character.h"
#include "../Camera/Camera.h"

Map::Map()
{
	Initialize();
}

Map::~Map()
{
	Finalize();
}

void Map::Initialize()
{
	//csv�t�@�C���̃}�b�v�^�C���`�����ǂݍ���
	m_csv_map_tile = tnl::LoadCsv<int>("csv/stage1-1.csv");
	//csv�t�@�C�����瓖���蔻��̏���ǂݍ���
	m_csv_collision = tnl::LoadCsv<int>("csv/stage1-1collision.csv");
	//�摜�̓ǂݍ���
	LoadDivGraph("graphics/Stage1-1.png", MAP_ALL_NUM, MAP_ROW_COL, MAP_ROW_COL, MAP_CHIP_SIZE, MAP_CHIP_SIZE, m_map_hdl);
}

//���`��(���󖈃t���[���ǂݎ��悤�ɂȂ��Ă��܂����c)
//�ǂݎ���Draw�𕪂���ׂ��������̂ŁAvector�ɏ������āB�J�����ɍ��킹�ĕ`�悷��̂�best���ȁH�ƍl����
void Map::Draw(const Camera* camera)
{
	//�}�b�v�摜�̕`��
	for (int i = 0; i < m_csv_map_tile.size(); ++i) //�s����m_map_tile�̃T�C�Y�Ɋ�Â�
	{
		for (int j = 0; j < m_csv_map_tile[i].size(); ++j) //�񐔂�m_map_tile[i]�̃T�C�Y�Ɋ�Â�
		{
			//tnl::Vector3 draw_pos;
			m_pos.x = j * MAP_CHIP_SIZE;
			m_pos.y = i * MAP_CHIP_SIZE;
			//�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
			tnl::Vector3 draw_pos = m_pos - camera->GetTarget() +
				tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

			DrawGraph(draw_pos.x, draw_pos.y, m_map_hdl[m_csv_map_tile[i][j]], TRUE);
		}
	}
}

//�������蔻��̓ǂݍ���(���󖈃t���[���ǂݎ��悤�ɂȂ��Ă��܂����̂Łc��ɓ�������)
void Map::LoadMapCollision(const Camera* camera)
{
	// �T�C�Y�������im_csv_collision.size()�ōŏ���0��ڂ̃T�C�Y��ǂݎ��A���ꂪsize�̗񕪂�������j
	m_collision_info.resize(m_csv_collision.size(), std::vector<sCollisionInfo>(m_csv_collision[0].size()));
	//�t�@�C����̐��l��S�ēǂݍ���
	for (int i = 0; i < m_csv_collision.size(); ++i)
	{
		for (int j = 0; j < m_csv_collision[i].size(); ++j)
		{
			//�����蔻��̒��S���W���v�Z
			int posX = j * MAP_CHIP_SIZE + (MAP_CHIP_SIZE >> 1);
			int posY = i * MAP_CHIP_SIZE + (MAP_CHIP_SIZE >> 1);
			//eCollisionType�Ɠǂݎ�����������֘A�t����i���������ŘA�����₷���悤�Ɂj
			eCollisionType type = static_cast<eCollisionType>(m_csv_collision[i][j]);
			//�\���̌^�Ɋe������
			sCollisionInfo info;
			info.s_pos = tnl::Vector3(posX, posY, 0);
			info.s_size = MAP_CHIP_SIZE;
			info.s_type = type;
			//�����蔻��̏����e�}�b�v�`�b�v�Ɋi�[
			m_collision_info[i][j] = info;
			//if (type != eCollisionType::None)
			//{
				////�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
				//tnl::Vector3 draw_pos = info.s_pos - camera->GetTarget() +
				//	tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

			//	if(type == eCollisionType::Box)
			//		DrawBoxEx(draw_pos, info.s_size, info.s_size);
				//if (type == eCollisionType::Line)
				//	DrawLine(draw_pos.x- (info.s_size>>1),draw_pos.y + (info.s_size >> 1),draw_pos.x+ (info.s_size >> 1), draw_pos.y - (info.s_size >> 1),-1);
			//}
		}
	}
}

void Map::Finalize()
{
	m_csv_map_tile.clear();
	m_csv_collision.clear();
}

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