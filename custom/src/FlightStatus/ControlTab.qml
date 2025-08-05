import QtQuick
import QtQuick.Controls
import QtQuick.Shapes 1.15
import QGroundControl.ScreenTools

import "qrc:/custom/qml/FlightStatus"

Rectangle {
    id: flightStatus_control
    color: "#000000"

    // 기체 형상 
    AirframeView {
        anchors.fill: parent
        anchors.topMargin: ScreenTools.defaultFontPixelWidth * 10
        anchors.bottomMargin: ScreenTools.defaultFontPixelWidth * 10
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 25
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 25
    }
}