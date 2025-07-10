#define MAVLINK_ENABLED_TILT_CTRL

#include "CustomTiltAngleFactGroup.h"


CustomTiltAngleFactGroup::CustomTiltAngleFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/CustomTiltAngleFactGroup.json", parent)
{
    setObjectName("CustomTiltAngleFactGroup");
    
    _addFact(&_tiltFlFact, "tiltFl");
    _addFact(&_tiltFrFact, "tiltFr");
    _addFact(&_tiltRlFact, "tiltRl");
    _addFact(&_tiltRrFact, "tiltRr");
}

void CustomTiltAngleFactGroup::handleMessage(Vehicle *vehicle, const mavlink_message_t &message) {
    switch (message.msgid) {
        case MAVLINK_MSG_ID_TILT_ANGLE: 
            qDebug() << "Received MAVLINK_MSG_ID_TILT_ANGLE.";
            _handleTiltAngle(message);
            break;
            default:
            break;
    }
}

void CustomTiltAngleFactGroup::_handleTiltAngle(const mavlink_message_t &message) {
    mavlink_tilt_angle_t tiltCtrl{}; 
    mavlink_msg_tilt_angle_decode(&message, &tiltCtrl);
    _updateTiltAngle(tiltCtrl.tilt_fl, tiltCtrl.tilt_fr, tiltCtrl.tilt_rl, tiltCtrl.tilt_rr);

    _setTelemetryAvailable(true); // FactGroup에 정의되어 있음
}

void CustomTiltAngleFactGroup::_updateTiltAngle(float fl, float fr, float rl, float rr) {
    _tiltFlFact.setRawValue(fl);
    _tiltFrFact.setRawValue(fr);
    _tiltRlFact.setRawValue(rl);
    _tiltRrFact.setRawValue(rr);
}
