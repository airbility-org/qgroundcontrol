import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QGroundControl.Palette
import QGroundControl.ScreenTools
import Qt5Compat.GraphicalEffects

Rectangle {
    id: roundButton
    property url iconSource: ""
    property string labelText: ""
    
    signal clicked()

    width: ScreenTools.defaultFontPixelWidth * 11
    height: ScreenTools.defaultFontPixelWidth * 5
    radius: 29.5
    border.color: qgcPal.globalTheme === QGCPalette.Light ? "#009788" : customPal.pointColor
    border.width: 1.5

    color: {
        if (mouseArea.containsMouse) {
            return qgcPal.globalTheme === QGCPalette.Light ? "#009788" : customPal.pointColor
        } else {
            return "transparent"
        }
    }

    RowLayout {
        anchors.centerIn: parent
        spacing: ScreenTools.defaultFontPixelWidth

        Image {
            id: iconImage
            source: roundButton.iconSource
            Layout.preferredWidth: ScreenTools.defaultFontPixelWidth * 1.5
            // Layout.leftMargin: ScreenTools.defaultFontPointSize * 0.3
            fillMode: Image.PreserveAspectFit

            ColorOverlay {
                anchors.fill: parent
                source: parent
                color: {
                    if (mouseArea.containsMouse) {
                        return qgcPal.globalTheme === QGCPalette.Light ? "#ffffff" : "#000000"
                    } else {
                        return qgcPal.text
                    }
                }
            }
        }

        Label {
            id: mainLabel
            text: roundButton.labelText
            font.family: "Pretendard"
            font.pointSize: 12
            color: {
                if (mouseArea.containsMouse) {
                    return qgcPal.globalTheme === QGCPalette.Light ? "#ffffff" : "#000000"
                } else {
                    return qgcPal.text
                }
            }
        }
    }
    
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        onClicked: roundButton.clicked()
    }
}