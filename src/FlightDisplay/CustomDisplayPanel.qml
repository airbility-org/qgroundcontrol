import QtQuick
import QtQuick.Controls
import QtQml.Models

import QGroundControl
import QGroundControl.ScreenTools
import QGroundControl.Controls
import QGroundControl.FlightDisplay
import QGroundControl.Vehicle

// 애플리케이션 시작 시 CustomDisplayPanel이 로드되면서 
// _activeVehicle에 현재 활성 차량 할당
// 이후 활성 Vehicle이 변경될 때마다 activeVehicleChanged 시그널 발생
// 이 시그널을 Connections에서 감지해 
Rectangle {
    width: 300
    height: 200
    color: "#1e1e1e"

    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    Component.onCompleted: {
        console.log("CustomDisplayPanel: _activeVehicle value:", _activeVehicle); // _activeVehicle 객체 자체를 출력

        if (_activeVehicle.fake) {
                console.log("CustomDisplayPanel: _activeVehicle.fake.dummyTiltFl:", _activeVehicle.fake.dummyTiltFl);
                console.log("CustomDisplayPanel: _activeVehicle.fake.dummyTiltFl.valueString:", _activeVehicle.fake.dummyTiltFl.valueString);
            } else {
                console.log("CustomDisplayPanel: _activeVehicle.fake is NULL/UNDEFINED.");
            }

        if (_activeVehicle.tiltAngle) {
                console.log("CustomDisplayPanel: _activeVehicle.tiltAngle.dummyTiltFl:", _activeVehicle.tiltAngle.tiltFl);
                console.log("CustomDisplayPanel: _activeVehicle.tiltAngle.dummyTiltFl.valueString:", _activeVehicle.tiltAngle.tiltFl.valueString);
            } else {
                console.log("CustomDisplayPanel: _activeVehicle.tiltAngle is NULL/UNDEFINED.");
            }
    }

    Column {
        anchors.centerIn: parent
        spacing: 10
        Label {
            text: _activeVehicle.
        }

        Label {
            text: "Dummy Tilt FL: " + (_activeVehicle ? _activeVehicle.fake.dummyTiltFl.valueString : "--")
            color: "white"
        }

        Label {
            text: "Dummy Tilt FR: " + (_activeVehicle ? _activeVehicle.fake.dummyTiltFr.valueString : "--")
            color: "white"
        }

        Label {
            text: "Tilt Fl: " + (_activeVehicle ? _activeVehicle.tiltAngle.tiltFl.valueString : "--")
            color: "white"
        }

        Label {
            text: "Tilt Fr: " + (_activeVehicle ? _activeVehicle.tiltAngle.tiltFl.valueString : "--")
            color: "white"
        }

        Label {
            text: "Tilt Rl: " + (_activeVehicle ? _activeVehicle.tiltAngle.tiltRl.valueString : "--")
            color: "white"
        }

        Label {
            text: "Tilt Rr: " + (_activeVehicle ? _activeVehicle.tiltAngle.tiltRr.valueString : "--")
            color: "white"
        }

        Button {
            text: "테스트 값 변경"
            onClicked: {
                if (_activeVehicle) {
                    _activeVehicle.fake.dummyTiltFl.value = Math.random() * 100
                    _activeVehicle.fake.dummyTiltFr.value = Math.random() * 100
                }
            }
        }
    }
}
