#pragma once
#include "../../engine/GameEngine.h"
#include "Character.h"
#include "../../wta_library/wta_DrawAnim.h"

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
	static constexpr float PLAYER_POS_X = 100;			//�v���C���[�̏����ʒu
	static constexpr float PLAYER_POS_Y = 250;
	
	static constexpr int PLAYER_SIZE = 35;				//�v���C���[�̃T�C�Y
	static constexpr int PLAYER_HP = 5;					//�v���C���[��HP
	
	static constexpr float PLAYER_VELOCITY_X = 100;		//�ړ����x�ipix/fps�j
	static constexpr float PLAYER_VELOCITY_Y = 100;

	static constexpr int PLAYER_JUMP_MAX_COUNT = 3;		//�ő�W�����v��

	//-----�����o�ϐ�-----//
	int m_jump_count = 0;								//�W�����v��
	float m_jump_time=10;								//�W�����v����
	tnl::Vector3 m_jump_height = {0,500,0};			//�W�����v����
	
	//�t���O
	bool m_is_jump = false;								//�W�����v��
	bool m_is_falling = false;							//������
	bool m_was_ground=false;							//�O�t���[���̐ڒn����
	bool m_is_dirction_right = true;					//����


	//-----�A�j���[�V����-----//
	wta::DrawAnim *animLoader = nullptr;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;
	void Finalize() override;

private:
	void MoveHandle(float delta_time);		//�ړ��ɂ����W�ω�
	void AnimHandle(float delta_time);		//�A�j���[�V�����̍Đ�
	void isFlag(float delta_time);
};

//Player�̃{�^������̋����������s���N���X
//�A�j���[�V�����̍Đ��ɂ��Ă͕ʃN���X���`��������������₷������