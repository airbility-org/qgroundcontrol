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

    
    property real actualImageVerticalOffset: (fuselageImage.height - fuselageImage.paintedHeight) / 2
    property real actualImageHorizontalOffset: (fuselageImage.width - fuselageImage.paintedWidth) / 2

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
        width: fuselageImage.paintedWidth * 0.15
        height: fuselageImage.paintedWidth * 0.15
        anchors.top: fuselageImage.top
        anchors.left: fuselageImage.left
        anchors.topMargin: actualImageVerticalOffset + fuselageImage.paintedHeight * 0.1
        anchors.leftMargin: actualImageHorizontalOffset + fuselageImage.paintedWidth * 0.2
        angle: _activeVehicle.vehicle.heading.value
        //angle: _activeVehicle.tiltAngle.tiltFl.value > 90 ? 90 : _activeVehicle.tiltAngle.tiltFl.value
    }

    TiltAnimation {
        id: tiltFRAnimation
        width: fuselageImage.paintedWidth * 0.15
        height: fuselageImage.paintedWidth * 0.15
        anchors.top: fuselageImage.top
        anchors.right: fuselageImage.right
        anchors.topMargin: actualImageVerticalOffset + fuselageImage.paintedHeight * 0.1
        anchors.rightMargin: actualImageHorizontalOffset + fuselageImage.paintedWidth * 0.2
        angle: _activeVehicle.vehicle.heading.value
        //angle: _activeVehicle.tiltAngle.tiltFr.value > 90 ? 90 : _activeVehicle.tiltAngle.tiltFr.value
    }

    TiltAnimation {
        id: tiltRLAnimation
        width: fuselageImage.paintedWidth * 0.15
        height: fuselageImage.paintedWidth * 0.15
        anchors.bottom: fuselageImage.bottom
        anchors.left: fuselageImage.left
        anchors.bottomMargin: actualImageVerticalOffset + fuselageImage.paintedHeight * 0.2
        anchors.leftMargin: actualImageHorizontalOffset + fuselageImage.paintedWidth * 0.2
        angle: _activeVehicle.vehicle.heading.value
        //angle: _activeVehicle.tiltAngle.tiltRl.value > 90 ? 90 : _activeVehicle.tiltAngle.tiltRl.value
    }

    TiltAnimation {
        id: tiltRRAnimation
        width: fuselageImage.paintedWidth * 0.15
        height: fuselageImage.paintedWidth * 0.15
        anchors.bottom: fuselageImage.bottom
        anchors.right: fuselageImage.right
        anchors.bottomMargin: actualImageVerticalOffset + fuselageImage.paintedHeight * 0.2
        anchors.rightMargin: actualImageHorizontalOffset + fuselageImage.paintedWidth * 0.2
        angle: _activeVehicle.vehicle.heading.value
        //angle: _activeVehicle.tiltAngle.tiltRr.value > 90 ? 90 : _activeVehicle.tiltAngle.tiltRr.value
    }

    Label {
        id: tiltFLValue
        //text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFl.value.toFixed(2) : "--") + " º"
        text: (_activeVehicle ? _activeVehicle.vehicle.heading.value.toFixed(2) : "--") + " º"
        //text: (_activeVehicle ? tiltFLAnimation.angle.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: customScreenTools.fontSize4
        anchors.top: tiltFLAnimation.top
        anchors.right: tiltFLAnimation.left
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 3
        color: getColorByAngle(_activeVehicle.vehicle.heading.value)
    }

    Label {
        id: tiltFRValue
        //text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
        text: (_activeVehicle ? _activeVehicle.vehicle.heading.value.toFixed(2) : "--") + " º"
        //text: (_activeVehicle ? tiltFLAnimation.angle.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: customScreenTools.fontSize4
        anchors.top: tiltFRAnimation.top
        anchors.left: tiltFRAnimation.right
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 3
        color: getColorByAngle(_activeVehicle.vehicle.heading.value)
    }

    Label {
        id: tiltRLValue
        //text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltRl.value.toFixed(2) : "--") + " º"
        text: (_activeVehicle ? _activeVehicle.vehicle.heading.value.toFixed(2) : "--") + " º"
        //text: (_activeVehicle ? tiltFLAnimation.angle.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: customScreenTools.fontSize4
        anchors.top: tiltRLAnimation.top
        anchors.right: tiltRLAnimation.left
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 3
        color: getColorByAngle(_activeVehicle.vehicle.heading.value)
    }

    Label {
        id: tiltRRValue
        //text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltRr.value.toFixed(2) : "--") + " º"
        text: (_activeVehicle ? _activeVehicle.vehicle.heading.value.toFixed(2) : "--") + " º"
        //text: (_activeVehicle ? tiltFLAnimation.angle.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: customScreenTools.fontSize4
        anchors.top: tiltRRAnimation.top
        anchors.left: tiltRRAnimation.right
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 3
        color: getColorByAngle(_activeVehicle.vehicle.heading.value)
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
                font.pointSize: customScreenTools.fontSize2
                color: "white"
            }

            Label {
                id: aileronLValue
                text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFl.value.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize3
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
                font.pointSize: customScreenTools.fontSize2
                color: "white"
            }

            Label {
                id: aileronRValue
                text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize3
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
                font.pointSize: customScreenTools.fontSize2
                color: "white"
            }

            Label {
                id: rudderLValue
                text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize3
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
                font.pointSize: customScreenTools.fontSize2
                color: "white"
            }

            Label {
                id: rudderRValue
                text: (_activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize3
                color: "white"
            }
        }
    }
}
