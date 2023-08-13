#pragma once
#include "../../engine/GameEngine.h"
#include "Object.h"

class Collision;

class MapChip :public Object{
public:
	//int�^�ŃR���X�g���N�^
	MapChip();
	~MapChip();

	//-----�萔-----//
	static const int MAP_ROW_COL=7;				//�}�b�v�`�b�v�̉���
	static const int MAP_ALL_NUM=49;			//�}�b�v�`�b�v�̏c��
	static const int MAP_CHIP_SIZE = 32;		//�}�b�v�`�b�v�̃T�C�Y

private:
	//-----�����o�ϐ�-----//
	int m_map_hdl[MAP_ALL_NUM];						//�}�b�v�`�b�v�̃^�C���n���h��

	//-----csv�`��֘A�̕ϐ�-----//
	//�}�b�v�`�b�v�`��f�[�^�̓ǂݎ��
	std::string csv_map_tile_data = "csv/TileStage_1-1re32.csv";
	//int�^�ŕ`��
	std::vector<std::vector<int>> m_map_tile;					//�}�b�v�^�C���X�e�[�W
	
	//-----csv�t�@�C���֘A�̕ϐ�-----//
	//�����蔻����̓ǂݎ��
	std::string csv_map_tile_ID = "csv/tileStageID_1-1.csv";
	//int�^�ŕ`��
	std::vector<std::vector<int>> m_csv_info;					//�}�b�v�^�C���X�e�[�W
	//�����蔻��i�[�p
	std::vector<std::vector<Collision>> m_map_chip_collision;	//�����蔻��

public:
	//-----�����o�֐�-----//
	void Initialize();
	void Update(float delta_time,float m_scroll_x);
	void Draw(float m_scroll_x);
	void LoadMapChipCollision();
	void Finalize();
};

////�}�b�v�`�b�vID�̏��J�n�`�I��(�s��)
//const int MAP_CHIP_ID_ROW_START = 10;			//10���
//const int MAP_CHIP_ID_ROW_END = 58;				//58���
//const int MAP_CHIP_ID_COL_START = 0;			//0�s��
//const int MAP_CHIP_ID_COL_END = 1;				//�s��



//�`��̂��Ƃ�����{�N���X�Œ�`
//PlayCamera�N���X�Ő�����s��