#pragma once

#include "FactGroup.h"

class Vehicle; // Vehicle 클래스는 전방 선언으로 처리합니다.

class CustomTiltStatusFactGroup : public FactGroup
{
    Q_OBJECT
public:
    explicit CustomTiltStatusFactGroup(QObject* parent = nullptr);

    void handleMessage(Vehicle* vehicle, const mavlink_message_t& message) override;

    // JSON 파일에 정의된 name("angleFl" 등)과 정확히 일치하는 Q_PROPERTY와 Getter
    Q_PROPERTY(Fact* angleFl READ angleFl CONSTANT)
    Q_PROPERTY(Fact* angleFr READ angleFr CONSTANT)
    Q_PROPERTY(Fact* angleRl READ angleRl CONSTANT)
    Q_PROPERTY(Fact* angleRr READ angleRr CONSTANT)
    Q_PROPERTY(Fact* angularVelFl READ angularVelFl CONSTANT)
    Q_PROPERTY(Fact* angularVelFr READ angularVelFr CONSTANT)
    Q_PROPERTY(Fact* angularVelRl READ angularVelRl CONSTANT)
    Q_PROPERTY(Fact* angularVelRr READ angularVelRr CONSTANT)
    Q_PROPERTY(Fact* voltageFl READ voltageFl CONSTANT)
    Q_PROPERTY(Fact* voltageFr READ voltageFr CONSTANT)
    Q_PROPERTY(Fact* voltageRl READ voltageRl CONSTANT)
    Q_PROPERTY(Fact* voltageRr READ voltageRr CONSTANT)
    Q_PROPERTY(Fact* currentFl READ currentFl CONSTANT)
    Q_PROPERTY(Fact* currentFr READ currentFr CONSTANT)
    Q_PROPERTY(Fact* currentRl READ currentRl CONSTANT)
    Q_PROPERTY(Fact* currentRr READ currentRr CONSTANT)
    Q_PROPERTY(Fact* tempFl READ tempFl CONSTANT)
    Q_PROPERTY(Fact* tempFr READ tempFr CONSTANT)
    Q_PROPERTY(Fact* tempRl READ tempRl CONSTANT)
    Q_PROPERTY(Fact* tempRr READ tempRr CONSTANT)

    Fact* angleFl()      { return &_facts[0]; }
    Fact* angleFr()      { return &_facts[1]; }
    Fact* angleRl()      { return &_facts[2]; }
    Fact* angleRr()      { return &_facts[3]; }
    Fact* angularVelFl() { return &_facts[4]; }
    Fact* angularVelFr() { return &_facts[5]; }
    Fact* angularVelRl() { return &_facts[6]; }
    Fact* angularVelRr() { return &_facts[7]; }
    Fact* voltageFl()    { return &_facts[8]; }
    Fact* voltageFr()    { return &_facts[9]; }
    Fact* voltageRl()    { return &_facts[10]; }
    Fact* voltageRr()    { return &_facts[11]; }
    Fact* currentFl()    { return &_facts[12]; }
    Fact* currentFr()    { return &_facts[13]; }
    Fact* currentRl()    { return &_facts[14]; }
    Fact* currentRr()    { return &_facts[15]; }
    Fact* tempFl()       { return &_facts[16]; }
    Fact* tempFr()       { return &_facts[17]; }
    Fact* tempRl()       { return &_facts[18]; }
    Fact* tempRr()       { return &_facts[19]; }

private:
    void _handleTiltStatus(const mavlink_message_t& message);

    static const int _count = 20; // JSON에 정의된 Fact의 총 개수
    Fact _facts[_count];
};