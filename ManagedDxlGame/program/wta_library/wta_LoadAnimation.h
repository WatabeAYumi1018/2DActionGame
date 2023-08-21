#pragma once
#include <string>
#include "../dxlib_ext/dxlib_ext.h"


namespace wta {
    //csv�L���̃f�[�^���i�[����\����
    struct CsvAnimData {
        int id;
        std::string characterName;
        std::string action;
        int direction;
        std::string fileName;
        bool loop;
        std::vector<int> animImage;	//�摜�n���h��ID���i�[����

        void LoadImages(const std::string& basePath);
    };

    std::vector<CsvAnimData> LoadAnimationData(const std::string& csvPath, const std::string& basePath);
}