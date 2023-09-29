#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

//�d���N���X

class EnemyFairy :public Enemy
{
public:

	enum sFairyType
	{
		Peach,
		Blue,
		Yellow
	};

	EnemyFairy(const sEnemyData& data, const sEnemyInfo& info, Player* player, Map* map, Collision* collision, Camera* camera);
	~EnemyFairy();

private:

	sFairyType s_type= Peach;		//�^�C�v

	TNL_CO_SEQUENCE(EnemyFairy, &EnemyFairy::SeqIdle);						//�R���[�`���V�[�P���X

public:
	
	void Update(const float delta_time) override;	//�X�V����
	void Draw(const float delta_time, const Camera* camera) override;		//�`�揈��

	void RandomType();		//�����_���Ń^�C�v����

	bool SeqIdle(const float delta_time);
	bool SeqMove(const float delta_time);
	bool SeqAttack(const float delta_time);
};
