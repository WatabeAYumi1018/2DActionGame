#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "../game/ScenePlay/Character.h"
#include "../game/ScenePlay/Player.h"
#include "../game/ScenePlay/MapManager.h"
#include "../engine/backGround.h"
#include "../game/ScenePlay/CollisionCalc.h"
#include "ScenePlay/PlayCamera.h"
#include "../engine/UI.h"
#include "../game/ScenePlay/Enemy.h"
#include "../game/ScenePlay/ScenePlay.h"
#include "../game/SceneTitle/SceneTitle.h"
#include "../engine/SceneManager.h"


//�@�}�b�v�A�w�i�`�� OK
//�A�L�����N�^�[�̓����Ɠ����蔻��̎����@����OK
//�B�J�����ړ��̎����@�ЂƂ܂�OK
//�C�U���̓����蔻��
//�D�G�L������AI		�ЂƂ܂�OK
//�EUI��p�����[�^�ȂǂƂ̕R�Â�
//�F�A�N�V�����̓����ƃA�j���[�V�����Ȃǂ̊m�F�ƂЂƒʂ�̃v���C����
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


//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));
	SetWindowText("Title");
	
	SceneManager::GetInstance(new ScenePlay());
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {


	SceneManager::GetInstance()->Update(delta_time);
	//DrawGraph(1000, 50, LoadGraph("graphics/color-yellow001.PNG"), true);
	//DrawGraph(1100, 50, LoadGraph("graphics/color-yellow002.PNG"), true);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {

}
