import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QGroundControl.Palette
import QGroundControl.ScreenTools

import Qt5Compat.GraphicalEffects

Button {
    id: control
    property url iconSource: "" // 아이콘 이미지 경로
    property string labelText: "" // 탭 텍스트
    property bool active: false // 현재 선택된 탭인지 여부

    Layout.topMargin: 0
    Layout.bottomMargin: 0
    Layout.fillWidth: true
    Layout.preferredHeight: rowLayout.implicitHeight + (ScreenTools.defaultFontPixelHeight * 2)
    //Layout.preferredHeight: contentItem.height

    background: Rectangle {
        color: {
            if (control.active || control.hovered) {
                return "#000000";
            } else {
                return "#292929";
            }
        }
        
        radius: 0
    }

    contentItem: Item {
        RowLayout {
            id: rowLayout
            anchors.fill: parent
            anchors.leftMargin: ScreenTools.defaultFontPixelWidth
            spacing: ScreenTools.defaultFontPixelWidth
            // Layout.alignment: Qt.AlignLeft

            // 아이콘
            Image {
                // Layout 속성을 사용하여 Image의 크기를 직접 지정
                Layout.preferredWidth: ScreenTools.defaultFontPixelWidth * 2
                Layout.preferredHeight: ScreenTools.defaultFontPixelWidth * 2
                source: control.iconSource
                fillMode: Image.PreserveAspectFit

                ColorOverlay {
                    anchors.fill: parent
                    source: parent
                    color: {
                        if (control.active || control.hovered) {
                            return "#1de9b6";
                        } else {
                            return "#ffffff";
                        }
                    }
                }
            }

            // 라벨
            Label {
                text: control.labelText
                font.pointSize: 12
                Layout.fillWidth: true
                color: {
                    if (control.active || control.hovered) {
                        return "#1de9b6";
                    } else {
                        return "#ffffff";
                    }
                }
            }
        }
    }
}
