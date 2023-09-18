#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"


//�X���C���N���X

class EnemyDoragon :public Enemy
{
public:
	
	EnemyDoragon(const sEnemyData& data, const sEnemyInfo& info, Player* player, Map1* map, Collision* collision, Camera* camera);
	~EnemyDoragon();

private:

	//TNL_CO_SEQUENCE(EnemyDoragon, &EnemyDoragon::SeqMove);						//�R���[�`���V�[�P���X

public:
	
	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

private:
	
	//bool SeqMove(const float delta_time) ;
	//bool SeqIdle(const float delta_time) ;
	//bool SeqAttack(const float delta_time);

};