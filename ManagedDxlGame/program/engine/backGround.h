#pragma once
#include "GameEngine.h"

class backGround 
	//:gameManager
{
public:
	backGround();
	~backGround();
	
private:
	//-----�����o�ϐ�-----//
	int back_hdl=0;				//�w�i�摜�n���h��
	Vector3 m_pos = {0,0,500};	//���W�i��X���Ԑ��ō폜�B�Ƃ肠�����j
	Mesh* m_mesh = nullptr;		//���b�V��
	Camera* m_camera = nullptr;


public:
	//-----�����o�֐�-----//
	void Initialize();
	void Update(float delta_time);
	//void Draw();
	void Finalize();
};
