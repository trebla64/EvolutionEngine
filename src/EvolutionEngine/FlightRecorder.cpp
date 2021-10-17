#include "StdAfx.h"
#include "FlightRecorder.h"

namespace EvolutionEngine
{
    constexpr char logFile[] = "creatures_engine_logfile.txt";

    // TODO: Move this to platform specific file touch function
    bool checkFileExist(const char *fileName)
    {
        return ::GetFileAttributesA(fileName) != INVALID_FILE_ATTRIBUTES;
    }

    FlightRecorder::FlightRecorder()
    {
        if (checkFileExist(logFile))
            this->unknown = 81;
        else
            this->unknown = 1;
        this->fileHandle = nullptr;
        this->fileName[0] = '\0';

        // TODO: Make this something more secure than strcpy
        strcpy(this->fileName, logFile);
    }

    FlightRecorder::~FlightRecorder()
    {
    }

    void __cdecl FlightRecorder::Log(FlightCategory category, const char *fmt, ...)
    {
    }

}