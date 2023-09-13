#pragma once
#include "../../../../engine/GameEngine.h"
#include "../Character.h"

class Camera;
class Map;
class Collision;

//�v���C���[�̃N���X
//��Ƀ{�^������̋����������s��
//�`��ɂ��Ă̎�Ȓ�`��wta_LoadAnim, wta_DrawAnim�ɂ�

class Player :public Character
{
public:
	Player(Collision* collision, Map* map);
	virtual ~Player();

private:
	//-----�萔-----//
	static constexpr float PLAYER_POS_X = 100;			//�����ʒu
	static constexpr float PLAYER_POS_Y = 0;

	static constexpr int PLAYER_SIZE = 35;				//�T�C�Y
	static constexpr int PLAYER_MAX_HP = 5;				//HP

	static constexpr float PLAYER_VELOCITY_X = 100;		//�ړ����x�ipix/fps�j
	static constexpr float PLAYER_VELOCITY_Y = 500;

	const float DASH_THRESHOLD = 0.8f;					/*�_�b�V���̂������l���`*/

	const float PLAYER_INITIAL_HOVER_FORCE = 1.5f; // �����̕��V��
	const float PLAYER_HOVER_DECAY_RATE = 1.0f; // ���V�͂̌�����

	//-----�����o�ϐ�-----//
	int m_hp_hdl = 0;									//HP�摜
	
	float m_hovering_force = 0.0f;						// ���݂̕��V��
	float m_landing_time = 0.0f;						// ���n���Ă���̌o�ߎ���
	
	bool m_is_hovering = false;							// �󒆂ɂ��邩�ǂ����̃t���O
	bool m_is_hovered = false;							// ��C�����������ǂ����̃t���O
	bool m_was_in_air = false;							// �󒆂ɂ������ǂ����̃t���O
	bool m_hover_end_drawed=false;						// ���n���̃A�N�V�������ݒ肳��Ă��邩�ǂ����̃t���O

	//�Q�[���X�e�B�b�N�p
	float normalized_input_x;							/*�A�i���O�X�e�B�b�N�̌X���x�N�g��*/
	int m_input_x;
	int m_input_y;

	Collision* m_collision=nullptr;
	Map* m_map=nullptr;

	ePlayerAction e_currentAction = ePlayerAction::Idle_right;		//�A�N�V����

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;
	void Finalize() override;

private:

	void MoveHandle(float delta_time);		//�Q�[���p�b�h�X�e�B�b�N����
	void ActionHandle(float delta_time);	//���͏���
	
	void MoveRange();						//�ړ��͈͂̐���
	void Gravity(float delta_time);			//�d�͏���

	void Hovering(float delta_time);		//�z�o�����O����
	void HoveringDirection(float delta_time);	//�z�o�����O����
	void HoveringStartRight(float delta_time);				//�z�o�����O�J�n�����i�E�j
	void HoveringStartLeft(float delta_time);				//�z�o�����O�J�n�����i���j
	void HoveringEnd();						//�z�o�����O�I������
	bool CheckIsGround();					//�ڒn����
	
	void Invincible(float delta_time);		//���G���Ԃ̏���
};

//Player�̃{�^������̋����������s���N���X
//�A�j���[�V�����̍Đ��ɂ��Ă͕ʃN���X���`��������������₷������