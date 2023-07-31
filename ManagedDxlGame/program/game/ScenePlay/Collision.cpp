#include "Collision.h"

//Collision::Collision(int width, int height):m_width(width),m_height(height){}
Collision::Collision(int radius) :m_radius(radius) {}

Collision::~Collision() { delete this; }

//���v�Z�~�X�̂��߁A�����m�F
bool Collision::CircleLine(const Vector3& circle_pos, float radius, float line_pos_start_x, float line_pos_end_x, float line_pos_start_y, float line_pos_end_y) {

	//Step 1: �~�̒��S�Ɛ����̍Ŋ��_�����߂�
	//�����̃x�N�g��
	float ABx = line_pos_end_x - line_pos_start_x;
	float ABy = line_pos_end_y - line_pos_start_y;
	//AB��AO�̓���
	float AB_dot = (circle_pos.x - line_pos_start_x) * ABx + (circle_pos.y - line_pos_start_y) * ABy;
	//����/�����̒���
	float t = AB_dot / (ABx * ABx + ABy * ABy);
	t = fmax(0, fmin(1, t));

	// �����̎n�_����Ŋ��_�܂ł̃x�N�g�������߂�
	float closestPoint_x = line_pos_start_x + t * ABx;
	float closestPoint_y = line_pos_start_y + t * ABy;

	//Step 2: �Ŋ��_��������ɂ��邩�ǂ������肷��
	//�Ŋ��_�Ɖ~�̒��S�̋����̂Q������߂�
	float distanceSquared = (closestPoint_x - circle_pos.x) * (closestPoint_x - circle_pos.x)
								+ (closestPoint_y - circle_pos.y) * (closestPoint_y - circle_pos.y);
	
	////�~�̔��a�̂Q��Ɣ�r����i�������ł̍��R�X�g�팸�̂��ߓ��Ŕ�r�j
	//if (distanceSquared < radius * radius || t < 0 || t > 1 ) {return false;}

	////Step 3: �Ŋ��_�Ɖ~�̒��S�̋��������߂�
	//float distance = distanceSquared;

	//Step 4: �������~�̔��a�������������ǂ����𔻒肷��
	if(distanceSquared <= radius * radius) {return true;}

	else { return false; }
}

	////-----�~�̒��S�Ɛ����̋��������߂�-----//
	////�@AO�̃x�N�g�������߂�(z��0)
	//Vector3 AO = { circle_pos.x - line_pos_start_x,circle_pos.y - line_pos_start_y,0 };
	////�AAO�̑傫���i�����j�����߂�
	//float AO_size = sqrt(AO.x * AO.x + AO.y * AO.y);
	////�BAO�̒P�ʃx�N�g�������߂�i���K���j
	//Vector3 AO_unit = { AO.x / AO_size,AO.y / AO_size,0 };

	////�CAB�̃x�N�g�������߂�
	//Vector3 AB = { line_pos_end_x - line_pos_start_x,line_pos_end_y - line_pos_start_y,0 };
	////�DAB�̑傫���i�����j�����߂�
	//float AB_size = sqrt(AB.x * AB.x + AB.y * AB.y);
	////�EAB�̒P�ʃx�N�g�������߂�i���K���j
	//Vector3 AB_unit = { AB.x / AB_size,AB.y / AB_size,0 };

	////�FAO��AB�̓��ς����߂�
	//float AO_dot_AB = AO.x * AB_unit.x + AO.y * AB_unit.y;

	////�G�_P�̍��W�����߂�
	//Vector3 P = { line_pos_start_x * AO_dot_AB, line_pos_start_y * AO_dot_AB ,0 };

	////�HAO��AP�̊O��
	//float AO_cross_AP = AO.x * P.y - AO.y * P.x;
	//
	////OP�̒����Ɖ~�̔��a���r
	//if (AO_cross_AP <= radius) {
	//	return false;
	//}
	//else {
	//	return true;
	//}
//}

//�L�����N�^�[���m�̓����蔻����`�F�b�N
//bool Collision::HitCheck(const Vector3& pos, const Object* other) {}
