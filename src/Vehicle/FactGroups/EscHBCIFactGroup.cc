#include "EscHBCIFactGroup.h"
#include "mavlink.h"
#include <mavlink/v2.0/development/mavlink_msg_esc_hbci_monitor.h>

#include <QDebug>

EscHBCIFactGroup::EscHBCIFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/EscHBCIFactGroup.json", parent)
{
    _addFact(&_voltageFl, "voltageFl");
    _addFact(&_voltageFr, "voltageFr");
    _addFact(&_voltageRl, "voltageRl");
    _addFact(&_voltageRr, "voltageRr");

    _addFact(&_currentFl, "currentFl");
    _addFact(&_currentFr, "currentFr");
    _addFact(&_currentRl, "currentRl");
    _addFact(&_currentRr, "currentRr");

    _addFact(&_rpmFl, "rpmFl");
    _addFact(&_rpmFr, "rpmFr");
    _addFact(&_rpmRl, "rpmRl");
    _addFact(&_rpmRr, "rpmRr");

    _addFact(&_motorTempFl, "motorTempFl");
    _addFact(&_motorTempFr, "motorTempFr");
    _addFact(&_motorTempRl, "motorTempRl");
    _addFact(&_motorTempRr, "motorTempRr");

    _addFact(&_escTempFl, "escTempFl");
    _addFact(&_escTempFr, "escTempFr");
    _addFact(&_escTempRl, "escTempRl");
    _addFact(&_escTempRr, "escTempRr");

    _addFact(&_outputPwmFl, "outputPwmFl");
    _addFact(&_outputPwmFr, "outputPwmFr");
    _addFact(&_outputPwmRl, "outputPwmRl");
    _addFact(&_outputPwmRr, "outputPwmRr");

    _addFact(&_inputPwmFl, "inputPwmFl");
    _addFact(&_inputPwmFr, "inputPwmFr");
    _addFact(&_inputPwmRl, "inputPwmRl");
    _addFact(&_inputPwmRr, "inputPwmRr");
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

    _voltageFl.setRawValue(esc.voltage_fl);
    _voltageFr.setRawValue(esc.voltage_fr);
    _voltageRl.setRawValue(esc.voltage_rl);
    _voltageRr.setRawValue(esc.voltage_rr);

    _currentFl.setRawValue(esc.current_fl);
    _currentFr.setRawValue(esc.current_fr);
    _currentRl.setRawValue(esc.current_rl);
    _currentRr.setRawValue(esc.current_rr);

    _rpmFl.setRawValue(esc.rpm_fl);
    _rpmFr.setRawValue(esc.rpm_fr);
    _rpmRl.setRawValue(esc.rpm_rl);
    _rpmRr.setRawValue(esc.rpm_rr);

    _motorTempFl.setRawValue(esc.motor_temper_fl);
    _motorTempFr.setRawValue(esc.motor_temper_fr);
    _motorTempRl.setRawValue(esc.motor_temper_rl);
    _motorTempRr.setRawValue(esc.motor_temper_rr);

    _escTempFl.setRawValue(esc.esc_temper_fl);
    _escTempFr.setRawValue(esc.esc_temper_fr);
    _escTempRl.setRawValue(esc.esc_temper_rl);
    _escTempRr.setRawValue(esc.esc_temper_rr);

    _outputPwmFl.setRawValue(esc.output_pwm_fl);
    _outputPwmFr.setRawValue(esc.output_pwm_fr);
    _outputPwmRl.setRawValue(esc.output_pwm_rl);
    _outputPwmRr.setRawValue(esc.output_pwm_rr);

    _inputPwmFl.setRawValue(esc.input_pwm_fl);
    _inputPwmFr.setRawValue(esc.input_pwm_fr);
    _inputPwmRl.setRawValue(esc.input_pwm_rl);
    _inputPwmRr.setRawValue(esc.input_pwm_rr);

    _setTelemetryAvailable(true);
}
