#pragma once
#include "../../engine/GameEngine.h"
#include "Character.h"


class Player :public Character {

public:
	Player(Vector3 pos);
	~Player();

private:
	//-----�萔-----//
	const int PLAYER_SPEED_WALK = 400;		//�ړ����x�ipix/fps�j
	const int PLAYER_SPEED_DASH = 800;		//�_�b�V�����x�ipix/fps�j
	const int PLAYER_HP = 5;				//�v���C���[��HP

	//-----�����o�ϐ�-----//
	Vector3 m_jump_velocity = {0,0,0};		//�W�����v�́ipix/fps�j
	int m_dash;								//�_�b�V���X�s�[�h
	Camera* m_camera = nullptr;				//�J����

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw() override;
	void Finalize() override;

	//-----Setter,Getter-----//
	void SetDash(int dash) { m_dash = dash; }
	int GetDash() { return m_dash; }
	
	void SetCamera(Camera* camera) { m_camera = camera; }
	Camera* GetCamera() { return m_camera; }

	//void SetAttackType(eAttackType type) { m_eAttackType = type; }
	//eAttackType GetAttackType() { return m_eAttackType; }
};