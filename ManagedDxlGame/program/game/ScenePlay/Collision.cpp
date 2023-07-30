#include "Collision.h"

//Collision::Collision(int width, int height):m_width(width),m_height(height){}
Collision::Collision(int radius) :m_radius(radius) {}

Collision::~Collision() { delete this; }

//���v�Z�~�X�̂��߁A�����m�F
bool Collision::CircleLine(const Vector3& circle_pos, float radius, int line_pos_start_x, int line_pos_end_x, int line_pos_start_y, int line_pos_end_y) {

	//-----�~�̒��S�Ɛ����̋��������߂�-----//
	//�@�x�N�g�������߂�ia,b�j
	int a = circle_pos.x - line_pos_start_x;
	int b = circle_pos.y - line_pos_start_y;

	//�A���ς����߂�a�Eb
	int inner_x(line_pos_end_x - line_pos_start_x);
	int inner_y(line_pos_end_y - line_pos_start_y);

	//�B���ς��x�N�g���̑傫���Ŋ���
	float distance = abs((inner_x)+(inner_y)) / sqrt(a * a + b * b);

	//�C�x�N�g���ƒ��S���W�̐����ړ_���W�����߂�
	//(line_pos_start_x,line_pos_end_x)+(a,b)
	int contact_x = line_pos_start_x + distance * a;
	int contact_y = line_pos_start_y + distance * b;		//(contact_x,contact_y)

	//�D�~�̔��a�Ɛ����̋��������߂�(contact_x,contact_y) - (circle_pos.x,circle_pos.y) x���m�Ay���m�̌v�Z
	float dis = (contact_x - circle_pos.x) * (contact_x - circle_pos.x) + (contact_y - circle_pos.y) * (contact_y - circle_pos.y);

	//�~�̔��a�Ɛ����̋������r
	if (dis > radius) {
		return false;
	}
	return true;
}


//�L�����N�^�[���m�̓����蔻����`�F�b�N
//bool Collision::HitCheck(const Vector3& pos, const Object* other) {}
