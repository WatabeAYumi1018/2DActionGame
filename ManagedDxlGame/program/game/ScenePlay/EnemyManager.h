#pragma once
#include "../SceneAll/GameObjectManager.h"

class Camera;

//�G�̓ǂݎ����Ǘ�����N���X
class EnemyManager : public GameObjectManager
{

public:
	
	//-----�����o�֐�-----//
	virtual void Update(float delta_time) override;
	virtual void Draw(float delta_time, const Camera* camera) override;
};