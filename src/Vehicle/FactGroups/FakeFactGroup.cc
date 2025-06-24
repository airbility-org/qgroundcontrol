#include "FakeFactGroup.h"

FakeFactGroup::FakeFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/FakeFactGroup.json", parent)
    // 생성자에서 JSON 파일 파싱 후 각 팩트에 대한 FactMetaData 생성
    // _addFact 함수를 호출해 실제 Fact 인스턴스를 해당 메타데이터와 연결하고 
    // 그룹에 추가
{
    _addFact(&_dummyTiltFl, "dummyTiltFl");
    _addFact(&_dummyTiltFr, "dummyTiltFr");

    _dummyTiltFl.setRawValue(42.5); // 가짜 데이터
    _dummyTiltFr.setRawValue(20.4); // 가짜 데이터
}
