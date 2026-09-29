#include <chrono>
#include <iostream>
#include <thread>

#include "safety_monitor.h"
#include "telemetry_simulator.h"

const char* statusToString(SafetyStatus status) {
    switch (status) {
        case SafetyStatus::Normal:
            return "NORMAL";
        case SafetyStatus::Warning:
            return "WARNING";
        case SafetyStatus::Critical:
            return "CRITICAL";
    }
    return "UNKNOWN";
}

int main() {
    TelemetrySimulator simulator;
    SafetyMonitor monitor;

    // simulator.setFailureMode(
    //     FailureMode::LostGps
    // );

    while (true) {
        Telemetry telemetry = simulator.next();
        SafetyStatus status = monitor.evaluate(telemetry);

        std::cout 
            << "Altitude: "
            << telemetry.altitudeMeters
            << " m | Battery: "
            << telemetry.batteryPercent
            << "% | GPS: "
            << telemetry.gpsSatellites
            << " | Roll: "
            << telemetry.rollDegrees
            << " | Pitch: "
            << telemetry.pitchDegrees
            << " | Age: "
            << telemetry.ageMilliseconds
            << " ms | Status: "
            << statusToString(status)
            << '\n';
    
        std::this_thread::sleep_for(
            std::chrono::milliseconds(100)
        );          
    }
}