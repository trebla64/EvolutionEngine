#pragma once

#include <string>

namespace EvolutionEngine
{

    class App
    {
    public:
        void UpdateApp();
        void DoLoadWorld(const std::string &name);
    };

    App *GetTheApp();

}
