#pragma once
#include "../../engine/GameEngine.h"
#include "Character.h"
#include "../../wta_library/wta_DrawAnim.h"

//�v���C���[�̃N���X
//��Ƀ{�^������̋����������s��
//�`��ɂ��Ă̎�Ȓ�`��wta_LoadAnim, wta_DrawAnim�ɂ�

class Player :public Character {

public:
	Player();
	virtual ~Player();

private:
	//-----�萔-----//
	const tnl::Vector3 PLAYER_POS = { 0,-100,0 };		//�v���C���[�̏����ʒu
	const int PLAYER_SIZE = 50;							//�v���C���[�̃T�C�Y
	const int PLAYER_HP = 5;							//�v���C���[��HP
	const tnl::Vector3 PLAYER_VELOCITY = { 100,100,0 };	//�ړ����x�ipix/fps�j

	//-----�����o�ϐ�-----//
	int m_jump_time;						//�W�����v����
	tnl::Vector3 m_jump_velocity;			//�W�����v���x
	bool m_is_jump = false;					//�W�����v��
	bool m_was_ground=false;				//�O�t���[���̐ڒn����

	//-----�A�j���[�V����-----//
	wta::DrawAnim *animLoader = nullptr;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Move(float delta_time);
	void Finalize() override;
};

//Player�̃{�^������̋����������s���N���X
//�A�j���[�V�����̍Đ��ɂ��Ă͕ʃN���X���`��������������₷������