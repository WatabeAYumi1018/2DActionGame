#include "ani��Loop.h"
#include <fstream>


AnimLoop::AnimLoop() :NumImgs(0), LoopFlag(true), currentFrame(0), elapsedTime(0.0f), frameDuration(0.1f) {}

AnimLoop::AnimLoop(const char* pathName) :
    NumImgs(0), LoopFlag(true), currentFrame(0), elapsedTime(0.0f), frameDuration(0.1f)
{
    loadAnimLoopFile(pathName);
}

AnimLoop::~AnimLoop() {
    for (int img : Imgs) {DeleteGraph(img);}
}

//�摜�t�@�C�������[�h����
void AnimLoop::loadAnimLoopFile(const char* path) {
    std::string folderPath = path;
    //Windows�v���b�g�t�H�[�������̃t�@�C���V�X�e������Ɏg�p�����\����
    //�t�@�C����f�B���N�g���Ɋւ���������W
    WIN32_FIND_DATA findData;
    //�t�@�C����f�B���N�g���̌����Ɏg�p
    HANDLE hFind = FindFirstFile((folderPath + "/*").c_str(), &findData);
    //�t�@�C����������Ȃ������ꍇ
    if (hFind == INVALID_HANDLE_VALUE) {return;}
    do {
        //�t�@�C���̑������f�B���N�g���łȂ��ꍇ
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::string fileName = findData.cFileName;
            std::string fullPath = folderPath + "/" + fileName;
            Imgs.push_back(LoadGraph(fullPath.c_str()));
        }
       //���̃t�@�C��������
    } while (FindNextFile(hFind, &findData) != 0);

    FindClose(hFind);

    NumImgs = static_cast<int>(Imgs.size());
}

//�摜�����[�v�`�悷��
void AnimLoop::drawAnimLoopFile(float delta_time, tnl::Vector3 pos, float angle, float scale) {
    elapsedTime += delta_time;
    if (elapsedTime >= frameDuration) {
        elapsedTime -= frameDuration;
        ++currentFrame;
        if (LoopFlag) {
            currentFrame %= NumImgs;
        }
        else if (currentFrame >= NumImgs) {
            currentFrame = NumImgs - 1;
        }
    }
    DrawGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), Imgs[currentFrame], TRUE);
}
