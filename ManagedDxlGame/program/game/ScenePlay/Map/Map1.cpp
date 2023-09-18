#include "Map1.h"
#include "../Character/Character.h"
#include "../Camera/Camera.h"

Map1::Map1()
{
	Initialize();
}

Map1::~Map1()
{
	Finalize();
}

void Map1::Initialize()
{
	//csv�t�@�C���̃}�b�v�^�C���`�����ǂݍ���
	m_csv_map_tile = tnl::LoadCsv<int>("csv/stage1-1.csv");
	//csv�t�@�C�����瓖���蔻��̏���ǂݍ���
	m_csv_collision = tnl::LoadCsv<int>("csv/stage1-1collision.csv");
	//�摜�̓ǂݍ���
	LoadDivGraph("graphics/stagetile/Stage1-1.png", MAP_ALL_NUM, MAP_ROW_COL, MAP_ROW_COL, MAP_CHIP_SIZE, MAP_CHIP_SIZE, m_map_hdl);
}

//�`��
void Map1::Draw(const Camera* camera)
{
	//�}�b�v�摜�̕`��
	for (int i = 0; i < m_csv_map_tile.size(); ++i) //�s����m_map_tile�̃T�C�Y�Ɋ�Â�
	{
		for (int j = 0; j < m_csv_map_tile[i].size(); ++j) //�񐔂�m_map_tile[i]�̃T�C�Y�Ɋ�Â�
		{
			m_pos.x = j * MAP_CHIP_SIZE;
			m_pos.y = i * MAP_CHIP_SIZE;
			//�J�����̈ʒu�ɍ��킹�ĕ`��ʒu�����炷
			tnl::Vector3 draw_pos = m_pos - camera->GetTarget() +
				tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

			DrawGraph(draw_pos.x, draw_pos.y, m_map_hdl[m_csv_map_tile[i][j]], TRUE);
		}
	}
}

//�����蔻��̓ǂݍ���
void Map1::LoadMapCollision(const Camera* camera)
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
			eMapCollisionType type = static_cast<eMapCollisionType>(m_csv_collision[i][j]);
			//�\���̌^�Ɋe������
			sCollisionInfo info;
			info.s_pos = tnl::Vector3(posX, posY, 0);
			info.s_size = MAP_CHIP_SIZE;
			info.s_type = type;
			//�����蔻��̏����e�}�b�v�`�b�v�Ɋi�[
			m_collision_info[i][j] = info;
		}
	}
}

void Map1::Finalize()
{
	m_csv_map_tile.clear();
	m_csv_collision.clear();
	DeleteGraph(m_map_hdl[0]);
}