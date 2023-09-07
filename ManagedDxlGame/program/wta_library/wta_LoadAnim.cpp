#include <fstream>
#include "wta_LoadAnim.h"


namespace wta
{
    //�摜�t�@�C�������[�h����
    void CsvAnimData::LoadImages(const std::string& basePath)
    {
        //���[�h�̓x�Ƀ��Z�b�g
        s_animImage.clear();
        std::string folderPath = basePath + "/" + s_fileName;
        //WIN32_FIND_DATA�\���́FWindows�Ńt�@�C���������s���ۂɎg�p�����f�[�^�\����
        //Windows API�̃t�@�C�������֐��ł���FindFirstFile��FindNextFile���g�p�����
         //�������ʂ̃t�@�C�������i�[���邽�߂Ɏg����
        WIN32_FIND_DATA findData;
        //�t�@�C���������J�n����
        HANDLE hFind = FindFirstFile((folderPath + "/*").c_str(), &findData);
        //�t�@�C����������Ȃ������ꍇ�͏I������
        if (hFind == INVALID_HANDLE_VALUE) return;
        do {
            //�t�@�C���݂̂��擾(���C�u�����łȂ����)
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                //�t�@�C���̃t���p�X���擾
                std::string fullPath = folderPath + "/" + findData.cFileName;
                //�摜�����[�h���Ĕz��ɒǉ�
                s_animImage.emplace_back(LoadGraph(fullPath.c_str()));
            }
        } while (FindNextFile(hFind, &findData) != 0);
        //�t�@�C���������I������
        FindClose(hFind);
    }

    std::vector<CsvAnimData> LoadAnimationData(const std::string& csvPath, const std::string& basePath)
    {
        std::vector<CsvAnimData> anims;
        auto csvData = tnl::LoadCsv(csvPath);
        // �ŏ���0�s�ڂ͓ǂݎ��s�v�̂��ߍ폜
        if (!csvData.empty())
        { 
            csvData.erase(csvData.begin());
        }
        //�e�s���Ƃɏ���
        for (const auto& row : csvData)
        {
            //csv�t�@�C���̏����\���̂Ɋi�[
            CsvAnimData anim;
            anim.s_id = row[0].getInt();
            anim.s_characterName = row[1].getString();
            anim.s_action = row[2].getString();
            anim.s_direction = row[3].getInt();
            anim.s_fileName = row[4].getString();
            anim.s_loop = row[5].getBool();
            anim.LoadImages(basePath);
            anims.emplace_back(anim);
        }
        return anims;
    }

    int CsvAnimData::GetAnimID(std::string action, int direction)
    {
        if (s_characterName == "player")
        {
            if (action == "idle")
            {
                return s_direction ? 0 : 1;
            }
            else if (action == "move")
            {
                return s_direction ? 2 : 3;
            }
            else if (action == "run")
            {
				return s_direction ? 4 : 5;
			}
            else if (action == "jump")
            {
				return s_direction ? 6 : 7;
			}
            else if (action == "roll")
            {
				return s_direction ? 8 : 9;
			}
            else if (action == "stamp")
            {
				return s_direction ? 10 : 11;
			}
            else if (action == "fire")
			{
            	return s_direction ? 12 : 13;
            }
            else if (action == "beam")
            {
            	return s_direction ? 14 : 15;
            }
        }
	
		return -1;
	}
}