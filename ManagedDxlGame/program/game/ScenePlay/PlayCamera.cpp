#pragma once
#include "../../engine/GameEngine.h"
#include "PlayCamera.h"
#include "Player.h"
#include "MapChip.h"

//�v���C���[�Ǐ]�J����
//�R���X�g���N�^�iObject�̃R���X�g���N�^�ŏ������q�j
PlayCamera::PlayCamera(tnl::Vector3 pos,Player* player) :Object(pos) ,m_player(player){
}

//�f�X�g���N�^
PlayCamera::~PlayCamera(){}

//���t���[���X�V
void PlayCamera::Update(float delta_time) {
	
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		// 1000.0f�͈ړ����x�̗�
		m_pos.x += 500.0f * delta_time;
		// �}�b�v�`�b�v�̕`��ʒu���J�����̈ړ��ɍ��킹�Ē���
		m_map_chip->AdjustPosition(tnl::Vector3(1000.0f * delta_time, 0.0f, 0.0f));
	}
	Draw();
	//	DrawCircle(m_pos.x, m_pos.y, 10.0f, -1);
	//	//��ʒ����܂Ői�񂾂�A���փX�N���[�����ĉ�ʊO�ɂ������`�b�v��`��
	//	if (m_pos.x > DXE_WINDOW_WIDTH / 2.0f) {
	//		DrawCircle(m_pos.x, m_pos.y, 10.0f, -1);
	//		mapChip->Update(delta_time);
	//	}
	//	
	//}
	//if (m_player) {
	//	//�v���C���[�̍��W����ʔ����𒴂�����J�������W���X�V
	//	float playerScreenPosX = m_player->GetPos().x - m_pos.x + DXE_WINDOW_WIDTH / 2.0f;

	//	if (playerScreenPosX > DXE_WINDOW_WIDTH / 2.0f) {
	//		//�v���C���[�̍��W����ʔ����𒴂�����J�������W���X�V
	//		m_pos.x = playerScreenPosX;
	//		DrawCircle(m_pos.x, m_pos.y, 10.0f, -1);
	//	}		
	//	else {
	//		//�v���C���[����ʔ����ֈړ�����܂ł̓J�������W���X�V���Ȃ�
	//		m_pos.x = 0;
	//		DrawCircle(m_pos.x,m_pos.y,10.0f,-1);
	//	}
	//}
	//std::vector<Object*> objects;

	//// �J�������W�̐���
	//if (m_pos.x < 0) {
	//	m_pos.x = 0;
	//}
	//else if (m_pos.x > 500) {
	//	m_pos.x = 500;
	//}

	//// �\�������I�u�W�F�N�g�̍��W����
	//for (Object* obj : objects) {
	//	obj->AdjustPosition(-m_move); // �J�����̈ړ��ʂƋt�����ɒ���
	//}
	//Draw(m_objects);
}

//�X�N���[����ʊO�`��
void PlayCamera::Draw() {
	//for (Object* obj : objects) {
	//	// �I�u�W�F�N�g�̃X�N���[�����W���v�Z
	//	float objScreenPosX = m_pos.x + DXE_WINDOW_WIDTH / 2.0f;
	//	//�J�������W����X�N���[����ʊO�̃I�u�W�F�N�g��`��
	//	if (objScreenPosX >= 0 && objScreenPosX <= DXE_WINDOW_WIDTH) {
	//		obj->Draw();
	//	}
	//}
	// PlayCamera::Draw ���Ƀf�o�b�O�`���ǉ�
	DrawFormatString(10, 10, 1, "Camera X: %.2f", m_pos.x);
	//�J�������W��`��
	//DrawCircle(m_pos.x, m_pos.y, 10.0f, -1);
}