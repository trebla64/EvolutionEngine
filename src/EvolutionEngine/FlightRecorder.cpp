#include "StdAfx.h"
#include "FlightRecorder.h"

namespace EvolutionEngine
{
    constexpr char logtastic[] = "logtastic"; // Not sure what this is for
    constexpr char logFile[] = "creatures_engine_logfile.txt";

    // TODO: Move this to platform specific file touch function
    // 0x00547CB0
    bool checkFileExist(const char *fileName)
    {
        return ::GetFileAttributesA(fileName) != INVALID_FILE_ATTRIBUTES;
    }

    // 0x0054B330
    FlightRecorder::FlightRecorder()
    {
        if (checkFileExist(logtastic))
            this->categories = 81;
        else
            this->categories = 1;
        this->fileHandle = nullptr;
        this->fileName[0] = '\0';

        // TODO: Make this something more secure than strcpy
        strcpy(this->fileName, logFile);
    }

    // 0x0054B3A0
    FlightRecorder::~FlightRecorder()
    {
        // TODO: Finish rest of implementation (for now it only closes open file)
        if (this->fileHandle)
        {
            fclose(this->fileHandle);
        }
    }

    void __cdecl FlightRecorder::Log(FlightCategory category, const char *fmt, ...)
    {
    }

    // 0x0054B760
    void FlightRecorder::SetCategories(uint32_t categories)
    {
        this->categories = categories;
        if (checkFileExist(logtastic))
        {
            // TODO: Move hardcoded value to enum
            this->categories |= 0x50;
        }
    }

}