#pragma once
#include "FactGroup.h"

class ControlSurfaceCmdFactGroup : public FactGroup
{
    Q_OBJECT
    // QML에서 vehicle.controlSurfaceCmd.leftAileron.valueString 식으로 사용
    Q_PROPERTY(Fact* leftAileron READ leftAileron CONSTANT)
    Q_PROPERTY(Fact* rightAileron READ rightAileron CONSTANT)
    Q_PROPERTY(Fact* leftRuddervator READ leftRuddervator CONSTANT)
    Q_PROPERTY(Fact* rightRuddervator READ rightRuddervator CONSTANT)

public:
    explicit ControlSurfaceCmdFactGroup(QObject* parent = nullptr);

    // 각 Fact를 반환하는 Getter 함수들
    Fact* leftAileron() { return &_leftAileronFact; }
    Fact* rightAileron() { return &_rightAileronFact; }
    Fact* leftRuddervator() { return &_leftRuddervatorFact; }
    Fact* rightRuddervator() { return &_rightRuddervatorFact; }

    // MAVLink 메시지 수신시 호출 (오버라이드)
    void handleMessage(Vehicle* vehicle, const mavlink_message_t& message) override;

protected:
    void _handleControlSurfaceCmd(const mavlink_message_t& message);

    // 각 변수에 실제 값을 저장
    Fact _leftAileronFact;
    Fact _rightAileronFact;
    Fact _leftRuddervatorFact;
    Fact _rightRuddervatorFact;

private:
    void _updateControlSurfaceCmd(float leftAil, float rightAil, float leftRud, float rightRud);
};
