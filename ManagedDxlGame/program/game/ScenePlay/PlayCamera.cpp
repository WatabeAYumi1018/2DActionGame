#pragma once
#include "../../engine/GameEngine.h"
#include "PlayCamera.h"
#include "Player.h"
#include "MapChip.h"

//�v���C���[�Ǐ]�J����
//�R���X�g���N�^�iObject�̃R���X�g���N�^�ŏ������q�j
PlayCamera::PlayCamera(tnl::Vector3 pos,Player* player) :
	Object(pos) ,m_player(player),m_scroll_x(5.0f){
	m_map_chip = new MapChip();
}

//�f�X�g���N�^
PlayCamera::~PlayCamera(){ delete m_map_chip; }

//���t���[���X�V
void PlayCamera::Update(float delta_time) {
	Draw();
	//�v���C���[����ʒ����ɒB������A�J�����𓮂���
	if (m_player->GetPos().x >= DXE_WINDOW_WIDTH / 2) {
		m_scroll_x = m_player->GetPos().x - DXE_WINDOW_WIDTH / 2;
	}
	// �}�b�v�`�b�v�̍X�V�ƕ`��
	m_map_chip->Update(delta_time,m_scroll_x);
}

//�X�N���[����ʊO�`��
void PlayCamera::Draw() {
	//�J�������W��`��
	DrawCircle(m_pos.x, m_pos.y, 10.0f, -1);
}

//PlayCamera����MapChip�𐶐�����ƃG���[�Ȃ�̂́AMapChip���ł�PlayCamera�̃R���X�g���N�^���Ăяo���Ă��邽��
//�������������ƒ�߂邱��