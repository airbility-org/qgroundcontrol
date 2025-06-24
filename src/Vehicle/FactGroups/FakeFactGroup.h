#pragma once

#include "Fact.h"
#include "FactGroup.h"

class FakeFactGroup : public FactGroup {
    Q_OBJECT
    // Fact *dummyTiltFl : 정의하려는 속성의 타입과 이름
    // 이때 지정한 이름은 QML에서 해당 값에 접근할 때 사용
    // READ dummyTiltFl : 이 속성의 값을 읽을 때 호출될 Getter 함수 이름 지정
    Q_PROPERTY(Fact *dummyTiltFl READ dummyTiltFl CONSTANT)
    Q_PROPERTY(Fact *dummyTiltFr READ dummyTiltFr CONSTANT)
public:
    FakeFactGroup(QObject* parent = nullptr);

    Fact* dummyTiltFl() { return &_dummyTiltFl; }
    Fact* dummyTiltFr() { return &_dummyTiltFr; }

private:
    Fact _dummyTiltFl;
    Fact _dummyTiltFr;
};
