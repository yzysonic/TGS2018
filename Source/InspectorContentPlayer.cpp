#include "InspectorContentPlayer.h"

void InspectorContentPlayer::Init(void)
{
	player = dynamic_cast<Player*>(object);
}

void InspectorContentPlayer::GuiContent(void)
{
	if (ImGui::TreeNodeEx("PlayerInformation", ImGuiTreeNodeFlags_DefaultOpen))
	{
		auto nh = GameManager::GetInstance()->Var<int>("NumPosHistory");
		//for (int i = 0; i < nh; i++)
		//{
		//	char t[32];
		//	sprintf(t, "his%02d", nh);
		//	//ImGui::DragFloat3(t, player->pos_history., );
		//}
		ImGui::Spacing();
		ImGui::TreePop();
	}
}
