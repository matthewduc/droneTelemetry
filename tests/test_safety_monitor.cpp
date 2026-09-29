#include <gtest/gtest.h>

#include "safety_monitor.h"
#include "telemetry_simulator.h"

TEST(SafetyMonitorTest, HealthyTelemetryIsNormal) {
    TelemetrySimulator simulator;
    SafetyMonitor monitor;
    Telemetry telemetry =
        simulator.next();

    EXPECT_EQ(
        monitor.evaluate(telemetry),
        SafetyStatus::Normal
    );
}

// Test low battery
TEST(SafetyMonitorTest, LowBatteryProducesWarning) {

    TelemetrySimulator simulator;

    simulator.setFailureMode(
        FailureMode::LowBattery
    );

    SafetyMonitor monitor;

    Telemetry telemetry =
        simulator.next();

    EXPECT_EQ(
        monitor.evaluate(telemetry),
        SafetyStatus::Warning
    );
}

// Verify Low Battery
TEST(TelemetrySimulatorTest, LowBatteryActuallyProducesLowBattery) {

    TelemetrySimulator simulator;

    simulator.setFailureMode(
        FailureMode::LowBattery
    );

    Telemetry telemetry =
        simulator.next();

    EXPECT_LT(
        telemetry.batteryPercent,
        20.0
    );
}


// Test GPS Failure
TEST(SafetyMonitorTest, LostGpsProducesCritical) {

    TelemetrySimulator simulator;

    simulator.setFailureMode(
        FailureMode::LostGps
    );

    SafetyMonitor monitor;

    Telemetry telemetry =
        simulator.next();

    EXPECT_EQ(
        monitor.evaluate(telemetry),
        SafetyStatus::Critical
    );
}

// Verify GPS Loss
TEST(TelemetrySimulatorTest, LostGpsActuallyProducesLowGps) {

    TelemetrySimulator simulator;

    simulator.setFailureMode(
        FailureMode::LostGps
    );

    Telemetry telemetry =
        simulator.next();

    EXPECT_LT(
        telemetry.gpsSatellites,
        4
    );
}


// Test Excessive Roll
TEST(SafetyMonitorTest, ExcessiveRollProducesCritical) {

    TelemetrySimulator simulator;

    simulator.setFailureMode(
        FailureMode::ExcessiveRoll
    );

    SafetyMonitor monitor;

    Telemetry telemetry =
        simulator.next();

    EXPECT_EQ(
        monitor.evaluate(telemetry),
        SafetyStatus::Critical
    );
}

// Test Excessive Pitch
TEST(SafetyMonitorTest, ExcessivePitchProducesCritical) {

    TelemetrySimulator simulator;

    simulator.setFailureMode(
        FailureMode::ExcessivePitch
    );

    SafetyMonitor monitor;

    Telemetry telemetry =
        simulator.next();

    EXPECT_EQ(
        monitor.evaluate(telemetry),
        SafetyStatus::Critical
    );
}


// Test Stale Telemetry
TEST(SafetyMonitorTest, StaleTelemetryProducesCritical) {

    TelemetrySimulator simulator;

    simulator.setFailureMode(
        FailureMode::StaleTelemetry
    );

    SafetyMonitor monitor;

    Telemetry telemetry =
        simulator.next();

    EXPECT_EQ(
        monitor.evaluate(telemetry),
        SafetyStatus::Critical
    );
}

// Verify Stale Telemetry
TEST(TelemetrySimulatorTest, StaleModeProducesOldTelemetry) {

    TelemetrySimulator simulator;

    simulator.setFailureMode(
        FailureMode::StaleTelemetry
    );

    Telemetry telemetry =
        simulator.next();

    EXPECT_GT(
        telemetry.ageMilliseconds,
        500.0
    );
}
