#include "DrawAnim.h"

DrawAnim::DrawAnim() {
	//csv�t�@�C���������ǂݍ���
	m_csv_anim = tnl::LoadCsv<int>(csv_anim);
	Initialize();
}

DrawAnim::~DrawAnim() { Finalize(); }

void DrawAnim::Initialize() {LoadFilePath();}

//�t�@�C���p�X��ǂݍ��݁Aenum�Ǘ�
void DrawAnim::LoadFilePath() {
	//
	//-----�t�@�C���p�X�̓ǂݍ���-----//
}

void DrawAnim::Finalize() {m_csv_anim.clear();}