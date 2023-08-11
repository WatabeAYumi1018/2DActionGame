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
	std::vector<std::vector<int>> m_map_tile_ID;	//csv�t�@�C���F�}�b�v�`�b�vID


public:
	//csv�t�@�C������}�b�v�`�b�v�̏���ǂݍ���
	void Initialize();
	void LoadMapChipID();
	void Fainalize();
};