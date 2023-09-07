#pragma once
#include <random>
#include "../../../../engine/GameEngine.h"
#include "../Character.h"

//��ɓG��AI���Ǘ�����N���X

class Camera;
class Player;
class Map;
class Collision;

class Enemy :public Character
{

public:

	Enemy(const sEnemyData& data, const sEnemyInfo& info,Player* player,Map *map,Collision *coiision);
	virtual ~Enemy() {}

protected:

	//-----�����o�ϐ�-----//
	int m_type_id;											/*�G�̃^�C�vID*/
	std::string m_type;										/*�G�̃^�C�v*/
	std::string m_color;									/*�G�̐F*/
	bool m_is_dirction_right = true;						/*�E����*/

	float m_moveTimeCounter = 0.0f;

	std::default_random_engine m_generator;								//�W�F�l���[�^�[�i�������z�Ƒg�ݍ��킹�Đ����j
	std::uniform_real_distribution<float> m_distribution{ 0.0f, 1.0f };	//�������߁iidle��move�j

	Player* m_player = nullptr;		
	Map * m_map = nullptr;
	Collision * m_collision = nullptr;

	//-----�����o�֐�-----//
	float DistanceCalc();						//�v���C���[�Ƃ̋����v�Z
	
public:
	virtual void Update(const float delta_time)  {}	//�X�V����
	virtual void Draw(const float delta_time, const Camera* camera)  {}		//�`�揈��

	virtual bool SeqMove(const float delta_time) { return 0; }	//��{�s��01�i�ʏ�j
	virtual bool SeqIdle(const float delta_time) { return 0; }	//��{�s��02�i�ʏ�`�J�ڂ�����ꍇ�̂ݎg�p�j
	virtual bool SeqAttack(const float delta_time) { return 0; }		//�U������(�v���C���[�����ȏ�߂Â��ƍU��)
};
