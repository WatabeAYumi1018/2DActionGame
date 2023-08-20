#include "AnimLoad.h"
#include <fstream>

AnimLoad::AnimLoad(const std::string pathName,bool isLoop) :
    numImgs(0),loopFlag(isLoop), currentFrame(0), elapsedTime(0.0f), frameDuration(0.2f)
{
    loadAnimFile(pathName);
}

AnimLoad::~AnimLoad() {
    for (int img : Imgs) {DeleteGraph(img);}
}

//�摜�t�@�C�������[�h����
void AnimLoad::loadAnimFile(const std::string folderPath) {
    //WIN32_FIND_DATA�\���́FWindows�Ńt�@�C���������s���ۂɎg�p�����f�[�^�\����
    //Windows API�̃t�@�C�������֐��ł���FindFirstFile��FindNextFile���g�p�����
    //�������ʂ̃t�@�C�������i�[���邽�߂Ɏg����
    WIN32_FIND_DATA findData;
    //�t�@�C���������J�n����
    HANDLE hFind = FindFirstFile((folderPath + "/*").c_str(), &findData);
    //�t�@�C����������Ȃ������ꍇ�͏I������
    if (hFind == INVALID_HANDLE_VALUE) {return;}
    do {
        //�t�@�C���݂̂��擾(���C�u�����łȂ����)
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            //�t�@�C�������擾
            std::string fileName = findData.cFileName;
            //�t�@�C���̃t���p�X���擾
            std::string fullPath = folderPath + "/" + fileName;
            //�摜�����[�h
            Imgs.emplace_back(LoadGraph(fullPath.c_str()));
        }
    } while (FindNextFile(hFind, &findData) != 0);
    //�t�@�C���������I������
    FindClose(hFind);
    //�摜�̖������擾
    numImgs = static_cast<int>(Imgs.size());
}

//�摜��`�悷��
void AnimLoad::drawAnimFile(float delta_time,tnl::Vector3 pos,float angle, float scale) {
    elapsedTime += delta_time;
    //�o�ߎ��Ԃ��t���[�����Ԃ𒴂����ꍇ
    if (elapsedTime >= frameDuration) {
        elapsedTime -= frameDuration;
        ++currentFrame;
        //���[�v����(�]��̐��Ń��[�v)
        if (loopFlag) {currentFrame %= numImgs;}
        //���[�v���Ȃ�
        else if (!loopFlag && currentFrame >= numImgs) {
            currentFrame = numImgs - 1;
        	//�Ō�̃t���[���ɒB������A�j���[�V�����I��
			animFinished = true;
        }
    }
    DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, tnl::ToRadian(0), Imgs[currentFrame], TRUE);
}

void AnimLoad::resetAnim(){
    currentFrame = 0; 
    elapsedTime = 0.0f; 
    animFinished = false; 
}


//�������������̂��ߕێ�
//AnimLoadLoop::AnimLoadLoop(const char* pathName) :
//    NumImgs(0), LoopFlag(true), currentFrame(0), elapsedTime(0.0f), frameDuration(0.2f)
//{
//    loadAnimLoopFile(pathName);
//}
//
//void AnimLoadLoop::loadAnimLoopFile(const char* path) {
//    std::string folderPath = path;
//    //WIN32_FIND_DATA�\���́FWindows�Ńt�@�C���������s���ۂɎg�p�����f�[�^�\����
//    //Windows API�̃t�@�C�������֐��ł���FindFirstFile��FindNextFile���g�p�����
//    //�������ʂ̃t�@�C�������i�[���邽�߂Ɏg����
//    WIN32_FIND_DATA findData;
//    //�t�@�C���������J�n����
//    HANDLE hFind = FindFirstFile((folderPath + "/*").c_str(), &findData);
//    //�t�@�C����������Ȃ������ꍇ�͏I������
//    if (hFind == INVALID_HANDLE_VALUE) { return; }
//    do {
//        //�t�@�C���݂̂��擾(���C�u�����łȂ����)
//        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
//            //�t�@�C�������擾
//            std::string fileName = findData.cFileName;
//            //�t�@�C���̃t���p�X���擾
//            std::string fullPath = folderPath + "/" + fileName;
//            //�摜�����[�h
//            Imgs.emplace_back(LoadGraph(fullPath.c_str()));
//        }
//    } while (FindNextFile(hFind, &findData) != 0);
//    //�t�@�C���������I������
//    FindClose(hFind);
//    //�摜�̖������擾
//    NumImgs = static_cast<int>(Imgs.size());
//}
