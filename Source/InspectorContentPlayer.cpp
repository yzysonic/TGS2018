#include "InspectorContentPlayer.h"

void InspectorContentPlayer::Init(void)
{
	player = dynamic_cast<Player*>(object);
}

void InspectorContentPlayer::GuiContent(void)
{
	if (ImGui::TreeNodeEx("PlayerInformation", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::Spacing();
		ImGui::TreePop();
	}
}
