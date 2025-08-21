import QtQuick
import QtQuick.Controls
import QtQuick.Shapes
import QGroundControl.Palette
import QGroundControl.ScreenTools

import "qrc:/custom/qml/FlightStatus"

Rectangle {
    id: flightStatus_control
    color: qgcPal.globalTheme === QGCPalette.Light ? "#ffffff" : "#000000"

    // 기체 형상 
    AirframeView {
        anchors.fill: parent
        anchors.topMargin: ScreenTools.defaultFontPixelWidth * 10
        anchors.bottomMargin: ScreenTools.defaultFontPixelWidth * 10
    }
}