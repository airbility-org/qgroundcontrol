#pragma once

#include "FactGroup.h"
#include <QMap>

class EscHBCIFactGroup : public FactGroup
{
    Q_OBJECT

public:
    explicit EscHBCIFactGroup(QObject* parent = nullptr);

    // QML에서 접근 가능하도록 map 형태로 getter 제공
    Q_INVOKABLE Fact* voltage(const QString& pos)    { return &_voltageMap[pos]; }
    Q_INVOKABLE Fact* current(const QString& pos)    { return &_currentMap[pos]; }
    Q_INVOKABLE Fact* rpm(const QString& pos)        { return &_rpmMap[pos]; }
    Q_INVOKABLE Fact* motorTemp(const QString& pos)  { return &_motorTempMap[pos]; }
    Q_INVOKABLE Fact* escTemp(const QString& pos)    { return &_escTempMap[pos]; }
    Q_INVOKABLE Fact* outputPwm(const QString& pos)  { return &_outputPwmMap[pos]; }
    Q_INVOKABLE Fact* inputPwm(const QString& pos)   { return &_inputPwmMap[pos]; }

    void handleMessage(Vehicle* vehicle, const mavlink_message_t& message) override;

protected:
    void _handleEscHbciMonitor(const mavlink_message_t& message);

private:
    // Map 기반 배열 형태로 관리 (key: Fl, Fr, Rl, Rr)
    QMap<QString, Fact> _voltageMap;
    QMap<QString, Fact> _currentMap;
    QMap<QString, Fact> _rpmMap;
    QMap<QString, Fact> _motorTempMap;
    QMap<QString, Fact> _escTempMap;
    QMap<QString, Fact> _outputPwmMap;
    QMap<QString, Fact> _inputPwmMap;
};
