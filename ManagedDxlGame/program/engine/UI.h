#pragma once
#include "GameEngine.h"
#include "GameObject.h"


class UI{

public:
	UI() { Initialize(); }
	virtual ~UI() {}
	
private:
	tnl::Vector3 m_pos = { 10,500,0 };
	int m_ui_hdl = 0;

public:
	//-----�����o�֐�-----//
	void Initialize();
	void Draw(float delta_time) ;
};

//UI�̏����ꊇ���s���N���X