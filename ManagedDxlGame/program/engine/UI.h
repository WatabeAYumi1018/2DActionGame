#pragma once
#include "GameEngine.h"
#include "GameObject.h"

//���A�����ԍr��Ă܂�

class UI:public GameObject{

public:
	UI();
	virtual ~UI();
	

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const PlayCamera* camera) override;
	void Finalize() override;
};

//UI�̏����ꊇ���s���N���X