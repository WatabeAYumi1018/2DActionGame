#pragma once
#include "GameEngine.h"
#include "GameObject.h"

class PlayCamera;

//�Q�[���I�u�W�F�N�g�^�ɂ���ƁA�`��ʒu������邽�߁c�B
//�N���X�^�֌W�Ȃ��A���C���[�֌W�𒲐����邱�Ƃ͂ł���̂��낤���c�B
class Balloon : public GameObject{

public:
    Balloon();
    ~Balloon() {}

private:
    tnl::Vector3 m_hover_velocity;        // �������x
    int m_balloon_hdl = 0;                // �o���[���̉摜�n���h��
    int m_size = 200;                      // �o���[���̃T�C�Y
    std::vector<Balloon> balloons;		  // �o���[���̔z��  
public:
    void Initialize() override;
    void Update(float delta_time) override;
    void Draw(float delta_time, const PlayCamera* camera) override;
    void Spawn();
};