#include "wta_DrawAnim.h"

namespace wta
{
    DrawAnim::DrawAnim(const std::string& csvPath, const std::string& basePath) :
        currentFrame(0), elapsedTime(0.0f), frameDuration(0.2f)
    {
        animations = LoadAnimationData(csvPath, basePath);
    }

    void DrawAnim::SetAnimation(int id) 
    {
        for (const auto& anim : animations)
        {
            if (anim.s_id == id) {
                //�A�j���[�V�����̎�ނ��ς�����ꍇ�͏�����
                if (currentAnim != &anim)
                {
                    elapsedTime = 0.0f;
                    currentFrame = 0;
                }
                currentAnim = &anim;
                return;
            }
        }
        currentAnim = nullptr;  // ������Ȃ������ꍇ��nullptr��ݒ�
    }

    // �A�j���[�V������`��
    void DrawAnim::Draw(float delta_time, tnl::Vector3 pos, float scale, float angle) 
    {
        if (!currentAnim || currentAnim->s_animImage.empty()) return; //���݂̃A�j���[�V�������Ȃ��A��̏ꍇ�������Ȃ�
       
        elapsedTime += delta_time;
        
        if (elapsedTime >= frameDuration) 
        {
            elapsedTime -= frameDuration;
            ++currentFrame;
           
            if (currentAnim->s_loop) 
            {
                currentFrame %= currentAnim->s_animImage.size();
            }
            else if (currentFrame >= currentAnim->s_animImage.size())
            {
                currentFrame = 0;  //���[�v���Ȃ��ꍇ�ŏ��̃t���[���Ƀ��Z�b�g
            }
        }
        //�����Ƃ̓����蔻�聕�␳��������angle��45�x�ɌŒ�
        DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), scale, tnl::ToRadian(angle), currentAnim->s_animImage[currentFrame], TRUE);
    }
}
