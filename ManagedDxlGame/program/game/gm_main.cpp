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
//�B�J�����ړ��̎����@�ЂƂ܂��u���Ƃ�
//�C�U���̓����蔻��
//�D�G�L������AI
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

//MapManager* mapChip = nullptr;
//UI* ui=nullptr;
//Character *player=nullptr;
//const PlayCamera& camera;
//CollisionCalc* m_collision = nullptr;	//�����蔻��
//

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));
	SetWindowText("Title");
	//�R���X�g���N�^�쐬(��ɑ��Ԑ��ł܂Ƃ߂ĊǗ�)
	//ui = new UI({10,0,50});
	//player = new Player();
	//const PlayCamera& camera=PlayCamera();
	//m_collision = new CollisionCalc();
	//mapChip = new MapManager();
	
	SceneManager::GetInstance(new ScenePlay());
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {

	////���������R���X�g���N�^��Update��
	//back->Update(delta_time);
	//ui->Update(delta_time);
	//camera->Update(delta_time);
	//player->Update(delta_time);
	//mapChip->Update(delta_time);//, camera);
	//m_collision->CollisionCalculate(player, mapChip, 2);
	//m_collision->CheckBoxCollision(player, mapChip, mapChip->GetCollisionInfo());

	//�g�p���@
	
	SceneManager::GetInstance()->Update(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {
	//delete camera;
	//camera = nullptr;
	//delete m_collision;
	//m_collision = nullptr;
}
