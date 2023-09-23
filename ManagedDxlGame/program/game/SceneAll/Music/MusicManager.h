#pragma once
#include "../engine/GameEngine.h"
#include "MusicBGM.h"
#include "MusicSE.h"

class MusicManager 
{
public:

    MusicManager() {}

private:

    //-----�����o�ϐ�-----//
    std::unique_ptr<MusicBGM> m_bgm;
    std::map<std::string, std::unique_ptr<MusicSE>> m_se;

public:

    //-----�����o�֐�-----//
    void LoadBGM(const std::string& path);                          /*BGM�̓ǂݍ���*/
    void LoadSE(const std::string& key, const std::string& path);  /*���ʉ��̓ǂݍ���*/

    void PlayBGM();
    void StopBGM(); 

    void PlaySE(const std::string& key);
    void StopSE(const std::string& key); 
};
