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
	const int MAP_ROW_COL=7;				//�}�b�v�`�b�v�̉���
	const int MAP_ALL_NUM=49;				//�}�b�v�`�b�v�̏c��
	const int MAP_CHIP_SIZE=16;				//�}�b�v�`�b�v�̃T�C�Y

private:
	//-----�����o�ϐ�-----//
	int m_map_hdl[49];						//�}�b�v�`�b�v�̃^�C���n���h��
	Collision* collision_map=nullptr;		//�����蔻��p�N���X

	//-----csv�t�@�C���֘A�̕ϐ�-----//
	//�ǂݎ��
	std::string csv_map_tile_data = "csv/TileStage_1-1.csv";
	//int�^�ŕ`��
	std::vector<std::vector<int>> m_map_tile;	//csv�t�@�C���F�}�b�v�^�C���X�e�[�W
	
public:
	//-----�����o�֐�-----//
	void Initialize();
	void Update(float delta_time,float m_scroll_x);
	void Draw(float m_scroll_x);
	void Finalize();
};

//�`��̂��Ƃ�����{�N���X�Œ�`
//PlayCamera�N���X�Ő�����s��