import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import Qt5Compat.GraphicalEffects

import QGroundControl
import QGroundControl.Controls
import QGroundControl.Palette
import QGroundControl.MultiVehicleManager
import QGroundControl.ScreenTools
import QGroundControl.Controllers

Item {
    id: aircraftRoot
    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    function getTiltImageSource(tiltAngle) {
        if(tiltAngle < 10) {
            return "qrc:/custom/img/vehicle/tilt_0.svg"
        } else if (tiltAngle < 45) {
            return "qrc:/custom/img/vehicle/tilt_30.svg"
        } else if (tiltAngle < 80) {
            return "qrc:/custom/img/vehicle/tilt_60.svg"
        } else {
            return "qrc:/custom/img/vehicle/tilt_90.svg"
        }
    }

    function isAngleOutlier(tiltAngle) {
        if(tiltAngle > 95) {
            return true
        }
        return false
    }

/** Helper
    Rectangle {
        width: fuselageImage.paintedWidth
        height: fuselageImage.paintedHeight
        anchors.centerIn: fuselageImage
        color: "transparent"
        border.color: "red"
    }

    Rectangle {
        width: fuselageImage.width
        height: fuselageImage.height
        anchors.centerIn: fuselageImage
        color: "transparent"
        border.color: "blue"
    }

**/

    Image {
        id: fuselageImage
        source: "qrc:/custom/img/vehicle/vehicle_graphic.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: aileronLImage
        source: "qrc:/custom/img/vehicle/aileron_l.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        ColorOverlay {
            anchors.fill: parent
            source: aileronLImage
            color: "#ACACAC"
        }
    }

    Image {
        id: aileronRImage
        source: "qrc:/custom/img/vehicle/aileron_r.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        ColorOverlay {
            anchors.fill: parent
            source: aileronRImage
            color: "#ACACAC"
        }
    }

    Image {
        id: rudderLImage
        source: "qrc:/custom/img/vehicle/rudder_l.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        ColorOverlay {
            anchors.fill: parent
            source: rudderLImage
            color: "#ACACAC"
        }
    }

    Image {
        id: rudderRImage
        source: "qrc:/custom/img/vehicle/rudder_r.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        ColorOverlay {
            anchors.fill: parent
            source: rudderRImage
            color: "#ACACAC"
        }
    }

    Image {
        id: tiltFLOverLay
        source: aircraftRoot.getTiltImageSource(_activeVehicle.vehicle.heading.value)
        // source: aircraftRoot.getTiltImageSource(_activeVehicle.tiltAngle.tiltFl.value)
        width: fuselageImage.width * 0.1
        height: fuselageImage.width * 0.1
        anchors.top: fuselageImage.top
        anchors.left: fuselageImage.left
        anchors.topMargin: fuselageImage.height * 0.15
        anchors.leftMargin: fuselageImage.width * 0.3
    }

    Image {
        id: tiltFROverLay
        source: aircraftRoot.getTiltImageSource(_activeVehicle.vehicle.heading.value)
        width: fuselageImage.width * 0.1
        height: fuselageImage.width * 0.1
        anchors.top: fuselageImage.top
        anchors.right: fuselageImage.right
        anchors.topMargin: fuselageImage.height * 0.15
        anchors.rightMargin: fuselageImage.width * 0.3
    }

    Image {
        id: tiltRLOverLay
        source: aircraftRoot.getTiltImageSource(_activeVehicle.vehicle.heading.value)
        width: fuselageImage.width * 0.1
        height: fuselageImage.width * 0.1
        anchors.bottom: fuselageImage.bottom
        anchors.left: fuselageImage.left
        anchors.bottomMargin: fuselageImage.height * 0.25
        anchors.leftMargin: fuselageImage.width * 0.3
    }

    Image {
        id: tiltRROverLay
        source: aircraftRoot.getTiltImageSource(_activeVehicle.vehicle.heading.value)
        width: fuselageImage.width * 0.1
        height: fuselageImage.width * 0.1
        anchors.bottom: fuselageImage.bottom
        anchors.right: fuselageImage.right
        anchors.bottomMargin: fuselageImage.height * 0.25
        anchors.rightMargin: fuselageImage.width * 0.3
    }
    

    Label {
        id: tiltFLValue
        // text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFl.value.toFixed(2) : "--") + " º"
        text: (_activeVehicle ? _activeVehicle.vehicle.heading.value.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: 30
        anchors.top: tiltFLOverLay.top
        anchors.right: tiltFLOverLay.left
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 3
        color: {
            if(isAngleOutlier(_activeVehicle.tiltAngle.tiltFl.value)) {
                "#E91D20"
            } else {
                "white"
            }
        }
    }

    Label {
        id: tiltFRValue
        // text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
        text: (_activeVehicle ? _activeVehicle.vehicle.heading.value.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: 30
        anchors.top: tiltFROverLay.top
        anchors.left: tiltFROverLay.right
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 3
        color: {
            if(isAngleOutlier(_activeVehicle.tiltAngle.tiltFl.value)) {
                "#E91D20"
            } else {
                "white"
            }
        }
    }

    Label {
        id: tiltRLValue
        // text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltRl.value.toFixed(2) : "--") + " º"
        text: (_activeVehicle ? _activeVehicle.vehicle.heading.value.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: 30
        anchors.top: tiltRLOverLay.top
        anchors.right: tiltRLOverLay.left
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 3
        color: {
            if(isAngleOutlier(_activeVehicle.tiltAngle.tiltFl.value)) {
                "#E91D20"
            } else {
                "white"
            }
        }
    }

    Label {
        id: tiltRRValue
        // text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltRr.value.toFixed(2) : "--") + " º"
        text: (_activeVehicle ? _activeVehicle.vehicle.heading.value.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: 30
        anchors.top: tiltRROverLay.top
        anchors.left: tiltRROverLay.right
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 3
        color: {
            if(isAngleOutlier(_activeVehicle.tiltAngle.tiltFl.value)) {
                "#E91D20"
            } else {
                "white"
            }
        }
    }

    Item {
        id: aileronL
        anchors.top: fuselageImage.top
        anchors.topMargin: fuselageImage.height * 0.4
        x: aileronLImage.x + (aileronLImage.width - aileronLImage.paintedWidth) / 2 - ScreenTools.defaultFontPixelWidth * 3 - aileronLLabel.width

        ColumnLayout {
            Label {
                id: aileronLLabel
                text: "L - Aileron"
                font.family: "Pretendard"
                font.pointSize: 15
                color: "white"
            }

            Label {
                id: aileronLValue
                text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFl.value.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: 15
                color: "white"
            }
        }
    }

    Item {
        id: aileronR
        anchors.top: fuselageImage.top
        anchors.topMargin: fuselageImage.height * 0.4
        x: aileronRImage.x + (aileronRImage.width + aileronRImage.paintedWidth) / 2 + ScreenTools.defaultFontPixelWidth * 3

        ColumnLayout {
            Label {
                id: aileronRLabel
                text: "R - Aileron"
                font.family: "Pretendard"
                font.pointSize: 15
                color: "white"
            }

            Label {
                id: aileronRValue
                text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: 15
                color: "white"
            }
        }
    }

    Item {
        id: rudderL
        x: (parent.width / 2) - fuselageImage.paintedWidth * (156.24 / 849.74) - rudderLLabel.width - ScreenTools.defaultFontPixelWidth * 3
        y: (parent.height / 2) + (fuselageImage.paintedHeight / 2) - ScreenTools.defaultFontPixelHeight * 2

        ColumnLayout {
            Label {
                id: rudderLLabel
                text: "L - Rudder"
                font.family: "Pretendard"
                font.pointSize: 15
                color: "white"
            }

            Label {
                id: rudderLValue
                text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: 15
                color: "white"
            }
        }
    }

    Item {
        id: rudderR
        x: (parent.width / 2) + fuselageImage.paintedWidth * (156.24 / 849.74) + ScreenTools.defaultFontPixelWidth * 3
        y: (parent.height / 2) + (fuselageImage.paintedHeight / 2) - ScreenTools.defaultFontPixelHeight * 2

        ColumnLayout {
            id: rudderLayout

            Label {
                id: rudderRLabel
                text: "R - Rudder"
                font.family: "Pretendard"
                font.pointSize: 15
                color: "white"
            }

            Label {
                id: rudderRValue
                text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: 15
                color: "white"
            }
        }
    }
}
