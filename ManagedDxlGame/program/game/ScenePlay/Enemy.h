#pragma once
#include <random>
#include "../../engine/GameEngine.h"
#include "Character.h"

//��ɓG��AI���Ǘ�����N���X

class MapManager;
class PlayCamera;

class Enemy :public Character
{
public:
	Enemy();
	virtual ~Enemy();

private:
	//-----�����o�ϐ�-----//
	int m_size = 30;
	float m_moveTimeCounter = 0.0f;
	
	std::default_random_engine m_generator;								//�W�F�l���[�^�[�i�������z�Ƒg�ݍ��킹�Đ����j
	std::uniform_real_distribution<float> m_distribution{ 0.0f, 1.0f};	//�����̕��z�i����͈͓̔��Ő����j
	TNL_CO_SEQUENCE(Enemy,&Enemy::SeqBaseAction);						//�R���[�`���V�[�P���X

	std::vector<std::vector<int>> m_enemy_csv;						//�G�ꏊ�̓ǂݎ��p
	std::vector<sEnemyData> m_enemy_info;							//�G�ꏊ�̏��i�[�p

	Character* m_player = nullptr;		//�R�c
	MapManager *m_mapmanager = nullptr;	//�}�b�v�}�l�[�W���[

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const PlayCamera* camera) override;
	void Finalize() override;

private:
	void LoadEnemy();							//�G�L��������
	float DistanceCalc();						//�v���C���[�Ƃ̋����v�Z
	bool SeqBaseAction(const float delta_time);	//��{�s��01�i�ʏ�j
	bool SeqNextAction(const float delta_time);	//��{�s��02�i�ʏ�`�J�ڂ�����ꍇ�̂ݎg�p�j
	bool SeqAttack(const float delta_time);		//�U������(�v���C���[�����ȏ�߂Â��ƍU��)
};
	
//eAttackType m_eAttackType;										//�A�^�b�N�^�C�v�^�O����p