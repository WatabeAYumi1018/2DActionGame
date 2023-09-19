#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

//�X���C���N���X

class EnemyMasician :public Enemy
{
public:

	EnemyMasician(const sEnemyData& data, const sEnemyInfo& info, Player* player, Map* map, Collision* collision, Camera* camera);
	~EnemyMasician();

private:

	TNL_CO_SEQUENCE(EnemyMasician, &EnemyMasician::SeqIdle);						//�R���[�`���V�[�P���X

public:

	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

	bool SeqIdle(const float delta_time);
	bool SeqMove(const float delta_time);
	bool SeqAttack(const float delta_time);
};