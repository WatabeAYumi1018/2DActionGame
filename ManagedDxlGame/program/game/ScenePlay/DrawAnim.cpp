//#include "DrawAnim.h"
//
//DrawAnim::DrawAnim() {
//	//csv�t�@�C���������ǂݍ���
//	m_anim_path=tnl::LoadCsv<std::string>(csv_anim);
//	Initialize();
//}
//
//DrawAnim::~DrawAnim() { Finalize(); }
//
//void DrawAnim::Initialize() { 
//	LoadPathLoop();
//	LoadPathNotLoop();
//}
//
////�t�@�C���p�X��ǂݍ��ށi���[�v�j
//void DrawAnim::LoadPathLoop() {
//	for (int i = ANIM_LOOP_ROW_START; i < ANIM_LOOP_ROW_END; ++i) {
//		std::vector<std::string> m_anim_loop;
//		//�t�@�C���p�X���̂݊i�[
//		m_anim_loop.emplace_back(m_anim_path[i][1]);
//	}
//}
//
////�t�@�C���p�X��ǂݍ��ށinot���[�v�j
//void DrawAnim::LoadPathNotLoop() {
//	for (int i = ANIM_NOTLOOP_ROW_START; i < ANIM_NOTLOOP_ROW_END; ++i) {
//		std::vector<std::string> m_anim_notLoop;
//		//�t�@�C���p�X���̂݊i�[
//		m_anim_notLoop.emplace_back(m_anim_path[i][4]);
//	}
//}
//
//
//void DrawAnim::Finalize() {
//	m_anim_path.clear();
//}