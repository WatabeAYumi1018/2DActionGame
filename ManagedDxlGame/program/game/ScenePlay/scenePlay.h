#pragma once
#include "../../engine/sceneBase.h"

class ScenePlay : public SceneBase {

public:
	ScenePlay();
	virtual ~ScenePlay();
	//-----�����o�֐�-----//
	void Update(float delta_time) override;
	void Draw() override;

private:
	std::vector<GameObject*> gameObjects;
	tnl::Sequence<ScenePlay> sequence_ = tnl::Sequence<ScenePlay>(this, &ScenePlay::SeqIdle);
	bool SeqIdle(float delta_time);

	//�J�ڌ�Aback,Map,UI,Player,Enemy�Ȃǂ�`�悷��
	//���݂̃V�[���ŕ`�悷��O���t�B�b�N��ς���
	int test_back_ground_gfx_ = 0;

};