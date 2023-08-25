#pragma once
#include <string>
#include "../dxlib_ext/dxlib_ext.h"

//csv�t�@�C������A�j���[�V�����f�[�^��ǂݍ��݁A�t�@�C������ɂĉ摜���[�h���s��

namespace wta {
    //csv�L���̃f�[�^���i�[����\����
    struct CsvAnimData {

        //-----�ϐ�-----//
        int id;
        std::string characterName;
        std::string action;
        int direction;
        std::string fileName;
        bool loop;
        std::vector<int> animImage;	//�摜�n���h��ID���i�[����
        
        //-----�֐�-----//
        //�摜�����[�h����
        void LoadImages(const std::string& basePath);
    };
    //csv����A�j���[�V�����f�[�^��ǂݍ���
    std::vector<CsvAnimData> LoadAnimationData(const std::string& csvPath, const std::string& basePath);
}