import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import QGroundControl
import QGroundControl.Controls
import QGroundControl.Palette
import QGroundControl.MultiVehicleManager
import QGroundControl.ScreenTools
import QGroundControl.Controllers

import QtQuick.Shapes

Rectangle {
    id: customTelemetryWidget
    width: mainWindow.width * 0.4
    color: Qt.rgba(0, 0, 0, 0.56) 
    radius: 10

    property int valuePointSize: 13
    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

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
            spacing: ScreenTools.defaultFontPixelWidth
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top // 세로 위치도 지정해줍니다.
            anchors.topMargin: ScreenTools.defaultFontPixelWidth * 2

            Image {
                id: speedIcon
                source: "qrc:/custom/icon/Speed_ico.svg"
                fillMode: Image.PreserveAspectFit
                // 이미지의 크기를 명시적으로 지정
                width: ScreenTools.defaultFontPixelHeight * 1.2
            }

            Text {
                id: speedLabel
                text: "SPEED"
                font.family: "Pretendard SemiBold"
                font.pointSize: 13
                color: "white"
            }
        }

        Column {
            id: airSpeedData
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: headerRow.bottom
            anchors.margins: ScreenTools.defaultFontPixelWidth * 2
            spacing: ScreenTools.defaultFontPixelWidth

            Row {
                spacing: ScreenTools.defaultFontPixelWidth

                Text {
                    id: airspeedLabel
                    text: "Airspeed"
                    font.family: "Pretendard"
                    font.pointSize: 10
                    color: "white"
                }

                Text {
                    id: airspeedValue
                    text: _activeVehicle ? _activeVehicle.vehicle.airSpeed.valueString : "--" 
                    font.family: "Pretendard SemiBold"
                    color: "white"
                    font.pointSize: 12
                }
                Text {
                    id: airspeedUnit
                    text: "m/s"
                    font.family: "Pretendard"
                    color: "white"
                    font.pointSize: 10
                }
            }

            Row {
                spacing: ScreenTools.defaultFontPixelWidth

                Text {
                    id: groundSpeedLabel
                    text: "Ground Speed"
                    font.family: "Pretendard"
                    font.pointSize: 10
                    color: "white"
                }

                Text {
                    id: groundSpeedValue
                    text: _activeVehicle ? _activeVehicle.vehicle.groundSpeed.valueString : "--" 
                    font.family: "Pretendard SemiBold"
                    color: "white"
                    font.pointSize: valuePointSize
                }
                Text {
                    id: groundSpeedUnit
                    text: "m/s"
                    font.family: "Pretendard"
                    color: "white"
                    font.pointSize: 10
                }
            }
        }
    }

    Item {
        id: positionSection
        anchors.left: speedSection.right
        width: parent.width / 3
        height: parent.height

        Row {
            id: positionRow
            spacing: ScreenTools.defaultFontPixelWidth
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top // 세로 위치도 지정해줍니다.
            anchors.topMargin: ScreenTools.defaultFontPixelWidth * 2

            Image {
                id: positionIcon
                source: "qrc:/custom/icon/Position_ico.svg"
                fillMode: Image.PreserveAspectFit
                width: ScreenTools.defaultFontPixelHeight * 1.2
            }

            Text {
                id: positionLabel
                text: "POSITION"
                font.family: "Pretendard SemiBold"
                font.pointSize: 13
                color: "white"
            }
        }

        Column {
            id: positionData
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: positionRow.bottom
            anchors.margins: ScreenTools.defaultFontPixelWidth * 2
            spacing: ScreenTools.defaultFontPixelWidth

            Row {
                spacing: ScreenTools.defaultFontPixelWidth
                Text {
                    id: latitudeLabel
                    text: "Latitude"
                    font.family: "Pretendard"
                    font.pointSize: 10
                    color: "white"
                }

                Text {
                    id: latitudeValue
                    text: _activeVehicle ? _activeVehicle.gps.lat.valueString : "--" 
                    font.family: "Pretendard SemiBold"
                    color: "white"
                    font.pointSize: valuePointSize
                }
                /**
                Text {
                    id: longitudeUnit
                    text: "m/s"
                    font.family: "Pretendard"
                    color: "white"
                    font.pointSize: 10
                }
                **/
            }

            Row {
                spacing: ScreenTools.defaultFontPixelWidth
                Text {
                    id: longitudeLabel
                    text: "Longitude"
                    font.family: "Pretendard"
                    font.pointSize: 10
                    color: "white"
                }

                Text {
                    id: longitudeValue
                    text: _activeVehicle ? _activeVehicle.gps.lon.valueString : "--" 
                    font.family: "Pretendard SemiBold"
                    color: "white"
                    font.pointSize: valuePointSize
                }
                /**
                Text {
                    id: longitudeUnit
                    text: "m/s"
                    font.family: "Pretendard"
                    color: "white"
                    font.pointSize: 10
                }
                **/
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
            spacing: ScreenTools.defaultFontPixelWidth
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top // 세로 위치도 지정해줍니다.
            anchors.topMargin: ScreenTools.defaultFontPixelWidth * 2

            Image {
                id: heightIcon
                source: "qrc:/custom/icon/Height_ico.svg"
                fillMode: Image.PreserveAspectFit
                width: ScreenTools.defaultFontPixelHeight * 1.2
            }

            Text {
                id: heightLabel
                text: "HEIGHT"
                font.family: "Pretendard SemiBold"
                font.pointSize: 13
                color: "white"
            }
         }

        Column {
            id: heightData
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: heightRow.bottom
            anchors.margins: ScreenTools.defaultFontPixelWidth * 2
            spacing: ScreenTools.defaultFontPixelWidth

            Row {
                spacing: ScreenTools.defaultFontPixelWidth
                Text {
                    id: aglLabel
                    text: "AGL"
                    font.family: "Pretendard"
                    font.pointSize: 10
                    color: "white"
                }

                Text {
                    id: aglValue
                    text: _activeVehicle ? _activeVehicle.vehicle.airSpeed.valueString : "--" 
                    font.family: "Pretendard SemiBold"
                    color: "white"
                    font.pointSize: valuePointSize
                }
                Text {
                    id: aglUnit
                    text: "m"
                    font.family: "Pretendard"
                    color: "white"
                    font.pointSize: 10
                }
            }

            Row {
                spacing: ScreenTools.defaultFontPixelWidth
                Text {
                    id: mslLabel
                    text: "MSL"
                    font.family: "Pretendard"
                    font.pointSize: 10
                    color: "white"
                }

                Text {
                    id: mslValue
                    text: _activeVehicle ? _activeVehicle.vehicle.altitudeAMSL.valueString : "--" 
                    font.family: "Pretendard SemiBold"
                    color: "white"
                    font.pointSize: valuePointSize
                }
                Text {
                    id: mslUnit
                    text: "m"
                    font.family: "Pretendard"
                    color: "white"
                    font.pointSize: 10
                }
            }
        }
    }
}


/**
        Item {
            id: groundSpeedData
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: airspeedUnit.bottom
            anchors.topMargin: ScreenTools.defaultFontPixelWidth

            Text {
                id: groundSpeedLabel
                text: "Ground Speed"
                font.family: "Pretendard"
                font.pointSize: 10
                color: "white"

                anchors.left: parent.left
                anchors.leftMargin: ScreenTools.defaultFontPixelWidth
            }

            Text {
                id: groundSpeedValue
                text: _activeVehicle ? _activeVehicle.vehicle.airSpeed.valueString : "--" 
                font.family: "Pretendard SemiBold"
                color: "white"
                font.pointSize: 12

                anchors.right: groundSpeedUnit.left
                anchors.rightMargin: ScreenTools.defaultFontPixelWidth
                anchors.bottom: groundSpeedUnit.bottom
            }

            Text {
                id: groundSpeedUnit
                text: "m/s"
                font.family: "Pretendard"
                color: "white"
                font.pointSize: 10

                anchors.right: parent.right
                anchors.rightMargin: ScreenTools.defaultFontPixelWidth
            }
        }
        Row {
            anchors.top: headerRow.bottom
            anchors.topMargin: ScreenTools.defaultFontPixelHeight * 1.5
            anchors.left: parent.left 
            anchors.leftMargin: ScreenTools.defaultFontPixelHeight
            
            Text {
                id: airspeedLabel
                text: "Airspeed"
                font.family: "Pretendard"
                font.pointSize: 10
                color: "white"
            }

            Item {
                width: speedSection.width - airspeedLabel.width - airspeedValue.width - airspeedUnit.width
                height: 1
            }

            Text {
                id: airspeedValue
                text: _activeVehicle.vehicle.altitudeAMSL.valueString
                font.family: "Pretendard SemiBold"
                color: "white"
                font.pointSize: 12

            }

            Text {
                id: airspeedUnit
                text: "m/s"
                font.family: "Pretendard"
                color: "white"
                font.pointSize: 10
            }
        }
        **/
/**
_activeVehicle.airSpeed
_activeVehicle.groundSpeed
_activeVehicle.altitude.altitudeRelative
_activeVehicle.altitude.altitudeAMSL
**/
