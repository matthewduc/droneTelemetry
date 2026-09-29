#include "telemetry_simulator.h"

TelemetrySimulator::TelemetrySimulator()
    : altitude(100.0),
      battery(100.0),
      gpsSatellites(14),
      roll(0.0),
      pitch(0.0),
      packetAge(20.0),
      failureMode(FailureMode::None) {

}

void TelemetrySimulator::setFailureMode (FailureMode mode) {
    failureMode = mode;
}

Telemetry TelemetrySimulator::next() {
    // changes over time
    altitude += 0.5;
    battery -= 0.1;
    roll -= 0.1;
    packetAge = 20.0;
    switch (failureMode) {
        case FailureMode::None:
            break;
        
        case FailureMode::LowBattery:
            battery = 10.0;
            break;
        
        case FailureMode::LostGps:
            gpsSatellites = 2;
            break;

        case FailureMode::ExcessiveRoll:
            roll = 60.0;
            break;
        
        case FailureMode::ExcessivePitch:
            pitch = -60.0;
            break;

        case FailureMode::StaleTelemetry:
            packetAge = 1000.0;
            break;
    }

    return Telemetry {
        altitude,
        battery,
        gpsSatellites,
        roll,
        pitch,
        packetAge
    };
}


/*
Calling simulator.next();

#1
Alt = 100.5
Battery = 99.9
Rool = 0.2
Pitch = -0.1

#2
Alt = 101.0
Battery = 99.8
Rool = 0.4
Pitch = -0.2


FailureModes deliberately inject failure cases into the simulated telemetry

e.g.
simulator.setFailureMode(
    FailureMode::LowBattery
);

Receive:
Battery = 10%

*/