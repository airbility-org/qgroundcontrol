target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        TerrainFactGroup.cc
        TerrainFactGroup.h
        VehicleBatteryFactGroup.cc
        VehicleBatteryFactGroup.h
        VehicleClockFactGroup.cc
        VehicleClockFactGroup.h
        VehicleDistanceSensorFactGroup.cc
        VehicleDistanceSensorFactGroup.h
        VehicleEFIFactGroup.cc
        VehicleEFIFactGroup.h
        VehicleEscStatusFactGroup.cc
        VehicleEscStatusFactGroup.h
        VehicleEstimatorStatusFactGroup.cc
        VehicleEstimatorStatusFactGroup.h
        VehicleGeneratorFactGroup.cc
        VehicleGeneratorFactGroup.h
        VehicleFactGroup.cc
        VehicleFactGroup.h
        VehicleGPS2FactGroup.cc
        VehicleGPS2FactGroup.h
        VehicleGPSFactGroup.cc
        VehicleGPSFactGroup.h
        VehicleLocalPositionFactGroup.cc
        VehicleLocalPositionFactGroup.h
        VehicleLocalPositionSetpointFactGroup.cc
        VehicleLocalPositionSetpointFactGroup.h
        VehicleRPMFactGroup.cc
        VehicleRPMFactGroup.h
        VehicleSetpointFactGroup.cc
        VehicleSetpointFactGroup.h
        VehicleTemperatureFactGroup.cc
        VehicleTemperatureFactGroup.h
        VehicleVibrationFactGroup.cc
        VehicleVibrationFactGroup.h
        VehicleWindFactGroup.cc
        VehicleWindFactGroup.h
        VehicleHygrometerFactGroup.cc
        VehicleHygrometerFactGroup.h

        FakeFactGroup.cc
        FakeFactGroup.h

        CustomTiltAngleSetpointFactGroup.cc
        CustomTiltAngleSetpointFactGroup.h

        ControlSurfaceCmdFactGroup.h
        ControlSurfaceCmdFactGroup.cc

        EscHBCIFactGroup.h
        EscHBCIFactGroup.cc

        CustomTiltStatusFactGroup.cc
        CustomTiltStatusFactGroup.h
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/libs/mavlink/include
        ${CMAKE_SOURCE_DIR}/libs/mavlink/include/mavlink/v2.0
        ${CMAKE_SOURCE_DIR}/libs/mavlink/include/mavlink/v2.0/development
)
