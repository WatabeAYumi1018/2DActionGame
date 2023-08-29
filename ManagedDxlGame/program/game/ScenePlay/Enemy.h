#pragma once
#include <random>
#include "../../engine/GameEngine.h"
#include "Character.h"

//��ɓG��AI���Ǘ�����N���X

class PlayCamera;

class Enemy :public Character {

public:
	Enemy();
	virtual ~Enemy();

private:
	//-----�����o�ϐ�-----//
	float m_moveTimeCounter = 0.0f;
	
	std::default_random_engine generator;								//�W�F�l���[�^�[�i�������z�Ƒg�ݍ��킹�Đ����j
	std::uniform_real_distribution<float> distribution{ 0.0f, 1.0f};	//�����̕��z�i����͈͓̔��Ő����j
	TNL_CO_SEQUENCE(Enemy,&Enemy::SeqBaseAction);						//�R���[�`���V�[�P���X

	Character* m_player = nullptr;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const PlayCamera* camera) override;
	void Finalize() override;

private:
	bool SeqBaseAction(const float delta_time);	//��{�s��01�i�ʏ�j
	bool SeqNextAction(const float delta_time);	//��{�s��02�i�ʏ�`�J�ڂ�����ꍇ�̂ݎg�p�j
	bool SeqAttack(const float delta_time);		//�U������(�v���C���[�����ȏ�߂Â��ƍU��)
};
	
//eAttackType m_eAttackType;										//�A�^�b�N�^�C�v�^�O����p