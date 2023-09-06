#include "../../game/ScenePlay/Character/Player/Player.h"
#include "../game/SceneAll/Balloon.h"
#include "../game/SceneAll/UI.h"

UI::UI() : GameObject(tnl::Vector3{ 10,500,0 })
{
	Initialize();
}

void UI::Initialize()
{
	m_ui_hdl = LoadGraph("graphics/UI/HPUI.png");
}

void UI::Draw(float delta_time, const Camera* camera)
{
	DrawExtendGraph(m_pos.x, m_pos.y, m_pos.x + m_extend_x, m_pos.y + m_extend_y, m_ui_hdl, true);
	HpBalloons();
}

//�`�揇�̂��Ƃ��l����Ƃ����ő��삷�ׂ��H
void UI::HpBalloons()
{
	for (int i = 0; i <= m_player->GetMaxHP(); i++)		
	{
		//DrawGraph(50 + (i * 32), 500, m_balloon->GetHdl(), TRUE);
	}
	

}