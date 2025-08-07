import QtQuick
import QtQuick.Layouts

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
        color: "white"
    }

    Item {
        Layout.fillWidth: true
        height: 1
    }

    Text {
        text: valueText
        font.family: "Pretendard SemiBold"
        color: "white"
        font.pointSize: customScreenTools.fontSize2
    }

    Text {
        text: unitText
        font.family: "Pretendard"
        color: "white"
        font.pointSize: customScreenTools.fontSize1
        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
    }
}
