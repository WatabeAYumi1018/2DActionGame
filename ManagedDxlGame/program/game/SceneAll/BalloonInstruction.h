#pragma once
#include "Balloon.h"

class BalloonInstruction : public Balloon
{
public:

    BalloonInstruction();
    ~BalloonInstruction() {}

private:
    //-----�����o�ϐ�-----//
    std::map<eInstructionType, int> m_instruction_hdl; // �摜�n���h���̃}�b�v
    std::map<eInstructionType, tnl::Vector3> m_positions; // �e�摜�̍��W��ێ�����}�b�v
    eInstructionType m_active_type = eInstructionType::Run; // �`�悷��摜�̎��


public:
    //-----�����o�֐�-----//
    void SetPositionForType(eInstructionType type, const tnl::Vector3& pos);

    void Initialize() override;
    void Update(float delta_time) override;
    void Draw(float delta_time, const Camera* camera) override;

    //-----Getter,Setter-----//
    void SetActiveType(eInstructionType active_type) { m_active_type = active_type; }
};
