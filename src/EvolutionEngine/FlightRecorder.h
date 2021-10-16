#pragma once

enum FlightCategory {
    UNKNOWN = 0
};

class FlightRecorder
{
public:
    void Log(FlightCategory category, const char *fmt, ...);
};
