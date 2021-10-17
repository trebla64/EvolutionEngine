#pragma once

// TODO: Move this (Don't know why vscode complains about FILE)
#include <stdio.h>
#include <stdint.h>

namespace EvolutionEngine
{

    enum FlightCategory
    {
        UNKNOWN64 = 64
    };

#pragma pack(push, 1)
    class FlightRecorder
    {
    public:
        char fileName[260];
        FILE *fileHandle;
        uint32_t categories;

        FlightRecorder();
        ~FlightRecorder();

        void __cdecl Log(FlightCategory category, const char *fmt, ...);
        void SetCategories(uint32_t categories);
    };
#pragma pack(pop)
    static_assert(sizeof(FlightRecorder) == (260 + sizeof(FILE *) + 4));

}
