import QtQuick

import "qrc:/custom/qml/CustomComponent"

Item {
    id: toggleComponent
    width: toggleButton.width * 1.4
    height: width
    
    signal toggleClicked()

    Rectangle {
        anchors.fill: parent
        color: qgcPal.toolbarBackground
        radius: 5

        CustomToggleButton {
            id: toggleButton
            isOpened: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: toggleClicked()
        }
    }
}
