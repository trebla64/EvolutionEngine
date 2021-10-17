#include "StdAfx.h"
#include "Window.h"
#include "C2eServices.h"
#include "FlightRecorder.h"
#include "App.h"
#include "ErrorMessageHandler.h"
#include "Win32Server.h"

namespace EvolutionEngine
{

    bool gbQuitting;
    bool gbTerminate; // 0x0060EB59
    bool gbUnknown0;  // 0x0060EBD8
    bool gbUnknown1;    // 0x0060EB5A
    bool gbUnknown2;    // 0x0060EB58

    // 0x00477690
    bool InitInstance(HINSTANCE hInstance)
    {
        FlightRecorder &flightRecorder = GetFlightRecorder();
        App *pApp = App::GetTheApp();

        flightRecorder.Log(FlightCategory::UNKNOWN64, "Init config files\n");
        pApp->InitConfigFiles();

        return true;
    }

    // 0x00478D40
    bool SetGameTicking(bool unknown)
    {
        // TODO: Implement
        return true;        
    }

    // 0x00478B80 [DONE]
    bool DoStartup(HWND hWnd)
    {
        FlightRecorder &flightRecorder = GetFlightRecorder();
        App *pApp = App::GetTheApp();
        bool result;

        flightRecorder.Log(FlightCategory::UNKNOWN64, "In DoStartup");
        gbTerminate = false;
        gbUnknown0 = false;
        ErrorMessageHandler::SetWindow(hWnd);
        flightRecorder.Log(FlightCategory::UNKNOWN64, "Calling App init");
        result = pApp->Init();
        if (result)
        {
            flightRecorder.Log(FlightCategory::UNKNOWN64, "Starting external interface");
            result = Win32Server::StartInterface(hWnd);
            if (result)
            {
                gbUnknown1 = false;
                gbUnknown2 = false;
                flightRecorder.Log(FlightCategory::UNKNOWN64, "Kick starting timer");
                result = SetGameTicking(true);
                if (result)
                {
                    flightRecorder.Log(FlightCategory::UNKNOWN64, "Finished DoStartup");
                    result = true;
                }
            }
        }

        return result;
    }

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
                        App::GetTheApp()->UpdateApp();
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
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
    {
        FlightRecorder &flightRecorder = GetFlightRecorder();
        App *pApp = App::GetTheApp();

        flightRecorder.Log(FlightCategory::UNKNOWN64, "Start of WinMain\n");
        timeBeginPeriod(1);

        if (pApp->ProcessCommandLine())
        {
            if (InitInstance(hInstance))
            {
            }
        }

        flightRecorder.Log(FlightCategory::UNKNOWN16, "Message Loop has terminated.");
        timeEndPeriod(1);

        return 0;
    }
#endif

}
