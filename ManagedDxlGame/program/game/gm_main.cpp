#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"


using namespace std;
using namespace tnl;

//�`8�����{�܂Ł`
//�@�}�b�v�`��
//�A�L�����N�^�[�̓����Ɠ����蔻��̎���
//�B�U���̓����蔻��
//�C�G�L������AI
//�DUI��p�����[�^�ȂǂƂ̕R�Â�
//�E�A�N�V�����̓����ƃA�j���[�V�����Ȃǂ̊m�F�ƂЂƒʂ�̃v���C����

//�`�W�����܂Ł`
//�F�X�e�[�W�Z���N�g��ʍ쐬
//�G�Ђƒʂ�Q�[���Ƃ��Ċ���
//�H�{�X��
//�I�A�C�e������

//�`9�����{�܂Ł`
//�J�f�o�b�N
//�K��ʃZ���N�g�쐬
//�L�^�C�g���쐬
//�M�G���f�B���O�쐬

// �`�����܂Ł`
//�N�ŏI�m�F

class SceneBase {};

//�v���C���[�A�G�A�J�����A�A�C�e���A�U��etc
class ScenePlay
	//:public SceneBase
{};

class Camera {};

class Effect {};

class UI {};

class Collision {};

class Character {

	Character(Vector3 m_pos, Vector3 m_velocity);
	virtual ~Character();

protected:
	int graph_hdl;						//�摜�n���h��
	int hp;


	Vector3 m_pos;						//���W
	Vector3 m_velocity;					//���x
	Vector3 m_gravity;					//�d��

	bool is_Exit;						//���݃t���O
	bool is_Jump;						//�W�����v��
	bool is_Attack;						//�U����

	Collision* collision = nullptr;		//�����蔻��
	//Effect* effect = nullptr;
};

class Player :public Character {};

class Enemy :public Character {};

class Item :public Character {};



//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));

}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {

}
