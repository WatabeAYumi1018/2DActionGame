#pragma once
#include "../engine/GameEngine.h"

class MusicSE
{
public:

	MusicSE(const std::string& path);
	~MusicSE();

private:

	//-----�����o�ϐ�-----//
	int m_hdl = 0;

public:

	//-----�����o�֐�-----//
	void Play();
	void Stop();


};
