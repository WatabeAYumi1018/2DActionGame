#pragma once
#include "../../engine/GameEngine.h"

//�ʁX��png�t�@�C����ǂݍ���ŁA���ꂼ��̉摜�����[�v�\�����ăA�j���[�V�������Đ�����N���X
class AnimLoadLoop {

public:
    AnimLoadLoop(const char* pathName);
    ~AnimLoadLoop();

    //�t�@�C����ǂݍ��ފ֐�
    void loadAnimLoopFile(const char* path);                                                    
    //�A�j���[�V������`�悷��֐�
    void drawAnimLoopFile(float delta_time, tnl::Vector3 pos, float angle=0, float scale=1.0f);

private:
    std::vector<int> Imgs;      //�ǂݍ���png�摜�̃n���h�����i�[����z��
    int NumImgs;				//�ǂݍ���png�摜�̐�  
    bool LoopFlag; 			    //���[�v���邩�ǂ���
    int currentFrame;			//���݂̃t���[��
    float elapsedTime;			//�o�ߎ���
    float frameDuration;		//1�t���[���̎��ԁi��s�Ƀ��[�V�����`��̃X�s�[�h�����j
};

//�A�j���[�V�������[�v�摜�̓ǂݎ����s���N���X