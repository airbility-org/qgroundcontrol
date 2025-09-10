#pragma once
#include "FactGroup.h"


class CustomTiltAngleSetpointFactGroup : public FactGroup
{
    Q_OBJECT
    // QML에서 FactGroup을 사용할 수 있도록 Qt 속성으로 등록
    // QML에서 _vehicle.tiltFl.valueString 이런 식으로 접근 가능
    // READ tiltFl 은 아래의 Fact* tiltFl() 함수와 연결
    Q_PROPERTY(Fact* tiltFl READ tiltFl CONSTANT)
    Q_PROPERTY(Fact* tiltFr READ tiltFr CONSTANT)
    Q_PROPERTY(Fact* tiltRl READ tiltRl CONSTANT)
    Q_PROPERTY(Fact* tiltRr READ tiltRr CONSTANT)

public:
    explicit CustomTiltAngleSetpointFactGroup(QObject* parent = nullptr);

    Fact* tiltFl() { return &_tiltFlFact; }
    Fact* tiltFr() { return &_tiltFrFact; }
    Fact* tiltRl() { return &_tiltRlFact; }
    Fact* tiltRr() { return &_tiltRrFact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, const mavlink_message_t& message) override;

protected:
    void _handleTiltAngleSetpoint(const mavlink_message_t& message);

    Fact _tiltFlFact;
    Fact _tiltFrFact;
    Fact _tiltRlFact;
    Fact _tiltRrFact;

private:
    void _updateTiltAngleSetpoint(float fl, float fr, float rl, float rr);
};

