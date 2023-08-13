#pragma once
#include "../../engine/GameEngine.h"

//�}�b�v�`�b�v�̏����擾�A�Ǘ�����N���X
//�����蔻��̊�ՂȂǂ������ŊǗ�����
class MapChipID {
public:
	MapChipID();
	~MapChipID();
private:
	//-----csv�t�@�C���֘A�̕ϐ�-----//
	//�ǂݎ��
	std::string csv_map_tile_ID = "csv/tileStageID_1-1.csv";
	//int�^�ŕ`��
	std::vector<std::vector<int>> m_map_tile_ID;		//csv�t�@�C���FID
	std::vector<std::vector<int>> m_map_tile_collision;	//csv�t�@�C���F�����蔻��

	//�}�b�v�`�b�vID�̏��J�n�`�I��(�s��)
	const int MAP_CHIP_ID_ROW_START = 10;			//10���
	const int MAP_CHIP_ID_ROW_END = 58;				//58���
	const int MAP_CHIP_ID_COL_START = 0;			//0�s��
	const int MAP_CHIP_ID_COL_END = 1;				//3�s��

public:
	//csv�t�@�C������}�b�v�`�b�v�̏���ǂݍ���
	void Initialize();
	void LoadMapChipID();
	void LoadMapChipCollision();
	void Fainalize();
};