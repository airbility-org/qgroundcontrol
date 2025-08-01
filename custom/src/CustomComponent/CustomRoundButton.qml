import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QGroundControl.Palette
import QGroundControl.ScreenTools
import Qt5Compat.GraphicalEffects

Rectangle {
    id: control
    property url iconSource: ""
    property string labelText: ""
    
    signal clicked()

    width: ScreenTools.defaultFontPixelWidth * 11
    height: ScreenTools.defaultFontPixelWidth * 4
    radius: 29.5
    border.color: "#1de9b6"
    border.width: ScreenTools.defaultFontPixelWidth * 0.1
    Layout.topMargin: ScreenTools.defaultFontPointSize * 1
    Layout.leftMargin: ScreenTools.defaultFontPointSize * 1
    Layout.bottomMargin: ScreenTools.defaultFontPointSize * 1

    color: {
        if (mouseArea.containsMouse) {
            return "#1de9b6"
        } else {
            "#292929"
        }
    }

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: ScreenTools.defaultFontPixelWidth
        spacing: ScreenTools.defaultFontPixelWidth

        Image {
            id: iconImage
            source: control.iconSource
            Layout.preferredWidth: ScreenTools.defaultFontPixelWidth * 1.5
            Layout.preferredHeight: ScreenTools.defaultFontPixelWidth * 1.5
            Layout.leftMargin: ScreenTools.defaultFontPointSize * 0.3
            fillMode: Image.PreserveAspectFit

            ColorOverlay {
                anchors.fill: parent
                source: parent
                color: {
                    if (mouseArea.containsMouse) {
                        return "#292929";
                    } else {
                        return "#ffffff";
                    }
                }
            }
        }

        Label {
            text: control.labelText
            font.family: "Pretendard"
            font.pointSize: 12
            color: {
                if (mouseArea.containsMouse) {
                    return "#292929"
                } else {
                    "white"
                }
            }
        }

    }
    
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        onClicked: control.clicked()
    }
}