#include "EscHBCIFactGroup.h"
#include "mavlink.h"
#include <mavlink/v2.0/development/mavlink_msg_esc_hbci_monitor.h>

#include <QDebug>

EscHBCIFactGroup::EscHBCIFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/EscHBCIFactGroup.json", parent)
{
    // 배열 기반으로 4개씩 등록 (Fl, Fr, Rl, Rr 순서)
    const QStringList suffixes = {"Fl", "Fr", "Rl", "Rr"};
    for (const QString& s : suffixes) {
        
        _addFact(&_voltageMap[s],    "voltage"    + s);
        _addFact(&_currentMap[s],    "current"    + s);
        _addFact(&_rpmMap[s],        "rpm"        + s);
        _addFact(&_motorTempMap[s],  "motorTemp"  + s);
        _addFact(&_escTempMap[s],    "escTemp"    + s);
        _addFact(&_outputPwmMap[s],  "outputPwm"  + s);
        _addFact(&_inputPwmMap[s],   "inputPwm"   + s);
    }
}


void EscHBCIFactGroup::handleMessage(Vehicle* vehicle, const mavlink_message_t& message)
{
    switch (message.msgid) {
        case MAVLINK_MSG_ID_ESC_HBCI_MONITOR:
            _handleEscHbciMonitor(message);
            break;
        default:
            break;
    }
}

void EscHBCIFactGroup::_handleEscHbciMonitor(const mavlink_message_t& message)
{
    mavlink_esc_hbci_monitor_t esc{};
    mavlink_msg_esc_hbci_monitor_decode(&message, &esc);

    _voltageMap["Fl"].setRawValue(esc.voltage_fl);
    _voltageMap["Fr"].setRawValue(esc.voltage_fr);
    _voltageMap["Rl"].setRawValue(esc.voltage_rl);
    _voltageMap["Rr"].setRawValue(esc.voltage_rr);

    _currentMap["Fl"].setRawValue(esc.current_fl);
    _currentMap["Fr"].setRawValue(esc.current_fr);
    _currentMap["Rl"].setRawValue(esc.current_rl);
    _currentMap["Rr"].setRawValue(esc.current_rr);

    _rpmMap["Fl"].setRawValue(esc.rpm_fl);
    _rpmMap["Fr"].setRawValue(esc.rpm_fr);
    _rpmMap["Rl"].setRawValue(esc.rpm_rl);
    _rpmMap["Rr"].setRawValue(esc.rpm_rr);

    _motorTempMap["Fl"].setRawValue(esc.motor_temper_fl);
    _motorTempMap["Fr"].setRawValue(esc.motor_temper_fr);
    _motorTempMap["Rl"].setRawValue(esc.motor_temper_rl);
    _motorTempMap["Rr"].setRawValue(esc.motor_temper_rr);

    _escTempMap["Fl"].setRawValue(esc.esc_temper_fl);
    _escTempMap["Fr"].setRawValue(esc.esc_temper_fr);
    _escTempMap["Rl"].setRawValue(esc.esc_temper_rl);
    _escTempMap["Rr"].setRawValue(esc.esc_temper_rr);

    _outputPwmMap["Fl"].setRawValue(esc.output_pwm_fl);
    _outputPwmMap["Fr"].setRawValue(esc.output_pwm_fr);
    _outputPwmMap["Rl"].setRawValue(esc.output_pwm_rl);
    _outputPwmMap["Rr"].setRawValue(esc.output_pwm_rr);

    _inputPwmMap["Fl"].setRawValue(esc.input_pwm_fl);
    _inputPwmMap["Fr"].setRawValue(esc.input_pwm_fr);
    _inputPwmMap["Rl"].setRawValue(esc.input_pwm_rl);
    _inputPwmMap["Rr"].setRawValue(esc.input_pwm_rr);

    _setTelemetryAvailable(true);
}