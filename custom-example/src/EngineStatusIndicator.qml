import QtQuick
import QtQuick.Layouts

import QGroundControl
import QGroundControl.Controls
import QGroundControl.MultiVehicleManager
import QGroundControl.ScreenTools
import QGroundControl.Palette
import QGroundControl.FactSystem
import QGroundControl.FactControls
import QGroundControl.AutoPilotPlugin
import MAVLink

RowLayout {
    spacing: 0

    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle
    property bool showIndicator: true

    function getEngineStatusText() {
        if(_activeVehicle) {
            if(_communicationLost) {
                return engineStatusText._commLostText
            }
            if (_activeVehicle.engineStatus <= 60) {
                return engineStatusText._engineArm
            } else {
                return engineStatusText._engineStart
            }
        }
    }

    function getEngineStatusImage() {
        if(_activeVehicle) {
            if(_communicationLost) {
                return "qrc:/custom/img/warning.png"
            }
            if (_activeVehicle.engineStatus <= 60) {
                return "qrc:/custom/img/armed.png"
            } else {
                return "qrc:/custom/img/running.png"
            }
        }
    }

    RowLayout {
        id: engineStatusIndicatorRow
        Layout.fillWidth: true

        Image {
            width:  ScreenTools.defaultFontPixelHeight * 1.3
            height: ScreenTools.defaultFontPixelHeight * 1.3
            fillMode:           Image.PreserveAspectFit
            mipmap: true
            source:             getEngineStatusImage()
            sourceSize.width: width
            sourceSize.height: height
            Component.onCompleted: {
                console.log("Image source:", source);
            }
        }

        ColumnLayout {
            id:                     engineStatusText
            anchors.top:            parent.top
            anchors.bottom:         parent.bottom
            spacing:                0

            property string _commLostText: "Engine unavailable"
            property string _engineArm: "Engine Armed"
            property string _engineStart: "Engine Start"
            property string _default: "Engine ready" 

            QGCLabel {
                Layout.alignment:       Qt.AlignHCenter
                verticalAlignment:      Text.AlignVCenter
                color:                  qgcPal.text
                text:                   getEngineStatusText()
                font.pointSize:         ScreenTools.mediumFontPointSize
            }
        }
    }
}