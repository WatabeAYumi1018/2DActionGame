#pragma once
#include "../../engine/GameEngine.h"

//csv����̃}�b�v�`�b�v�A�����蔻��̓ǂݎ��
//�J�����X�N���[���ɍ��킹���`��X�V���K�v
//����኱�̃Y������i�����A�`�b�v�T�C�Y��ς������Ƃɂ�镾�Q�Ǝv����B����X���[��OK�j
//cpp�ł͑��݃C���N���[�h�Ƃ肠����OK

class Camera;
class Player;

class Map
{
public:
	Map();
	virtual ~Map();

	//-----�萔-----//
	//�}�b�v�`�b�v�̊�{���
	static const int MAP_ROW_COL=7;				//�}�b�v�`�b�v�̉���
	static const int MAP_ALL_NUM=49;			//�}�b�v�`�b�v�̏c��
	static const int MAP_CHIP_SIZE = 32;		//�}�b�v�`�b�v�̃T�C�Y

private:
	//-----�����o�ϐ�-----//
	tnl::Vector3 m_pos;											//�}�b�v�̍��W
	int m_map_hdl[MAP_ALL_NUM];									//�}�b�v�`�b�v�̃^�C���n���h��
	std::vector<std::vector<int>> m_csv_map_tile;				//�`��t�@�C��
	std::vector<std::vector<int>> m_csv_collision;				//�`�b�v���t�@�C��
	std::vector<std::vector<sCollisionInfo>> m_collision_info;	//�����蔻��̏��i�[�p

public:
	//-----�����o�֐�-----//
	void Initialize ();
	void Draw(const Camera* camera);
	void Finalize();

	//�����蔻���p�̃}�b�v�֐�
	void LoadMapCollision(const Camera* camera);
	
	//-----Getter-----//
	const size_t GetMapChipX() const { return m_csv_map_tile[0].size(); }
	const size_t GetMapChipY() const { return m_csv_map_tile.size(); }
	const std::vector<std::vector<sCollisionInfo>>& GetCollisionInfo() const { return m_collision_info; }
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
