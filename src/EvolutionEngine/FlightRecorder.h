#pragma once

namespace EvolutionEngine
{

    enum FlightCategory
    {
        UNKNOWN64 = 64
    };

    class FlightRecorder
    {
    public:
        void __cdecl Log(FlightCategory category, const char *fmt, ...);
    };

}
