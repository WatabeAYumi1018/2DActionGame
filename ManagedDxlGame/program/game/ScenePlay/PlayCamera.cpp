#pragma once
#include "../../engine/GameEngine.h"
#include "Object.h"
#include "PlayCamera.h"
#include "Character.h"
#include "MapChip.h"


//�v���C���[�Ǐ]�J����
//�R���X�g���N�^�iObject�̃R���X�g���N�^�ŏ������q�j
PlayCamera::PlayCamera(Character *player) :m_player(player) , m_scroll_x(0){}
//�f�X�g���N�^
PlayCamera::~PlayCamera(){ }

//���t���[���X�V
void PlayCamera::Update(float delta_time) {
	Scroll();
}

void PlayCamera::Scroll() {
	// ��ʒ����̍��W���v�Z
	float center_x = m_player->GetPos().x;
	// �v���C���[����ʂ̒����ɓ��B������
	if (center_x >= DXE_WINDOW_WIDTH / 2) {
		m_scroll_x = center_x - DXE_WINDOW_WIDTH / 2;
		DrawFormatString(290, 30, 1, "true");

	}
	else {
		m_scroll_x = 0;
		DrawFormatString(290, 30, 1, "false");

	}
	DrawFormatString(190, 30, 1, "centerX:%f", center_x);
	DrawFormatString(190,50,1,"m_scroll_x:%f", m_scroll_x);
}
	//�}�b�v�l�ǂݎ��T�C�Y�i��ʒ[�j�փJ�������X�N���[��������A�ĂуJ�����Œ�
	//if (m_scroll_x >= 0) {m_scroll_x = 0;}

		//�X�N���[���X�s�[�h��ݒ�(�w�i�ƃ`�b�v�ł̃X�N���[���X�s�[�h�����̂��߂Ɏg������)	
		//m_scroll_x == m_player->GetVelocity().x;

//PlayCamera����MapChip�𐶐�����ƃG���[�Ȃ����̂́AMapChip���ł�PlayCamera�̃R���X�g���N�^���Ăяo���Ă��邽��
//�������������ƒ�߂邱��