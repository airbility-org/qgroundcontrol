import QtQuick
import QtQuick.Layouts

import QGroundControl.Palette

RowLayout {
    property var fact 
    property string labelText: ""
    property var valueText: fact ? fact.value : NaN
    property string unitText: fact ? fact.units : "--"

    Text {
        text: labelText
        font.family: "Pretendard"
        font.pointSize: customScreenTools.fontSize1
        color: qgcPal.text
        horizontalAlignment: Text.AlignLeft
    }

    Item {
        Layout.fillWidth: true
        height: 1
    }

    Text {
        text: !isNaN(valueText) ? valueText.toFixed(2) : "--"
        font.family: "Pretendard SemiBold"
        color: qgcPal.text
        font.pointSize: customScreenTools.fontSize2
        Layout.preferredWidth: customScreenTools.fontSize2 * 4
        horizontalAlignment: Text.AlignRight
    }

    Text {
        text: unitText
        font.family: "Pretendard"
        color: qgcPal.text
        font.pointSize: customScreenTools.fontSize1
        Layout.alignment: Qt.AlignRight
    }
}
