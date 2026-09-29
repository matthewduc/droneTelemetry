#include "safety_monitor.h"

SafetyStatus SafetyMonitor::evaluate(const Telemetry &telemetry) const
{
    // Telemetry is too old
    if (telemetry.ageMilliseconds > 500.0) {
        return SafetyStatus::Critical;
    }

    // Insufficient GPS information
    if (telemetry.gpsSatellites < 4) {
        return SafetyStatus::Critical;
    }

    // Excessive Roll
    if (telemetry.rollDegrees > 45.0 ||
        telemetry.rollDegrees < -45.0) {
            return SafetyStatus::Critical;
    }

    // Excessive Pitch
    if (telemetry.pitchDegrees > 45.0 ||
        telemetry.pitchDegrees < -45.0) {
            return SafetyStatus::Critical;
    }

    // Low Battery
    if (telemetry.batteryPercent < 20.0) {
        return SafetyStatus::Warning;
    }
    
    
    return SafetyStatus::Normal;
}