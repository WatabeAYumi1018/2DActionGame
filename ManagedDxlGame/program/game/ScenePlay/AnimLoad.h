#pragma once
#include "../../engine/GameEngine.h"

//�ʁX��png�t�@�C����ǂݍ���ŁA���ꂼ��̉摜�����[�v�\�����ăA�j���[�V�������Đ�����N���X
class AnimLoad {

public:
    AnimLoad(const std::string pathName,bool isLoop);
    ~AnimLoad();

private:
    //-----�����o�ϐ�-----//
    std::vector<int> Imgs;      //�ǂݍ���png�摜�̃n���h�����i�[����z��
    int numImgs;				//�ǂݍ���png�摜�̐�  
    bool loopFlag; 			    //���[�v���邩�ǂ���
    bool animFinished;			//�A�j���[�V�������I���������ǂ���
    int currentFrame;			//���݂̃t���[��
    float elapsedTime;			//�o�ߎ���
    float frameDuration;		//1�t���[���̎��ԁi�A�j���[�V�����`��̃X�s�[�h�����j

public:
    //-----�����o�֐�-----//
    //�t�@�C����ǂݍ��ފ֐�
    void loadAnimFile(const std::string folderPath);
    //�A�j���[�V������`�悷��֐�
    void drawAnimFile(float delta_time, tnl::Vector3 pos, float angle=0, float scale=1.0f);
    //�A�j���[�V�������I���������ǂ�����Ԃ��֐�
    bool isAnimFinished() const { return animFinished; }
    //�A�j���[�V���������Z�b�g����֐�
    void resetAnim();
};

//�A�j���[�V�������[�v�摜�̓ǂݎ����s���N���X

//char*����std::string�ւ̕ϊ�(�������������̂��ߕێ�)
//AnimLoadLoop(const char* pathName);
//~AnimLoadLoop();
//
////�t�@�C����ǂݍ��ފ֐�
//void loadAnimLoopFile(const char* path);