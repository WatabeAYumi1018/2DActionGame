#pragma once
#include "../../../../engine/GameEngine.h"
#include "../Character.h"

class Camera;


//�v���C���[�̃N���X
//��Ƀ{�^������̋����������s��
//�`��ɂ��Ă̎�Ȓ�`��wta_LoadAnim, wta_DrawAnim�ɂ�

class Player :public Character
{
public:
	Player();
	virtual ~Player();

private:
	//-----�萔-----//
	static constexpr float PLAYER_POS_X = 100;			//�����ʒu
	static constexpr float PLAYER_POS_Y = 100;

	static constexpr int PLAYER_SIZE = 35;				//�T�C�Y
	static constexpr int PLAYER_MAX_HP = 5;				//HP

	static constexpr float PLAYER_VELOCITY_X = 100;		//�ړ����x�ipix/fps�j
	static constexpr float PLAYER_VELOCITY_Y = 100;

	static constexpr int PLAYER_JUMP_MAX_COUNT = 3;		//�ő�W�����v��

	//-----�����o�ϐ�-----//
	int m_hp_hdl = 0;									//HP�摜
	int m_jump_count = 0;								//�W�����v��
	float m_jump_time = 10;								//�W�����v����
	tnl::Vector3 m_jump_height = { 0,200,0 };			//�W�����v����

	//�t���O
	bool m_is_jump = false;								//�W�����v��
	bool m_is_falling = false;							//������
	bool m_was_ground = false;							//�O�t���[���̐ڒn����

	//�Q�[���X�e�B�b�N�p
	int m_direction;									/*�ړ�����*/
	int m_input_x;
	int m_input_y;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;
	void Finalize() override;

	//-----Getter-----//
	int GetMaxHP() const { return PLAYER_MAX_HP; }

private:
	void HpHandle();						//HP�̋�������
	void MoveHandle(float delta_time);		//�ړ��ɂ����W�ω�
	void AnimHandle(float delta_time);		//�A�j���[�V�����̍Đ�
	void isFlag(float delta_time);
};

//Player�̃{�^������̋����������s���N���X
//�A�j���[�V�����̍Đ��ɂ��Ă͕ʃN���X���`��������������₷������