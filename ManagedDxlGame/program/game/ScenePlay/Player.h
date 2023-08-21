#pragma once
#include "../../engine/GameEngine.h"
#include "Character.h"
#include "../../wta_library/wta_DrawAnim.h"

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
	wta::DrawAnim *animLoader = nullptr;
	
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