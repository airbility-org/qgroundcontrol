import QtQuick
import QtQuick.Layouts

import QGroundControl.Palette

RowLayout {
    property var fact 
    property string labelText: ""
    property string valueText: fact ? fact.valueString : "--"
    property string unitText: fact ? fact.units : "--"

    width: parent ? parent.width : 0

    Text {
        text: labelText
        font.family: "Pretendard"
        font.pointSize: customScreenTools.fontSize1
        color: qgcPal.text
    }

    Item {
        Layout.fillWidth: true
        height: 1
    }

    Text {
        text: valueText
        font.family: "Pretendard SemiBold"
        color: qgcPal.text
        font.pointSize: customScreenTools.fontSize2
    }

    Text {
        text: unitText
        font.family: "Pretendard"
        color: qgcPal.text
        font.pointSize: customScreenTools.fontSize1
        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
    }
}
