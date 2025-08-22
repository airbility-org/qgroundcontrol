import QtQuick
import Qt5Compat.GraphicalEffects

import QGroundControl.ScreenTools

Rectangle {
    id: toggleButton
    border.color: qgcPal.customPointColor
    border.width: 1.5

    width: ScreenTools.defaultFontPixelWidth * 4.7
    height: width
    radius: width / 2

    signal clicked()

    color: {
        if (mouseArea.containsMouse) {
            return qgcPal.customPointColor
        } else {
            return "transparent"
        }
    }

    property var isOpened: true

    Image {
        source: isOpened ? "qrc:/custom/icon/Toggle_close_ico.svg" : "qrc:/custom/icon/Toggle_open_ico.svg"
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
        anchors.margins: ScreenTools.defaultFontPixelWidth * 1.5

        ColorOverlay {
            anchors.fill: parent
            source: parent
            color: {
                if (mouseArea.containsMouse) {
                    return customPal.normalColor
                } else {
                    return qgcPal.customPointColor
                }
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        onClicked: toggleButton.clicked()
    }
}
