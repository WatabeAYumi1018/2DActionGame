#include "../dxlib_ext/dxlib_ext.h"
#include "SceneManager.h"
#include "../engine/sceneBase.h"

//�R���X�g���N�^�̈�����GameManager�̈����ɏ�����
SceneManager::SceneManager(SceneBase* start_scene) : now_scene_(start_scene) 
{
	//�g�����W�V�����p�̃O���t�B�b�N��ǂݍ���(���w�i)
	tansition_graph_hdl_ = LoadGraph("graphics/black.bmp");
}

SceneManager* SceneManager::GetInstance(SceneBase* start_scene)
{
	//�V���O���g��
	static SceneManager* instance = nullptr;
	
	if (!instance) 
	{
		instance = new SceneManager(start_scene);
	}
	return instance;
}

//���݂̃V�[���̍X�V�ƕ`��
void SceneManager::Update(float delta_time)
{
	if (now_scene_) 
	{
		now_scene_->Update(delta_time);
		now_scene_->Draw(delta_time);
	}
	sequence_.update(delta_time);
}

//�V�[���̐؂�ւ�
void SceneManager::ChangeScene(SceneBase* next_scene, float trans_time) 
{
	next_scene_ = next_scene;
	trans_time_ = trans_time;
	//�g�����W�V�����̊J�n
	sequence_.change(&SceneManager::SeqTransOut);
}

//�V�[���̐؂�ւ��i�t�F�[�h�C���j
bool SceneManager::SeqTransIn(const float delta_time)
{
	//�����������ɂ��Ă���
	int alpha = 255 - (sequence_.getProgressTime() / trans_time_ * 255.0f);
	if (alpha <= 0) 
	{
		sequence_.change(&SceneManager::SeqRunScene);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, tansition_graph_hdl_, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
	return true;
}

//�V�[���̐؂�ւ��i�t�F�[�h�A�E�g�j
bool SceneManager::SeqTransOut(const float delta_time)
{
	int alpha = (sequence_.getProgressTime() / trans_time_ * 255.0f);

	if (alpha >= 255)
	{
		sequence_.change(&SceneManager::SeqTransIn);
		now_scene_->Finalize();		//���݂̃V�[���̏I������
		delete now_scene_;			//���݂̃V�[���폜
		now_scene_ = nullptr;
		now_scene_ = next_scene_;	//���̃V�[�������݂̃V�[����
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, tansition_graph_hdl_, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	return true;
}

//�V�[���̎��s
bool SceneManager::SeqRunScene(const float delta_time) 
{
	return true;
}

void SceneManager::Finalize() 
{
	delete GetInstance();
}


//�g�p���@
//SceneManager::GetInstance( new SceneTitle() );�@�ŏ��̃V�[����ݒ肵��
//SceneManager::GetInstance()->Update();�@���t���[���Ăяo��