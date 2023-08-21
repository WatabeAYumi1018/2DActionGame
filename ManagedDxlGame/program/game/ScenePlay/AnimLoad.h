#pragma once
#include "../../wta_library/wta_LoadAnimation.h"

namespace wta {

    class AnimLoad {
    public:
        // �R���X�g���N�^��CSV����A�j���[�V�����f�[�^�����[�h
        AnimLoad(const std::string& csvPath, const std::string& basePath);

    private:
        std::vector<CsvAnimData> animations;    // ���ׂẴA�j���[�V�����f�[�^
        const CsvAnimData* currentAnim = nullptr;    // ���݂̃A�j���[�V����
        float elapsedTime;
        int currentFrame;
        float frameDuration;		                 //1�t���[���̎��ԁi�A�j���[�V�����`��̃X�s�[�h�����j

	public:
        // �w��ID�̃A�j���[�V�������Z�b�g
        void SetAnimation(int id);

        // �A�j���[�V������`��
        void Draw(float delta_time, tnl::Vector3 pos, float scale = 1.0f, float angle = 0.0f);
        
    };
}

//�A�j���[�V�������[�v�摜�̓ǂݎ����s���N���X
//char*����std::string�ւ̕ϊ�(�������������̂��ߕێ�)
//AnimLoadLoop(const char* pathName);
//~AnimLoadLoop();
//
////�t�@�C����ǂݍ��ފ֐�
//void loadAnimLoopFile(const char* path);