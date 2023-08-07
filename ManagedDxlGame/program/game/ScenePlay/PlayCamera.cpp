#pragma once
#include "../../engine/GameEngine.h"
#include "PlayCamera.h"
#include "Object.h"
#include "Player.h"

//�v���C���[�Ǐ]�J����
//�R���X�g���N�^�iObject�̃R���X�g���N�^�ŏ������q�j
PlayCamera::PlayCamera(tnl::Vector3 pos,Player* player) :Object(m_pos) ,m_player(player)
{}

//�f�X�g���N�^
PlayCamera::~PlayCamera(){}

//���t���[���X�V
void PlayCamera::Update(float delta_time) {
	if (m_player) {
		if (m_player->GetPos().x <DXE_WINDOW_WIDTH/2) {
			//�v���C���[����ʔ����ֈړ�����܂ł̓J�������W���X�V���Ȃ�
			m_pos.x = 0;
		}		
		else {
			//�v���C���[�̍��W����ʔ����𒴂�����J�������W���X�V
			m_pos.x = m_player->GetPos().x;
		}
	}
}
