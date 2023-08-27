#pragma once
#include "../../engine/GameEngine.h"
#include "PlayCamera.h"
#include "Character.h"
#include "MapManager.h"


//�v���C���[�Ǐ]�J����
PlayCamera::PlayCamera(Character *player) :m_player(player) , m_scroll_x(0){}
PlayCamera::~PlayCamera(){ }

//���t���[���X�V
void PlayCamera::Update(float delta_time) {
	Scroll();
	//PosRevise();
}

//�J�����̃X�N���[��
void PlayCamera::Scroll() {
	// ��ʒ����̍��W���v�Z
	float center_x = m_player->GetPos().x;
	// �v���C���[����ʂ̒����ɓ��B������
	if (center_x >= DXE_WINDOW_WIDTH / 2) {
		m_scroll_x = center_x - DXE_WINDOW_WIDTH / 2;
		DrawFormatString(300, 30, 1, " move:true");
	}
	else {
		m_scroll_x = 0;
		DrawFormatString(300, 30, 1, " move:false");
	}
	DrawFormatString(150, 30, 1, " =centerX:%.2f", center_x);
	DrawFormatString(150,50,1,"  scroll_x:%.2f", m_scroll_x);
}

//���v���C���[�̕\���ʒu�𒲐��H
void PlayCamera::PosRevise() {
	tnl::Vector3 pos = m_player->GetPos();
	tnl::Vector3 screenPos;
	screenPos.x = pos.x - m_scroll_x;
	screenPos.y = pos.y;
	screenPos.z = pos.z;
	if (pos.x >= DXE_WINDOW_WIDTH / 2) {
		// �J�����̒��S�Ƀv���C���[��z�u����
		m_player->SetPos(screenPos);
	}
}

	//�}�b�v�l�ǂݎ��T�C�Y�i��ʒ[�j�փJ�������X�N���[��������A�ĂуJ�����Œ�
	//if (m_scroll_x >= 0) {m_scroll_x = 0;}

	//�X�N���[���X�s�[�h��ݒ�(�w�i�ƃ`�b�v�ł̃X�N���[���X�s�[�h�����̂��߂Ɏg������)	
	//m_scroll_x == m_player->GetVelocity().x;

//PlayCamera����MapChip�𐶐�����ƃG���[�Ȃ����̂́AMapChip���ł�PlayCamera�̃R���X�g���N�^���Ăяo���Ă��邽��
//�������������ƒ�߂邱��