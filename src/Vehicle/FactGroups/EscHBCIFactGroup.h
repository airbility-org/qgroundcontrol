#pragma once

#include "FactGroup.h"

class EscHBCIFactGroup : public FactGroup
{
    Q_OBJECT

    // QML에서 사용 가능한 속성 등록
    Q_PROPERTY(Fact* voltageFl READ voltageFl CONSTANT)
    Q_PROPERTY(Fact* voltageFr READ voltageFr CONSTANT)
    Q_PROPERTY(Fact* voltageRl READ voltageRl CONSTANT)
    Q_PROPERTY(Fact* voltageRr READ voltageRr CONSTANT)

    Q_PROPERTY(Fact* currentFl READ currentFl CONSTANT)
    Q_PROPERTY(Fact* currentFr READ currentFr CONSTANT)
    Q_PROPERTY(Fact* currentRl READ currentRl CONSTANT)
    Q_PROPERTY(Fact* currentRr READ currentRr CONSTANT)

    Q_PROPERTY(Fact* rpmFl READ rpmFl CONSTANT)
    Q_PROPERTY(Fact* rpmFr READ rpmFr CONSTANT)
    Q_PROPERTY(Fact* rpmRl READ rpmRl CONSTANT)
    Q_PROPERTY(Fact* rpmRr READ rpmRr CONSTANT)

    Q_PROPERTY(Fact* motorTempFl READ motorTempFl CONSTANT)
    Q_PROPERTY(Fact* motorTempFr READ motorTempFr CONSTANT)
    Q_PROPERTY(Fact* motorTempRl READ motorTempRl CONSTANT)
    Q_PROPERTY(Fact* motorTempRr READ motorTempRr CONSTANT)

    Q_PROPERTY(Fact* escTempFl READ escTempFl CONSTANT)
    Q_PROPERTY(Fact* escTempFr READ escTempFr CONSTANT)
    Q_PROPERTY(Fact* escTempRl READ escTempRl CONSTANT)
    Q_PROPERTY(Fact* escTempRr READ escTempRr CONSTANT)

    Q_PROPERTY(Fact* outputPwmFl READ outputPwmFl CONSTANT)
    Q_PROPERTY(Fact* outputPwmFr READ outputPwmFr CONSTANT)
    Q_PROPERTY(Fact* outputPwmRl READ outputPwmRl CONSTANT)
    Q_PROPERTY(Fact* outputPwmRr READ outputPwmRr CONSTANT)

    Q_PROPERTY(Fact* inputPwmFl READ inputPwmFl CONSTANT)
    Q_PROPERTY(Fact* inputPwmFr READ inputPwmFr CONSTANT)
    Q_PROPERTY(Fact* inputPwmRl READ inputPwmRl CONSTANT)
    Q_PROPERTY(Fact* inputPwmRr READ inputPwmRr CONSTANT)

public:
    explicit EscHBCIFactGroup(QObject* parent = nullptr);

    // Getter 함수들
    Fact* voltageFl()     { return &_voltageFl; }
    Fact* voltageFr()     { return &_voltageFr; }
    Fact* voltageRl()     { return &_voltageRl; }
    Fact* voltageRr()     { return &_voltageRr; }

    Fact* currentFl()     { return &_currentFl; }
    Fact* currentFr()     { return &_currentFr; }
    Fact* currentRl()     { return &_currentRl; }
    Fact* currentRr()     { return &_currentRr; }

    Fact* rpmFl()         { return &_rpmFl; }
    Fact* rpmFr()         { return &_rpmFr; }
    Fact* rpmRl()         { return &_rpmRl; }
    Fact* rpmRr()         { return &_rpmRr; }

    Fact* motorTempFl()   { return &_motorTempFl; }
    Fact* motorTempFr()   { return &_motorTempFr; }
    Fact* motorTempRl()   { return &_motorTempRl; }
    Fact* motorTempRr()   { return &_motorTempRr; }

    Fact* escTempFl()     { return &_escTempFl; }
    Fact* escTempFr()     { return &_escTempFr; }
    Fact* escTempRl()     { return &_escTempRl; }
    Fact* escTempRr()     { return &_escTempRr; }

    Fact* outputPwmFl()   { return &_outputPwmFl; }
    Fact* outputPwmFr()   { return &_outputPwmFr; }
    Fact* outputPwmRl()   { return &_outputPwmRl; }
    Fact* outputPwmRr()   { return &_outputPwmRr; }

    Fact* inputPwmFl()    { return &_inputPwmFl; }
    Fact* inputPwmFr()    { return &_inputPwmFr; }
    Fact* inputPwmRl()    { return &_inputPwmRl; }
    Fact* inputPwmRr()    { return &_inputPwmRr; }

    void handleMessage(Vehicle* vehicle, const mavlink_message_t& message) override;

protected:
    void _handleEscHbciMonitor(const mavlink_message_t& message);

private:
    // Fact 객체 선언
    Fact _voltageFl, _voltageFr, _voltageRl, _voltageRr;
    Fact _currentFl, _currentFr, _currentRl, _currentRr;
    Fact _rpmFl, _rpmFr, _rpmRl, _rpmRr;
    Fact _motorTempFl, _motorTempFr, _motorTempRl, _motorTempRr;
    Fact _escTempFl, _escTempFr, _escTempRl, _escTempRr;
    Fact _outputPwmFl, _outputPwmFr, _outputPwmRl, _outputPwmRr;
    Fact _inputPwmFl, _inputPwmFr, _inputPwmRl, _inputPwmRr;
};
