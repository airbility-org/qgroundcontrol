import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import Qt5Compat.GraphicalEffects
import QtQuick.Shapes

import QGroundControl
import QGroundControl.Controls
import QGroundControl.Palette
import QGroundControl.MultiVehicleManager
import QGroundControl.ScreenTools
import QGroundControl.Controllers

import "qrc:/custom/qml/FlightStatus"

Item {
    id: aircraftRoot
    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    function getColorByAngle(tiltAngle) {
        if(tiltAngle >= 100 || tiltAngle <= -100) {
            return "#E91D20"
        }
        return "white"
    }

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

    TiltAnimation {
        id: tiltFLAnimation
        width: fuselageImage.width * 0.1
        height: fuselageImage.width * 0.1
        anchors.top: fuselageImage.top
        anchors.left: fuselageImage.left
        anchors.topMargin: fuselageImage.height * 0.15
        anchors.leftMargin: fuselageImage.width * 0.3
        angle: _activeVehicle.tiltAngle.tiltFl.value
    }

    TiltAnimation {
        id: tiltFRAnimation
        width: fuselageImage.width * 0.1
        height: fuselageImage.width * 0.1
        anchors.top: fuselageImage.top
        anchors.right: fuselageImage.right
        anchors.topMargin: fuselageImage.height * 0.15
        anchors.rightMargin: fuselageImage.width * 0.3
        angle: _activeVehicle.tiltAngle.tiltFr.value
    }

    TiltAnimation {
        id: tiltRLAnimation
        width: fuselageImage.width * 0.1
        height: fuselageImage.width * 0.1
        anchors.bottom: fuselageImage.bottom
        anchors.left: fuselageImage.left
        anchors.bottomMargin: fuselageImage.height * 0.25
        anchors.leftMargin: fuselageImage.width * 0.3
        angle: _activeVehicle.tiltAngle.tiltRl.value > 90 ? 90 : _activeVehicle.tiltAngle.tiltRl.value
    }

    TiltAnimation {
        id: tiltRRAnimation
        width: fuselageImage.width * 0.1
        height: fuselageImage.width * 0.1
        anchors.bottom: fuselageImage.bottom
        anchors.right: fuselageImage.right
        anchors.bottomMargin: fuselageImage.height * 0.25
        anchors.rightMargin: fuselageImage.width * 0.3
        angle: _activeVehicle.tiltAngle.tiltRr.value
    }

    Label {
        id: tiltFLValue
        text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFl.value.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: 30
        anchors.top: tiltFLAnimation.top
        anchors.right: tiltFLAnimation.left
        // anchors.right: tiltFLOverLay.left
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 3
        color: aircraftRoot.getColorByAngle(_activeVehicle.tiltAngle.tiltFl.value)
    }

    Label {
        id: tiltFRValue
        text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: 30
        anchors.top: tiltFRAnimation.top
        anchors.left: tiltFRAnimation.right
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 3
        color: aircraftRoot.getColorByAngle(_activeVehicle.tiltAngle.tiltFr.value)
    }

    Label {
        id: tiltRLValue
        text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltRl.value.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: 30
        anchors.top: tiltRLAnimation.top
        anchors.right: tiltRLAnimation.left
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 3
        color: aircraftRoot.getColorByAngle(_activeVehicle.tiltAngle.tiltRl.value)
    }

    Label {
        id: tiltRRValue
        text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltRr.value.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: 30
        anchors.top: tiltRRAnimation.top
        anchors.left: tiltRRAnimation.right
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 3
        color: aircraftRoot.getColorByAngle(_activeVehicle.tiltAngle.tiltRr.value)
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

