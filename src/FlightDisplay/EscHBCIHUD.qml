import QtQuick
import QtQuick.Controls

import QGroundControl
import QGroundControl.Controls
import QGroundControl.FlightDisplay
import QGroundControl.Vehicle

Rectangle {
    width: 400
    height: 700
    color: "#222222"
    border.color: "#888888"
    border.width: 1
    radius: 8

    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle
    property var positions: ["Fl", "Fr", "Rl", "Rr"]

    Column {
        anchors.centerIn: parent
        spacing: 6

        Label {
            text: "ESC HBCI Monitor"
            color: "white"
            font.bold: true
        }

        Repeater {
            model: positions
            delegate: Column {
                spacing: 2

                Label { text: "Voltage " + modelData + ": " + (_activeVehicle ? _activeVehicle.escHBCI.voltage(modelData).valueString : "--") + " V"; color: "white" }
                Label { text: "Current " + modelData + ": " + (_activeVehicle ? _activeVehicle.escHBCI.current(modelData).valueString : "--") + " A"; color: "white" }
                Label { text: "RPM " + modelData + ": " + (_activeVehicle ? _activeVehicle.escHBCI.rpm(modelData).valueString : "--") + " RPM"; color: "white" }
                Label { text: "MotorTemp " + modelData + ": " + (_activeVehicle ? _activeVehicle.escHBCI.motorTemp(modelData).valueString : "--") + "°C"; color: "white" }
                Label { text: "ESCTemp " + modelData + ": " + (_activeVehicle ? _activeVehicle.escHBCI.escTemp(modelData).valueString : "--") + "°C"; color: "white" }
                Label { text: "OutputPWM " + modelData + ": " + (_activeVehicle ? _activeVehicle.escHBCI.outputPwm(modelData).valueString : "--") + " %"; color: "white" }
                Label { text: "InputPWM " + modelData + ": " + (_activeVehicle ? _activeVehicle.escHBCI.inputPwm(modelData).valueString : "--") + " %"; color: "white" }

                Rectangle {
                    width: parent.width
                    height: 1
                    color: "#555555"
                }
            }
        }
    }
}
