#define MAVLINK_ENABLED_TILT_CTRL // mavlink custom 메시지 헤더를 찾을 수 있도록

#include "ControlSurfaceCmdFactGroup.h"
#include "mavlink/v2.0/development/mavlink_msg_control_surface_cmd.h"
#include <QDebug> // qDebug() 사용



ControlSurfaceCmdFactGroup::ControlSurfaceCmdFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/ControlSurfaceCmdFactGroup.json", parent)
{
    setObjectName("ControlSurfaceCmdFactGroup");

    // 각 필드 등록 - 반드시 json name과 일치
    _addFact(&_leftAileronFact, "leftAileron");
    _addFact(&_rightAileronFact, "rightAileron");
    _addFact(&_leftRuddervatorFact, "leftRuddervator");
    _addFact(&_rightRuddervatorFact, "rightRuddervator");
}

void ControlSurfaceCmdFactGroup::handleMessage(Vehicle *vehicle, const mavlink_message_t &message) {
    switch (message.msgid) {
        case MAVLINK_MSG_ID_CONTROL_SURFACE_CMD:
            qDebug() << "Received MAVLINK_MSG_ID_CONTROL_SURFACE_CMD.";
            _handleControlSurfaceCmd(message);
            break;
        default:
            break;
    }
}

void ControlSurfaceCmdFactGroup::_handleControlSurfaceCmd(const mavlink_message_t &message) {
    mavlink_control_surface_cmd_t surfCmd{};
    mavlink_msg_control_surface_cmd_decode(&message, &surfCmd);
    _updateControlSurfaceCmd(
        surfCmd.left_aileron,
        surfCmd.right_aileron,
        surfCmd.left_ruddervator,
        surfCmd.right_ruddervator
    );
    _setTelemetryAvailable(true); // FactGroup 함수
}

void ControlSurfaceCmdFactGroup::_updateControlSurfaceCmd(float leftAil, float rightAil, float leftRud, float rightRud) {
    _leftAileronFact.setRawValue(leftAil);
    _rightAileronFact.setRawValue(rightAil);
    _leftRuddervatorFact.setRawValue(leftRud);
    _rightRuddervatorFact.setRawValue(rightRud);
}
