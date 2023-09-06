#pragma once
#include <vector>
#include "../library/tnl_math.h"

namespace wta
{
	//�~���m�̓����蔻��v�Z
	bool IsIntersectCircleCircle(const tnl::Vector3& pos1, float radius1, const tnl::Vector3& pos2, float radius2);

}
	//�g�p�ɂ͖��Ȃ�����ǁA����͂����܂ł̔��菈���͕s�v�̂��߁Atnl�����̊֐����g�p����
	////�~���m�̍��W�␳	
	////�~�Ɛ����̓����蔻��v�Z
	//bool IsIntersectCircleLine(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& lineStart, const tnl::Vector3& lineEnd);

	////�~�Ɛ����̍��W�␳
	//tnl::Vector3 CorrectCircleLineCollision(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& lineStart, const tnl::Vector3& lineEnd);


	//�~�Ɖ~�̍��W�␳
	//tnl::Vector3 CorrectCircleCircleOverlap(const tnl::Vector3& circle01, const int CircleSize01, const tnl::Vector3& circle02, const int CircleSize02); 

	////���~�Ƌ�`�̓����蔻��v�Z(�v�Z�~�X�Ŗ������̂��߁A�ۑ�I����ɉ��ς�ڎw��)
	//bool IsIntersectCircleBox(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& box, const int boxSize);