#pragma once

struct Telemetry {
    double altitudeMeters;
    double batteryPercent;
    int gpsSatellites;

    double rollDegrees;
    double pitchDegrees;

    double ageMilliseconds;
};