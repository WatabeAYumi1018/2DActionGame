#pragma once
#include "../../engine/GameEngine.h"
#include "Character.h"
#include "Ani��.h"

class MapChip;

class Player :public Character {

public:
	Player();
	~Player();

private:
	//-----�萔-----//
	const int PLAYER_SPEED_WALK = 100;		//�ړ����x�ipix/fps�j
	const int PLAYER_SPEED_DASH = 300;		//�_�b�V�����x�ipix/fps�j
	const int PLAYER_HP = 5;				//�v���C���[��HP

	//-----�����o�ϐ�-----//
	int animFileHdl=0;					//�摜�̃n���h��
	//dxe::Camera* m_camera = nullptr;	//�J����
	MapChip* m_mapchip = nullptr;		//�}�b�v�`�b�v
	Anim* animLoop = nullptr;			//�A�j���[�V�������[�v
	Anim* animLoop2 = nullptr;			//�A�j���[�V�������[�v
	Anim* animLoop3 = nullptr;			//�A�j���[�V�������[�v

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Move(float delta_time);
	void Finalize() override;
	
	float overCenterX();

	//-----Setter,Getter-----//
	void SetPos(tnl::Vector3 pos) { m_pos = pos; }
	tnl::Vector3 GetPos() const { return m_pos; }
};