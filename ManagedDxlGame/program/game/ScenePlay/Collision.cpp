#include "Collision.h"


Collision::Collision(Vector3 pos,int radius):m_pos(pos),m_radius(radius){}



Collision::~Collision() { delete this; }

// �����Ɖ~�̓����蔻��
//bool Collision::HitCircleLine(const Player& circle, const Object& line) {
//   
//    // �����̎n�_�ƏI�_�̃x�N�g��
//    Vector3 line_vec = line.m_end - line.m_start;
//    // �����̎n�_����~�̒��S�܂ł̃x�N�g��
//    Vector3 circle_vec = circle.m_pos - line.m_start;
//
//    // �����̒�����2��
//    float line_length_pow = line_vec.x * line_vec.x + line_vec.y * line_vec.y;
//    // �����̎n�_����~�̒��S�܂ł̋����i�����̌������l���������ρj
//    float dot_product = line_vec.x * circle_vec.x + line_vec.y * circle_vec.y;
//
//    // ������̌�_���v�Z
//    float t = dot_product / line_length_pow;
//
//	// t��0~1�̊Ԃɂ���ꍇ�F������Ɍ�_�����݂���
//    if (t >= 0 && t <= 1.0f) {
//        // ��_����~�̒��S�܂ł̋������v�Z
//        Vector3 intersection_point = line.m_start + t * line_vec;
//        // ������2����v�Z
//        float distance_squared = (intersection_point.x - circle.m_pos.x) * (intersection_point.x - circle.m_pos.x) +
//            (intersection_point.y - circle.m_pos.y) * (intersection_point.y - circle.m_pos.y);
//        //�~�̔��a��2��
//        float radius_squared = m_radius * m_radius;
//        // �������~�̔��a�ȉ����𔻒�
//        if (distance_squared <= radius_squared) {return true;}
//    }
//
//	//t��0~1�̊O�F�������[�̓_�Ɖ~�̓����蔻����`�F�b�N
//    else {
//        // �����̎n�_�Ɖ~�̒��S�̋�����2��
//        Vector3 distance1 = line.m_start - circle.m_pos;
//        // �����̏I�_�Ɖ~�̒��S�̋�����2��
//        Vector3 distance2 = { line.m_end - circle.m_pos;
//        //�~�̔��a��2��
//        float radius_squared = m_radius * m_radius;
//        //���ꂼ��̒������v�Z
//        float distance1_squared = distance1.x * distance1.x + distance1.y * distance1.y;
//        float distance2_squared = distance2.x * distance2.x + distance2.y * distance2.y;
//        // �������~�̔��a�ȉ����𔻒�
//        if (distance1_squared <= radius_squared || distance2_squared <= radius_squared) { return true; }
//    }
//    return false;
//}

//�L�����N�^�[���m�̓����蔻����`�F�b�N
//bool Collision::HitCheck(const Vector3& pos, const Object* other) {}
