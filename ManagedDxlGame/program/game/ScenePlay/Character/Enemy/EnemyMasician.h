#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

class Camera;

//�X���C���N���X

class EnemyMasician :public Enemy
{
public:

	EnemyMasician(const sEnemyData& data, const sEnemyInfo& info);
	~EnemyMasician();

private:

	TNL_CO_SEQUENCE(Enemy, &Enemy::SeqMove);						//�R���[�`���V�[�P���X

public:

	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

private:

	bool SeqMove(const float delta_time) override;	//��{�s��01�i�ʏ�j
	bool SeqIdle(const float delta_time) override;	//��{�s��02�i�ʏ�`�J�ڂ�����ꍇ�̂ݎg�p�j
	bool SeqAttack(const float delta_time) override;		//�U������(�v���C���[�����ȏ�߂Â��ƍU��)
};