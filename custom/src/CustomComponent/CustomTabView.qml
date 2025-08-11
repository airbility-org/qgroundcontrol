// File: MyNewTabView.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QGroundControl
import QGroundControl.Controls
import QGroundControl.Palette
import QGroundControl.ScreenTools
import QGroundControl.FlightDisplay

import "qrc:/custom/qml/CustomComponent"

Item {
    id: customTabViewRoot
    anchors.fill: parent

    property var tabSources: [
        "qrc:/custom/qml/FlightStatus/PropulsionPowerTab.qml",
        "qrc:/custom/qml/FlightStatus/ControlTab.qml",

        "qrc:/custom/qml/VehicleConfiguration/GeneralTab.qml",
        "qrc:/custom/qml/VehicleConfiguration/PropulsionPowerTab.qml",
        "qrc:/custom/qml/VehicleConfiguration/ControlTab.qml",
    ]

    function initialize(initialIndex) {
        leftTabPanel.currentTabIndex = initialIndex;
        mainContentLoader.source = tabSources[initialIndex];
    }

    CustomTabToolbar {
        id: toolbar
    }

    CustomLeftTab {
        id: leftTabPanel
        contentLoader: mainContentLoader
        anchors.top: toolbar.bottom
        visible: parent.width > 800

        onToggleClicked: {
            leftTabPanel.visible = false        // LeftTab 숨김
            toggleComponent.visible = true // Toggle 버튼 보이기
        }
    }

    CustomToggleComponent {
        id: toggleComponent
        anchors.top: toolbar.bottom
        z: QGroundControl.zOrderTopMost

        visible: false
        onButtonClicked: {
            leftTabPanel.visible = true
            toggleComponent.visible = false
        }
    }

    // 동적 콘텐츠 영역
    Loader {
        id: mainContentLoader
        Layout.fillWidth: true
        Layout.fillHeight: true
        anchors.left: leftTabPanel.visible ? leftTabPanel.right : parent.left
        anchors.right: parent.right
        anchors.top: toolbar.bottom
        anchors.bottom: parent.bottom
    }
}
