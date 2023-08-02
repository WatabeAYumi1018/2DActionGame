#include "Collision.h"

//Collision::Collision(int width, int height):m_width(width),m_height(height){}
Collision::Collision(int radius) :m_radius(radius) {}

Collision::~Collision() { delete this; }

//���o���Ă�͂��Ȃ̂ɂȂ񂩈Ⴄ�炵��
// �����Ɖ~�̓����蔻��
bool Collision::CircleLine(const Vector3& circle_pos, float radius,float line_pos_start_x,
                            float line_pos_end_x,float line_pos_start_y, float line_pos_end_y) 
{
    // �����̎n�_�ƏI�_�̃x�N�g��
    Vector3 line_vec = { line_pos_end_x - line_pos_start_x, line_pos_end_y - line_pos_start_y, 0 };
    // �����̎n�_����~�̒��S�܂ł̃x�N�g��
    Vector3 circle_vec = { circle_pos.x - line_pos_start_x, circle_pos.y - line_pos_start_y, 0 };

    // �����̒�����2��
    float line_length_pow = line_vec.x * line_vec.x + line_vec.y * line_vec.y;
    // �����̎n�_����~�̒��S�܂ł̋����i�����̌������l���������ρj
    float dot_product = line_vec.x * circle_vec.x + line_vec.y * circle_vec.y;

    // ������̌�_���v�Z
    float t = dot_product / line_length_pow;
    // ��_��������ɑ��݂��邩�𔻒�
    bool point_on_segment = (t >= 0 && t <= 1.0f);

    if (point_on_segment) {
        // ��_����~�̒��S�܂ł̋������v�Z
        Vector3 intersection_point = { line_pos_start_x + t * line_vec.x, line_pos_start_y + t * line_vec.y, 0 };
        float distance_squared = (intersection_point.x - circle_pos.x) * (intersection_point.x - circle_pos.x) +
            (intersection_point.y - circle_pos.y) * (intersection_point.y - circle_pos.y);

        // �������~�̔��a�ȉ����𔻒�
        float radius_squared = radius * radius;
        if (distance_squared <= radius_squared) {
            return true; // ������
        }
    }
    return false; // ������Ȃ�
}



//�L�����N�^�[���m�̓����蔻����`�F�b�N
//bool Collision::HitCheck(const Vector3& pos, const Object* other) {}
