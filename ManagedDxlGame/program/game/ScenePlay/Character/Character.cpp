#include "Character.h"


Character::Character(const tnl::Vector3 pos, int size, int hp, const tnl::Vector3 velocity) :
	GameObject(pos), m_size(size), m_hp(hp), m_velocity(velocity)
{
	// CSV����A�j���[�V�����f�[�^�����[�h
	animLoader = new wta::DrawAnim("csv/AnimLoad.csv", "graphics/animation");
}

Character::~Character()
{
	delete animLoader;
	animLoader = nullptr;
}

void Character::DecreaseHP(int damage)
{
	m_hp-=damage;

	if (m_hp <= 0)
	{
		m_is_dead = true;
	}
}

//���G���Ԃ̃��Z�b�g
void Character::MakeInvincible()
{
	m_is_invincible = true;
	m_invincible_time = 0.0f;
}