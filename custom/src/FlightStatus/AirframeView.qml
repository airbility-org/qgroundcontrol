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

    // temp value for test
    property var tiltFLAngle: _activeVehicle ? _activeVehicle.vehicle.heading.value : null
    property var tiltFRAngle: _activeVehicle ? _activeVehicle.vehicle.heading.value : null
    property var tiltRLAngle: _activeVehicle ? _activeVehicle.vehicle.heading.value : null
    property var tiltRRAngle: _activeVehicle ? _activeVehicle.vehicle.heading.value : null

    property var aileronLAngle: _activeVehicle ? _activeVehicle.vehicle.heading.value : null
    property var aileronRAngle: _activeVehicle ? _activeVehicle.vehicle.heading.value : null
    property var rudderLAngle: _activeVehicle ? _activeVehicle.vehicle.heading.value : null
    property var rudderRAngle: _activeVehicle ? _activeVehicle.vehicle.heading.value : null

    //property var tiltFLAngle: _activeVehicle ? _activeVehicle.tiltAngle.tiltFl.value : null
    //property var tiltFRAngle: _activeVehicle ? _activeVehicle.tiltAngle.tiltFr.value : null
    //property var tiltRLAngle: _activeVehicle ? _activeVehicle.tiltAngle.tiltRl.value : null
    //property var tiltRRAngle: _activeVehicle ? _activeVehicle.tiltAngle.tiltRr.value : null

    property var maxLightness: 0.7
    property var minLightness: 0.3

    function getColorByTiltAngle(tiltAngle) {
        // temp value for test
        if(tiltAngle >= 100 || tiltAngle <= -100) {
            return customPal.warnColor
        }
        return qgcPal.text
    }

    function isAileronAngleOutlier(aileronAngle) {
        // temp value for test
        if(aileronAngle > 300) {
            return true
        } 
        return false
    }

    function isRudderAngleOutlier(rudderAngle) {
        // temp value for test
        if(rudderAngle > 300) {
            return true
        } 
        return false
    }
 
    Image {
        id: fuselageImage
        source: "qrc:/custom/img/vehicle/vehicle_graphic.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        ColorOverlay {
            anchors.fill: parent
            source: fuselageImage
            color: qgcPal.globalTheme === QGCPalette.Light ? "#D7D7D7" : "#5A5A5A"
        }
    }

    property real actualImageVerticalOffset: (fuselageImage.height - fuselageImage.paintedHeight) / 2
    property real actualImageHorizontalOffset: (fuselageImage.width - fuselageImage.paintedWidth) / 2

    Image {
        id: aileronLImage
        source: "qrc:/custom/img/vehicle/aileron_l.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        // Temp Range: 0 ~ 60, Real Range: -30 ~ 30
        property var adjustedAileronLAngle: aileronLAngle <= 60 ? aileronLAngle : 60
        readonly property real progress: adjustedAileronLAngle / 60
        //readonly property real progress: (adjustedAileronLAngle + 30) / 60

        ColorOverlay {
            anchors.fill: parent
            source: aileronLImage
            color: {
                var l = aileronLImage.progress * (maxLightness - minLightness) + minLightness
                return Qt.hsla(0, 0, l, 1);
            }
            visible : !isAileronAngleOutlier(aileronLAngle)
        }

        ColorOverlay {
            anchors.fill: parent
            source: aileronLImage
            color: qgcPal.warningText
            visible: isAileronAngleOutlier(aileronLAngle)
        }
    }

    Image {
        id: aileronRImage
        source: "qrc:/custom/img/vehicle/aileron_r.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        property var adjustedAileronRAngle: aileronRAngle <= 60 ? aileronRAngle : 60
        readonly property real progress: adjustedAileronRAngle / 60
        //readonly property real progress: (adjustedAileronRAngle + 30) / 60

        ColorOverlay {
            anchors.fill: parent
            source: aileronRImage
            color: {
                var l = aileronRImage.progress * (maxLightness - minLightness) + minLightness
                return Qt.hsla(0, 0, l, 1);
            }
            visible : !isAileronAngleOutlier(aileronRAngle)
        }

        ColorOverlay {
            anchors.fill: parent
            source: aileronRImage
            color: qgcPal.warningText
            visible : isAileronAngleOutlier(aileronRAngle)
        }
    }

    Image {
        id: rudderLImage
        source: "qrc:/custom/img/vehicle/rudder_l.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        // Temp Range: 0 ~ 80, Real Range: -40 ~ 40
        property var adjustedRudderLAngle: rudderLAngle <= 80 ? rudderLAngle : 80
        readonly property real progress: adjustedRudderLAngle / 80
        //readonly property real progress: (adjustedRudderLAngle + 40) / 80

        ColorOverlay {
            anchors.fill: parent
            source: rudderLImage
            color: {
                var l = rudderLImage.progress * (maxLightness - minLightness) + minLightness
                return Qt.hsla(0, 0, l, 1);
            }
        }
    }

    Image {
        id: rudderRImage
        source: "qrc:/custom/img/vehicle/rudder_r.svg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        property var adjustedRudderRAngle: rudderRAngle <= 80 ? rudderRAngle : 80
        readonly property real progress: adjustedRudderRAngle / 80
        //readonly property real progress: (adjustedRudderRAngle + 40) / 80

        ColorOverlay {
            anchors.fill: parent
            source: rudderRImage
            color: {
                var l = rudderRImage.progress * (maxLightness - minLightness) + minLightness
                return Qt.hsla(0, 0, l, 1);
            }
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
        angle: tiltFLAngle
    }

    TiltAnimation {
        id: tiltFRAnimation
        width: fuselageImage.paintedWidth * 0.15
        height: fuselageImage.paintedWidth * 0.15
        anchors.top: fuselageImage.top
        anchors.right: fuselageImage.right
        anchors.topMargin: actualImageVerticalOffset + fuselageImage.paintedHeight * 0.1
        anchors.rightMargin: actualImageHorizontalOffset + fuselageImage.paintedWidth * 0.2
        angle: tiltFRAngle
    }

    TiltAnimation {
        id: tiltRLAnimation
        width: fuselageImage.paintedWidth * 0.15
        height: fuselageImage.paintedWidth * 0.15
        anchors.bottom: fuselageImage.bottom
        anchors.left: fuselageImage.left
        anchors.bottomMargin: actualImageVerticalOffset + fuselageImage.paintedHeight * 0.2
        anchors.leftMargin: actualImageHorizontalOffset + fuselageImage.paintedWidth * 0.2
        angle: tiltRLAngle
    }

    TiltAnimation {
        id: tiltRRAnimation
        width: fuselageImage.paintedWidth * 0.15
        height: fuselageImage.paintedWidth * 0.15
        anchors.bottom: fuselageImage.bottom
        anchors.right: fuselageImage.right
        anchors.bottomMargin: actualImageVerticalOffset + fuselageImage.paintedHeight * 0.2
        anchors.rightMargin: actualImageHorizontalOffset + fuselageImage.paintedWidth * 0.2
        angle: tiltRRAngle
    }

    Label {
        id: tiltFLValue
        text: (tiltFLAngle ? tiltFLAngle.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: customScreenTools.fontSize4
        anchors.top: tiltFLAnimation.top
        anchors.right: tiltFLAnimation.left
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 3
        color: getColorByTiltAngle(tiltFLAngle)
    }

    Label {
        id: tiltFRValue
        text: (tiltFRAngle ? tiltFRAngle.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: customScreenTools.fontSize4
        anchors.top: tiltFRAnimation.top
        anchors.left: tiltFRAnimation.right
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 3
        color: getColorByTiltAngle(tiltFRAngle)
    }

    Label {
        id: tiltRLValue
        text: (tiltRLAngle ? tiltRLAngle.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: customScreenTools.fontSize4
        anchors.top: tiltRLAnimation.top
        anchors.right: tiltRLAnimation.left
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 3
        color: getColorByTiltAngle(tiltRLAngle)
    }

    Label {
        id: tiltRRValue
        text: (tiltRRAngle ? tiltRRAngle.toFixed(2) : "--") + " º"
        font.family: "Pretendard SemiBold"
        font.pointSize: customScreenTools.fontSize4
        anchors.top: tiltRRAnimation.top
        anchors.left: tiltRRAnimation.right
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 3
        color: getColorByTiltAngle(tiltRRAngle)
    }

    Item {
        id: aileronL
        anchors.top: fuselageImage.top
        anchors.topMargin: fuselageImage.height * 0.4
        width:  customScreenTools.fontSize3 * 7
        x: aileronLImage.x + (aileronLImage.width - aileronLImage.paintedWidth) / 2  - width - ScreenTools.defaultFontPixelWidth * 3

        ColumnLayout {
            anchors.fill: parent
            Label {
                id: aileronLLabel
                text: "Aileron L"
                font.family: "Pretendard"
                font.pointSize: customScreenTools.fontSize2
                color: qgcPal.text
                horizontalAlignment: Text.AlignRight
                Layout.fillWidth: true
            }

            Label {
                id: aileronLValue
                text: (aileronLAngle ? aileronLAngle.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize3
                color: {
                    if(isAileronAngleOutlier(aileronLAngle)) {
                        return qgcPal.warningText
                    }
                    return qgcPal.text
                }
                horizontalAlignment: Text.AlignRight
                Layout.fillWidth: true
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
                text: "Aileron R"
                font.family: "Pretendard"
                font.pointSize: customScreenTools.fontSize2
                color: qgcPal.text
            }

            Label {
                id: aileronRValue
                text: (aileronRAngle ? aileronRAngle.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize3
                color: {
                    if(isAileronAngleOutlier(aileronRAngle)) {
                        return qgcPal.warningText
                    }
                    return qgcPal.text
                }
            }
        }
    }

    Item {
        id: rudderL
        width:  customScreenTools.fontSize3 * 7
        x: (parent.width / 2) - fuselageImage.paintedWidth * (156.24 / 849.74) - width - ScreenTools.defaultFontPixelWidth * 3
        y: (parent.height / 2) + (fuselageImage.paintedHeight / 2) - ScreenTools.defaultFontPixelHeight * 2

        ColumnLayout {
            anchors.fill: parent
            Label {
                id: rudderLLabel
                text: "Rudder L"
                font.family: "Pretendard"
                font.pointSize: customScreenTools.fontSize2
                color: qgcPal.text
                horizontalAlignment: Text.AlignRight
                Layout.fillWidth: true
            }

            Label {
                id: rudderLValue
                text: (rudderLAngle ? rudderLAngle.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize3
                color: qgcPal.text
                horizontalAlignment: Text.AlignRight
                Layout.fillWidth: true
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
                text: "Rudder R"
                font.family: "Pretendard"
                font.pointSize: customScreenTools.fontSize2
                color: qgcPal.text
            }

            Label {
                id: rudderRValue
                text: (rudderRAngle ? rudderRAngle.toFixed(2) : "--") + " º"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize3
                color: qgcPal.text
            }
        }
    }
}
