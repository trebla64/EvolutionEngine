#include "StdAfx.h"
#include "Window.h"
#include "C2eServices.h"
#include "FlightRecorder.h"
#include "App.h"

namespace EvolutionEngine
{

#ifdef _WIN32
    // 0x00477280
    int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
    {
        FlightRecorder &flightRecorder = GetFlightRecorder();
        App *pApp = App::GetTheApp();

        flightRecorder.Log(FlightCategory::UNKNOWN64, "Start of WinMain\n");

        timeBeginPeriod(1);

        timeEndPeriod(1);

        return 0;
    }
#endif

}
