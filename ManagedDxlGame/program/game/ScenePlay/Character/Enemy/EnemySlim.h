#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

//�X���C���N���X

class EnemySlim :public Enemy
{
public:

	EnemySlim(const sEnemyData& data, const sEnemyInfo& info, Player* player, Map* map, Collision* collision, Camera* camera);
	~EnemySlim();

private:

	TNL_CO_SEQUENCE(EnemySlim, &EnemySlim::SeqIdle);						//�R���[�`���V�[�P���X

public:
	
	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

private:

	bool SeqIdle(const float delta_time) ;	
	bool SeqMove(const float delta_time) ;	
	bool SeqAttack(const float delta_time);
};

//idle���ƃX���C���Battack���ƐA���ɂȂ��Ă�