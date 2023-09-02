#pragma once
#include <random>
#include "../../engine/GameEngine.h"
#include "Character.h"

//��ɓG��AI���Ǘ�����N���X

class EnemyLoad;
class Camera;

class Enemy :public Character
{

public:

	Enemy(const sEnemyData& data);
	~Enemy() {}

private:

	//-----�����o�ϐ�-----//
	float m_moveTimeCounter = 0.0f;
	eEnemyType m_type = eEnemyType::None;					/*�G�̃^�C�v*/

	std::default_random_engine m_generator;								//�W�F�l���[�^�[�i�������z�Ƒg�ݍ��킹�Đ����j
	std::uniform_real_distribution<float> m_distribution{ 0.0f, 1.0f};	//�������߁iidle��move�j
	TNL_CO_SEQUENCE(Enemy,&Enemy::SeqBaseAction);						//�R���[�`���V�[�P���X

	Character* m_player = nullptr;		//�R�c
	EnemyLoad *m_enemyLoad = nullptr;	//�G�ǂݎ��

public:
	//-----�����o�֐�-----//
	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;

	float DistanceCalc();						//�v���C���[�Ƃ̋����v�Z
	bool SeqBaseAction(const float delta_time);	//��{�s��01�i�ʏ�j
	bool SeqNextAction(const float delta_time);	//��{�s��02�i�ʏ�`�J�ڂ�����ꍇ�̂ݎg�p�j
	bool SeqAttack(const float delta_time);		//�U������(�v���C���[�����ȏ�߂Â��ƍU��)
};
	