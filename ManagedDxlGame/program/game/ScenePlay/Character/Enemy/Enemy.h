#pragma once
#include "../../../../library/tnl_sequence.h"
#include "../../../../engine/GameEngine.h"
#include "../Character.h"

//��ɓG��AI���Ǘ�����N���X

class Collision;
class Camera;
class Player;
class Map;

class Enemy :public Character
{
public:

	Enemy(const sEnemyData& data, const sEnemyInfo& info,Player* player, Map*map,Collision * collision, Camera* camera);
	virtual ~Enemy() {}

protected:

	//-----�����o�ϐ�-----//
	int m_type_id;											/*�G�̃^�C�vID*/
	
	std::string m_type;										/*�G�̃^�C�v*/
	std::string m_color;									/*�G�̐F*/
	
	bool m_is_dirction_right = true;						/*�E����*/

	bool m_is_active = true;								/*�U����*/

	Player* m_player = nullptr;		
	Map* m_map = nullptr;
	Collision * m_collision = nullptr;
	Camera* m_camera = nullptr;

	//-----�����o�֐�-----//
	float DistanceCalc();						//�v���C���[�Ƃ̋����v�Z
	
public:
	virtual void Update(const float delta_time)  {}	//�X�V����
	virtual void Draw(const float delta_time, const Camera* camera)  {}		//�`�揈��d 

	bool CanMoveRight();
	bool CanMoveLeft();

	//-----Setter&Getter-----//
	int GetTypeID() const { return m_type_id; }

	bool GetIsActive() const { return m_is_active; }
	void SetIsActive(const bool is_active) { m_is_active = is_active; }
};
