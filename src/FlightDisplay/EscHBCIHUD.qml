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

    Column {
        anchors.centerIn: parent
        spacing: 5

        Label { text: "ESC HBCI Monitor" ; color: "white"; font.bold: true }

        Label { text: "Voltage FL: " + (_activeVehicle ? _activeVehicle.escHBCI.voltageFl.valueString : "--") + " V"; color: "white" }
        Label { text: "Voltage FR: " + (_activeVehicle ? _activeVehicle.escHBCI.voltageFr.valueString : "--") + " V"; color: "white" }
        Label { text: "Voltage RL: " + (_activeVehicle ? _activeVehicle.escHBCI.voltageRl.valueString : "--") + " V"; color: "white" }
        Label { text: "Voltage RR: " + (_activeVehicle ? _activeVehicle.escHBCI.voltageRr.valueString : "--") + " V"; color: "white" }

        Label { text: "Current FL: " + (_activeVehicle ? _activeVehicle.escHBCI.currentFl.valueString : "--") + " A"; color: "white" }
        Label { text: "Current FR: " + (_activeVehicle ? _activeVehicle.escHBCI.currentFr.valueString : "--") + " A"; color: "white" }
        Label { text: "Current RL: " + (_activeVehicle ? _activeVehicle.escHBCI.currentRl.valueString : "--") + " A"; color: "white" }
        Label { text: "Current RR: " + (_activeVehicle ? _activeVehicle.escHBCI.currentRr.valueString : "--") + " A"; color: "white" }

        Label { text: "RPM FL: " + (_activeVehicle ? _activeVehicle.escHBCI.rpmFl.valueString : "--") + " RPM"; color: "white" }
        Label { text: "RPM FR: " + (_activeVehicle ? _activeVehicle.escHBCI.rpmFr.valueString : "--") + " RPM"; color: "white" }
        Label { text: "RPM RL: " + (_activeVehicle ? _activeVehicle.escHBCI.rpmRl.valueString : "--") + " RPM"; color: "white" }
        Label { text: "RPM RR: " + (_activeVehicle ? _activeVehicle.escHBCI.rpmRr.valueString : "--") + " RPM"; color: "white" }

        Label { text: "MotorTemp FL: " + (_activeVehicle ? _activeVehicle.escHBCI.motorTempFl.valueString : "--") + "°C"; color: "white" }
        Label { text: "MotorTemp FR: " + (_activeVehicle ? _activeVehicle.escHBCI.motorTempFr.valueString : "--") + "°C"; color: "white" }
        Label { text: "MotorTemp RL: " + (_activeVehicle ? _activeVehicle.escHBCI.motorTempRl.valueString : "--") + "°C"; color: "white" }
        Label { text: "MotorTemp RR: " + (_activeVehicle ? _activeVehicle.escHBCI.motorTempRr.valueString : "--") + "°C"; color: "white" }

        Label { text: "ESCTemp FL: " + (_activeVehicle ? _activeVehicle.escHBCI.escTempFl.valueString : "--") + "°C"; color: "white" }
        Label { text: "ESCTemp FR: " + (_activeVehicle ? _activeVehicle.escHBCI.escTempFr.valueString : "--") + "°C"; color: "white" }
        Label { text: "ESCTemp RL: " + (_activeVehicle ? _activeVehicle.escHBCI.escTempRl.valueString : "--") + "°C"; color: "white" }
        Label { text: "ESCTemp RR: " + (_activeVehicle ? _activeVehicle.escHBCI.escTempRr.valueString : "--") + "°C"; color: "white" }

        Label { text: "OutputPWM FL: " + (_activeVehicle ? _activeVehicle.escHBCI.outputPwmFl.valueString : "--") + " %"; color: "white" }
        Label { text: "OutputPWM FR: " + (_activeVehicle ? _activeVehicle.escHBCI.outputPwmFr.valueString : "--") + " %"; color: "white" }
        Label { text: "OutputPWM RL: " + (_activeVehicle ? _activeVehicle.escHBCI.outputPwmRl.valueString : "--") + " %"; color: "white" }
        Label { text: "OutputPWM RR: " + (_activeVehicle ? _activeVehicle.escHBCI.outputPwmRr.valueString : "--") + " %"; color: "white" }

        Label { text: "InputPWM FL: " + (_activeVehicle ? _activeVehicle.escHBCI.inputPwmFl.valueString : "--") + " %"; color: "white" }
        Label { text: "InputPWM FR: " + (_activeVehicle ? _activeVehicle.escHBCI.inputPwmFr.valueString : "--") + " %"; color: "white" }
        Label { text: "InputPWM RL: " + (_activeVehicle ? _activeVehicle.escHBCI.inputPwmRl.valueString : "--") + " %"; color: "white" }
        Label { text: "InputPWM RR: " + (_activeVehicle ? _activeVehicle.escHBCI.inputPwmRr.valueString : "--") + " %"; color: "white" }
    }
}
