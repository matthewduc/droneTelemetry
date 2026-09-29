#pragma once
#include "telemetry.h"

enum class FailureMode {
    None,
    LowBattery,
    LostGps,
    ExcessiveRoll,
    ExcessivePitch,
    StaleTelemetry
};

class TelemetrySimulator {
    public:
        TelemetrySimulator();

        Telemetry next();

        void setFailureMode(FailureMode mode);

    private:
        double altitude;
        double battery;
        int gpsSatellites;

        double roll;
        double pitch;
        double packetAge;

        FailureMode failureMode;
};