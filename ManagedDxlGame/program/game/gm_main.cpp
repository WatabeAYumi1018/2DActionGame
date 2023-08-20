#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "../game/ScenePlay/Character.h"
#include "../game/ScenePlay/Player.h"
#include "../game/ScenePlay/MapChip.h"
#include "../engine/backGround.h"
#include "../game/ScenePlay/CollisionCalc.h"
#include "ScenePlay/PlayCamera.h"
#include "../engine/UI.h"

//�`8�����{�܂Ł`
//�@�}�b�v�A�w�i�`�� OK
//�A�L�����N�^�[�̓����Ɠ����蔻��̎���
//�B�J�����ړ��̎����@�ЂƂ܂�OK
//�C�U���̓����蔻��
//�D�G�L������AI
//�EUI��p�����[�^�ȂǂƂ̕R�Â�
//�F�A�N�V�����̓����ƃA�j���[�V�����Ȃǂ̊m�F�ƂЂƒʂ�̃v���C����

//�`�W�����܂Ł`
//�G�X�e�[�W�Z���N�g��ʍ쐬
//�H�Ђƒʂ�Q�[���Ƃ��Ċ���
//�I�{�X��
//�J�A�C�e������

//�`9�����{�܂Ł`
//�K�f�o�b�N
//�L��ʃZ���N�g�쐬
//�M�^�C�g���쐬
//�N�G���f�B���O�쐬

// �`�����܂Ł`
//�O�ŏI�m�F

MapChip * mapChip = nullptr;
UI* ui=nullptr;
Player* player=nullptr;
PlayCamera* camera=nullptr;
backGround* back=nullptr;
CollisionCalc* m_collision = nullptr;	//�����蔻��


//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));

	//�R���X�g���N�^�쐬(��ɑ��Ԑ��ł܂Ƃ߂ĊǗ�)
	back = new backGround();
	ui = new UI({10,0,50});
	player = new Player();
	camera = new PlayCamera({0,0,0}, player);
	m_collision = new CollisionCalc();
	mapChip = new MapChip();
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {

	////���������R���X�g���N�^��Update��
	back->Update(delta_time);
	ui->Update(delta_time);
	player->Update(delta_time);
	camera->Update(delta_time);
	m_collision->CollisionCalculate(player, mapChip, 3);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {
	camera = nullptr;
	delete camera;
	m_collision = nullptr;
	delete m_collision;
}
