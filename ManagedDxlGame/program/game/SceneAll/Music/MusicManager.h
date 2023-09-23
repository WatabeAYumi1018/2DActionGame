#pragma once
#include "../engine/GameEngine.h"
#include "MusicBGM.h"
#include "MusicSE.h"

class MusicManager 
{
public:

    MusicManager() {}

private:

    //-----メンバ変数-----//
    std::unique_ptr<MusicBGM> m_bgm;
    std::map<std::string, std::unique_ptr<MusicSE>> m_se;

public:

    //-----メンバ関数-----//
    void LoadBGM(const std::string& path);                          /*BGMの読み込み*/
    void LoadSE(const std::string& key, const std::string& path);  /*効果音の読み込み*/

    void PlayBGM();
    void StopBGM(); 

    void PlaySE(const std::string& key);
    void StopSE(const std::string& key); 
};
