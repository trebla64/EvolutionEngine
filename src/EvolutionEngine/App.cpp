#include "App.h"

namespace EvolutionEngine
{

    App ourApp;

    // 0x0054CC50
    App *App::GetTheApp()
    {
        return &ourApp;
    }

    // 0x0054E000
    void App::UpdateApp()
    {

    }

    // 0x0054E4D0
    void App::SetUpMainView()
    {
        // TODO: Implement
    }

    // 0x00550E10
    void App::DoLoadWorld(const std::string &name)
    {

    }

    // 0x005511F0
    bool App::ProcessCommandLine()
    {
        // TODO: Implement
        return true;
    }

    // 0x005578B0
    bool App::InitConfigFiles()
    {
        // TODO: Implement
        return true;
    }

}
