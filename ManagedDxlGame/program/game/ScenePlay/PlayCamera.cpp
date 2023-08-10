#pragma once
#include "../../engine/GameEngine.h"
#include "PlayCamera.h"
#include "Player.h"
#include "MapChip.h"

//�v���C���[�Ǐ]�J����
//�R���X�g���N�^�iObject�̃R���X�g���N�^�ŏ������q�j
PlayCamera::PlayCamera(tnl::Vector3 pos,Player* player) :
	Object(pos) ,m_player(player),m_scroll_x(0.0f){
	m_map_chip = new MapChip();
}

//�f�X�g���N�^
PlayCamera::~PlayCamera(){ delete m_map_chip; }

//���t���[���X�V
void PlayCamera::Update(float delta_time) {
	// ��ʒ����̍��W���v�Z
	float centerX = m_player->GetPos().x;
	float centerY = m_player->GetPos().y;
	// �v���C���[����ʂ̒����ɓ��B������
	if (centerX >= DXE_WINDOW_WIDTH / 2) {
		m_scroll_x = centerX - DXE_WINDOW_WIDTH / 2;}

	Draw();
	// �}�b�v�`�b�v�̍X�V�ƕ`��
	m_map_chip->Update(delta_time,m_scroll_x);
}

//PlayCamera����MapChip�𐶐�����ƃG���[�Ȃ�̂́AMapChip���ł�PlayCamera�̃R���X�g���N�^���Ăяo���Ă��邽��
//�������������ƒ�߂邱��