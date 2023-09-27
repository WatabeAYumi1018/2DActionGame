#pragma once
#include "../../../../engine/GameEngine.h"
#include "../Character.h"

class Camera;
class Map;
class Collision;
class Wind;
class Logo;

//�v���C���[�N���X

class Player :public Character
{
public:

	Player(const tnl::Vector3& initialPos, Collision* collision, Map* map,Wind* wind,Logo* logo);
	virtual ~Player() {}

private:

	//-----�萔-----//
	static constexpr int SIZE = 35;						/*�T�C�Y*/
	static constexpr int MAX_HP = 5;					/*HP*/

	static constexpr float VELOCITY_X = 100;			/*�ړ����x�ipix / fps)*/
	static constexpr float VELOCITY_Y = 500;

	const float DASH_THRESHOLD = 0.8f;					/*�_�b�V���̂������l*/

	const float HOVER_FIRST_FORCE = 1.2f;				/*�����̕��V��*/
	const float HOVER_DECAY_FORCE = 1.0f;				/*���V�͂̌�����*/

	const float STAMP_TIME= 1.5f;						/*���n���̃A�N�V�����̎���*/

	const float ROLL_MAX_SPEED = VELOCITY_X;			/*���[���̍ő呬�x*/
	const float ROLL_DECELERATION = VELOCITY_X * 0.05f;	/*�����x*/

	//-----�����o�ϐ�-----//
	float m_hovering_force = 0.0f;						/*���݂̕��V��*/
	float m_stamp_time = 0.0f;							/*���n���̃A�N�V�����̃^�C�}�[*/

	bool m_is_draw = true;								/*�������t���O*/

	bool m_is_hovering = false;							/*�󒆂̃t���O*/
	bool m_is_hovered = false;							/*���~�t���O*/

	bool m_is_stamp = false;							/*���n�̃t���O*/
	bool m_is_rolling=false;							/*���[���̃t���O*/

	//�Q�[���X�e�B�b�N�p
	float normalized_input_x;							/*�A�i���O�X�e�B�b�N�̌X���x�N�g��*/
	int m_input_x;
	int m_input_y;

	ePlayerAction e_currentAction = ePlayerAction::Idle_right;

	//-----�|�C���^�ϐ�-----//
	Collision* m_collision=nullptr;
	Map* m_map=nullptr;
	Wind* m_wind=nullptr;
	Logo* m_logo=nullptr;

	//-----�����o�֐�-----//
	void MoveHandle(float delta_time);			/*�Q�[���p�b�h�X�e�B�b�N����*/
	void ActionHandle(float delta_time);		/*���͏���*/

	void MoveRange();							/*�ړ��͈͂̐���*/
	void Gravity(float delta_time);				/*�d�͏���*/

	void ApplyWind(float delta_time);			/*���̉e��*/

	void Hovering(float delta_time);			/*�z�o�����O����*/
	void HoveringDirection(float delta_time);	/*�z�o�����O����*/
	void HoveringStartRight(float delta_time);	/*�z�o�����O�J�n�����i�E�j*/
	void HoveringStartLeft(float delta_time);	/*�z�o�����O�J�n�����i���j*/
	//void HoveringEnd();						/*�z�o�����O�I������*/

	void Invincible(float delta_time);			/*���G���Ԃ̏���*/

public:

	void StampAction(float delta_time);			/*���n���̃A�N�V����*/
	void RollAction(float delta_time);			/*���[�����̃A�N�V����*/
	bool CheckIsGround();						/*�ڒn����*/

	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;

	//-----Getter,Setter-----//
	void SetIsDraw(bool is_draw) { m_is_draw = is_draw; }
	void SetIsStamp(bool is_stamp) { m_is_stamp = is_stamp; }
	bool GetIsRolling() const { return m_is_rolling; }
};

//Player�̃{�^������̋����������s���N���X
//�A�j���[�V�����̍Đ��ɂ��Ă͕ʃN���X���`��������������₷������