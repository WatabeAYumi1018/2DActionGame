#pragma once
#include "../../../engine/GameEngine.h"

//csv����̃}�b�v�`�b�v�A�����蔻��̓ǂݎ��

class Camera;
class Player;

class Map
{
public:

	Map(const std::string& stageName);
	virtual ~Map();

	//-----�萔-----//
	//�}�b�v�`�b�v�̊�{���
	static const int MAP_ROW_COL = 7;				//�}�b�v�`�b�v�̉���
	static const int MAP_ALL_NUM = 49;			//�}�b�v�`�b�v�̏c��
	static const int MAP_CHIP_SIZE = 32;		//�}�b�v�`�b�v�̃T�C�Y


private:
	//-----�����o�ϐ�-----//
	int m_map_hdl[MAP_ALL_NUM];									//�}�b�v�`�b�v�̃^�C���n���h��
	tnl::Vector3 m_pos;											//�}�b�v�̍��W
	std::vector<std::vector<int>> m_csv_map_tile;				//�`��t�@�C��
	std::vector<std::vector<int>> m_csv_collision;				//�`�b�v���t�@�C��
	std::vector<std::vector<sCollisionInfo>> m_collision_info;	//�����蔻��̏��i�[�p

	std::vector<sStageInfo> stageList = 
	{ 
		{"stage1", "csv/stage1-1.csv", "csv/stage1-1collision.csv", "csv/stage1-1enemy.csv", {0,100,0}},
		{ "stage2", "csv/stage1-2.csv", "csv/stage1-2collision.csv", "csv/stage1-2enemy.csv",{500,6000,0} },
		{ "stage3", "csv/stage1-3.csv", "csv/stage1-3collision.csv", "csv/stage1-3enemy.csv",{100,300,0} }
	};

	sStageInfo s_current_stage_info;  //���݂̃X�e�[�W���

public:
	//-----�����o�֐�-----//
	void Initialize(const std::string& stageName);
	void Draw(const Camera* camera);
	void Finalize();

	//�����蔻���p�̃}�b�v�֐�
	void LoadMapCollision();

	//-----Getter-----//
	const size_t GetMapChipX() const { return m_csv_map_tile[0].size(); }
	const size_t GetMapChipY() const { return m_csv_map_tile.size(); }
	const std::vector<std::vector<sCollisionInfo>>& GetCollisionInfo() const { return m_collision_info; }
	const sStageInfo& GetCurrentStageInfo() const { return s_current_stage_info; }
};


//----------------------------------------------------------------�O�̂��ߎc���Ă�������
	//ID�Ɠ����蔻��̏��J�n�`�I��(�s)
	//const int MAP_CHIP_ID_ROW_START = 10;
	//const int MAP_CHIP_ID_ROW_END = 58;

	//std::unordered_map<int, eCollisionType> m_id_map_collision_type;	//ID�Ɠ����蔻���map�z��

	//std::vector<std::vector<CollisionInfo>> GetCollisionInfo() const { return m_collision_info; }
	//tnl::Vector3 GetChipPos(int x ,int y) {return tnl::Vector3(x * MAP_CHIP_SIZE, y * MAP_CHIP_SIZE, 0);}
	//�߂�l�Ƃ��Ă�const�A�֐��Ƃ��Ă�const�i�l�̕ύX��s�ɂ��A�I�u�W�F�N�g�̏�ԕύX���j�~�j
	//const std::vector<std::vector<int>>& getMapChip() const {return m_csv_map_tile;}

	//�����蔻������ɂ����ĕK�v�Ȍʊ֐�
	//int GetChipId(int y, int x);
	//eCollisionType GetCollisionTypeById(int id);										//ID���瓖���蔻��̎�ގ擾
	//void LoadMapChipCollisionType();													//�����蔻��̎�ނ�ǂݍ���	
	//void GetTileLineSegment(int y, int x, tnl::Vector3& start, tnl::Vector3& end);	//�ΐ��`�b�v�̐������W�擾

	//�ǂݎ��ƕ`��A�����蔻��̂��߂ɕK�v�ȏ��擾�ƊT�O���`