#pragma once
#include "../../engine/GameEngine.h"
#include "Character.h"
#include "AnimLoad.h"

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
	int ye = 0;
	int animFileHdl=0;					//�摜�̃n���h��
	bool m_was_Ground=false;			//�O�t���[���̐ڒn����

	//-----�A�j���[�V����-----//
	//����A�A�j���[�V�����N���X���쐬���A�����Ɉړ�
	AnimLoad* animLoop = nullptr;			//walk_right
	AnimLoad* animLoop2 = nullptr;			//walk_left
	AnimLoad* animLoop3 = nullptr;			//jump_right
	AnimLoad* animLoop4 = nullptr;			//jump_left
	AnimLoad* animLoop5 = nullptr;			//idle_right
	AnimLoad* animLoop6 = nullptr;			//idle_left
	AnimLoad* animLoop7 = nullptr;			//run_right
	AnimLoad* animLoop8 = nullptr;			//run_left
	AnimLoad* animLoop9 = nullptr;			//touchdown_right
	AnimLoad* animLoop10 = nullptr;			//touchdown_left

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Move(float delta_time);
	void Finalize() override;
	
	float overCenterX();
};

//Player�̃{�^������̋����������s���N���X
//�A�j���[�V�����̍Đ��ɂ��Ă͕ʃN���X���`��������������₷������