#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

class Camera;

//�X���C���N���X

class EnemyPlant :public Enemy
{
public:

	EnemyPlant(const sEnemyData& data, const sEnemyInfo& info);
	~EnemyPlant();

private:

	TNL_CO_SEQUENCE(Enemy, &Enemy::SeqIdle);						//�R���[�`���V�[�P���X

public:

	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

private:

	bool SeqIdle(const float delta_time) override;	//��{�s���i
	bool SeqAttack(const float delta_time) override;//�U������(�v���C���[�����ȏ�߂Â��ƍU��)
};