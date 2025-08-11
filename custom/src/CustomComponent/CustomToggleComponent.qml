import QtQuick

import "qrc:/custom/qml/CustomComponent"

Item {
    id: toggleComponent
    width: toggleButton.width * 1.4
    height: width
    
    signal buttonClicked()

    Rectangle {
        anchors.fill: parent
        color: customPal.darkGray
        radius: 5

        CustomToggleButton {
            id: toggleButton
            isOpened: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: buttonClicked()
        }
    }
}
