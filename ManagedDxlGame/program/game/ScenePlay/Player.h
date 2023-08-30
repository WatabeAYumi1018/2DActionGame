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
	static constexpr float PLAYER_POS_X = 0;			//�v���C���[�̏����ʒu
	static constexpr float PLAYER_POS_Y = -200;
	
	static constexpr int PLAYER_SIZE = 30;				//�v���C���[�̃T�C�Y
	static constexpr int PLAYER_HP = 5;					//�v���C���[��HP
	
	static constexpr float PLAYER_VELOCITY_X = 100;		//�ړ����x�ipix/fps�j
	static constexpr float PLAYER_VELOCITY_Y = 100;

	//-----�����o�ϐ�-----//
	int m_jump_time;						//�W�����v����
	tnl::Vector3 m_jump_velocity;			//�W�����v���x
	
	bool m_is_jump = false;					//�W�����v��
	bool m_was_ground=false;				//�O�t���[���̐ڒn����
	bool m_is_dirction_right = true;					//�E�������ǂ���

	//-----�A�j���[�V����-----//
	wta::DrawAnim *animLoader = nullptr;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const PlayCamera* camera) override;
	void Finalize() override;

private:
	void MoveHandle(float delta_time);		//�ړ��ɂ����W�ω�
	void AnimHandle(float delta_time);		//�A�j���[�V�����̍Đ�
	void isFlag(float delta_time);
};

//Player�̃{�^������̋����������s���N���X
//�A�j���[�V�����̍Đ��ɂ��Ă͕ʃN���X���`��������������₷������