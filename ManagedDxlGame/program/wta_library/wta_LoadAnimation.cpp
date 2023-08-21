#include <fstream>
#include "wta_LoadAnimation.h"


namespace wta {

    void CsvAnimData::LoadImages(const std::string& basePath) {
        animImage.clear();
        std::string folderPath = basePath + "/" + fileName;
        WIN32_FIND_DATA findData;
        HANDLE hFind = FindFirstFile((folderPath + "/*").c_str(), &findData);
        if (hFind == INVALID_HANDLE_VALUE) return;
        do {
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                std::string fullPath = folderPath + "/" + findData.cFileName;
                animImage.emplace_back(LoadGraph(fullPath.c_str()));
            }
        } while (FindNextFile(hFind, &findData) != 0);
        FindClose(hFind);
    }

    std::vector<CsvAnimData> LoadAnimationData(const std::string& csvPath, const std::string& basePath) {
        std::vector<CsvAnimData> anims;
        auto csvData = tnl::LoadCsv(csvPath);
        // �ŏ���0�s�ڂ͓ǂݎ��s�v�̂��ߍ폜
        if (!csvData.empty()) { csvData.erase(csvData.begin()); }
        //�e�s���Ƃɏ���
        for (const auto& row : csvData) {
            //csv�t�@�C���̏����\���̂Ɋi�[
            CsvAnimData anim;
            anim.id = row[0].getInt();
            anim.characterName = row[1].getString();
            anim.action = row[2].getString();
            anim.direction = row[3].getInt();
            anim.fileName = row[4].getString();
            anim.loop = row[5].getBool();
            anim.LoadImages(basePath);
            anims.emplace_back(anim);
        }
        return anims;
    }

}