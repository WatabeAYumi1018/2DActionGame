#pragma once
#include "../../engine/GameEngine.h"

class Collision;

class MapChip {
public:
	//int�^�ŃR���X�g���N�^
	MapChip(const std::string& csv_map_tile);
	~MapChip();

private:
	//-----�����o�ϐ�-----//
	int m_map_hdl[49];						//�}�b�v�`�b�v�̃^�C���n���h��
	Collision* collision_map=nullptr;		//�����蔻��p�N���X

	//-----�萔-----//
	const int MAP_ROW_COL=7;				//�}�b�v�`�b�v�̉���
	const int MAP_ALL_NUM=49;				//�}�b�v�`�b�v�̏c��
	const int MAP_CHIP_SIZE=16;				//�}�b�v�`�b�v�̃T�C�Y

	//int�^��csv�t�@�C���̓ǂݍ���
	std::vector<std::vector<int>> m_map_tile;	//csv�t�@�C���F�}�b�v�^�C���X�e�[�W
	
public:
	//-----�����o�֐�-----//
	void Initialize();
	void Update(float delta_time);
	void Draw();
	void Finalize();
};