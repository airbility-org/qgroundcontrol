// MAVLink 메시지 헤더를 포함하기 전에 해당 메시지를 활성화하는 define을 추가합니다.
#define MAVLINK_ENABLED_TILT_STATUS

#include "CustomTiltStatusFactGroup.h"
#include "Vehicle.h"

CustomTiltStatusFactGroup::CustomTiltStatusFactGroup(QObject* parent)
    : FactGroup(100, ":/json/Vehicle/CustomTiltStatusFactGroup.json", parent)
{
    const char* rgFactNames[_count] = {
        "angleFl",      "angleFr",      "angleRl",      "angleRr",
        "angularVelFl", "angularVelFr", "angularVelRl", "angularVelRr",
        "voltageFl",    "voltageFr",    "voltageRl",    "voltageRr",
        "currentFl",    "currentFr",    "currentRl",    "currentRr",
        "tempFl",       "tempFr",       "tempRl",       "tempRr"
    };

    for (int i = 0; i < _count; i++) {
        _addFact(&_facts[i], rgFactNames[i]);
    }
}

void CustomTiltStatusFactGroup::handleMessage(Vehicle* /*vehicle*/, const mavlink_message_t& message)
{
    if (message.msgid == MAVLINK_MSG_ID_TILT_STATUS) {
        _handleTiltStatus(message);
    }
}

void CustomTiltStatusFactGroup::_handleTiltStatus(const mavlink_message_t& message)
{
    mavlink_tilt_status_t tiltStatus{};
    mavlink_msg_tilt_status_decode(&message, &tiltStatus);

    for (int i = 0; i < 4; i++) {
        _facts[i].setRawValue(tiltStatus.angle[i]);
        _facts[i + 4].setRawValue(tiltStatus.angular_vel[i]);
        _facts[i + 8].setRawValue(tiltStatus.voltage[i]);
        _facts[i + 12].setRawValue(tiltStatus.current[i]);
        _facts[i + 16].setRawValue(tiltStatus.temperature[i]);
    }

    _setTelemetryAvailable(true);
}