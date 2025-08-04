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

Rectangle {
    id: tabToolbar
    width: parent.width
    height: ScreenTools.toolbarHeight
    color: "#292929"

    Item {
        anchors.fill: parent

        Image {
            id: airbility_logo
            source: "qrc:/custom/img/airbility_small_logo.svg"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: ScreenTools.defaultFontPixelWidth * 1.5
            width: ScreenTools.defaultFontPixelWidth * 3.2
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: airbility_typo_logo
            source: "qrc:/custom/img/airbility_typo_logo_white.svg"
            anchors.top:            parent.top
            anchors.bottom:         parent.bottom
            anchors.right: parent.right
            anchors.margins:        ScreenTools.defaultFontPixelHeight
            fillMode: Image.PreserveAspectFit
        }
    }
    
    Rectangle {
        id: bottomBorder
        width: parent.width
        height: 1
        color: "#848484"
        anchors.bottom: parent.bottom
    }
}
