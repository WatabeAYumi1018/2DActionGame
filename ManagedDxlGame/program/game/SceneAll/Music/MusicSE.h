#pragma once
#include "../engine/GameEngine.h"

class MusicSE
{
public:

	MusicSE(const std::string& path);
	~MusicSE();

private:

	//-----メンバ変数-----//
	int m_hdl = 0;

public:

	//-----メンバ関数-----//
	void Play();
	void Stop();


};
