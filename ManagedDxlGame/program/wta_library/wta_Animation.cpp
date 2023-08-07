//#include "wta_Animation.h"
//#include <fstream>
//#include <time.h>
//#include <string>
//#include "../dxlib_ext/dxlib_ext.h"
//
//namespace wta {
//
//    std::vector<int> Imgs;	    //�ǂݍ���png�摜�̃n���h�����i�[����z��  
//    int NumImgs;				//�摜�̖���
//    bool LoopFlag; 			    //���[�v���邩�ǂ���
//    int currentFrame;			//���݂̃t���[��
//    float elapsedTime;			//�o�ߎ���
//    float frameDuration;		//1�t���[���̎��ԁi��s�Ƀ��[�V�����`��̃X�s�[�h�����j
//
//    //�摜�t�@�C�������[�h����
//    int loadAnimLoopFile(const char* path) {
//        std::string folderPath = path;
//        //WIN32_FIND_DATA�\���́FWindows�Ńt�@�C���������s���ۂɎg�p�����f�[�^�\����
//        //Windows API�̃t�@�C�������֐��ł���FindFirstFile��FindNextFile���g�p�����
//        //�������ʂ̃t�@�C�������i�[���邽�߂Ɏg����
//        WIN32_FIND_DATA findData;
//        //�t�@�C���������J�n����
//        HANDLE hFind = FindFirstFile((folderPath + "/*").c_str(), &findData);
//        //�t�@�C����������Ȃ������ꍇ�͏I������
//        if (hFind == INVALID_HANDLE_VALUE) { return 1; }
//        do {
//            //�t�@�C���݂̂��擾(���C�u�����łȂ����)
//            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
//                //�t�@�C�������擾
//                std::string fileName = findData.cFileName;
//                //�t�@�C���̃t���p�X���擾
//                std::string fullPath = folderPath + "/" + fileName;
//                //�摜�����[�h
//                Imgs.emplace_back(LoadGraph(fullPath.c_str()));
//            }
//        } while (FindNextFile(hFind, &findData) != 0);
//        //�t�@�C���������I������
//        FindClose(hFind);
//        //�摜�̖������擾
//        NumImgs = static_cast<int>(Imgs.size());
//
//        return 0;
//    }
//
//    //�摜�����[�v�`�悷��
//    int drawAnimLoopFile(float delta_time, tnl::Vector3 pos, int path_hdl, float angle, float scale) {
//        elapsedTime += delta_time;
//        //�o�ߎ��Ԃ��t���[�����Ԃ𒴂����ꍇ
//        if (elapsedTime >= frameDuration) {
//            elapsedTime -= frameDuration;
//            ++currentFrame;
//            //���[�v����(�]��̐��Ń��[�v)
//            if (LoopFlag) { currentFrame %= NumImgs; }
//            //���[�v���Ȃ�
//            else if (currentFrame >= NumImgs) { currentFrame = NumImgs - 1; }
//        }
//        DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, tnl::ToRadian(-45), Imgs[currentFrame], TRUE);
//
//        return 0;
//    }
//}