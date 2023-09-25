#pragma once
#include "../engine/GameEngine.h"
#include "MusicBGM.h"
#include "MusicSE.h"

class MusicManager 
{
private:

    MusicManager() {}

    //-----�����o�ϐ�-----//
    std::unique_ptr<MusicBGM> m_bgm;
    std::map<std::string, std::unique_ptr<MusicSE>> m_se;

public:
    // �V���O���g���C���X�^���X���擾���邽�߂̊֐�
    static MusicManager& GetInstance()
    {
        static MusicManager instance;  // �ÓI�ϐ��Ƃ��ăV���O���g���C���X�^���X���쐬
        return instance;
    }

    //-----�����o�֐�-----//
    void LoadBGM(const std::string& path);                          /*BGM�̓ǂݍ���*/
    void LoadSE(const std::string& key, const std::string& path);  /*���ʉ��̓ǂݍ���*/

    void PlayBGM();
    void StopBGM(); 

    void PlaySE(const std::string& key);
    void StopSE(const std::string& key); 
};
