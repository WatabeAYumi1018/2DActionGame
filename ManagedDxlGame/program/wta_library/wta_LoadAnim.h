#pragma once
#include <string>
#include "../engine/GameEngine.h"

//csv�t�@�C������A�j���[�V�����f�[�^��ǂݍ��݁A�t�@�C������ɂĉ摜���[�h���s��

namespace wta 
{
    //csv�L���̃f�[�^���i�[����\����
    struct CsvAnimData 
    {
        //-----�����o�ϐ�-----//
        int s_id;
        std::string s_characterName;
        std::string s_action;
        int s_direction;
        std::string s_fileName;
        bool s_loop;
        std::vector<int> s_animImage;	//�摜�n���h��ID���i�[����
        
        //-----�����o�֐�-----//
        //�摜�����[�h����
        void LoadImages(const std::string& basePath);
        
        int GetAnimID(std::string action, int direction);
    };
    //csv����A�j���[�V�����f�[�^��ǂݍ���
    std::vector<CsvAnimData> LoadAnimationData(const std::string& csvPath, const std::string& basePath);

}