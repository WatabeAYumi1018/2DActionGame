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
	void TitlePlayMovie();


	//�^�C�g����ʂ̃O���t�B�b�N 
	int title_back_gif = 0;

	//�X�N���[��(�t�B���^�[���������摜��ۑ�����p)�n���h��
	int screen_handle = 0;

	//���邳�N���b�v�t�B���^�[�Ɏg�p����臒l
	int bright_border = 150;
};
