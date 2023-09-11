#pragma once
#include "../../engine/sceneBase.h"

class GameObject;

class SceneTitle : public SceneBase {

public:
	void Update(float delta_time) override;
	void Draw(float delta_time) override;

private:
	tnl::Sequence<SceneTitle> sequence_ = tnl::Sequence<SceneTitle>(this, &SceneTitle::SeqIdle);
	bool SeqIdle(float delta_time);

	//�^�C�g����ʂ̃O���t�B�b�N 
	int title_back_gif = 0;
};
