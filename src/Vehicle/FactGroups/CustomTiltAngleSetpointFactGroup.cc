#define MAVLINK_ENABLED_TILT_CTRL

#include "CustomTiltAngleSetpointFactGroup.h"


CustomTiltAngleSetpointFactGroup::CustomTiltAngleSetpointFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/CustomTiltAngleSetpointFactGroup.json", parent)
{
    setObjectName("CustomTiltAngleSetpointFactGroup");
    
    _addFact(&_tiltFlFact, "tiltFl");
    _addFact(&_tiltFrFact, "tiltFr");
    _addFact(&_tiltRlFact, "tiltRl");
    _addFact(&_tiltRrFact, "tiltRr");
}

void CustomTiltAngleSetpointFactGroup::handleMessage(Vehicle *vehicle, const mavlink_message_t &message) {
    switch (message.msgid) {
        case MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT: 
            qDebug() << "Received MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT.";
            _handleTiltAngleSetpoint(message);
            break;
            default:
            break;
    }
}

void CustomTiltAngleSetpointFactGroup::_handleTiltAngleSetpoint(const mavlink_message_t &message) {
    mavlink_tilt_angle_setpoint_t tiltCtrl{}; 
    mavlink_msg_tilt_angle_setpoint_decode(&message, &tiltCtrl);
    _updateTiltAngleSetpoint(tiltCtrl.tilt_fl, tiltCtrl.tilt_fr, tiltCtrl.tilt_rl, tiltCtrl.tilt_rr);

    _setTelemetryAvailable(true); // FactGroup에 정의되어 있음
}

void CustomTiltAngleSetpointFactGroup::_updateTiltAngleSetpoint(float fl, float fr, float rl, float rr) {
    _tiltFlFact.setRawValue(fl);
    _tiltFrFact.setRawValue(fr);
    _tiltRlFact.setRawValue(rl);
    _tiltRrFact.setRawValue(rr);
}
