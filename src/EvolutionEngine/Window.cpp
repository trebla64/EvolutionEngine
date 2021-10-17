#include "StdAfx.h"
#include "Window.h"
#include "C2eServices.h"
#include "FlightRecorder.h"

namespace EvolutionEngine
{

#if _WIN32
    // 0x00477280
    int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
    {
        FlightRecorder &flightRecorder = EvolutionEngine::GetFlightRecorder();

        flightRecorder.Log(FlightCategory::UNKNOWN64, "Start of WinMain\n");

        return 0;
    }
#endif

}
