#pragma once
#include "../engine/GameEngine.h"

class MusicBGM
{
public:

	MusicBGM(const std::string& path);
	~MusicBGM();

private:

	//-----メンバ変数-----//
	int m_hdl = 0;

public:

	//-----メンバ関数-----//
	void Play();
	void Stop();
};
