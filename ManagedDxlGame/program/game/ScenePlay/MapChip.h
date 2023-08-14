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

public:
	//-----�����o�֐�-----//
	void Initialize();
	void Update(float delta_time,float m_scroll_x);
	void Draw(float m_scroll_x);
	void LoadMapChipCollisionType();
	void Finalize();
};


//std::vector<IDCollision> map_id_collision;		//�K�v���݈̂ꎞ�i�[�p
//�����蔻��i�[�p
//std::vector<eCollisionType> m_map_chip_collision;	//�����蔻��

//�ǂݎ��ƕ`��i��`�t���j�̂ݒ�`
//Collision�N���X�œ����蔻��̌v�Z�������s��
//��MapChip�N���X�œ����蔻��̏���ǂݎ��ACollision�N���X�œ����蔻��̌v�Z�������s��