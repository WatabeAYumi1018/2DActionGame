#pragma once
#include "../../engine/GameEngine.h"
#include "Object.h"

class Character;

class MapChip :public Object{
public:
	MapChip();
	~MapChip();

	//-----�萔-----//
	//�}�b�v�`�b�v�̊�{���
	static const int MAP_ROW_COL=7;				//�}�b�v�`�b�v�̉���
	static const int MAP_ALL_NUM=49;			//�}�b�v�`�b�v�̏c��
	static const int MAP_CHIP_SIZE = 32;		//�}�b�v�`�b�v�̃T�C�Y

	//ID�Ɠ����蔻��̏��J�n�`�I��(�s��)
	const int MAP_CHIP_ID_ROW_START = 10;			//10�s��
	const int MAP_CHIP_ID_ROW_END = 58;				//58�s��

private:
	//-----�����o�ϐ�-----//
	int m_map_hdl[MAP_ALL_NUM];						//�}�b�v�`�b�v�̃^�C���n���h��

	//-----csv�`��֘A�̕ϐ�-----//
	//�}�b�v�`�b�v�`��f�[�^�̓ǂݎ��
	std::string csv_map_tile_data = "csv/TileStage_1-1re32.csv";
	//int�^�ŕ`��
	std::vector<std::vector<int>> m_csv_map_tile;		//�}�b�v�^�C���`����
	
	//-----csv�����蔻��֘A�̕ϐ�-----//
	//�����蔻����̓ǂݎ��
	std::string csv_map_tile_ID = "csv/tileStageID_1-1.csv";
	//int�^�ŕ`��
	std::vector<std::vector<int>> m_csv_collision;		//�}�b�v�^�C�������蔻����

	//-----�����蔻��֘A�t���̂��߂�map�z��̕ϐ�-----//
	std::unordered_map<int, eCollisionType> m_id_map_collision_type;

public:
	//-----�����o�֐�-----//
	void Initialize();
	void Update(float delta_time,float m_scroll_x);
	void Draw(float m_scroll_x);
	void Finalize();

	//-----�����蔻������ɂ����ĕK�v�Ȍʕϐ�-----//
	//ID�擾
	int GetChipId(int row, int col);
	//ID���瓖���蔻��̎�ގ擾
	eCollisionType GetCollisionTypeById(int id);
	//ID��Collision���֘A�t����
	void LoadMapChipCollisionType();
	//�ΐ��`�b�v�̐������W�擾
	void GetTileLineSegment(int row, int col, tnl::Vector3& start, tnl::Vector3& end);
	
	//-----Getter-----//
	tnl::Vector3 GetChipPos(int row, int col) {return tnl::Vector3(col * MAP_CHIP_SIZE, row * MAP_CHIP_SIZE, 0);}
	//�߂�l�Ƃ��Ă�const�A�֐��Ƃ��Ă�const�i�l�̕ύX��s�ɂ��A�I�u�W�F�N�g�̏�ԕύX���j�~�j
	const std::vector<std::vector<int>>& getMapChip() const {return m_csv_map_tile;}
};

//�ǂݎ��ƕ`��A�����蔻��̂��߂ɕK�v�ȏ��擾�ƊT�O���`
