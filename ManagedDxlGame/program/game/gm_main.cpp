#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "../game/ScenePlay/Character.h"
#include "../game/ScenePlay/Player.h"
#include "../game/ScenePlay/MapChip.h"
#include "../engine/backGround.h"

//�`8�����{�܂Ł`
//�@�}�b�v�`�� OK
//�A�L�����N�^�[�̓����Ɠ����蔻��̎���
//�B�J�����ړ��̎���
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


Player* player;
MapChip* mapChip;

backGround* back;

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));

	//�w�i�̃R���X�g���N�^�쐬
	back = new backGround();

	//�v���C���[�̃R���X�g���N�^����
	player = new Player({ 100,100,0 });

	//�}�b�v�`�b�v��CSV�t�@�C��
	string csv_map_tile_data = "csv/TileStage_1-1.csv";	

	//�}�b�v�`�b�v�̃R���X�g���N�^����
	mapChip = new MapChip(csv_map_tile_data);
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {

	//���������R���X�g���N�^��Update��
	back->Update(delta_time);
	player->Update(delta_time);
	mapChip->Update(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {

}
