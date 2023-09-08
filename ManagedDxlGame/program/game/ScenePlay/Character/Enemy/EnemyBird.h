#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

//�X���C���N���X

class EnemyBird :public Enemy
{
public:
	
	EnemyBird(const sEnemyData& data, const sEnemyInfo& info, Player* player, Map* map, Collision* collision);
	~EnemyBird();

private:

	TNL_CO_SEQUENCE(EnemyBird, &EnemyBird::SeqMove);						//�R���[�`���V�[�P���X

public:

	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

private:

	bool SeqMove(const float delta_time) override;	
	bool SeqAttack(const float delta_time) override;		
};