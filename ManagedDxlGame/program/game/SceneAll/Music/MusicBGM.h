#pragma once
#include "../engine/GameEngine.h"

class MusicBGM
{
public:

	MusicBGM(const std::string& path);
	~MusicBGM();

private:

	//-----�����o�ϐ�-----//
	int m_hdl = 0;

public:

	//-----�����o�֐�-----//
	void Play();
	void Stop();
};
