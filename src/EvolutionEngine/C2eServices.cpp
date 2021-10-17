#include "C2eServices.h"
#include "FlightRecorder.h"

namespace EvolutionEngine
{

    static FlightRecorder gFlightRecorder;

    FlightRecorder &GetFlightRecorder()
    {
        return gFlightRecorder;
    }

}