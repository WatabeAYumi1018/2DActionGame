#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

class Camera;
class Player;

//�X���C���N���X

class EnemySlim :public Enemy
{
public:

	EnemySlim(const sEnemyData& data, const sEnemyInfo& info, Player* player, Map* map, Collision* collision);
	~EnemySlim();

private:

	TNL_CO_SEQUENCE(EnemySlim, &EnemySlim::SeqMove);						//�R���[�`���V�[�P���X

public:
	
	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

private:

	bool SeqMove(const float delta_time) override;	//��{�s��01�i�ʏ�j
	bool SeqIdle(const float delta_time) override;	//��{�s��02�i�ʏ�`�J�ڂ�����ꍇ�̂ݎg�p�j
	bool SeqAttack(const float delta_time) override;		//�U������(�v���C���[�����ȏ�߂Â��ƍU��)
};
