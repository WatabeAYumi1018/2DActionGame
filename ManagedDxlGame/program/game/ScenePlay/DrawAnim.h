//#pragma once
//#include "../../engine/GameEngine.h"
//
////�A�j���[�V��������csv����ǂݎ��N���X�i���[�v�ƒP���œ��ޑ��݁j
//class DrawAnim {
//
//public:
//	//int�^�ŃR���X�g���N�^
//	DrawAnim();
//	~DrawAnim();
//
//private:
//	//-----�萔-----//
//	//�@���[�v�A�j���[�V����
//	const int ANIM_LOOP_ROW_START = 1;			//1�s��
//	const int ANIM_LOOP_ROW_END = 20;			//20�s��
//	//�A�P���A�j���[�V����
//	const int ANIM_NOTLOOP_ROW_START = 1;		//1�s��
//	const int ANIM_NOTLOOP_ROW_END = 16;		//16�s��
//
//private:
//	//-----csv�t�@�C���p�X�֘A�̕ϐ�-----//
//	//ID�ƃt�@�C���p�X�̓ǂݎ��
//	std::string csv_anim= "csv/AnimPath.csv";
//	//string�^�Ŋi�[
//	std::vector<std::vector<std::string>> m_anim_path;
//
//public:
//	//-----�����o�֐�-----//
//	void Initialize();
//	void LoadPathLoop();		//���[�v�A�j���[�V�����̓ǂݎ��
//	void LoadPathNotLoop();		//�P���A�j���[�V�����̓ǂݎ��
//	void Finalize();
//};
//
