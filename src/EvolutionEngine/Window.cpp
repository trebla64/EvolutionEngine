#include "StdAfx.h"
#include "Window.h"
#include "C2eServices.h"
#include "FlightRecorder.h"
#include "App.h"

namespace EvolutionEngine
{

    bool gbQuitting;

#ifdef _WIN32
    // 0x00476FC0
    bool HandleMessages(UINT wMsgFilterMin, UINT wMsgFilterMax, uint8_t a1)
    {
        MSG Msg;
        bool result = gbQuitting;
        BOOL getMessageResult;

        for (int i = 0; !gbQuitting; result = gbQuitting)
        {
            if (i == -1)
                break;

            result = PeekMessageA(&Msg, 0, wMsgFilterMin, wMsgFilterMax, 0);
            if (!result)
                break;

            getMessageResult = GetMessageA(&Msg, 0, wMsgFilterMin, wMsgFilterMax);
            i = getMessageResult;
            if (getMessageResult)
            {
                if (getMessageResult != -1)
                {
                    if (Msg.message == 1024)
                    {
                        // TODO: Some more stuff in here
                    }
                    else
                    {
                        TranslateMessage(&Msg);
                        DispatchMessage(&Msg);
                    }
                }
            }
            else
            {
                gbQuitting = true;
            }

            result = a1;
            if (a1)
                break;
        }

        return result;
    }

    // 0x00477280
    int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
    {
        FlightRecorder &flightRecorder = GetFlightRecorder();
        App *pApp = App::GetTheApp();

        flightRecorder.Log(FlightCategory::UNKNOWN64, "Start of WinMain\n");

        timeBeginPeriod(1);

        flightRecorder.Log(FlightCategory::UNKNOWN16, "Message Loop has terminated.");
        timeEndPeriod(1);

        return 0;
    }
#endif

}
