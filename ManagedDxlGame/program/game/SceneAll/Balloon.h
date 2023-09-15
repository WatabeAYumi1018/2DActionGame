#pragma once
#include "../engine/GameEngine.h"
#include "../game/SceneAll/GameObject.h"

class Camera;

class Balloon : public GameObject
{

public:
    Balloon();
    ~Balloon() {}

private:

    //-----�����o�ϐ�-----//
    tnl::Vector3 m_hover_velocity;        // �������x

    int m_size = 200;
    int m_red_hdl = 0;            
    int m_blue_hdl = 0;                
    int m_green_hdl = 0;                

    eBalloonColor e_balloon_color = eBalloonColor::None;

    std::vector<int> m_balloons_hdl;

public:

    //-----�����o�֐�-----//
    void Initialize() override;
    void Update(float delta_time) override;
    void Draw(float delta_time, const Camera* camera) override;
    void Finalize() override;

    //-----Getter&Setter-----//
    int GetSize() const { return m_size; }
    int GetHdl() const { return m_balloons_hdl[static_cast<int>(e_balloon_color)]; }
};