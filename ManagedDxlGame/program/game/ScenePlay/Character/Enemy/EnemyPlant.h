#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

//�A���N���X

class EnemyPlant :public Enemy
{
public:

	EnemyPlant(const sEnemyData& data, const sEnemyInfo& info,Player *player, Map* map, Collision* collision, Camera* camera);
	~EnemyPlant();

private:

	TNL_CO_SEQUENCE(EnemyPlant, &EnemyPlant::SeqIdle);						//�R���[�`���V�[�P���X

public:

	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

private:

	bool SeqIdle(const float delta_time);	
	bool SeqAttack(const float delta_time);
};
