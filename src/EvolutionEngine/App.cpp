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

    // 0x00550E10
    void App::DoLoadWorld(const std::string &name)
    {

    }

}
