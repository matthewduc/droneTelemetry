add_test([=[SafetyMonitorTest.HealthyTelemetryIsNormal]=]  [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build/safety_tests]==] [==[--gtest_filter=SafetyMonitorTest.HealthyTelemetryIsNormal]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SafetyMonitorTest.HealthyTelemetryIsNormal]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/tests/test_safety_monitor.cpp:6]==]
    WORKING_DIRECTORY [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[SafetyMonitorTest.LowBatteryProducesWarning]=]  [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build/safety_tests]==] [==[--gtest_filter=SafetyMonitorTest.LowBatteryProducesWarning]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SafetyMonitorTest.LowBatteryProducesWarning]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/tests/test_safety_monitor.cpp:19]==]
    WORKING_DIRECTORY [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[SafetyMonitorTest.LostGpsProducesCritical]=]  [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build/safety_tests]==] [==[--gtest_filter=SafetyMonitorTest.LostGpsProducesCritical]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SafetyMonitorTest.LostGpsProducesCritical]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/tests/test_safety_monitor.cpp:39]==]
    WORKING_DIRECTORY [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[SafetyMonitorTest.ExcessiveRollProducesCritical]=]  [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build/safety_tests]==] [==[--gtest_filter=SafetyMonitorTest.ExcessiveRollProducesCritical]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SafetyMonitorTest.ExcessiveRollProducesCritical]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/tests/test_safety_monitor.cpp:59]==]
    WORKING_DIRECTORY [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[SafetyMonitorTest.ExcessivePitchProducesCritical]=]  [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build/safety_tests]==] [==[--gtest_filter=SafetyMonitorTest.ExcessivePitchProducesCritical]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SafetyMonitorTest.ExcessivePitchProducesCritical]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/tests/test_safety_monitor.cpp:79]==]
    WORKING_DIRECTORY [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[SafetyMonitorTest.StaleTelemetryProducesCritical]=]  [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build/safety_tests]==] [==[--gtest_filter=SafetyMonitorTest.StaleTelemetryProducesCritical]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SafetyMonitorTest.StaleTelemetryProducesCritical]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/tests/test_safety_monitor.cpp:100]==]
    WORKING_DIRECTORY [==[/Users/nguyen/Documents/Code/C++/SearchAlgorithms/droneTelemetry/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(safety_tests_TESTS [==[SafetyMonitorTest.HealthyTelemetryIsNormal]==] [==[SafetyMonitorTest.LowBatteryProducesWarning]==] [==[SafetyMonitorTest.LostGpsProducesCritical]==] [==[SafetyMonitorTest.ExcessiveRollProducesCritical]==] [==[SafetyMonitorTest.ExcessivePitchProducesCritical]==] [==[SafetyMonitorTest.StaleTelemetryProducesCritical]==])
