#pragma once
#include "../../engine/GameEngine.h"
#include "Object.h"
#include "PlayCamera.h"
#include "Character.h"
#include "MapChip.h"


//�v���C���[�Ǐ]�J����
//�R���X�g���N�^�iObject�̃R���X�g���N�^�ŏ������q�j
PlayCamera::PlayCamera(tnl::Vector3 pos,Character *player) : Object(pos) {}
//�f�X�g���N�^
PlayCamera::~PlayCamera(){ delete m_map_chip; }

//���t���[���X�V
void PlayCamera::Update(float delta_time) {
	Scroll();
	m_player->Update(delta_time);
}

void PlayCamera::Scroll() {
	// ��ʒ����̍��W���v�Z
	float centerX = m_player->GetPos().x;
	// �v���C���[����ʂ̒����ɓ��B������
	if (centerX >= DXE_WINDOW_WIDTH / 2) {
		m_scroll_x = centerX - DXE_WINDOW_WIDTH / 2;
	}
}
	//�}�b�v�l�ǂݎ��T�C�Y�i��ʒ[�j�փJ�������X�N���[��������A�ĂуJ�����Œ�
	//if (m_scroll_x >= 0) {m_scroll_x = 0;}

		//�X�N���[���X�s�[�h��ݒ�(�w�i�ƃ`�b�v�ł̃X�N���[���X�s�[�h�����̂��߂Ɏg������)	
		//m_scroll_x == m_player->GetVelocity().x;

//PlayCamera����MapChip�𐶐�����ƃG���[�Ȃ����̂́AMapChip���ł�PlayCamera�̃R���X�g���N�^���Ăяo���Ă��邽��
//�������������ƒ�߂邱��