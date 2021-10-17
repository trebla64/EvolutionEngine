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

    // 0x0054B550
    void __cdecl FlightRecorder::Log(FlightCategory category, const char *fmt, ...)
    {
        char buffer[4096];
        va_list va;

        va_start(va, fmt);
        if (category || category & this->categories)
        {
            bool bOpenedFile = false;
            if (this->fileHandle)
                goto skip_open;
            if (this->fileName[0])
                this->fileHandle = fopen(this->fileName, "a+tc");
            bOpenedFile = true;
            if (this->fileHandle)
            {
            skip_open:
                if (bOpenedFile)
                {
                    // TODO: Decompile some extra junk in here
                }

                // TODO: Rework this using more secure method
                int len = vsprintf(buffer, fmt, va);
                buffer[len] = '\n';
                buffer[len + 1] = '\0';
                fwrite(buffer, 1, len + 1, this->fileHandle);
                fflush(this->fileHandle);
            }
            else
            {
                std::cerr << "Failed to make flight recorder file " << std::endl;
            }
        }
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