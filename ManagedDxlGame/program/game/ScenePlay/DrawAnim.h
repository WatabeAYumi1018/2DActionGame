#pragma once
#include "../../engine/GameEngine.h"

//�A�j���[�V��������csv����ǂݎ��N���X�i���[�v�ƒP���œ��ޑ��݁j
class DrawAnim {

public:
	//int�^�ŃR���X�g���N�^
	DrawAnim();
	~DrawAnim();

private:
	//-----�萔-----//
	//�@���[�v�A�j���[�V����
	//ID�ƃt�H���_�p�X�̏��J�n�`�I��(�s��)
	const int ANIM_LOOP_ROW_START = 1;			//1�s��
	const int ANIM_LOOP_ROW_END = 20;			//20�s��
	const int ANIM_LOOP_COL_START = 0;			//0���
	const int ANIM_LOOP_COL_END = 1;			//1���
	//�A�P���A�j���[�V����
	//ID�ƃt�H���_�p�X�̏��J�n�`�I��(�s��)
	const int ANIM_NOTLOOP_ROW_START = 1;			//1�s��
	const int ANIM_NOTLOOP_ROW_END = 16;			//16�s��
	const int ANIM_NOTLOOP_COL_START = 3;			//3���
	const int ANIM_NOTLOOP_COL_END = 4;				//4���

private:
	//-----csv�t�@�C���p�X�֘A�̕ϐ�-----//
	//ID�ƃt�@�C���p�X�̓ǂݎ��
	std::string csv_anim= "csv/PlayerAnimLoop.csv";
	//
	std::vector<std::vector<int>> m_csv_anim;		

public:
	//-----�����o�֐�-----//
	void Initialize();
	void LoadFilePath();
	void Finalize();
};

