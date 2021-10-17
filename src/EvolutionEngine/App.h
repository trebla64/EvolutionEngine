#pragma once

#include <string>

namespace EvolutionEngine
{

    class App
    {
    public:
        static App *GetTheApp();
        void UpdateApp();
        void SetUpMainView();
        void DoLoadWorld(const std::string &name);
        bool ProcessCommandLine();
        bool InitConfigFiles();
    };

}
