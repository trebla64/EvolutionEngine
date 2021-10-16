#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

namespace EvolutionEngine
{

    void main()
    {
    }

#ifdef _WIN32
    __declspec(dllexport) int StartEvolutionEngine(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    __declspec(dllexport) int StartEvolutionEngine(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    {
        EvolutionEngine::main();
        return 0;
    }
#endif

}
