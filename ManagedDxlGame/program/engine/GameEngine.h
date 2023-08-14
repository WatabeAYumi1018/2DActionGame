#pragma once
#include "../dxlib_ext/dxlib_ext.h"


enum class eAttackType {
	eAttack_Push,
	eAttack_Fire,
	eAttack_Beam,
	eAttack_Max
};

enum class eCollisionType {
	eCollision_None,
	eCollision_Block,
	eCollision_Line,
	eCollision_Max
};

// ID�Ɠ����蔻��̏���ێ�����\����
struct IDCollision {
	int id;
	eCollisionType collision;
};