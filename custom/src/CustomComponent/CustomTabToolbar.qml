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
            source: "qrc:/custom/img/airbility_small_logo.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: ScreenTools.defaultFontPointSize * 1
        }

        Image {
            id: airbility_typo_logo
            source: "qrc:/custom/img/airbility_typo_logo.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: ScreenTools.defaultFontPointSize * 1
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
