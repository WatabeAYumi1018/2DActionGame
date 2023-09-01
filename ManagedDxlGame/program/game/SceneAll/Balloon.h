#pragma once
#include "../../engine/GameEngine.h"
#include "GameObject.h"

class Camera;

//�����������������ǁA�����̃N���X���Ŏ����𐶐�����͉̂\�Ȃ̂��R�c��
class Balloon : public GameObject{

public:
    Balloon();
    ~Balloon() {}

private:
    tnl::Vector3 m_hover_velocity;        // �������x
    int m_balloon_hdl = 0;                // �o���[���̉摜�n���h��
    int m_size = 200;                     // �o���[���̃T�C�Y
    std::vector<Balloon> balloons;		  // �o���[���̔z��  

public:
    void Initialize() override;
    void Update(float delta_time) override;
    void Draw(float delta_time, const Camera* camera) override;
    void Spawn();
};