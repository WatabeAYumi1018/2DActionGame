#pragma once

class SceneBase;

class SceneManager 
{
public:
	//-----static�֐�-----//
	static SceneManager* GetInstance(SceneBase* start_scene = nullptr);
	static void Finalize();

	//-----�����o�֐�-----//
	void ChangeScene(SceneBase* next_scene, float trans_time = 0.5f);
	void Update(float delta_time);

private:
	//-----singleton-----//
	SceneManager(SceneBase* start_scene);

	//-----�����o�ϐ�-----//
	float trans_time_ = 0.5f;
	int tansition_graph_hdl_ = 0;
	SceneBase* now_scene_ = nullptr;
	SceneBase* next_scene_ = nullptr;
	
	//-----�V�[�P���X-----//
	tnl::Sequence<SceneManager> sequence_ = tnl::Sequence<SceneManager>(this, &SceneManager::SeqTransIn);
	
	//-----�V�[�P���X�֐�-----//
	bool SeqTransIn(const float delta_time);
	bool SeqTransOut(const float delta_time);
	bool SeqRunScene(const float delta_time);
};