#include "../engine/BackGround.h"
#include "../game/ScenePlay/PlayCamera.h"


void BackGround::Initialize()
{
	m_back_hdl = LoadGraph("graphics/backSky.jpg");
}

void BackGround::Draw(const PlayCamera* camera) 
{
	tnl::Vector3 draw_pos =
		m_pos - (camera->GetTarget()*m_scroll_speed) + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	DrawRotaGraph(draw_pos.x, draw_pos.y, 1.0f, 0, m_back_hdl, true);
}
	//Movie(camera);

//void BackGround::Movie(const PlayCamera* camera){
//
//	tnl::Vector3 draw_pos =
//		m_pos - camera->GetTarget() + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
//
//	//����̉摜�T�C�Y���擾
//	int size_x = 0;
//	int size_y = 0;
//
//	GetGraphSize(m_back_hdl, &size_x, &size_y);
//
//	//����Ɠ��T�C�Y�̃X�N���[�����쐬(�����ȃs�N�Z�����������ߎO�ڂ̈�����TRUE)
//	m_screen_handle = MakeScreen(size_x, size_y, TRUE);
//
//	//����̍Đ��J�n
//	PlayMovieToGraph(m_back_hdl, DX_PLAYTYPE_LOOP);
//
//	//���߂�����@�Ƃ��Ė��邳�N���b�v�t�B���^�[������
//	//�u���ȏ�/�ȉ��̖��邳�̐F�����ׂēh��Ԃ��v�Ƃ����͋����������ł���
//	//FilterType�ȍ~�̈���...��r���@�iLESS/GREATER),��r����l,�Y������F��h��Ԃ���,
//	//�h��Ԃ�����̐F,�h��Ԃ�����̐F�̕s�����x(�����ɂ������̂�0)
//	GraphFilterBlt(m_back_hdl, m_screen_handle, DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, m_bright_border, true, GetColor(0, 0, 0), 0);
//
//	//���ߏ������ꂽ�摜����ʂ����ς��ɕ`��
//	DrawExtendGraph(draw_pos.x, draw_pos.y, draw_pos.x+DXE_WINDOW_WIDTH, draw_pos.y+DXE_WINDOW_WIDTH, m_screen_handle, TRUE);
//	//DrawRotaGraph(draw_pos.x, draw_pos.y, 1.0f, 0, m_screen_handle, true);
//}

