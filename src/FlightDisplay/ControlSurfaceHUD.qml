import QtQuick
import QtQuick.Controls

import QGroundControl
import QGroundControl.Controls
import QGroundControl.FlightDisplay
import QGroundControl.Vehicle

Rectangle {
    width: 300
    height: 200
    color: "#333333"

    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    Column {
        anchors.centerIn: parent
        spacing: 10

        Label {
            text: "Left Aileron: " + (_activeVehicle ? _activeVehicle.controlSurfaceCmd.leftAileron.valueString : "--") + " deg"
            color: "white"
        }
        Label {
            text: "Right Aileron: " + (_activeVehicle ? _activeVehicle.controlSurfaceCmd.rightAileron.valueString : "--") + " deg"
            color: "white"
        }
        Label {
            text: "Left Ruddervator: " + (_activeVehicle ? _activeVehicle.controlSurfaceCmd.leftRuddervator.valueString : "--") + " deg"
            color: "white"
        }
        Label {
            text: "Right Ruddervator: " + (_activeVehicle ? _activeVehicle.controlSurfaceCmd.rightRuddervator.valueString : "--") + " deg"
            color: "white"
        }
    }
}
