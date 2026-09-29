#pragma once
#include "telemetry.h"

enum class SafetyStatus {
    Normal, 
    Warning,
    Critical
};

class SafetyMonitor {
    public:
        SafetyStatus evaluate(const Telemetry& telemetry) const;
};