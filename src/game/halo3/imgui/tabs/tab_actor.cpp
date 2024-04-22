#include "../basic_widget.h"

#include "game/halo3/ai/actors.h"

class TabActor : public BasicWidget {
public:
    TabActor(const char* name) : BasicWidget(name) {}
    void render() override;

};

static TabActor s_instance("Actor");
BasicWidget* tab_actor = &s_instance;

void TabActor::render() {
    auto p_actor = Actor()->getActor();

    if (p_actor == nullptr) return;

    ImGui::Checkbox("Enable Ai", &p_actor->enable_ai);
}
