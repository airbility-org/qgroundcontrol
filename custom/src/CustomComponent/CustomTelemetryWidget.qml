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

import QtQuick.Shapes
import "qrc:/custom/qml"
import "qrc:/custom/qml/CustomComponent"

Rectangle {
    id: customTelemetryWidget
    property int externalParentWidth: parent.width
    property int externalParnetHeight: parent.height

    width: 750 * customScreenTools.defaultWidthRatio
    height: 200 * customScreenTools.defaultHeightRatio
    color: qgcPal.window
    radius: 10

    property int valuePointSize: 13
    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    QGCPalette { id: qgcPal; colorGroupEnabled: enabled }

    DeadMouseArea {
        anchors.fill:       parent
    }

    Item {
        id: speedSection
        anchors.left: parent.left
        width: parent.width / 3
        height: parent.height

        Row {
            id: headerRow
            spacing: customScreenTools.fontSize2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: customScreenTools.fontSize2

            Image {
                id: speedIcon
                source: "qrc:/custom/icon/Speed_ico.svg"
                fillMode: Image.PreserveAspectFit
                width: customScreenTools.fontSize2 * 1.3

                ColorOverlay {
                    anchors.fill: parent
                    source: speedIcon
                    color: qgcPal.text
                }
            }

            Text {
                id: speedLabel
                text: "SPEED"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize2
                color: qgcPal.text
            }
        }

        Column {
            id: airSpeedData
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: headerRow.bottom
            anchors.margins: customScreenTools.fontSize2
            spacing: customScreenTools.fontSize1
            
            CustomFactValueRowComponent {
                labelText: "Airspeed"
                fact: _activeVehicle ? _activeVehicle.vehicle.airSpeed : undefined
            }

            CustomFactValueRowComponent {
                labelText: "Ground Speed"
                fact: _activeVehicle ? _activeVehicle.vehicle.groundSpeed : undefined
            }
        }
    }

    Item {
        id: positionSection
        anchors.left: speedSection.right
        width: parent.width / 3
        height: parent.height

        RowLayout {
            id: positionRow
            spacing: customScreenTools.fontSize2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top // 세로 위치도 지정해줍니다.
            anchors.topMargin: customScreenTools.fontSize2

            Image {
                id: positionIcon
                source: "qrc:/custom/icon/Position_ico.svg"
                fillMode: Image.PreserveAspectFit
                width: customScreenTools.fontSize2 * 1.2

                ColorOverlay {
                    anchors.fill: parent
                    source: positionIcon
                    color: qgcPal.text
                }
            }

            Text {
                id: positionLabel
                text: "POSITION"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize2
                color: qgcPal.text
            }
        }

        Column {
            id: positionData
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: positionRow.bottom
            anchors.margins: customScreenTools.fontSize2
            spacing: customScreenTools.fontSize1

            CustomFactValueRowComponent {
                labelText: "Latitude"
                fact: _activeVehicle ? _activeVehicle.gps.lat : undefined
            }

            CustomFactValueRowComponent {
                labelText: "Longitude"
                fact: _activeVehicle ? _activeVehicle.gps.lon : undefined
            }
        }
    }

    Item {
        id: heightSection
        anchors.left: positionSection.right
        width: parent.width / 3
        height: parent.height

        Row {
            id: heightRow
            spacing: customScreenTools.fontSize2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top // 세로 위치도 지정해줍니다.
            anchors.topMargin: customScreenTools.fontSize2

            Image {
                id: heightIcon
                source: "qrc:/custom/icon/Height_ico.svg"
                fillMode: Image.PreserveAspectFit
                width: customScreenTools.fontSize2 * 1.2
                
                ColorOverlay {
                    anchors.fill: parent
                    source: speedIcon
                    color: qgcPal.text
                }
            }

            Text {
                id: heightLabel
                text: "HEIGHT"
                font.family: "Pretendard SemiBold"
                font.pointSize: customScreenTools.fontSize2
                color: qgcPal.text
            }
         }

        Column {
            id: heightData
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: heightRow.bottom
            anchors.margins: customScreenTools.fontSize2
            spacing: customScreenTools.fontSize1

            CustomFactValueRowComponent {
                labelText: "AGL"
                fact: _activeVehicle ? _activeVehicle.vehicle.airSpeed : undefined
            }

            CustomFactValueRowComponent {
                labelText: "MSL"
                fact: _activeVehicle ? _activeVehicle.vehicle.altitudeAMSL : undefined
            }
        }
    }
}

