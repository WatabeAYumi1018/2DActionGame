#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "../game/ScenePlay/ScenePlay.h"
#include "../game/SceneTitle/SceneTitle.h"
#include "../engine/SceneManager.h"


//�I�{�X��
//�K�f�o�b�N
//�N�G���f�B���O�쐬

// �`�����܂Ł`
//�O�ŏI�m�F
//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart()
{
	srand(time(0));
	SetWindowText("Palloon!");
	
	SceneManager::GetInstance(new SceneTitle());
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time)
{

	SceneManager::GetInstance()->Update(delta_time);

	//�Q�[���p�b�h�U���e�X�g
	//StartJoypadVibration(DX_INPUT_PAD1, 1000, 3000, -1);
	//StopJoypadVibration(DX_INPUT_PAD1);

	////�Q�[���X�e�B�b�N�ł̈ړ��e�X�g
	//int xInput, yInput;
	//if(GetJoypadAnalogInput(&xInput, &yInput, DX_INPUT_PAD1));
	//// ����X�s�[�h�萔�ɓ��͒l���|���ăL�����N�^�[�̈ړ��ʂ𓾂�
	//float speed = 0.05; // ���̒l�͒������K�v
	//characterPos.x += xInput * speed;
	//characterPos.y += yInput * speed;  // ����������ł���ꍇ

	//DrawCircle(characterPos.x, characterPos.y, 10, -1, true);

	//DrawGraph(1000, 50, LoadGraph("graphics/color-yellow001.PNG"), true);
	//DrawGraph(1100, 50, LoadGraph("graphics/color-yellow002.PNG"), true);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd()
{

}
