#pragma once
#include "../engine/GameEngine.h"
#include "../game/SceneAll/GameObject.h"

class Camera;


//UI�̏����ꊇ���s���N���X
class UI : public GameObject
{
public:
	UI();
	virtual ~UI() {}
	
private:
	//-----�����o�ϐ�-----//
	int m_ui_hdl = 0;
	int m_extend_x;
	int m_extend_y;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Draw(float delta_time, const Camera* camera) override;
};
