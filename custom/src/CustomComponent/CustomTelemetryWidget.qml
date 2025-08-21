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

    implicitWidth: rowLayout.implicitWidth + customScreenTools.fontSize2 * 2
    implicitHeight: rowLayout.implicitHeight + customScreenTools.fontSize2 * 2
    anchors.margins: customScreenTools.fontSize2
    color: Qt.rgba(qgcPal.window.r, qgcPal.window.g, qgcPal.window.b, 0.8) 
    radius: 10

    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    QGCPalette { id: qgcPal; colorGroupEnabled: enabled }

    DeadMouseArea {
        anchors.fill: parent
    }

    RowLayout {
        id: rowLayout
        anchors.fill: parent
        anchors.margins: customScreenTools.fontSize2
        spacing: customScreenTools.fontSize2 * 3

        Repeater {
            model: [
                { 
                    title: "SPEED", 
                    icon: "qrc:/custom/icon/Speed_ico.svg", 
                    rows: [
                        { label: "Airspeed", vehicleFact: _activeVehicle ? _activeVehicle.vehicle.airSpeed : undefined },
                        { label: "Ground Speed", vehicleFact: _activeVehicle ? _activeVehicle.vehicle.groundSpeed : undefined },
                    ]
                },
                { 
                    title: "POSITION", 
                    icon: "qrc:/custom/icon/Position_ico.svg", 
                    rows: [
                        { label: "Latitude", vehicleFact: _activeVehicle ? _activeVehicle.gps.lat : undefined },
                        { label: "Longitude", vehicleFact: _activeVehicle ? _activeVehicle.gps.lon : undefined },
                    ]
                },
                { 
                    title: "HEIGHT", 
                    icon: "qrc:/custom/icon/Height_ico.svg", 
                    rows: [
                        { label: "AGL", vehicleFact: _activeVehicle ? _activeVehicle.vehicle.airSpeed : undefined },
                        { label: "MSL", vehicleFact: _activeVehicle ? _activeVehicle.vehicle.altitudeAMSL : undefined },
                    ]
                }
            ]

            delegate: Item {
                id: section
                Layout.fillHeight: true
                Layout.preferredWidth: colLayout.implicitWidth + customScreenTools.fontSize2
                implicitHeight: colLayout.implicitHeight

                ColumnLayout {
                    id: colLayout
                    anchors.fill: parent
                    spacing: customScreenTools.fontSize1

                    RowLayout {
                        Layout.alignment: Qt.AlignHCenter
                        spacing: customScreenTools.fontSize2 / 2
                        Image {
                            id: icon
                            source: modelData.icon
                            fillMode: Image.PreserveAspectFit
                            width: title.height * 0.9

                            ColorOverlay {
                                anchors.fill: parent
                                source: icon
                                color: qgcPal.text
                            }
                        }
                        Text {
                            id: title
                            text: modelData.title
                            font.family: "Pretendard SemiBold"
                            font.pointSize: customScreenTools.fontSize2
                            color: qgcPal.text
                        }
                    }

                    Repeater {
                        model: modelData.rows
                        delegate: CustomFactValueRowComponent {
                            Layout.fillWidth: true
                            labelText: modelData.label
                            fact: modelData.vehicleFact
                        }
                    }
                }
                Rectangle {
                    visible: index < 2
                    width: 1.5
                    height: colLayout.height
                    color: qgcPal.text
                    anchors.left: section.right
                    anchors.leftMargin: customScreenTools.fontSize2 * 1.5
                }
            }
        }
    }
}

