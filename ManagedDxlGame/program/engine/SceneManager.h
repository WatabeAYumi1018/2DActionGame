#pragma once

class SceneBase;

//�Q�[���S�̂��Ǘ�����N���X�i�V���O���g���j

class SceneManager
{
private:
	//-----�V���O���g��-----//
	SceneManager(SceneBase* start_scene);

	//-----�V�[�P���X-----//
	tnl::Sequence<SceneManager> sequence_ = tnl::Sequence<SceneManager>(this, &SceneManager::SeqTransIn);

	//-----�����o�ϐ�-----//
	float trans_time_ = 0.5f;
	int tansition_graph_hdl_ = 0;

	SceneBase* now_scene_ = nullptr;
	SceneBase* next_scene_ = nullptr;

public:

	//-----�����o�֐�-----//
	void ChangeScene(SceneBase* next_scene, float trans_time = 0.5f);
	void Update(float delta_time);

	//-----static�֐�-----//
	static SceneManager* GetInstance(SceneBase* start_scene = nullptr);
	static void Finalize();

private:
		
	//-----�V�[�P���X�֐�-----//
	bool SeqTransIn(const float delta_time);
	bool SeqTransOut(const float delta_time);
	bool SeqRunScene(const float delta_time);
};