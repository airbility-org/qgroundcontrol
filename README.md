# QGroundControl — 에어빌리티 내부 커스터마이징 버전

본 저장소는 [mavlink/qgroundcontrol](https://github.com/mavlink/qgroundcontrol) 오픈소스 GCS를 에어빌리티 내부 프로젝트의 운용 요구사항에 맞춰 커스터마이징한 포크입니다. 업스트림 코드 베이스 위에 자체 MAVLink 메시지를 처리하는 FactGroup, HUD/계기판 UI 보강, 그리고 자체 MAVLink 다이얼렉트(c_library_v2 fork) 적용이 추가되어 있습니다.

> 업스트림 QGC의 일반적인 사용/빌드 방법은 본 문서 아래쪽 원본 README를 참고하시면 됩니다. 이 섹션은 **에어빌리티가 직접 수정한 부분**만 정리한 문서입니다.

---

## 변경 요약

| 카테고리 | 변경 내용 | 주요 파일 |
| --- | --- | --- |
| MAVLink 다이얼렉트 | 업스트림 `mavlink/c_library_v2` → `airbility-org/c_library_v2` fork 사용 (자체 메시지 정의 포함) | `cmake/CustomOptions.cmake` |
| 텔레메트리 모델 | 자체 MAVLink 메시지를 위한 4개 FactGroup 신규 추가 및 `Vehicle`에 등록 | `src/Vehicle/FactGroups/`, `src/Vehicle/Vehicle.{h,cc}` |
| HUD / 계기판 | `decimalPlaces` 메타데이터 적용으로 소수점 자릿수 포매팅, 커스텀 디스플레이 패널(QML) 추가 | `src/QmlControls/InstrumentValueValue.qml`, `src/FlightDisplay/CustomDisplayPanel.qml` |
| 코드 가독성 | Vehicle/FlightDisplay/QmlControls 전반에 한국어 주석 보강 | `src/API/QGCCorePlugin.cc`, `src/QGCApplication.cc`, `src/UI/MainRootWindow.qml` 등 |

---

## 1. MAVLink fork 적용

자체 MAVLink 메시지(`TILT_STATUS`, `TILT_ANGLE_SETPOINT`, `CONTROL_SURFACE_CMD` 등)를 사용하기 위해 업스트림 c_library_v2 대신 회사 fork를 가져오도록 `cmake/CustomOptions.cmake`를 수정했습니다.

```cmake
set(QGC_MAVLINK_GIT_REPO "https://github.com/airbility-org/c_library_v2.git" CACHE STRING "URL to MAVLink Git Repo")
set(QGC_MAVLINK_GIT_TAG  "f1386175cb6367c6b9e917916686a636ec58cda8" CACHE STRING "Tag of MAVLink Git Repo")
```

CMake configure 시점에 위 fork가 자동으로 fetch되므로, 빌드 환경에서 별도의 mavlink 저장소 클론은 필요하지 않습니다. 자체 메시지를 추가/수정할 때는 fork 저장소에서 변경한 뒤 `QGC_MAVLINK_GIT_TAG` 값을 갱신하면 됩니다.

---

## 2. 신규 FactGroup

기체에서 송신하는 자체 MAVLink 메시지를 QML에서 `vehicle.<group>.<fact>` 형태로 바인딩할 수 있도록 4개의 FactGroup을 추가하고 `Vehicle` 클래스에 등록했습니다 (`src/Vehicle/Vehicle.cc`, `Vehicle.h`).

| FactGroup | QML 바인딩 | 처리 메시지 | 용도 |
| --- | --- | --- | --- |
| `CustomTiltStatusFactGroup` | `vehicle.tiltStatus.*` | `TILT_STATUS` | 4축 틸트로터(FL/FR/RL/RR)별 현재 각도, 각속도, 전압, 전류, 온도 (총 20개 Fact) |
| `CustomTiltAngleSetpointFactGroup` | `vehicle.tiltAngleSetpoint.*` | `TILT_ANGLE_SETPOINT` | 4축 틸트로터별 명령 각도 (`tiltFl/Fr/Rl/Rr`, 소수점 2자리 표시) |
| `ControlSurfaceCmdFactGroup` | `vehicle.controlSurfaceCmd.*` | `CONTROL_SURFACE_CMD` | 에일러론(좌/우), 러더베이터(좌/우) 명령각 |
| `FakeFactGroup` *(개발 전용)* | `vehicle.fake.*` | — | 더미값을 그대로 노출하는 테스트용 그룹. 실제 운용 빌드에서는 사용하지 않습니다. |

각 FactGroup은 `src/Vehicle/FactGroups/<Name>FactGroup.{h,cc,json}` 형태로 구성되어 있으며, JSON에는 Fact 이름·타입·단위·표시 자릿수가 정의되어 있습니다. 신규 메시지를 추가하려는 경우 기존 4개 FactGroup의 패턴을 참고하시면 됩니다.

---

## 3. UI / HUD 변경

- **`InstrumentValueValue.qml`**: Fact 메타데이터의 `decimalPlaces` 값이 지정되어 있으면 `Number.toFixed()`로 자릿수를 맞춰 표시하도록 변경 (예: 틸트 각도 → 소수점 2자리). 업스트림은 자릿수 포매팅 없이 `enumOrValueString`을 그대로 출력합니다.
- **`CustomDisplayPanel.qml`** (`src/FlightDisplay/`): 위 FactGroup 값들을 화면에 띄워 동작을 확인하기 위한 테스트용 패널입니다. `QGroundControl/FlightDisplay` 모듈(`qmldir`) 및 `qgroundcontrol.qrc`에 등록되어 있으며, 현재는 디버그용으로 `FlyViewWidgetLayer.qml`에서 인스턴스화는 잠시 비활성화되어 있습니다(필요 시 활성화하여 검증).
- **한국어 주석 보강**: `FlyView.qml`, `FlyViewInstrumentPanel.qml`, `FlyViewWidgetLayer.qml`, `TelemetryValuesBar.qml`, `IntegratedCompassAttitude.qml`, `MainRootWindow.qml`, `HorizontalFactValueGrid.qml`, `InstrumentValueEditDialog.qml`, `FactValueGrid.{h,cc}`, `InstrumentValueData.{h,cc}`, `QGCCorePlugin.cc`, `QGCApplication.cc` 등에 구조 설명 주석을 추가하여 신규 인입자가 코드 흐름을 빠르게 파악할 수 있도록 했습니다.

---

## 4. 빌드 / 실행

기본 빌드 절차는 업스트림 QGC와 동일합니다. 공식 가이드는 [QGC Developer Guide](https://dev.qgroundcontrol.com/en/getting_started/)를 참고하세요.

추가로 본 포크에서 알아두어야 할 점:

1. CMake configure 시 `cmake/CustomOptions.cmake`에 지정된 **`airbility-org/c_library_v2`** fork가 자동으로 다운로드됩니다 — 별도의 사전 작업이 필요 없습니다.
2. MAVLink 메시지 정의를 변경했다면 fork 저장소를 갱신한 뒤 `QGC_MAVLINK_GIT_TAG` 값을 새 커밋 해시로 업데이트하고 다시 configure하면 됩니다.
3. 자체 추가한 FactGroup 디버깅이 필요할 때는 `vehicle.tiltStatus.angleFl.value` 처럼 QML 콘솔에서 직접 바인딩 값을 찍어볼 수 있습니다 (`CustomDisplayPanel.qml`이 좋은 예시입니다).

---

## 5. 디렉터리 변경 요약

```
cmake/CustomOptions.cmake            # MAVLink fork 지정
qgroundcontrol.qrc                   # 신규 JSON / QML 리소스 등록
src/Vehicle/Vehicle.{h,cc}           # 신규 FactGroup 멤버 등록 + Q_PROPERTY 노출
src/Vehicle/FactGroups/
    CustomTiltStatusFactGroup.*           # 신규
    CustomTiltAngleSetpointFactGroup.*    # 신규
    ControlSurfaceCmdFactGroup.*          # 신규
    FakeFactGroup.*                       # 신규 (개발 전용)
    CMakeLists.txt                        # 위 4개 FactGroup 빌드 등록
src/FlightDisplay/CustomDisplayPanel.qml  # 신규 테스트 패널
src/QmlControls/QGroundControl/FlightDisplay/qmldir  # CustomDisplayPanel 등록
src/QmlControls/InstrumentValueValue.qml  # decimalPlaces 포매팅
```

---

<br>

# 원본 QGroundControl README

<p align="center">
  <img src="https://raw.githubusercontent.com/Dronecode/UX-Design/35d8148a8a0559cd4bcf50bfa2c94614983cce91/QGC/Branding/Deliverables/QGC_RGB_Logo_Horizontal_Positive_PREFERRED/QGC_RGB_Logo_Horizontal_Positive_PREFERRED.svg" alt="QGroundControl Logo" width="500">
</p>

<p align="center">
  <a href="https://github.com/mavlink/QGroundControl/releases">
    <img src="https://img.shields.io/github/release/mavlink/QGroundControl.svg" alt="Latest Release">
  </a>
</p>

*QGroundControl* (QGC) is a highly intuitive and powerful Ground Control Station (GCS) designed for UAVs. Whether you're a first-time pilot or an experienced professional, QGC provides a seamless user experience for flight control and mission planning, making it the go-to solution for any *MAVLink-enabled drone*.

---

### 🌟 *Why Choose QGroundControl?*

- *🚀 Ease of Use*: A beginner-friendly interface designed for smooth operation without sacrificing advanced features for pros.
- *✈️ Comprehensive Flight Control*: Full flight control and mission management for *PX4* and *ArduPilot* powered UAVs.
- *🛠️ Mission Planning*: Easily plan complex missions with a simple drag-and-drop interface.

🔍 For a deeper dive into using QGC, check out the [User Manual](https://docs.qgroundcontrol.com/en/) – although, thanks to QGC's intuitive UI, you may not even need it!


---

### 🚁 *Key Features*

- 🕹️ *Full Flight Control*: Supports all *MAVLink drones*.
- ⚙️ *Vehicle Setup*: Tailored configuration for *PX4* and *ArduPilot* platforms.
- 🔧 *Fully Open Source*: Customize and extend the software to suit your needs.

🎯 Check out the latest updates in our [New Features and Release Notes](https://github.com/mavlink/qgroundcontrol/blob/master/ChangeLog.md).

---

### 💻 *Get Involved!*

QGroundControl is *open-source*, meaning you have the power to shape it! Whether you're fixing bugs, adding features, or customizing for your specific needs, QGC welcomes contributions from the community.

🛠️ Start building today with our [Developer Guide](https://dev.qgroundcontrol.com/en/) and [build instructions](https://dev.qgroundcontrol.com/en/getting_started/).

---

### 🔗 *Useful Links*

- 🌐 [Official Website](http://qgroundcontrol.com)
- 📘 [User Manual](https://docs.qgroundcontrol.com/en/)
- 🛠️ [Developer Guide](https://dev.qgroundcontrol.com/en/)
- 💬 [Discussion & Support](https://docs.qgroundcontrol.com/en/Support/Support.html)
- 🤝 [Contributing](https://dev.qgroundcontrol.com/en/contribute/)
- 📜 [License Information](https://github.com/mavlink/qgroundcontrol/blob/master/.github/COPYING.md)

---

With QGroundControl, you're in full command of your UAV, ready to take your missions to the next level.
